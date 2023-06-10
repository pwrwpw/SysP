#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void catFile(FILE* file, int n, int e, int t, int b);

int main(int argc, char* argv[]) {
    FILE* file;

    // 옵션 플래그 변수 초기화
    int n = 0; // -n 옵션
    int e = 0; // -E 옵션
    int t = 0; // -T 옵션
    int b = 0; // -b 옵션

    // 옵션 처리
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            n = 1;
        } else if (strcmp(argv[i], "-E") == 0) {
            e = 1;
        } else if (strcmp(argv[i], "-T") == 0) {
            t = 1;
        } else if (strcmp(argv[i], "-b") == 0) {
            b = 1;
        } else {
            // 파일 열기 시도
            file = fopen(argv[i], "r");
            if (file == NULL) {
                perror("파일 열기 실패");
                return 1;
            }

            // 파일 내용 출력
            catFile(file, n, e, t, b);

            // 파일 닫기
            fclose(file);
        }
    }

    return 0;
}

// 파일 내용을 읽고 출력하는 함수
void catFile(FILE* file, int n, int e, int t, int b) {
    int c;
    int lineNumber = 1;
    int printLineNumber = n || b; // 줄 번호를 출력해야 할지 여부를 결정하기 위한 변수
    int emptyLine = 1;            // 빈 줄 여부를 체크하기 위한 변수

    c = fgetc(file);
    while (c != EOF) {
        if (c == '\n') {
            if (printLineNumber) {
                if (b && emptyLine) {
                    printf("%6d  ", lineNumber);
                    lineNumber++;
                } else if (n) {
                    printf("%6d  ", lineNumber);
                    lineNumber++;
                }
            }
            printLineNumber = n || b;
            emptyLine = 1;
        } else if (c != ' ' && c != '\t') {
            emptyLine = 0;
        }

        if (t && c == '\t') {
            putchar('^');
            putchar('I');
            printLineNumber = 0;
        } else if (e && c == '\n') {
            putchar('$');
            putchar('\n');
            printLineNumber = 0;
        } else {
            putchar(c);
            printLineNumber = 0;
        }

        c = fgetc(file);
    }
}
