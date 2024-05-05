#include <iostream>
using namespace std;

template <class T>

class Pet{
protected:    
string name;
int age;

public:
Pet(string name,int age) : name(name),age(age) {}

virtual void makesound()=0;
};

class Cat: public Pet<Cat>{
public:
Cat(string name,int age) : Pet(name,age) {}

void makesound()override{
    cout<<"Meow!"<<endl;
}

void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;

}
};

class Dog: public Pet<Dog>{
public:
Dog(string name,int age) : Pet(name,age){}

void makesound()override{
    cout<<"Woof! Woof!"<<endl;
}

void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;

}
};

class Bird: public Pet<Bird>{
public:
Bird(string name,int age) : Pet(name,age){}

void makesound()override{
    cout<<"Chirp..."<<endl;
}

void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;

}
};

int main(){
    cout<<"SYEDA RIJA ALI [23K-0057]"<<endl<<endl;

    Cat c("Muffin",5);
    c.display();
    c.makesound();

    Dog d("Pluto",7);
    d.display();
    d.makesound();

    Bird b("Tweetie",2);
    b.display();
    b.makesound();

return 0;    
}
