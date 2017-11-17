.SUFFIXES:.c .o
CC=gcc
SRCS_TEST_SORT=Common.c \
	XSort.c\
	Test_Sort.c
OBJS_TEST_SORT=$(SRCS_TEST_SORT:.c=.o)
EXERC_TEST_SORT=TestSort

SRCS_TEST_LIST=Common.c \
	alist.c\
	llist.c\
	sllist.c\
	linkedlist.c\
	Test_List.c
OBJS_TEST_LIST=$(SRCS_TEST_LIST:.c=.o)
EXERC_TEST_LIST=TestList

start:$(OBJS_TEST_SORT) $(OBJS_TEST_LIST)
	$(CC) -o $(EXERC_TEST_SORT) $(OBJS_TEST_SORT)
	$(CC) -o $(EXERC_TEST_LIST) $(OBJS_TEST_LIST)
	@echo ---------------SUCCESS----------------
.c.o:
	$(CC) -g -o $@ -c $<
clean: 
	rm -rf $(OBJS_TEST_SORT) $(EXERC_TEST_SORT)
	rm -rf $(OBJS_TEST_LIST) $(EXEC_TEST_LIST)


#TestXqGraph: XqList.h XqList.c XqGraph.c XqGraph.c Test_XqGraph.c
#	gcc -o TestXqGraph XqList.c XqGraph.c Test_XqGraph.c

#TestXqHashTable: XqList.h XqList.c XqHashTable.h XqHashTable.c
#	gcc -o TestXqHashTable XqList.c XqHashTable.c Test_XqHashTable.c

#TestXqTree: XqTree.h XqTree.c  Test_XqTree.c
#	gcc -o TestXqTree  XqTree.c Test_XqTree.c
