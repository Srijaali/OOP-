/*
Name: Syeda Rija Ali
ID:23K-0057
desc: simple inheritance between book and fiction book class
*/

#include <iostream>
#include <string>

using namespace std;

//base class 
class Book {
	protected:
    	string title;
    	string author;
    	string publisher;

	public:
    Book(string title, string author, string publisher)
        : title(title), author(author), publisher(publisher) {}

    void display() const {
    	cout<<"Displaying book information:"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author << endl;
        cout<<"Publisher: "<<publisher<<endl;
    }
};

//derived
class FictionBook : public Book {
	private:
    	string genre;
    	string protagonist;

	public:
    	FictionBook(string title, string author, string publisher, string genre, string protagonist)
        : Book(title, author, publisher), genre(genre), protagonist(protagonist) {}

    void display() const {
        Book::display();
        cout<<"Genre: "<<genre<<endl;
        cout<<"Protagonist: "<<protagonist<<endl;
    }
};

int main() {
    //instance of the derived class
    FictionBook book("Harry Potter and the Philospher's Stone", "J.K.Rowling", "oxford", "Fiction", "Harry Potter");
    book.display();

    return 0;
}
