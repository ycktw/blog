#include "libs/listnode.h"

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->next = head;
	struct ListNode* current = dummy;

	while (current->next != NULL) {
		if (current->next->val == val) {
			struct ListNode* temp = current->next;
			current->next = current->next->next;
			free(temp);
		} else {
			current = current->next;
		}
	}

	struct ListNode* newHead = dummy->next;
	free(dummy);
	return newHead;
}

int main() {
    // 測試 Case: [1, 2, 3, 4]
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct ListNode* head = arrayToList(arr, n);

    printf("原始鏈表: ");
    printList(head);

    struct ListNode* removed = removeElements(head, 3);

    printf("removeElemtns: ");
    printList(removed);

    freeList(removed);

    return 0;
}