/*
Name: Syeda Rija Ali
ID:23K-0057
desc: multipal inheritance between classes
LAB 8 Q3
*/

#include <iostream>
#include <string>

using namespace std;

class Position{
    protected:
    int cood_x;
    int cood_y;
    int cood_z;

    public:
    Position(int cood_x,int cood_y,int cood_z) : cood_x(cood_x),cood_y(cood_y),cood_z(cood_z) {}

    void displayPosition()const {
        cout << "Position at coordinate x: " << cood_x << " , at coordinate y: " << cood_y << " and at coordinate z: " << cood_z << endl;
    }
};

class Health{
    protected: 
    int health;

    public:
    Health(int health) : health(health) {}

    void displayHealth()const{
        cout << "Health: " << health << endl;
    }
};

class Character : public Position , public Health {
    protected:
    string name;
    int age;
   
    public:
    Character(int cood_x,int cood_y,int cood_z,int health,string name,int age) : name(name), age(age), Position(cood_x,cood_y,cood_z) , Health(health) {}

    void displayCharacter(){
        cout <<"Name: " << name << endl;
        cout << "Age: " << age << endl;

        Position :: displayPosition();
        Health :: displayHealth();
    }
};

int main() {
    Character c(2 , 4 , 6 , 20 , "Louis" , 21);
    c.displayCharacter();

  return 0;
}
