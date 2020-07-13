#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

uint32_t gilgil(uint32_t n){
	return (n&0xFF000000)>>24|(n &0x00FF0000)>>8|(n&0x0000FF00)<<8|(n & 0x000000FF)<<24;
}

int main(int argc, char *argv[]){
	FILE *fd, *fd2;
	uint32_t buf, buf2, sum;

	if(argc < 2){
		printf("argument error %s <file1><file2>\n",argv[0]);
		return 0;
	}

	fd = fopen(argv[1],"r");

	if(fd == NULL){
		printf("file open error");
		return 0;
	}

	fd2 = fopen(argv[2], "r");

	if(fd2 == NULL){
		printf("file open error");
		return 0;
	}

	fread(&buf, 1, 256, fd);
	fread(&buf2, 1, 256, fd2);

	buf = gilgil(buf);
	buf2 = gilgil(buf2);
	sum = buf+buf2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",buf,buf,buf2,buf2,sum,sum);
	
	return 0;
}
