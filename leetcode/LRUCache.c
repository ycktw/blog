#include "libs/LRUCache.h"

// --- 使用範例 ---
int main() {
    printf("--- LRU Cache 測試開始 ---\n");
    LRUCache* cache = lRUCacheCreate(2); // 容量設為 2

    printf("Put (1, 10)\n");
    lRUCachePut(cache, 1, 10);

    printf("Put (2, 20)\n");
    lRUCachePut(cache, 2, 20);

    printf("Get (1): %d\n", lRUCacheGet(cache, 1)); // 回傳 10，此時 1 變最新，2 變最舊

    printf("Put (3, 30) -> 觸發驅逐 (2 會被踢掉)\n");
    lRUCachePut(cache, 3, 30);

    printf("Get (2): %d (預期 -1)\n", lRUCacheGet(cache, 2));
    printf("Get (3): %d\n", lRUCacheGet(cache, 3));

    lRUCacheFree(cache);
    printf("--- 測試結束 ---\n");
    return 0;
}