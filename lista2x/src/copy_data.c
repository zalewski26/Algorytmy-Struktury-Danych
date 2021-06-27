#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	char* filename = argv[1];
	FILE* ptr = fopen(filename, "r");
	FILE* insert = fopen("insert.txt", "w");
	FILE* merge = fopen("merge.txt", "w");
	FILE* quick = fopen("quick.txt", "w");
	FILE* dual = fopen("dual.txt", "w");
	FILE* hybrid = fopen("hybrid.txt", "w");
	
	char c = fgetc(ptr);
    while (c != EOF)
    {
		switch (c){
			case 'I':
				c = fgetc(ptr);
				c = fgetc(ptr);
				while (c != '\n'){
					fputc(c, insert);
					c = fgetc(ptr);
				}
				fputc('\n', insert);
				break;
			case 'M':
				c = fgetc(ptr);
				c = fgetc(ptr);
				while (c != '\n'){
					fputc(c, merge);
					c = fgetc(ptr);
				}
				fputc('\n', merge);
				break;
			case 'Q':
				c = fgetc(ptr);
				c = fgetc(ptr);
				while (c != '\n'){
					fputc(c, quick);
					c = fgetc(ptr);
				}
				fputc('\n', quick);
				break;	
			case 'D':
				c = fgetc(ptr);
				c = fgetc(ptr);
				while (c != '\n'){
					fputc(c, dual);
					c = fgetc(ptr);
				}
				fputc('\n', dual);
				break;	
			case 'H':
				c = fgetc(ptr);
				c = fgetc(ptr);
				while (c != '\n'){
					fputc(c, hybrid);
					c = fgetc(ptr);
				}
				fputc('\n', hybrid);
				break;		
		}
        c = fgetc(ptr);
    }
    printf("Contents copied\n");
}