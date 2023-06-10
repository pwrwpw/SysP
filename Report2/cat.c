#include <stdio.h>
#include <unistd.h>

#define SIZE 1024

int cat(char *filename, int n, int b, int E, int T);

int main(int argc, char *argv[])
{
    int n = 0, b = 0, e = 0, t = 0;
    int opt;

    // 옵션 처리를 위한 반복문
    while ((opt = getopt(argc, argv, "nbET")) != -1)
    {
        switch (opt)
        {
        case 'n':
            n = 1; // -n 옵션 설정
            break;
        case 'b':
            b = 1; // -b 옵션 설정
            break;
        case 'E':
            e = 1; // -E 옵션 설정
            break;
        case 'T':
            t = 1; // -T 옵션 설정
            break;
        default:
            printf("%s: 잘못된 옵션 -- '%c'\n", argv[0], optopt);
            return 1;
        }
    }

    // 파일명이 입력되지 않은 경우 오류 메시지 출력
    if (optind == argc)
    {
        printf("파일명을 입력해주세요.\n");
        return 1;
    }

    char *filename = argv[optind];
    return cat(filename, n, b, e, t);
}

// cat 함수: 파일을 읽어서 출력하는 함수
int cat(char *filename, int n, int b, int E, int T)
{
    FILE *fp = fopen(filename, "r");

    // 파일 열기 실패 시 오류 메시지 출력
    if (fp == NULL)
    {
        printf("존재하지 않은 파일입니다.\n");
        return 1;
    }

    char buff[SIZE]; // 파일의 내용을 저장할 버퍼
    int line = 0;    // 줄 번호

    // 파일의 각 줄을 읽어서 처리
    while (fgets(buff, SIZE, fp) != NULL)
    {
        if (b && buff[0] != '\n')
            printf("%6d  ", ++line); // -b 옵션이 설정되고 빈 줄이 아닌 경우에 줄 번호 출력
        else if (!b && n)
            printf("%6d  ", ++line); // -n 옵션이 설정되었을 때 줄 번호 출력

        if (b && E && buff[0] == '\n')
            printf("%6s  ", ""); // -b 옵션이 설정되고 -E 옵션이 설정되고 빈 줄인 경우에 빈 줄 표시

        int i = 0;
        while (buff[i] != '\0')
        {
            if (E && buff[i] == '\n')
                printf("$\n"); // -E 옵션이 설정되어 있을 때 줄의 끝에 $ 표시
            else if (T && buff[i] == '\t')
                printf("^I"); // -T 옵션이 설정되어 있을 때 탭 문자를 ^I로 표시
            else
                printf("%c", buff[i]); // 그 외의 경우에는 문자 그대로 출력

            i++; // 다음 문자로 이동
        }
    }

    fclose(fp);
    return 0;
}
