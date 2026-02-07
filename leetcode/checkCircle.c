#include "libs/listnode.h"

bool hasCycle(struct ListNode *head) {
    // 1. 處理空鏈表或只有一個節點的情況
    if (head == NULL || head->next == NULL) {
        return false;
    }

    // 2. 初始化快慢指標
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // 3. 開始賽跑
    while (fast != NULL && fast->next != NULL) {
        // --- 請在這裡填入你的邏輯 ---

        // 龜走一步
		if (slow->next != NULL) {
			slow = slow->next; // 烏龜走一步
		} else {
			return false; // 烏龜已經走到終點了，沒有環
		}
		if (fast->next != NULL && fast->next->next != NULL) {
			fast = fast->next->next; // 兔子走兩步
		} else {
			return false; // 兔子已經走到終點了，沒有環
		}
        // 如果相遇，回傳什麼？
		if (slow == fast) {
			return true; // 兔子追上烏龜了，代表有環
		}
    }

    // 4. 如果跳出迴圈，代表兔子跑到終點了
    return false;
}

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

    //printf("改銜尾後: ");
	//head->next->next->next = head; // 讓最後一個節點指向頭部，形成環
	if (hasCycle(head)) {
		printf("鏈表中有環！\n");
	} else {
		printf("鏈表中沒有環！\n");
	}
	// 解除環，避免 freeList 時進入無限迴圈
	head->next->next->next = NULL;
    // 釋放記憶體
    freeList(head);

    return 0;
}