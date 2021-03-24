#include <vector>
#include <string>
#include <iostream>
#include <map>

enum PersonStatus {
    OK,
    BAD,
    GOOD,
    NOTGOOD,
    EXCELLENT
};

class Dog {
    

    public:

    Dog(){
        name = "";
        dogYears = 0;
    }

    Dog(std::string nm, int dy){
        name = nm;
        dogYears = dy;
    }

    std::string name;
    int dogYears;


    void setName(std::string nm){
        name = nm;
    }

    std::string getName(){
        return name;
    }

    void setDogYears(int years){
        dogYears = years;
    }

    int getDogYears(){
        return dogYears;
    }

    void printDoggyDetails(){
        std::cout << "Dog Name: " << name << "\n" << "Dog Years old: " << dogYears << "\n";
    }
    
};

class PersonBase {
    public:
    PersonBase();
    PersonBase(PersonStatus s, Dog d);

    PersonStatus status;
    Dog doggy;

    Dog getDog(){
        return doggy;
    }

    void setDog(Dog dog){
        doggy = dog;
    }

    void setStatus(PersonStatus ps){
        status = ps;
    }

    void printStatus(){
        switch(status){
            case PersonStatus::OK : {
                std::cout << "I\'m OK";
                break;
            }
            case PersonStatus::BAD : {
                std::cout << "I\'m BAD";
                break;
            }
            case PersonStatus::GOOD : {
                std::cout << "I\'m Good";
                break;
            }
            case PersonStatus::NOTGOOD : {
                std::cout << "I\'m Not Good";
                break;
            }
            case PersonStatus::EXCELLENT : {
                std::cout << "I\'m Excellent";
                break;
            }
        }
    }
};

PersonBase::PersonBase() : status(PersonStatus::GOOD), doggy(){} 

PersonBase::PersonBase(PersonStatus ps, Dog d) : status(ps), doggy(d) {}


class Person : public PersonBase {
    public:

    Person();
    Person(std::string name);
    Person(std::string name, int age, float bal, bool pa);
    Person(std::string name, int age, float bal, bool pa, PersonStatus ps, Dog d);

    void printName(){
        std::cout << name << "\n";
    }

    void setName(std::string nm){
        name = nm;
    }

    void printAge(){
        std::cout << age << "\n";
    }

    void setAge(int a){
        age = a;
    }

    bool canPass(){
        return pass;
    }

    void setPass(bool p);
    void doesPass();

    void setBalance(float f);
    void printBalance();

    void printDetails();

    private:
    std::string name;
    int age;
    bool pass;
    float balance;
};

Person::Person() : name(""), age(0), pass(false), balance(0.00){}

Person::Person(std::string n) : name(n), age(0), pass(false), balance(0.00){}

Person::Person(std::string n, int a, float b, bool p) : name(n), age(a), balance(b), pass(p){}

Person::Person(std::string n, int a, float b, bool p, PersonStatus ps, Dog doggy) : PersonBase(ps, doggy), name(n), age(a), balance(b), pass(p) {}

void Person::setPass(bool p){
    pass = p;
}

void Person::doesPass(){
    std::cout << pass << "\n";
}

void Person::setBalance(float f){
    balance = f;
}

void Person::printBalance(){
    std::cout << balance << "\n";
}

void Person::printDetails(){
    std::cout << "Name: " << name << "\n" <<  "Age: " << age << "\n" <<  "Balance: " << balance << "\n"  <<   "Pass: " << pass << "\n" << std::endl; 
}

int main(){
    Person joe("Joe McNamara");
    joe.setAge(25);
    joe.setBalance(10002.21);
    joe.setPass(true);

    // joe.printName();
    // joe.printAge();
    // joe.printBalance();
    // joe.doesPass();

    Person mick("Mick", 55, 4532.43, true);
    //mick.printDetails();

    Person mary("Mary", 44, 9843.23, true);
    Person adrian("Adrian", 37, 89843.33, false);

    std::vector<Person> people;

    people.push_back(joe);
    people.push_back(mick);
    people.push_back(mary);
    people.push_back(adrian);

    for(Person& person : people){
        person.printDetails();
    }

    std::cout << "The people that pass:\n" << std::endl;

    Dog dogPass("Rusty", 70);
    Dog dogFail("Ben", 10);


    for(Person& p : people){
        if(p.canPass()){
            p.setDog(dogPass);
        } else {
            p.setDog(dogFail);
        }
        p.printDetails();
    }
    
    return 0;
}