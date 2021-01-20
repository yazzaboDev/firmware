#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char log_print_buffer[512];

void main ( void ) {

	FILE *fp;
	printf("access(): %d\n", access( "logs.txt", F_OK ));
	fp = fopen("logs.txt", "w+");
   	fprintf(fp, "This is testing for fprintf...\n");
   	fputs("This is testing for fputs...\n", fp);
   	fprintf(fp, "This is testing for fprintf2...\n");
   	fputs("This is testing for fputs2...\n", fp);
   	fclose(fp);
   	
	fp = fopen("logs.txt", "r");
	char line[128];
   	while ( fgets(line, sizeof(line), fp) != NULL ) {
   		printf("%s",line);
	}
   	
   	fclose(fp);
   	
   	
    printf("\033[0;31m");
    printf("hello to all");
    printf("\033[0m");
    printf("\033[0;35m");
    printf("\nthis is a c program from which see how the colour coding (ANSI Colors) works ");
    printf("\033[0m");
    printf("\033[1;36m");
    printf("\n\nfollow these steps :\nfirstly you must now about the colour codes ");
    printf("\033[0m	");
  printf("\033[0;34m");
  printf("\nthese are some ansi codes for colour changing::::");
    printf("\033[0m");
    printf("\033[0;35m");
  printf("\nplease see the code how i use the colour code");
  printf("\033[0m");
  printf("\033[0;31m");
  printf("\nbecause the compiler tries also to run the syntax in printf statement");
    printf("\033[0m");
    printf("\033[0;31m");
    printf("\n\nred==[0;31m");
    printf("\033[0m");
    printf("\033[1;31m");
    printf("\nbold red==[1;31m");
    printf("\033[0m");
    printf("\033[0;32m");
    printf("\ngreen==[0;32m");
    printf("\033[0m");
    printf("\033[1;32m");
    printf("\nbold green==[1;32m");
    printf("\033[0m");
    printf("\033[0;33m");
    printf("\nyellow==[0;33m");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("\nbold yellow==[1;33m");
    printf("\033[0m");
    printf("\033[0;34m");
    printf("\nblue==[0,34m");
    printf("\033[0m");
    printf("\033[1;34m");
    printf("\nbold blue==[1;34m");
    printf("\033[0m");
    printf("\033[0;35m");
    printf("\nmagenta==[0;35m");
    printf("\033[0m");
    printf("\033[1;35m");
    printf("\nbold magenta==[1;35m");
    printf("\033[0m");
    printf("\033[0;36m");
    printf("\ncyan==[0;36m");
    printf("\033[0m");
    printf("\033[1;36m");
    printf("\nbold cyan==[1;36m");
    printf("\033[0m");
    printf("\033[0m");
    printf("\n reset or to end the change in colour==[0m");
    printf("\033[0m");
    printf("\033[0;34m");
    printf("\nby using this colour coding scheme you can make your code look good");
    printf("\033[0m");
    printf("\033[1;32m");
    printf("\nthank you ");
    printf("\033[0m");
   	
	return;
}
