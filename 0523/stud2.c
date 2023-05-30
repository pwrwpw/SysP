#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

struct student {
    int id; 
    char name[20];  
    struct student *next;  
};

int main() 
{ 
    int count = 0, id;
    char name[20];
    struct student *p, *head = NULL, *tail = NULL;
    struct student *tmp;
 
    printf("학번과 이름을 입력하세요\n"); 	
    
    while (scanf("%d %s", &id, name) == 2) {
        p = (struct student *) malloc(sizeof(struct student));
        if (p == NULL) {
            perror("malloc");
            exit(1);
        }
        p->id = id;
        strcpy(p->name, name);
        p->next = NULL;
        
        if (head == NULL) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    printf("\n* 학생 정보 (정방향) *\n");
    tmp = head;
    while (tmp != NULL) {
        printf("학번: %d 이름: %s\n", tmp->id, tmp->name);
        tmp = tmp->next;
    }

    // 메모리 해제
    tmp = head;
    while (tmp != NULL) {
        struct student *next = tmp->next;
        free(tmp);
        tmp = next;
    }

    return 0;
}
