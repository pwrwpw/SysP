#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

struct student {
    int id; 
    char name[20];  
    struct student *next;  
};

/* 학생 정보를 입력받아 연결 리스트에 저장하고 학생 정보를 역순으로 
   출력한다.  
*/
int main() 
{ 

    int count = 0, id;
    char name[20];
    struct student *p, *head, *prev= NULL;
 
    printf("학번과  이름을 입력하세요\n"); 	
    
    while (scanf("%d %s", &id, name) == 2)  {
        p = (struct student *) malloc(sizeof(struct student));
        if (p == NULL) {
            perror("malloc");
            exit(1);
        }
        p->id = id;
        strcpy(p->name,name);
	p->next = head;
	head = p;
    }
    printf("\n* 학생 정보(정방향) *\n");
    p = head;
    while (p != NULL) {
        
        printf("학번: %d 이름: %s \n", p->id, p->name);
        
        p->next = prev;  // 현재 노드의 next 포인터를 이전 노드로 설정
        prev = p;  // prev를 현재 노드로 업데이트
        
        p = p->next;  // p를 다음 노드로 이동
    }

    head = prev;  // 마지막 노드를 head로 설정


    printf("총 %d 명입니다.\n", count); 
    exit(0);
}
