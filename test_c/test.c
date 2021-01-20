#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

			// {"nadr\":\"0\",\"radr\":\"1\",\"val\":\"2"}
//char str[] = "{\"nadr\":\"0\",\"radr\":\"1\",\"val\":\"2\"}";
char str[] = "{\"nadr\":\"0,radr:1,val:2\"}";

char* get_first_key( char instr[], const char* sep ) {
	char * tmpstr = strtok(instr,sep); 	// remove first '{' and '"' or '''
	tmpstr = strtok(NULL,sep);			// get key between '"' or '''
	return tmpstr;							// FIRST KEY
}

char* get_key_val( char instr[], const char* sep ) {
	char * tmpstr = strtok(NULL,sep); 	// remove first '{' and '"' or '''
	tmpstr = strtok(NULL,sep);			// get key between '"' or '''
	return tmpstr;							// NEXT KEY
}

char* get_next_key( char instr[], const char* sep ) {
	char * tmpstr = strtok(NULL,sep); 	// remove first '{' and '"' or '''
	tmpstr = strtok(NULL,sep);			// get key between '"' or '''
	return tmpstr;							// NEXT VAL
}

int main(void) {
	// your code goes here
	
	printf("%s\n\n",str);
	char *tmpstr;
	
	/*
	printf("key: %s\n", (tmpstr = get_first_key(str)) ); 		// FIRST KEY
	printf("val: %s\n\n", (tmpstr = get_key_val(tmpstr)) ); 		// FIRST VAL
	
	printf("key: %s\n",get_next_key(tmpstr)); 					// SECOND KEY
	printf("val: %s\n\n", (tmpstr = get_key_val(tmpstr)) ); 		// SECOND VAL
	
	printf("key: %s\n",get_next_key(tmpstr)); 					// THIRD KEY
	printf("val: %s\n\n", (tmpstr = get_key_val(tmpstr)) ); 		// THIRD VAL
	*/
	
	printf("Key0: %s\n", (tmpstr = get_first_key(str,"'\"")) );							// first key
	printf("Node addres val: %s\n", (tmpstr = get_key_val(tmpstr,",'\"")) );			// first key value
	printf("key1: %s\n", (tmpstr = strtok(NULL,":")));									// next key
	printf("Node register addres val: %s\n", (tmpstr = strtok(NULL,",")));				// key value
	printf("key2: %s\n", (tmpstr = strtok(NULL,":")));									// next key
	printf("Node register addres val: %s\n", (tmpstr = strtok(NULL,"\"")));				// key value

	/*
	char * tmpstr = strtok(str,"'\""); 	// remove first '{' and '"' or '''
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	printf("key: %s\n",tmpstr); 		// FIRST KEY
	
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	printf("val: %s\n",tmpstr);	 		// FIRST VAL
	
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	printf("key: %s\n",tmpstr);	 		// SECOND KEY
	
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	printf("val: %s\n",tmpstr);	 		// SECOND VAL
	
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	printf("key: %s\n",tmpstr);	 		// THIRD KEY
	
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	tmpstr = strtok(NULL,"'\"");		// get key between '"' or '''
	printf("val: %s\n",tmpstr);	 		// THIRD VAL
	*/
	
	return 0;
}

