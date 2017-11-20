#include "XSort.h"

#include "Common.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>

static bool showDetail = false;
static bool useRandom = false;
static int size = 10;
static enum{
	BubbleSortFakeK, BubbleSortPrimaryK, BubbleSortK, SelectSortK, InsertSortK, ShellSortK
} sortingAlgorithms = BubbleSortFakeK;


static void usage(char * argv[]){
	printf("Usage %s [options] <lgorithm>\n"
			"test sorting algorithms, and each algorithms efficiency.\n"
			"\n"
			"Options:\n"
			"--help\n"
			"    Show this message.\n"
			"--random\n"
			"    use random data.\n"
			"--size SIZE\n"
			"    test data size.\n"
			"--detail\n"
			"    display sorting detail process\n"
			"\n"
			"Algorithms:\n"
			"--BubbleSortFake: fake bubble sort,  only simple exchange sort\n"
			"--BubbleSortPrimary: primary bubble sort\n"
			"--BubbleSort: efficient bubble sort, shut down loop when list has been orderly\n"
			"--SelectSort: select sort\n"
			"--InsertSort: insert sort\n"
			"--ShellSort: Shell sort\n"
			"\n"
			"For example:\n"
			" %s --random --detail --size 100 --algorithm BubbleSort\n",
			argv[0], argv[0]
			);
}

int main(int argc, char *argv[])
{

	static const struct option longOptions[] = {
		{"help",         no_argument,        NULL,      'h'},
		{"algorithm",    required_argument,  NULL,      'a'},
		{"random",       no_argument,        NULL,      'r'},
		{"size",         required_argument,  NULL,      's'},
		{"detail",       no_argument,        NULL,      'd'},
		{NULL,           0,                  NULL,       0 }
	};

	printf("sort arithmetic test\n");
	if(argc <= 1){
		usage(argv);
		exit(-1);
	}

	while(true){
		int optionIndex = 0;
		int ic = getopt_long(argc, argv, "", longOptions, &optionIndex);
		if(ic == -1){
			break;
		}
		switch(ic){
			case 'h':
				usage(argv);
				return 0;
			case 'a':
				if(strcmp(optarg, "BubbleSortFake") == 0){
					sortingAlgorithms = BubbleSortFakeK;
				}else if(strcmp(optarg, "BubbleSortPrimary") == 0){
					sortingAlgorithms = BubbleSortPrimaryK;
				}else if(strcmp(optarg, "BubbleSort") == 0){
					sortingAlgorithms = BubbleSortK;
				}else if(strcmp(optarg, "SelectSort") == 0){
					sortingAlgorithms = SelectSortK;
				}else if(strcmp(optarg, "InsertSort") == 0){
					sortingAlgorithms = InsertSortK;
				}else if(strcmp(optarg, "ShellSort") == 0){
					sortingAlgorithms = ShellSortK;
				}else{
					printf("unsupported sorting algorithm: %s !!!\n", optarg);
					return 2;
				}
				break;
			case 'r':
				useRandom = true;
				break;
			case 'd':
				showDetail = true;
				break;
			case 's':
				size = atoi(optarg);
				break;
			default:
				if(ic != '?'){
					printf("getopt_long returned unexpected value 0x%x\n", ic);
				}
				return 2;
		}
	}

	SqList list;
	list.length = size;
	
	if(!useRandom){
		printf("donnot use random data, please init array:\n");
		int i, data;
		for(i = 0; i < size; i++){
			scanf("%d",&data);
			list.r[i] = data;
		}
	}else{
		random_initialize(list.r, size);
	}
	printf("to sort data has inited:\n");
	printfArray(list.r, 0, size);
	printf("\n");
	printf("sortingAlgorithms:%d\n", sortingAlgorithms);
	switch(sortingAlgorithms){
		case BubbleSortFakeK:
			BubbleSortFake(&list, showDetail);
			break;
		case BubbleSortPrimaryK:
			BubbleSortPrimary(&list, showDetail);
			break;
		case BubbleSortK:
			BubbleSort(&list, showDetail);
			break;
		case SelectSortK:

			break;
		 case InsertSortK:

		 	break;
		 case ShellSortK:

		 	break;
	}
	printf("\nsorted data is:\n");
	printfArray(list.r, 0, size);
	return 0;
}

