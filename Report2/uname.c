#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int c;

    int option = 's'; // 기본적으로 -s 옵션을 선택합니다.

    while ((c = getopt(argc, argv, "asnrvm")) != -1) {
        switch (c) {
            case 'a':
            case 's':
            case 'n':
            case 'r':
            case 'v':
            case 'm':
                option = c; // 입력된 옵션을 선택합니다.
                break;
            default:
                printf("Invalid option: -%c\n", optopt);
                printf("Usage: uname [-a | -s | -n | -r | -v | -m]\n");
                return 1;
        }
    }

    struct utsname sys_info;
    if (uname(&sys_info) != 0) { // 시스템 정보를 가져옵니다.
        perror("uname"); // uname 함수 호출이 실패한 경우 오류 메시지를 출력합니다.
        return 1;
    }

    // 선택된 옵션에 따라 해당하는 시스템 정보를 출력합니다.
    switch (option) {
        case 'a': // 모든 시스템 정보를 출력합니다.
            printf("%s ", sys_info.sysname);
            printf("%s ", sys_info.nodename);
            printf("%s ", sys_info.release);
            printf("%s ", sys_info.version);
            printf("%s ", sys_info.machine);
            printf("\n");
            break;
        case 's': // 시스템 이름을 출력합니다.
            printf("%s\n", sys_info.sysname);
            break;
        case 'n': // 노드 이름을 출력합니다.
            printf("%s\n", sys_info.nodename);
            break;
        case 'r': // 릴리스 정보를 출력합니다.
            printf("%s\n", sys_info.release);
            break;
        case 'v': // 버전 정보를 출력합니다.
            printf("%s\n", sys_info.version);
            break;
        case 'm': // 머신(하드웨어) 정보를 출력합니다.
            printf("%s\n", sys_info.machine);
            break;
    }

    return 0;
}
