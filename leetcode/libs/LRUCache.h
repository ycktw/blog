#include <stdio.h>
#include <stdlib.h>

// 1. 定義雙向鏈表節點
typedef struct DLinkedNode {
    int key;
    int value;
    struct DLinkedNode *prev;
    struct DLinkedNode *next;
} DLinkedNode;

// 2. 定義 LRU Cache 結構
typedef struct {
    int size;
    int capacity;
    DLinkedNode *head; // 哨兵頭
    DLinkedNode *tail; // 哨兵尾
    DLinkedNode **table; // 簡易 Hash Map (用陣列實現，key 為索引)
} LRUCache;

// 輔助函式：建立節點
DLinkedNode* createNode(int key, int value);
void removeNode(DLinkedNode* node);
void addToHead(LRUCache* obj, DLinkedNode* node);
LRUCache* lRUCacheCreate(int capacity);
int lRUCacheGet(LRUCache* obj, int key);
void lRUCachePut(LRUCache* obj, int key, int value);
void lRUCacheFree(LRUCache* obj);
