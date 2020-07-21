#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint16_t my_ntohs(uint16_t n){
	return (n & 0xFF00) >> 8 | (n & 0x00FF) << 8;
}

int main(){
	uint16_t n = 0x1234;
	printf("%04x %04x\n", ntohs(n), my_ntohs(n));
}

