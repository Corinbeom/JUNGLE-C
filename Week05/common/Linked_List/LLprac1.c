//
// Created by 박은범 on 25. 4. 13.
//
#include <stdio.h>
#include <stdlib.h>

// 연결 리스트 구조체
typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;
// 노드 구조체
typedef struct _linkedlist{
	int size;
	ListNode *head;
} LinkedList;

// 기본 함수 선언
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);

// 연결 리스트 기본 함수 확인용 프로그램
// 함수 구현 후 C파일을 실행해 제대로 동작하는지 테스트해볼 수 있습니다.
int main() {
    LinkedList ll;
    int c = 1;
    int index, value;
    ListNode *node;

    // 초기화
    ll.head = NULL;
    ll.size = 0;

    printf("===== 연결 리스트 테스트 메뉴 =====\n");
    printf("1: insertNode(index, value)\n");
    printf("2: removeNode(index)\n");
    printf("3: findNode(index)\n");
    printf("4: printList()\n");
    printf("5: removeAllItems()\n");
    printf("0: 종료\n");

    while (c != 0) {
        printf("\n메뉴 선택 (0~5): ");
        scanf("%d", &c);

        switch (c) {
        case 1:
            printf("삽입할 인덱스를 입력하세요: ");
            scanf("%d", &index);
            printf("삽입할 값을 입력하세요: ");
            scanf("%d", &value);
            if (insertNode(&ll, index, value) == 0)
                printf("삽입 성공!\n");
            else
                printf("삽입 실패 (인덱스 오류)!\n");
            break;

        case 2:
            printf("삭제할 인덱스를 입력하세요: ");
            scanf("%d", &index);
            if (removeNode(&ll, index) == 0)
                printf("삭제 성공!\n");
            else
                printf("삭제 실패 (인덱스 오류)!\n");
            break;

        case 3:
            printf("찾을 인덱스를 입력하세요: ");
            scanf("%d", &index);
            node = findNode(&ll, index);
            if (node != NULL)
                printf("해당 노드의 값: %d\n", node->item);
            else
                printf("노드를 찾을 수 없습니다 (인덱스 오류)!\n");
            break;

        case 4:
            printf("현재 연결 리스트: ");
            printList(&ll);
            break;

        case 5:
            removeAllItems(&ll);
            printf("모든 노드 삭제 완료!\n");
            break;

        case 0:
            removeAllItems(&ll);
            printf("프로그램 종료.\n");
            break;

        default:
            printf("알 수 없는 선택입니다.\n");
            break;
        }
    }

    return 0;
}

// index에 해당하는 노드의 주소를 반환하는 함수
ListNode *findNode(LinkedList *ll, int index)
{
    if (ll == NULL || ll->head == NULL || index < 0 || index > ll->size) {
        return NULL;
    }

    ListNode *curr = ll->head;
    int i = 0;

    while (i < index) {
        curr = curr->next;
        i++;
    }
    return curr;
}

// index 위치에 새로운 노드를 삽입하는 함수
// 성공 시 0, 실패 시 -1 반환
int insertNode(LinkedList *ll, int index, int value)
{
    if (ll == NULL || index < 0 || index > ll->size) {
        return -1;
    }

    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (!newNode) return -1;

    newNode->item = value;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = ll->head;
        ll->head = newNode;
    } else {
        ListNode *prev = ll->head;
        for (int i = 0; i < index -1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    ll->size++;
    free(newNode);
    return 0;
}

// index 위치의 노드를 삭제하는 함수
// 성공 시 0, 실패 시 -1 반환
int removeNode(LinkedList *ll, int index)
{
    if (ll == NULL || ll->head == NULL || index < 0 || index > ll->size) {
        return -1;
    }

    ListNode *toDelete;
    ListNode *prev = NULL;

    if (index == 0) {
        toDelete = ll->head;
        ll->head = ll->head->next;
    } else {
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        toDelete = prev->next;
        prev->next = toDelete->next;
    }

    free(toDelete);
    ll->size--;
    return 0;
}

// 연결 리스트의 모든 노드를 순서대로 출력하는 함수
void printList(LinkedList *ll)
{
    ListNode *curr = ll->head;

    if (ll->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (curr != NULL) {
        printf("%d ", curr->item);
        curr = curr->next;
    }
}

// 연결 리스트의 모든 노드를 제거하고 초기화하는 함수
void removeAllItems(LinkedList *ll)
{
    ListNode *curr = ll->head;
    ListNode *temp;

    while (curr != NULL) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }

    ll->head = NULL;
    ll->size = 0;
}