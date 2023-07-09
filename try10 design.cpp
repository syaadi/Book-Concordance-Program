#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Book structure definition
typedef struct {
    char name[100];
    char ISBN[20];
    char author[100];
    char publicationDate[20];
} Book;

// Binary search tree node definition
typedef struct BSTNode {
    Book book;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Function to create a new binary search tree node
BSTNode* createNode(Book book) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->book = book;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a book record into the binary search tree
BSTNode* insert(BSTNode* root, Book book) {
    if (root == NULL) {
        return createNode(book);
    }

    int cmp = strcmp(book.author, root->book.author);
    if (cmp == 0) {
        // Duplicate key, insert on the right
        root->right = insert(root->right, book);
    } else if (cmp < 0) {
        // Key is smaller, insert on the left
        root->left = insert(root->left, book);
    } else {
        // Key is larger, insert on the right
        root->right = insert(root->right, book);
    }

    return root;
}

// Function to display the book records in the binary search tree in inorder traversal
void displayInorder(BSTNode* root) {
    if (root != NULL) {
        displayInorder(root->left);
        printf("| %-50s | %-17s | %-18s | %-16s |\n", root->book.name, root->book.ISBN, root->book.author, root->book.publicationDate);
        displayInorder(root->right);
    }
}

// Function to save the book records to a text file
void saveRecords(BSTNode* root, FILE* file) {
    if (root != NULL) {
        saveRecords(root->left, file);
        fprintf(file, "Name: %s\n", root->book.name);
        fprintf(file, "ISBN: %s\n", root->book.ISBN);
        fprintf(file, "Author: %s\n", root->book.author);
        fprintf(file, "Publication Date: %s\n", root->book.publicationDate);
        fprintf(file, "--------------------------------\n");
        saveRecords(root->right, file);
    }
}

// Function to save the book records to a text file
void saveToFile(BSTNode* root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    saveRecords(root, file);

    fclose(file);
}

// Function to validate user input as a number
int validateInput(const char* input) {
    size_t length = strlen(input);
    for (size_t i = 0; i < length; i++) {
        if (!isdigit(input[i])) {
            return 0; // Not a number
        }
    }
    return 1; // Valid number
}

// Function to search and display book records by author name
int displayByAuthor(BSTNode* root, const char* author) {
    int found = 0; // Flag to indicate if book records are found

    if (root != NULL) {
        found += displayByAuthor(root->left, author);

        // Convert the author name to lowercase for case-insensitive search
        char lowercaseAuthor[100];
        strcpy(lowercaseAuthor, root->book.author);
        for (int i = 0; lowercaseAuthor[i]; i++) {
            lowercaseAuthor[i] = tolower(lowercaseAuthor[i]);
        }

        // Convert the search keyword to lowercase for case-insensitive search
        char lowercaseKeyword[100];
        strcpy(lowercaseKeyword, author);
        for (int i = 0; lowercaseKeyword[i]; i++) {
            lowercaseKeyword[i] = tolower(lowercaseKeyword[i]);
        }

        // Search for book records by author name
        if (strstr(lowercaseAuthor, lowercaseKeyword) != NULL) {
            printf("| %-50s | %-17s | %-18s | %-16s |\n", root->book.name, root->book.ISBN, root->book.author, root->book.publicationDate);
            found++;
        }

        found += displayByAuthor(root->right, author);
    }

    return found;
}


// Function to load book records from a text file
BSTNode* loadFromFile(const char* filename) {
    BSTNode* root = NULL;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return NULL;
    }

    Book book;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, "Name: ") != NULL) {
            strcpy(book.name, line + 6);
            book.name[strcspn(book.name, "\n")] = '\0';
        } else if (strstr(line, "ISBN: ") != NULL) {
            strcpy(book.ISBN, line + 6);
            book.ISBN[strcspn(book.ISBN, "\n")] = '\0';
        } else if (strstr(line, "Author: ") != NULL) {
            strcpy(book.author, line + 8);
            book.author[strcspn(book.author, "\n")] = '\0';
        } else if (strstr(line, "Publication Date: ") != NULL) {
            strcpy(book.publicationDate, line + 18);
            book.publicationDate[strcspn(book.publicationDate, "\n")] = '\0';
            root = insert(root, book);
        }
    }

    fclose(file);
    return root;
}

void printHeading() {
    printf("*********************************************************************************\n");
    printf("*										*\n");
    printf("*			Book Concordance Program				*\n");
    printf("*										*\n");
    printf("* This program allows you to manage book records using a Binary Search Tree.	*\n");
    printf("* You can add book records, display all records, and search records by author.	*\n");
    printf("* The program provides an intuitive interface for easy interaction.             *\n");
    printf("*										*\n");
    printf("* Developed by: Group 6, Section 4						*\n");
    printf("* Date: 5 July 2023								*\n");
    printf("*										*\n");
    printf("*********************************************************************************\n\n");
}

int main() {
    BSTNode* root = NULL;
    int choice;
    Book book;
    char author[100];

    // Load book records from the text file
    root = loadFromFile("book_records.txt");

    do {
        printHeading();
        printf("1. Add a book record\n");
        printf("2. Display all book records\n");
        printf("3. Search book records by author\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        char input[100];
        scanf("%s", input);

        if (!validateInput(input)) {
            printf("Invalid choice. Please enter a number.\n\n");
            continue;
        }

        choice = atoi(input);

        switch (choice) {
            case 1:
                printf("Enter the name of the book: ");
                scanf(" %[^\n]s", book.name);
                printf("Enter the ISBN: ");
                scanf(" %s", book.ISBN);
                printf("Enter the author: ");
                scanf(" %[^\n]s", book.author);
                printf("Enter the publication date: ");
                scanf(" %s", book.publicationDate);
                root = insert(root, book);
                printf("Book record added successfully!\n");

                // Save the book records to a text file
                saveToFile(root, "book_records.txt");
                break;

            case 2:
                if (root == NULL) {
                    printf("No book records found.\n");
                } else {
                    printf("Book Records:\n");
                    printf("| %-50s | %-17s | %-18s | %-15s |\n", "Name", "ISBN", "Author", "Publication Date");
                    printf("|----------------------------------------------------|-------------------|--------------------|------------------|\n");
                    displayInorder(root);
                }
                break;

           case 3:
  	  if (root == NULL) {
        printf("No book records found.\n");
    } else {
        printf("Enter the author name: ");
        scanf(" %[^\n]s", author);

        // Convert the author name to lowercase for case-insensitive search
        for (int i = 0; author[i]; i++) {
            author[i] = tolower(author[i]);
        }

       printf("Book Records by Author:\n");
        printf("| %-50s | %-17s | %-18s | %-15s |\n", "Name", "ISBN", "Author", "Publication Date");
        printf("|----------------------------------------------------|-------------------|--------------------|------------------|\n");
        int numRecords = displayByAuthor(root, author);
        if (numRecords == 0) {
            printf("No book records for this name.\n");
        }
    }
    break;


            case 4:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}
