# 指定編譯器
CC = gcc
# 編譯參數：-Wall 顯示所有警告, -O2 優化
CFLAGS = -Wall -O2
LISTNODE_OBJ = libs/listnode.o
LRUCACHE_OBJ = libs/LRUCache.o

# 取得目錄下所有的 .c 檔案清單
SRCS = $(wildcard *.c)
# 將 .c 檔名替換成 .exe 檔名
PROGS = swapInPairs LRUCache removeElements checkCircle reverseLinkedList
#$(patsubst %.c, %.exe, $(SRCS))

# 預設目標：編譯所有程式
all: $(PROGS)

# 模式規則：如何從 %.c 產生 %.exe
#%.exe: %.c
#	$(CC) $(CFLAGS) $< -o $@


$(LISTNODE_OBJ): libs/listnode.c libs/listnode.h
	$(CC) $(CFLAGS) -c libs/listnode.c -o $(LISTNODE_OBJ)

$(LRUCACHE_OBJ): libs/LRUCache.c libs/LRUCache.h
	$(CC) $(CFLAGS) -c libs/LRUCache.c -o $(LRUCACHE_OBJ)

swapInPairs: swapInPairs.c $(LISTNODE_OBJ)
	$(CC) $(CFLAGS) $^ -o $@
checkCircle: checkCircle.c $(LISTNODE_OBJ)
	$(CC) $(CFLAGS) $^ -o $@
reverseLinkedList: reverseLinkedList.c $(LISTNODE_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

removeElements: removeElements.c $(LISTNODE_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

LRUCache: LRUCache.c $(LRUCACHE_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# 清理編譯產出的 .exe 檔案
clean:
	rm $(PROGS)

# vim set fdm=marker ts=4 ai et tw=0 noexpandtab