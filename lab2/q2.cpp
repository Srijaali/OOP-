/*
Name: Rija Ali
ID  : 23K-0057
Desc: library programs
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/* Create a menu in which the following can be done.
1. Expand the program to manage an array of multiple books.
2. Develop a function to find a book by its title or author.
3. Enable the user to interactively input newbooks and update existing bookdata.
*/

#define Max_books 100

//struct to define books
struct Books {
   
    int publication_year;
    char author_name[50];
    char book_title[1000];
    char genre[30]; 
};

// Function prototypes
void bookinfo(Books book[], int count);
int addnewbook(Books book[], int *count);
void books_by_author(Books book[], int count);
void book_by_title(Books book[], int count);
void totalbookcountlib(int count);

//function to display information of books
void bookinfo(struct Books book[], int count){
    int i;

    cout << "Book Information.";

    for(i=0;i<count;i++){
      cout << " Publication year: " << book[i].publication_year << endl;
       cout <<" Author Name " << book[i].author_name << endl;
        cout << " Book Title: " << book[i].book_title << endl;
        cout << " Genre: " << book[i].genre << endl;
        cout << endl;
    }
}

//function to add a new book
int addnewbook(struct Books book[], int *count){
    if(*count < Max_books){
        struct Books newbook;
        cout << "Enter book details: "<< endl;
        cout << "---------------------" << endl;
        cout << "Publication year: ";
        cin >> newbook.publication_year;
        cin.ignore();
        cout << "Book Title: ";
        cin.getline(newbook.book_title, 1000);
        cout << "Author name: ";
        cin.getline(newbook.author_name, 50);
        cout << "Genre: ";
        cin.getline(newbook.genre, 30);
       
       book[*count] = newbook;
        (*count)++; //increasing count after adding a new book

        cout << "Book added successfully!";
    }
    else{
        cout << "No space left to add a new book!" << endl;
    }
}

//function to display books by a particular author
void books_by_author(struct Books book[], int count){
    int i;
    char searchauthor[50];
    cout << "Enter the author name you want to search the book of: ";
    cin.ignore(); // Clearing input buffer before reading a new string
    cin.getline(searchauthor, 50);


    for(i=0;i<count;i++){
        if(strcmp(book[i].author_name,searchauthor)==0){
            cout <<" Book Title: " <<  book[i].book_title << endl;
        }
    }
}

// Function to display books by a particular title
void book_by_title(struct Books book[], int count){
    char searchtitle[1000];
    int titlecount = 0;
    cout << "Enter the name of the book you want to search: "<< endl;
    cin.ignore(); 
    cin.getline(searchtitle, 1000);
  
    for(int i = 0; i < count; i++){
        if(strcmp(searchtitle, book[i].book_title) == 0){
            titlecount++;
        }
    }
        cout << "-----"<< endl;
        cout << "No. of books found with the title: " << searchtitle << "\":" << titlecount << endl;
  
}

//function to display total number of books in the library.
void totalbookcountlib(int count){
    cout <<"Total books in library  " << count << endl;
}



int main(){
    struct Books book[Max_books];
    int bookcount=0;
    int choice;
    int count=0;

do{
   cout << "\nLIBRARY PROGRAM!" << endl;
    cout << "1 - Display book information" << endl;
    cout << "2 - Add a new book" << endl;
    cout << "3 - Display all the books in the library of a particular author" << endl;
    cout << "4 - Display the number of books of a particular title" << endl;
    cout << "5 - Display the total number of books in the library" << endl;
   

   cout<< "Choose an OPTION: ";
    cin >>  choice;

    switch(choice) {
        case 1:
            bookinfo( book, count);
            break;
        case 2:    
            addnewbook( book, &count);
            break;
        case 3:
             books_by_author(book, count);
             break;
        case 4:        
            book_by_title( book, count);
            break;
        case 5:
            totalbookcountlib(count);
            break;
        case 0:
            cout << "EXITING PROGRAM" << endl;
            break;
        default:
       cout<< "Invalid choice!" << endl;    
    }
}
while (choice != 0);

    return 0;

}
