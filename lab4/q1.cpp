#include <iostream>
#include <string>

using namespace std;

class Book{
private:
    string name;
    string author;
    string ISBN;
    int totalPages;
    int pagesRead;

public:
//default constructor
      Book() {
        name = "";
        author = "";
        ISBN = "";
        totalPages = 0;
        pagesRead = 0;
    }

     // Parameterized constructor
    Book(string bookName, string authorName, string bookISBN, int bookTotalPages) {
        name = bookName;
        author = authorName;
        ISBN = bookISBN;
        totalPages = bookTotalPages;
        pagesRead = 0;
    }

    void updatePagesRead(int pages) {
        pagesRead += pages;
        if (pagesRead >= totalPages) {
            cout << "The book has finished!" << endl;
        }
        else
        {
            cout << "Pages read " << pagesRead << " out of " << totalPages << " " << "pages. " << endl;
        }
    }
};

int main(){
    Book book1;

   
    Book book2("Charlie and the Chocolate Factory", "Roald Dahl", "97878543020-2", 1500 );

    // Update pages read for book2
    book2.updatePagesRead(36);
    book2.updatePagesRead(80);

    return 0;
}
