#include <stdlib.h>
#include <stdio.h>

#define byte unsigned char




int main() 
{
    byte original[] = {1, 2, 0xA, 0xF, 5, 0xC};
    //print the original array
    printf("Original Array: ");
    for(int i = 0; i < 6; ++i)
    {
        printf("%02X " , original[i]);
    }
    printf("\n");
   
    //declare a compressed array with the size half of the uncompressed
    byte compressed[3];
    for(int i = 0; i<3; ++i)
    {
        //get always two bytes from the original array
        int idx = 2*i;
        byte a1 = original[idx];
        byte a2 = original[idx+1];
        //now shift the first byte 4 binary digits to the left
        a1<<= 4; // or a1*=16
        //add then add the bitwise OR of both bytes to our compressed array
        compressed[i] = a1 | a2;
    }
    
    //print compressed 
    printf("Compressed Array: ");
    for(int i = 0; i < 3; ++i)
    {
        printf("%02X  " , compressed[i]);
    }
    printf("\n");
    
    //now uncompress the compressed again
    byte uncompressed[6];
    for(int i = 0; i< 3; ++i)
    {
        int idx = 2*i;
        //get the first bits 
        uncompressed[idx] = compressed[i]>>4;
        //get the last bits
        uncompressed[idx+1] = compressed[i] & 0x0F;
    }
    
    //print uncompressed
    printf("Uncompressed Array: ");
    for(int i = 0; i < 6; ++i)
    {
        printf("%02X " , uncompressed[i]);
    }
    printf("\n");
	return 0;
}


