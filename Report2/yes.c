#include <stdio.h>

int main(int argc,char* argv[])
{
    if(argc == 1)
    {
        while(1)
        {
            printf("y\n");
        }
    }
    else if(argc > 1)
    {
        while(1)
        {
            printf("%s\n",argv[1]);
        }
    }

}