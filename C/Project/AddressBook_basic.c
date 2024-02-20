#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 100    //최대100명

//학생 구조체
typedef struct {
    int id;          //학번으로 사용합니다.
    char name[100];  //이름
    int isUsed;     // 1이면 현재값 사용 중 0이면 비어있음으로 표시
} Student;        

Student database[MAX_DATA];

void insertData(int id, char* name) {
    for (int i = 0; i < MAX_DATA; i++) {
        if (!database[i].isUsed) {
            database[i].id = id;
            strcpy(database[i].name, name);
            database[i].isUsed = 1;
            printf("데이터 삽입됨: %d, %s\n", id, name);
            return;
        }
    }
    printf("데이터베이스가 가득 찼습니다.\n");
}

void deleteData(int id) {
    for (int i = 0; i < MAX_DATA; i++) {
        if (database[i].isUsed && database[i].id == id) {
            database[i].isUsed = 0;
            printf("데이터 삭제됨: %d, %s\n", id, database[i].name);
            return;
        }
    }
    printf("데이터를 찾을 수 없습니다.\n");
}

void updateData(int id, char* newName) {
    for (int i = 0; i < MAX_DATA; i++) {
        if (database[i].isUsed && database[i].id == id) {
            strcpy(database[i].name, newName);
            printf("데이터 수정됨: %d -> %s\n", id, newName);
            return;
        }
    }
    printf("데이터를 찾을 수 없습니다.\n");
}

void searchData(int id) {
    for (int i = 0; i < MAX_DATA; i++) {
        if (database[i].isUsed && database[i].id == id) {
            printf("데이터 찾음: %d, %s\n", id, database[i].name);
            return;
        }
    }
    printf("데이터를 찾을 수 없습니다.\n");
}

int main() {
    int choice, id;
    char name[100];

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 데이터 삽입\n");
        printf("2. 데이터 삭제\n");
        printf("3. 데이터 수정\n");
        printf("4. 데이터 검색\n");
        printf("5. 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        getchar(); // 버퍼에 남은 개행 문자 제거 즉, 엔터제거 효과가 있음 편법

        switch (choice) {
            case 1:
                printf("삽입할 학번을 입력하세요: ");
                scanf("%d", &id);
                getchar(); // 버퍼에 남은 개행 문자 제거
                printf("이름을 입력하세요: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // 개행 문자 제거
                insertData(id, name);
                break;
            case 2:
                printf("삭제할 학번을 입력하세요: ");
                scanf("%d", &id);
                deleteData(id);
                break;
            case 3:
                printf("수정할 학번을 입력하세요: ");
                scanf("%d", &id);
                getchar(); // 버퍼에 남은 개행 문자 제거
                printf("새 이름을 입력하세요: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // 개행 문자 제거
                updateData(id, name);
                break;
            case 4:
                printf("검색할 학번을 입력하세요: ");
                scanf("%d", &id);
                searchData(id);
                break;
            case 5:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 다시 시도해 주세요.\n");
        }
    }

    return 0;
}
