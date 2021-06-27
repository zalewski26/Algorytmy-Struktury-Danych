#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
#include "ex.h"

int comparisons = 0;
int moves = 0;

int main(int argc, char** argv){
	if (argc == 1 || !(strcmp(argv[1], "--help"))){
		printf("Example:\n./main --type $type --comp $comparison\n./main --stat $filename $numOfLoops --comp $comparison\n");
		return 1;
	}
	int type = -1;
	int comp = -1;
	int stat = 0;
	int k;
	char* filename;

	for (int i = 1; i < argc; i++){
		if (!strcmp(argv[i], "--type")){
			if (i + 1 == argc){
				printf("Missing parameters!\n");
				return 1; 
			}
			if (!strcmp(argv[i + 1], "insert")){
				type = INSERT;
			}
			else if (!strcmp(argv[i + 1], "merge")){
				type = MERGE;
			}
			else if (!strcmp(argv[i + 1], "quick")){
				type = QUICK;
			}
			else if (!strcmp(argv[i + 1], "dual")){
				type = DUAL;
			}
			else if (!strcmp(argv[i + 1], "hybrid")){
				type = HYBRID;
			}
			else{
				printf("Invalid type: %s\n", argv[i + 1]);
				return 1;
			}
			i++;
		}
		else if (!strcmp(argv[i], "--comp")){
			if (i + 1 == argc){
				printf("Missing parameters!\n");
				return 1; 
			}
			if (!strcmp(argv[i + 1], "<=")){
				comp = INCREASE;
			}
			else if (!strcmp(argv[i + 1], ">=")){
				comp = DECREASE;
			}
			else if (!strcmp(argv[i + 1], "A")){
				comp = ALPHABETICAL;
			}
			else if (!strcmp(argv[i + 1], "Z")){
				comp = REVERSE_ALPHABETICAL;
			}
			else{
				printf("Invalid comparison: %s\n", argv[i + 1]);
				return 1;
			}
			i++;
		}
		else if (!strcmp(argv[i], "--stat")){
			if (i + 1 == argc || i + 2 == argc){
				printf("Missing parameters!\n");
				return 1; 
			}
			filename = argv[i + 1];
			stat = 1;
			k = atoi(argv[i + 2]);
			i += 2;
		}
		else {
			printf("Invalid argument: %s\n", argv[i]);
				return 1;
		}
	}

	if (stat){
		secondEx(filename, k, comp);
	}
	else{
		firstEx(type, comp);
	}	
	return 0;
}
