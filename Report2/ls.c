#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

// 파일 타입을 리턴
char type(mode_t mode);

// 파일 허가권을 리턴
char* perm(mode_t mode);

// 파일 정보 출력
void print_file_info(const char*);

int main(int argc, char** argv) {
    DIR* dir;
    struct dirent* ent;
    struct stat st;

    if (argc == 1) {
        // 현재 디렉터리의 파일 및 디렉터리 이름 출력
        if ((dir = opendir(".")) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
                if (ent->d_name[0] != '.')
                    printf("%s\t", ent->d_name);
            }
            closedir(dir);
            printf("\n");
        } else {
            perror("디렉토리 열기 실패");
            return 1;
        }
    } else if (argc == 2 && strcmp("-l", argv[1]) == 0) {
        dir = opendir(".");
        if (dir == NULL) {
            perror("error");
            return -1;
        }
        // 현재 디렉터리의 파일 정보 출력
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] != '.')
                print_file_info(ent->d_name);
        }
        closedir(dir);
    } else if (argc == 2 && strcmp("-a", argv[1]) == 0) {
        dir = opendir(".");
        if (dir == NULL) {
            perror("error");
            return -1;
        }
        // 현재 디렉터리의 모든 파일 및 디렉터리 이름 출력
        while ((ent = readdir(dir)) != NULL) {
            printf("%s\t", ent->d_name);
        }
        closedir(dir);
        printf("\n");
    } else if (argc == 2 && strcmp("-al", argv[1]) == 0) {
        dir = opendir(".");
        if (dir == NULL) {
            perror("error");
            return -1;
        }
        // 현재 디렉터리의 모든 파일 정보 출력
        while ((ent = readdir(dir)) != NULL) {
            print_file_info(ent->d_name);
        }
        closedir(dir);
    } else {
        puts("잘못된 명령어입니다.");
        return -1;
    }

    return 0;
}

// 파일 타입을 리턴

2 / 2

아래의 type 함수는 파일 모드에 따라 해당하는 문자를 반환합니다:

c
Copy code
char type(mode_t mode) {
    if (S_ISREG(mode))
        return ('-'); // 일반 파일을 나타내는 문자 '-'
    if (S_ISDIR(mode))
        return ('d'); // 디렉터리를 나타내는 문자 'd'
    if (S_ISCHR(mode))
        return ('c'); // 문자 장치 파일을 나타내는 문자 'c'
    if (S_ISBLK(mode))
        return ('b'); // 블록 장치 파일을 나타내는 문자 'b'
    if (S_ISLNK(mode))
        return ('l'); // 심볼릭 링크를 나타내는 문자 'l'
    if (S_ISFIFO(mode))
        return ('p'); // FIFO(명명된 파이프)를 나타내는 문자 'p'
    if (S_ISSOCK(mode))
        return ('s'); // 소켓을 나타내는 문자 's'

    return ('-'); // 그 외의 파일 타입은 '-'로 표시
}

// 파일 허가권을 리턴
char* perm(mode_t mode) {
    int i;
    char* perms = (char*)malloc(10 * sizeof(char));
    strcpy(perms, "---------");

    for (i = 0; i < 3; i++) {
        if (mode & (S_IREAD >> i * 3))
            perms[i * 3] = 'r'; // 읽기 권한을 나타내는 'r'을 설정
        if (mode & (S_IWRITE >> i * 3))
            perms[i * 3 + 1] = 'w'; // 쓰기 권한을 나타내는 'w'를 설정
        if (mode & (S_IEXEC >> i * 3))
            perms[i * 3 + 2] = 'x'; // 실행 권한을 나타내는 'x'를 설정
    }
    return perms; // 허가권 문자열을 반환
}
\
// 파일 정보 출력
void print_file_info(const char* filename) {
    struct stat st;
    if (lstat(filename, &st) < 0) {
        perror("lstat error");
        return;
    }

    // 파일 타입과 허가권 출력
    printf("%c%s  ", type(st.st_mode), perm(st.st_mode)); //st_mode: 파일의 모드와 허가권 정보를 나타내는 값입니다.
    
    // 링크 개수 출력
    printf("%2d ", st.st_nlink); //st_nlink: 파일에 대한 링크 수

    // 소유자 출력
    struct passwd* pw = getpwuid(st.st_uid); //st_uid: 파일의 소유자 ID
    if (pw != NULL) {
        printf("%s ", pw->pw_name);
    } else {
        printf("%d ", st.st_uid);
    }

    // 그룹 출력
    struct group* gr = getgrgid(st.st_gid); //st_gid: 파일의 그룹 ID
    if (gr != NULL) {
        printf("%s ", gr->gr_name);
    } else {
        printf("%d ", st.st_gid);
    }

    // 파일 크기 출력
    printf("%5lld ", st.st_size); //st_size: 파일의 크기(바이트)

    // 수정 시간 출력
    struct tm* t = localtime(&st.st_mtime); //st_mtime: 파일의 최종 수정 시간
    printf("%2d %2d %2d:%2d ", t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min);

    // 파일 이름 출력
    printf("%s\n", filename);

}

