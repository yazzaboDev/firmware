#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include <stdlib.h>
#include <string.h>

	
char d[] = "Vg4DQnNoUUBWDgNCVg4DQgAAgL8AAODAAACAvwAAgL9TDgPCYzq3wVMOA8JTDgPC";

void compressStr(char* inputString) {

	int inlen = strlen(inputString);
	
	char compressedString[inlen];
	
	int i=0;
	int j=i+1;
	char *chars = inputString;
	
	while(i< inlen)	{

		int counter=1;
		compressedString[i] = compressedString[i] + chars[i];
		while(j<inlen && chars[j] == chars[i]) {
			i++;
			j++;
			counter++;
		}
		compressedString[i] = compressedString[i] + counter;
		i++;
		j++;
			
	}
	printf("%d: %s\n",strlen(compressedString),compressedString);
	return;
}

int main(){
	printf("%d: %s\n",strlen(d),d);
	compressStr(d);
	return 0;
}
