#include <stdio.h>
#include <stdlib.h>

// 1. 定義節點結構
struct ListNode {
    int val;
    struct ListNode *next;
};

// --- 核心演算法 ---
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode *curr = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            curr->next = list1;
            list1 = list1->next;
			curr = curr->next;
        } else if (list1->val > list2->val) {
            curr->next = list2;
            list2 = list2->next;
			curr = curr->next;
        } else {
            // 關鍵點：當兩者數值相等時
            curr->next = list1;    // 只取 list1
            list1 = list1->next;
            curr = curr->next;

            // 跳過 list2 的這個重複節點，並釋放記憶體
            struct ListNode *temp = list2;
            list2 = list2->next;
            free(temp);
        }
    }
    // 將剩餘的部分串接上去
    curr->next = (list1 != NULL) ? list1 : list2;

    return dummy.next;
}

// --- 輔助函式：建立節點 ---
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// --- 輔助函式：將陣列轉換為鏈表 ---
struct ListNode* arrayToList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = createNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// --- 輔助函式：列印鏈表 ---
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// --- 輔助函式：釋放鏈表記憶體 ---
void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// --- 測試主程式 ---
int main() {
    // 測試 Case 1
    // list1 = [1, 2, 4], list2 = [1, 3, 4]
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    struct ListNode* l1 = arrayToList(arr1, 3);
    struct ListNode* l2 = arrayToList(arr2, 3);

    printf("Input List 1: ");
    printList(l1);
    printf("Input List 2: ");
    printList(l2);

    struct ListNode* mergedHead = mergeTwoLists(l1, l2);

    printf("Merged List:  ");
    printList(mergedHead);

    // 注意：因為 merge 只是移動指標，所以我們只需要釋放合併後的這條鏈表即可
    freeList(mergedHead);

    return 0;
}