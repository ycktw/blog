#include "LRUCache.h"

// 輔助函式：建立節點
DLinkedNode* createNode(int key, int value) {
    DLinkedNode* node = (DLinkedNode*)malloc(sizeof(DLinkedNode));
    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// 核心操作：拔除節點
void removeNode(DLinkedNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// 核心操作：加到頭部 (Dummy Head 之後)
void addToHead(LRUCache* obj, DLinkedNode* node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

// 初始化 Cache
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->size = 0;
    obj->capacity = capacity;
    obj->head = createNode(0, 0);
    obj->tail = createNode(0, 0);
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    // 假設 key 範圍 0-1000
    obj->table = (DLinkedNode**)calloc(1001, sizeof(DLinkedNode*));
    return obj;
}

// 讀取資料
int lRUCacheGet(LRUCache* obj, int key) {
    if (key < 0 || key > 1000 || obj->table[key] == NULL) return -1;
    DLinkedNode* node = obj->table[key];
    removeNode(node); // 拔掉
    addToHead(obj, node); // 放回頭部 (代表最新使用)
    return node->value;
}

// 存入資料
void lRUCachePut(LRUCache* obj, int key, int value) {
    if (key < 0 || key > 1000) return;
    DLinkedNode* node = obj->table[key];
    if (node != NULL) {
        node->value = value;
        removeNode(node);
        addToHead(obj, node);
    } else {
        DLinkedNode* newNode = createNode(key, value);
        obj->table[key] = newNode;
        addToHead(obj, newNode);
        obj->size++;
        if (obj->size > obj->capacity) {
            DLinkedNode* last = obj->tail->prev;
            obj->table[last->key] = NULL;
            removeNode(last);
            free(last);
            obj->size--;
        }
    }
}

// 釋放記憶體
void lRUCacheFree(LRUCache* obj) {
    DLinkedNode* curr = obj->head;
    while (curr) {
        DLinkedNode* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj->table);
    free(obj);
}