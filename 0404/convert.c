#include <stdio.h>
void fuc(unsigned n){
	for(int i = 15; i >=  0; i--) {
		if(i == 11 || i == 8) printf("  :");
		int output = n >> i & 1;
		printf("%d", output);
	}
}
int main(){
	int input;
	while(1)
	{
		scanf("%x",&input);
		if(input >= 0x1000 && input <= 0xFFFF) break;	
		else printf("16비트의 입력이 아닙니다 다시 입력해주세요\n");
	}
	printf("4비트: 3비트: 9비트\n");
	fuc(input);

	return 0;

}

