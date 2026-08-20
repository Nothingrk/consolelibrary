#define BOOKFILE "books.txt" // books data file

#include <stdio.h>   // input-output, basic work with files
#include <stdlib.h>  // for dynamic memory
#include <string.h>  // for strcspn

#include "IOF.h"     // Input Output Files

char version[5] = "1.5"; // version

void addbook() { // adding book to BOOKFILE
    char author[100];
    char book[200];
    char year[50];

    printf("Author: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = 0; // remove newline

    printf("Book: ");
    fgets(book, sizeof(book), stdin);
    book[strcspn(book, "\n")] = 0;

    printf("Year: ");
    fgets(year, sizeof(year), stdin);
    year[strcspn(year, "\n")] = 0;

    adddata(BOOKFILE, author, book, year);
    printf("Data saved\n");
}

void showall() {
	printf("Books:\n");
	read(BOOKFILE);
    printf("End of file.\n");
}

void CleanOrCreateBf() {
	int c;

	printf("Do you really want to clear bookfile?\n");
	printf("Input: ");
	c = getchar();
	
	switch(c) {
		case 'y':
		case 'Y':
			cleanORcreateBF(BOOKFILE);
			break;
		case 'n':
		case 'N':
			break;
		default:
			printf("Incorrect input.");
			CleanOrCreateBf();		
	}
	

}
void op_choise() {
    char input[16];    // buffer for user input
    int usinput;

    while (1) {
        printf("\n1.Add book.\n2.Show all books.\n3.Clean bookfile or create it.\n4.Bookfile.\n5.Exit.\n");
        printf("Input: ");

        // read whole line with fgets (safe)
        fgets(input, sizeof(input), stdin);

        // try to convert to integer
        if (sscanf(input, "%d", &usinput) == 1) {
            switch (usinput) {
                case 1:
                    addbook();
                    break;
                case 2:
                    showall();
                    break;
                case 3:
					CleanOrCreateBf(); 
                    break;
				case 4:
					printf(BOOKFILE"\n");
					break;
				case 5:
                    return;
                default:
                    printf("Unknown command\n");
                    break;
            }
        } else {
            printf("Incorrect input. Please enter a number.\n");
        }
    }
}

int main() {
    ISfileExists(BOOKFILE);

    printf("Console Library. Version %s\nPress Enter to continue\n", version);
    getchar(); // wait for Enter

    op_choise();

    return 0;
}
