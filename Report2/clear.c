#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    write(1,"\e[1;1H\e[2J",12);
    return 0;
}
