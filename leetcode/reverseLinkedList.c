#include "libs/listnode.h"

struct ListNode* reverseList(struct ListNode* head) {
    // 1. 終止條件：空鏈表或只有一個節點
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // 2. 遞迴反轉後面的部分，newHead 會一路從末端傳回來
    struct ListNode* newHead = reverseList(head->next);

    // 3. 核心動作：讓「下一個節點」的 next 指向「我自己」
    // 假設目前是 1 -> 2，head 是 1，head->next 是 2
    // 執行完這行後，2 的 next 就會指向 1 (變成 1 <-> 2)
    head->next->next = head;

    // 4. 切斷 1 原本指向 2 的箭頭，防止產生循環
    // 變成 NULL <- 1 <- 2
    head->next = NULL;

    // 5. 將反轉後的新頭部 (原本的尾巴) 一路回傳回去
    return newHead;
}

// --- 核心演算法 ---
struct ListNode* reverseLinkedList(struct ListNode* list) {
    struct ListNode *prev = NULL;
	struct ListNode *curr = list;
    struct ListNode *nextTemp = NULL;

	// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    while (curr != NULL) {
        // 1. 暫存下一個節點，否則箭頭反轉後會斷路
        nextTemp = curr->next;

        // 2. 核心動作：把當前節點的箭頭指向「前一個」
        curr->next = prev;

        // 3. 往後移動指標，準備處理下一個節點
        prev = curr;
        curr = nextTemp;
    }

    // 當 curr 為 NULL 時，prev 正好指向原本的最後一個節點（新的頭）
    return prev;
}

// --- 測試主程式 ---
int main() {
    // 測試 Case 1
    int arr[] = {1, 2, 3, 4, 5};

    struct ListNode* list = arrayToList(arr, 5);

    printf("Input List: ");
    printList(list);

    //struct ListNode* newList = reverseLinkedList(list);
    struct ListNode* newList = reverseList(list);

    printf("New List: ");
    printList(newList);

    // 注意：因為 merge 只是移動指標，所以我們只需要釋放合併後的這條鏈表即可
    freeList(newList);

    return 0;
}