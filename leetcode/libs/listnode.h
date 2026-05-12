#include <stdio.h>
#include <stdlib.h>

// 定義節點結構
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* arrayToList(int* arr, int size);
void printList(struct ListNode* head);
void freeList(struct ListNode* head);