# Book Concordance Program
The Book Concordance Program is a command-line tool that allows users to manage book records using a Binary Search Tree (BST). Users can perform various operations such as adding book records, displaying all records, and searching records by author. The program provides an intuitive interface for easy interaction.

# Table of Contents
* Introduction
* Features
* Compilation
* Usage
* File Format
* Contributors
* License

# Introduction
The Book Concordance Program is developed using the C programming language. It utilizes a Binary Search Tree (BST) to efficiently store and manage book records. The program provides a simple and intuitive command-line interface for interacting with the book records.

When you run the program, you will be presented with a menu that allows you to choose different options. You can add book records by providing details such as the book's name, ISBN, author, and publication date. The program will store the records in a BST for easy retrieval and searching.

You can also display all the book records in the BST, which will be presented in alphabetical order by the author's name. Additionally, you can search for book records based on the author's name and display the matching records.

The program provides a convenient way to manage book records, making it useful for libraries, bookstores, or personal book collections.

# Features
* Add a Book Record: Users can add a new book record to the Binary Search Tree (BST). The program prompts the user to enter the book's name, ISBN, author, and publication date.

* Display All Book Records: The program allows users to view all the book records stored in the BST. It presents the records in an organized table format, including the book's name, ISBN, author, and publication date.

* Search Book Records by Author: Users can search for book records based on the author's name. The program prompts the user to enter an author's name and then displays all the book records that match the provided author name. The search is case-insensitive, meaning it matches regardless of uppercase or lowercase characters.

* Save Book Records to a File: The program provides a function to save the book records to a text file named book_records.txt. This allows users to persist their book collection beyond the program's execution. The file follows a specific format, with each book record separated by a line of dashes.

* Load Book Records from a File: At startup, the program automatically loads book records from the book_records.txt file into the BST. This feature ensures that previous book records are preserved and can be accessed and manipulated during the program's runtime.

* Intuitive User Interface: The program offers an intuitive command-line interface, presenting a menu with numbered options. Users can simply enter the corresponding number to select an operation, making it easy to interact with the program.

* Error Handling: The program includes error handling to deal with potential issues. For example, it checks if the file could be opened for reading or writing and displays appropriate error messages. It also validates user input, ensuring that numeric choices are entered for menu options.

# Compilation
To compile the program, follow the steps below:

1. Make sure you have a C compiler installed on your system. The program is written in C and requires a C or C++ compiler to build and run.

2. Copy and paste the provided program code into the file.

3. Save the file with a .c / .cpp extension, for example, book_concordance.c.

4. Click Compile & Run.

# Usage
To run the Book Concordance Program, follow these steps:

1. Open a command prompt or terminal and navigate to the directory where you compiled the program.

2. Run the program.
3. The program will display a menu with options numbered from 1 to 4. Follow the on-screen instructions to perform the desired operation.

4. To add a book record, select option 1 and provide the necessary details prompted by the program.

5. To display all book records, select option 2. The program will show a table with the book records sorted by the author's name.

6. To search for book records by author, select option 3 and enter the author's name. The program will display the matching records.

7. To exit the program, select option 4.

# File Format
The Book Concordance Program uses a text file named book_records.txt to store the book records. The file format is as follows:
![image](https://github.com/syaadi/Book-Concordance-Program/assets/136919621/ba3b3c2a-09dc-4f54-a999-0a890d8ff4ff)

Each book record is stored as a block in the text file. The block starts with the "Name:" line, followed by the book's name. The "ISBN:" line contains the book's ISBN number, the "Author:" line contains the author's name, and the "Publication Date:" line contains the publication date. The block ends with a line of dashes ("--------------------------------") as a separator.

When you add new book records using the program, they will be appended to the existing records in the text file. The program reads the file during startup to load the previously stored records. You can manually edit the book_records.txt file to add or modify book records. However, ensure the file format remains consistent to avoid any issues with loading or saving records.

# Contributors
The Book Concordance Program is developed by Group 6, Section 4, BIT10703, UTHM. The program was created as a collaborative effort by the following individuals:

* ALIYA NAZEERA CHE JUSOH
* SYAHIRAH ADIBAH BINTI ESA
* NURIN NAJWA BINTI MUHAMMAD AZHAR
* WAN AHMAD WAAFI YASIN BIN OMAR
* MOHD NIZWAN BIN MOHD ASRI

For any inquiries or issues related to the program, please contact the contributors.

# License

