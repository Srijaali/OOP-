/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc: Table Management system
*/

#include <iostream>
using namespace std;

class Table{
    private:
    int capacity;
    int occupiedSeats;
    bool cleanliness;

    public:
    //default constructor
    Table() : capacity(4), occupiedSeats(0), cleanliness(true) {}
    
	//parameterized constructor
    Table(int roundcap) {
    	if(roundcap==8||roundcap==4) {
    		capacity=roundcap;
		} else {
			capacity = (roundcap+2)/(4*4);
		}
		occupiedSeats=0;
		cleanliness=true;
	}

//setters
    void setCapacity(int cap){
        capacity = cap;
    }

    void setOccupiedSeats(int occ_seats){
        occupiedSeats = occ_seats;
    }

    void isClean(bool clean){
        cleanliness = clean;
    }

//getters
    int getCapacity()const{
        return capacity;
    }

    int getOccupiedSeats()const{
        return occupiedSeats;
    }

    bool isClean()const{
        return cleanliness;
    }

    void useTable(int groupsize){
        if (cleanliness && groupsize <= capacity){
            occupiedSeats = groupsize;

            cout << "Table with seating capacity of " << capacity << " seats is occupied by the group size of " << groupsize << " people" << endl;
        }
        else{
            cout << "The table is either dirty or the group size is too big to be seated on the table!" << endl;
        }
    }

    void haveLunch(){
         cleanliness=false;
        cout<<"People are having lunch on the table"<<endl;
    }

    void leaveTable(){
        if (occupiedSeats == 0){
            cout << "Table already empty!" << endl;
            return;
        }
        occupiedSeats = 0;
        if(cleanliness)
            cout<< "People have left the table without having lunch!\n" << endl;
        else
            cout<< "Table left after having lunch on\n"<< endl;
    }

    void cleantable(){
        if (occupiedSeats == 0 && !cleanliness){
            cout << "The table is being cleaned!" << endl;
        }
        else{
            cout << "The table is full and hence can not be cleaned." << endl;
        }
    }


};

    void OccupyTable (Table tables[], int groupsize){
        for (int i = 0; i < 5; i++){
        if(tables[i].getOccupiedSeats()==0 && tables[i].isClean() && groupsize <= tables[i].getCapacity()){

            tables[i].useTable(groupsize);
            return;
            }
        }
          cout << "No available tables!" << endl;
    }

  void EmptyTable(Table tables[], int tablenum){
       if (tablenum >= 0 && tablenum < 5){
            tables[tablenum].leaveTable();
       }
       else{
        cout << "Invalid table number!" << endl;
       }
    }

int main(){
    Table tables[5] = {Table(8), Table(8), Table(4), Table(4), Table(4)};

    OccupyTable(tables,4);
    cout << endl;
    OccupyTable(tables,6);
    cout << endl;
    cout<<"--Actions being performed on the sample table--\n" <<endl;
    tables[0].useTable(4);
    cout << endl;
    tables[0].haveLunch();
    cout << endl;
    tables[0].leaveTable();
    cout << endl;
    tables[0].cleantable();
    cout << endl;
    EmptyTable(tables,1);

    return 0;
}
