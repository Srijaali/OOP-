/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc: creating an inheritance hierarchy for a gaming environment. The environment consists of different aspects of the game.
*/

#include <iostream>
#include <string>
using namespace std;

class Player{
    protected:
    int playerID;
    string playerName;
    int health;
    
    public:
    Player(int id, string name) : playerID(id), playerName(name) , health(100) {}

    void setHealth(int health){
        this -> health = health;
    }

    int getHealth(){
        return health;
    }
};

class Weapon{
    protected:
    string weapons[5];

    public:
    Weapon(){
        weapons[0] = "Gun";
        weapons[1] = "Sword";
        weapons[2] = "Dagger";
        weapons[3] = "Grenade";
        weapons[4] = "Spear";
    }

void display(){
     cout << "Displaying Weapons:" << endl;
        for(int i=0; i<5; i++){
            cout << i+1 << ". " << weapons[i] << endl;
        }
}
    string   use(){
        int n;
        cout << "Choose the weapon from the given list(select number): " << endl;
        cin >> n;

        while(n<1 || n>5){
            cout << "Invalid Choice! Re-enter the number.." << endl;
            cin >> n; 
        }

         return weapons[n-1];
    }
};

class Enemy;

class Character : public Player {
    protected:
    int level;
    string experience;
    int points;

    public:
    Character(int id, string name) : Player(id,name), level(0) , experience("Beginner"), points(0) {}

    void levelUp(){
        points += 10;
        if(points >= 10){
            level++;
          if(level == 1){
            experience = "Intermediate";
        }
         if(level == 2){
            experience = "Advanced";
        }
        if(level == 3){
            experience = "Expert";
        }
        points =0;
        }
    }

    void playGame(Weapon weapon , Enemy& enemy);

    string getExp(){
            return this-> experience;
        }

        	void display() const {
    		cout<<"Player ID: "<<playerID<<endl;
        	cout<<"Player Name: "<<playerName<<endl;
        	cout<<"Health: "<<health<<endl;
        	cout<<"Experience: "<<experience<<endl;
        	cout<< "Points: "<<points<<endl;
    	}
};

class Enemy : public Player{
    protected:
    int damage;

    public:
    Enemy(int id, string name , int damage) : Player(id,name) , damage(damage){
        if(damage < 1 || damage > 5){
            damage =5;
        }
    }

    void attack(Character& player , Weapon& weapon){
        cout << "Enemy's Turn..."  << endl;
        string enemyWeapon = weapon.use();

        cout << "Enemy used " << enemyWeapon << " to attack." << endl;
        player.setHealth(player.getHealth()-damage);
    }

    	void display() const {
    		cout<<"Enemy ID: "<<playerID<<endl;
        	cout<<"Enemy Name: "<<playerName<<endl;
    	}
};

void Character::playGame(Weapon weapon, Enemy& enemy){
    cout << "\nCharacter's Turn...\n";
        string cWeapon = weapon.use();

        cout << "Player used '" << cWeapon << "' to attack the enemy\n";
        enemy.setHealth(enemy.getHealth() - 5);
        points += 10;
        levelUp();
}

int main(){
   
    cout << "Name: Syeda Rija Ali" << endl;
    cout << "ID: 23K-0057" << endl;
    cout << endl;
   
    Weapon weapon;
    Character character(22 , "Alex");
    character.display();
    cout<<endl;
     weapon.display();
    Enemy enemy(20, "Louis" , 5);
     for (int i = 0; i < 4; i++) {
        cout << "Character experience: " << character.getExp() << "\n";
        cout << "Character health: " << character.getHealth() << "\n";
        character.playGame(weapon, enemy);
        enemy.display();
        cout << "Enemy health: " << enemy.getHealth() << "\n";
        enemy.attack(character , weapon);
    }

    return 0;
}

