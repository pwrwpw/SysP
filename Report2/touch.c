#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("사용법: %s 파일명\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    struct stat st;

    if (stat(filename, &st) != 0) {
         FILE* file = fopen(filename, "w");
         fclose(file);
         return 1;
    }

    struct utimbuf new_times; //파일의 액세스 시간과 수정 시간을 나타내는 멤버 변수를 포함하는 구조체
    new_times.actime = st.st_atime;  // 액세스 시간은 기존 파일의 액세스 시간으로 설정
    new_times.modtime = time(NULL);  // 수정 시간은 현재 시간으로 설정

    if (utime(filename, &new_times) != 0) {
        printf("파일의 수정 시간을 갱신할 수 없습니다.\n");
        return 1;
    }

    printf("%s 파일의 수정 시간을 갱신했습니다.\n", filename);
    return 0;
}
