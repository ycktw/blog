#include "libs/listnode.h"

// --- 核心演算法：遞迴法 ---
struct ListNode* swapPairs(struct ListNode* head) {
    // 1. 終止條件：如果剩下 0 個或 1 個節點，無法交換，直接回傳
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // 2. 準備交換
    struct ListNode* first = head;
    struct ListNode* second = head->next;

    // 3. 遞迴：處理後面剩下的部分，並將回傳的「新頭部」接在 first 的後面
    // 這裡體現了你提到的「護送國王」：swapPairs 會傳回下一對交換好的起點
    first->next = swapPairs(second->next);

    // 4. 反轉當前這一對：讓第二個節點指向第一個
    second->next = first;

    // 5. 回傳這組交換後的頭部（原本的第二個節點）
    return second;
}

// --- 測試主程式 ---
int main() {
    // 測試 Case: [1, 2, 3, 4]
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct ListNode* head = arrayToList(arr, n);

    printf("原始鏈表: ");
    printList(head);

    struct ListNode* swappedHead = swapPairs(head);

    printf("兩兩交換後: ");
    printList(swappedHead);

    // 釋放記憶體
    freeList(swappedHead);

    return 0;
}