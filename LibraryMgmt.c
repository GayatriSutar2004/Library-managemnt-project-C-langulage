#include <stdio.h>
#include <string.h>

struct Library {
    char title[50];
    char author[50];
    char publication[50];
    int price;
    int id;
    int is_issued; // 0 = available, 1 = issued
};

struct Library books[20], issuedBook;
int bookCount = 0;

void addBooks(int n);
void issueBook();
void showIssuedBook();
void displayBooks(int n);

int main() {
    int ch;

    do {
        printf("\n==================== LIBRARY MENU ====================\n");
        printf("1. Add Book\n");
        printf("2. Issue Book\n");
        printf("3. Show Issued Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("=======================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar(); // clear newline from buffer

        switch (ch) {
            case 1:
                printf("\nHow many books do you want to add? ");
                scanf("%d", &bookCount);
                getchar();
                addBooks(bookCount);
                break;

            case 2:
                issueBook();
                break;

            case 3:
                showIssuedBook();
                break;

            case 4:
                displayBooks(bookCount);
                break;

            case 5:
                printf("\nThank you for using this library software!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (ch != 5);

    return 0;
}

void addBooks(int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter Book ID: ");
        scanf("%d", &books[i].id);
        getchar();

        printf("Enter Book Title: ");
        scanf(" %[^\n]", books[i].title);

        printf("Enter Book Author: ");
        scanf(" %[^\n]", books[i].author);

        printf("Enter Book Publication: ");
        scanf(" %[^\n]", books[i].publication);

        printf("Enter Book Price: ");
        scanf("%d", &books[i].price);
        getchar();

        books[i].is_issued = 0;

        printf("---------------------------------------------------\n");
    }
}

void issueBook() {
    int id, found = 0;

    printf("\nEnter the Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (books[i].is_issued == 0) {
                books[i].is_issued = 1;
                issuedBook = books[i];
                printf("\nBook '%s' issued successfully!\n", books[i].title);
            } else {
                printf("\nThis book is already issued.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found!\n", id);
    }
}

void showIssuedBook() {
    if (issuedBook.id != 0) {
        printf("\n================ ISSUED BOOK DETAILS ================\n");
        printf("Book ID       : %d\n", issuedBook.id);
        printf("Title         : %s\n", issuedBook.title);
        printf("Author        : %s\n", issuedBook.author);
        printf("Publication   : %s\n", issuedBook.publication);
        printf("Price         : %d\n", issuedBook.price);
        printf("=====================================================\n");
    } else {
        printf("\nNo book has been issued yet.\n");
    }
}

void displayBooks(int n) {
    if (n == 0) {
        printf("\nNo books to display.\n");
        return;
    }

    printf("\n%-10s %-20s %-20s %-20s %-10s %-10s\n", "Book ID", "Title", "Author", "Publication", "Price", "Status");
    printf("===============================================================================================\n");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-20s %-20s %-10d %-10s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].publication,
               books[i].price,
               books[i].is_issued ? "Issued" : "Available");
    }
}
