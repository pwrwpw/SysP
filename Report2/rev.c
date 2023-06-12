#include <stdio.h>
#include <string.h>
#include <unistd.h>

void rev(char *s) {
    int start = 0;
    int end = strlen(s) - 1;
    while (start < end) { // 문자열 뒤집기
        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++;         // 다음 문자로 이동
        end--;
    }
}

int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    char *str = argv[1];
    rev(str);
    printf("%s\n", str);
    return 0;
}