#include <stdio.h>

int main(){

	char input;
	while(input != 48)
	{	
		input = getchar();	
		
		if(input >= 97 && input <= 122)
		{
			input -= 32;
			printf("%c\n",input);
		}
		else if(input >= 65 && input <= 90)
		{
			input += 32;
			printf("%c\n",input);
		}
	}
	return 0;
}
