#include <vector>
#include <string>
#include <iostream>

class Person {
    public:

    Person();
    Person(std::string name);
    Person(std::string name, int age, float bal, bool pa);

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


    std::cout << "The people that pass" << std::endl;

    for(Person& p : people){
        if(p.canPass()){
            p.printDetails();
        }
    }


    return 0;
}