#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include <stdlib.h>
#include <string.h>

// 3n bytes [buffer] == 4n bytes [base64] 
// es: 3 bytes = 4 bytes

//  base64 encoding
//
//  buf:     binary input data
//  size:    size of input (bytes)
//  return:  base64-encoded string (null-terminated)
//           memory for output will be allocated here, free it later
//
char* base64_encode(const void* buf, size_t size)
{
	static const char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	char* str = (char*) malloc((size+3)*4/3 + 1);

	char* p = str;
	const unsigned char* q = (const unsigned char*) buf;
	size_t i = 0;

	while (i < size) {
		int c = q[i++];
		c *= 256;
		if (i < size)
            c += q[i];
		i++;

		c *= 256;
		if (i < size)
            c += q[i];
		i++;

		*p++ = base64[(c & 0x00fc0000) >> 18];
		*p++ = base64[(c & 0x0003f000) >> 12];

		if (i > size + 1)
			*p++ = '=';
		else
			*p++ = base64[(c & 0x00000fc0) >> 6];

		if (i > size)
			*p++ = '=';
		else
			*p++ = base64[c & 0x0000003f];
	}

	*p = 0;

	return str;
}


//  single base64 character conversion
//
static int POS(char c)
{
	if (c>='A' && c<='Z') return c - 'A';
	if (c>='a' && c<='z') return c - 'a' + 26;
	if (c>='0' && c<='9') return c - '0' + 52;
	if (c == '+') return 62;
	if (c == '/') return 63;
	if (c == '=') return -1;
    return -2;
}

//  base64 decoding
//
//  s:       base64 string, must be null-terminated
//  data:    output buffer for decoded data
//  data_len size of decoded data
//  return:  allocated data buffer
//
void* base64_decode(const char* s, size_t *data_len)
{
    const char *p;
    unsigned char *q, *data;
    int n[4];

	size_t len = strlen(s);
	if (len % 4)
		return NULL;
	data = (unsigned char*) malloc(len/4*3);
	q = (unsigned char*) data;

	for (p = s; *p; ) {
	    n[0] = POS(*p++);
	    n[1] = POS(*p++);
	    n[2] = POS(*p++);
	    n[3] = POS(*p++);

            if (n[0] == -2 || n[1] == -2 || n[2] == -2 || n[3] == -2)
                return NULL;

	    if (n[0] == -1 || n[1] == -1)
		return NULL;

	    if (n[2] == -1 && n[3] != -1)
		return NULL;

            q[0] = (n[0] << 2) + (n[1] >> 4);
	    if (n[2] != -1)
                q[1] = ((n[1] & 15) << 4) + (n[2] >> 2);
	    if (n[3] != -1)
                q[2] = ((n[2] & 3) << 6) + n[3];
	    q += 3;
	}

	*data_len = q-data - (n[2]==-1) - (n[3]==-1);

	return data;
}

typedef union {
	float buff[4];
	char buf[17];
} data_t;

int main(void) {
	// your code goes here
	
	data_t d;
	d.buff[0] = 25.50f;
	d.buff[1] = 2.043f;
	d.buff[2] = 255.450f;
	printf("d.buff[0]: %f\n", d.buff[0]);
	printf("d.buff[1]: %f\n", d.buff[1]);
	printf("d.buff[2]: %f\n", d.buff[2]);
	printf("before encode ---------------------------------- \n");
	printf("%x %x %x %x\n", d.buf[0],d.buf[1],d.buf[2],d.buf[3]);
	printf("%x %x %x %x\n", d.buf[4],d.buf[5],d.buf[6],d.buf[7]);
	printf("%x %x %x %x\n", d.buf[8],d.buf[9],d.buf[10],d.buf[11]);
	
	char* pchar = base64_encode(d.buf, 12);
	printf("base64: %s\nlen: %d\n", pchar, 12);
	
	size_t len2 = 0;
	char *pchar2 = base64_decode( pchar, &len2 );
	printf("after encode ---------------------------------- \n");
	printf("%x %x %x %x\n", pchar2[0],pchar2[1],pchar2[2],pchar2[3]);
	printf("%x %x %x %x\n", pchar2[4],pchar2[5],pchar2[6],pchar2[7]);
	printf("%x %x %x %x\n", pchar2[8],pchar2[9],pchar2[10],pchar2[11]);
	printf("pchar2[0]: %f\n", *((float*)&pchar2[0]));
	printf("pchar2[1]: %f\n", *((float*)&pchar2[4]));
	printf("pchar2[2]: %f\n", *((float*)&pchar2[8]));
	printf("len: %d\n", len2);
	
	free(pchar);
	free(pchar2);
	
	return 0;
}

