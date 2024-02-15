#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int pageCount;
    int pagesRead;

public:
    Book() : pageCount(1000), pagesRead(0) {} 

    //setter methods:
    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthorName(string authorName)
    {
        author = authorName;
    }

    void setPageCount(int newPageCount)
    {
        pageCount = newPageCount;
    }

    void setPagesRead(int newPagesRead)
    {
        pagesRead = newPagesRead;
    }

      void showBookInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author <<  endl;
        cout << "Page Count: " << pageCount << endl;
        cout << "Pages Read: " << pagesRead << endl;
      }
};

int main() {

    Book book1;

    book1.setTitle("The Alchemist");
    book1.setAuthorName("Paulo Coelho");
    book1.setPageCount(280);
    book1.setPagesRead(100);

    book1.showBookInfo();

    return 0;

}
