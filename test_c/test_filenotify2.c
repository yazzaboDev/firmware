#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>    
#include <sys/select.h>   
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/inotify.h>

#define MAX_EVENTS 1024 /*Max. number of events to process at one go*/
#define LEN_NAME 16 /*Assuming that the length of the filename won't exceed 16 bytes*/
#define EVENT_SIZE  ( sizeof (struct inotify_event) ) /*size of one event*/
#define BUF_LEN     ( MAX_EVENTS * ( EVENT_SIZE + LEN_NAME )) /*buffer to store the data of events*/
 
void main( int argc, char **argv ) {
	char inotifybuf[sizeof(struct inotify_event) + MAX_EVENTS];
	int inotifyfd, inotifywd, subscribefd, ret, i;
	fd_set read_flags, write_flags;
	struct timeval timeout;
	timeout.tv_usec=0;
	char cwd[MAX_EVENTS];
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
	   printf("Current working dir: %s\n", cwd);
	} else {
	   perror("getcwd() error");
	   return;
	}
	const char *fname = "syncf";
	strcat(cwd,"/");
	strcat(cwd,fname);
	printf("File to watch: %s\n", cwd);
	
	inotifyfd = inotify_init();
	if(inotifyfd<0) {
		perror("inotify init error");
	}
	inotifywd = inotify_add_watch(inotifyfd, (const char*) cwd, IN_MODIFY|IN_CREATE);
		
	FD_ZERO(&read_flags);
	FD_ZERO(&write_flags);
	while(1){
		timeout.tv_sec=30;
		FD_SET(inotifyfd, &read_flags);
		ret = select(inotifyfd+1, &read_flags,NULL,NULL, &timeout );
		if(ret < 0){
			//error
			break;
		}
		if(FD_ISSET(inotifyfd, &read_flags)){
			FD_CLR(inotifyfd, &read_flags);
			i=read(inotifyfd, inotifybuf, sizeof(inotifybuf));
			//printf("read: %d\n",i);
			
			// open file and read
			FILE *fp;
			fp = fopen(fname, "r");
			char line[128];
		   	while ( fgets(line, sizeof(line), fp) != NULL ) {
		   		printf("line read: %s\n",line);
			}
   			fclose(fp);
   			
   			if ( line[0] == '0') {
				printf("Edit file process 2\n");
   				fp = fopen(fname, "w");
   				line[0] = '1';
   				fwrite(line, 1, 1, fp);
   				fclose(fp);
				inotify_rm_watch( inotifyfd, inotifywd);
				inotifywd = inotify_add_watch(inotifyfd, (const char*) cwd, IN_MODIFY|IN_CREATE);
   			}
   			
   			sleep(2);
		}
	}
	
	return;
}
