#include<stdio.h>
#include<stdint.h>
#include"sum.h"


uint32_t my_htonl(uint32_t n) {
	uint32_t n1 = (n & 0xFF000000) >> 24;
	uint32_t n2 = (n & 0x00FF0000) >> 8;
	uint32_t n3 = (n & 0x0000FF00) << 8;
	uint32_t n4 = (n & 0x00000FF)<<24;
	return(n1 | n2 | n3 | n4);
}

uint32_t sum_fun(uint32_t first, uint32_t two)

{
	uint32_t sum_result;
	sum_result = first + two;
	return sum_result;
}

int main(int argc, char *argv[]) {
	FILE* fp, * fp2;

	fp = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");

	uint32_t buffer1=0;
	uint32_t buffer2=0;

	fread(&buffer1, sizeof(uint32_t), 1, fp);
	fread(&buffer2, sizeof(uint32_t), 1, fp2);

	buffer1 = my_htonl(buffer1);
	buffer2 = my_htonl(buffer2);

	uint32_t result = sum_fun(buffer1, buffer2);
	printf("%d(0x%x) + %d(0x%x) =  %d(0x%x)",buffer1,buffer1, buffer2, buffer2, result,result);

}
