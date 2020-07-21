#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

//network byte order, uint32_t
uint32_t gilgil(uint32_t n){
	return (n&0xFF000000) >> 24| (n&0x00FF0000) >> 8
	| (n&0x0000FF00) << 8| (n&0x000000FF) << 24;
}

int main(int argc, char *argv[]){
	FILE *fd, *fd2; // file pointer defined
	uint32_t buf, buf2, sum; // uint32_t type variable defined

	if(argc < 2){ // !argc(argv[1], argv[2] -> error occured
		printf("argument error %s <file1><file2>\n",argv[0]);
		return 0;
	}

	fd = fopen(argv[1],"r"); // fopen function(argv[1], ex, thousand.bin

	if(fd == NULL){
		printf("file open error");
		return 0;
	}

	fd2 = fopen(argv[2], "r"); // fopen function(argv[2] ex, five-hundred.bin

	if(fd2 == NULL){
		printf("file open error");
		return 0;
	}

	fread(&buf, 1, sizeof(&buf), fd); // buf sizeof added
	fread(&buf2, 1, sizeof(&buf), fd2); // buf sizeof added

	buf = gilgil(buf); // uint32_t gilgil function call
	buf2 = gilgil(buf2); // uint32_t gilgil function call
	sum = buf+buf2;

	printf("%d(0x%02x) + %d(0x%02x) = %d(0x%02x)\n",buf,buf,buf2,buf2,sum,sum);
	
	return 0;
}
