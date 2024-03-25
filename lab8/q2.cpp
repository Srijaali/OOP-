/*
Name: Syeda Rija Ali
ID:23K-0057
desc: hierarchical inheritance between classes
LAB 8 Q2
*/

#include <iostream>
#include <string>

using namespace std;

class Character{
    public:
        int health;
        int damage;
       
        Character(int health,int damage):health(health),damage(damage){}

        void displayCharacter(){
            cout << "Character's Health: " << health << endl;
            cout << "Character Damage: " << damage << endl;
        }
};

class Enemy : public Character{
    public:
    Enemy(int health,int damage) : Character(health,damage){}

    void displayEnemy(){
    cout << "Deriving Base class from enemy class: " << endl;
    Character :: displayCharacter();
    }
};

class Player : public Character{
    public:
    Player(int health , int damage) : Character(health,damage){}

    void displayPlayer(){
    cout << "Deriving base class from Player class: " << endl;
    Character :: displayCharacter();
    }
};

class Wizard : public Player{
    public:
    int magic_power;
    string spells;

    Wizard(int health,int damage,int magic_power,string spells) : Player(health,damage) , magic_power(magic_power) , spells(spells){}

    void displaywizard(){
        Player :: displayPlayer();
        cout << "From Wizard Class: " << endl;
        cout << "Magic Powers: " << magic_power << endl;
        cout << "Spells: " << spells << endl;
    }
};

int main(){
    Wizard w(20 , 10  , 5 , "Wingardium Leviosa");
    w.displaywizard();
}
