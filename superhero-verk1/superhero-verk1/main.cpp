//
//  main.cpp
//  superhero
//
//  Created by Haukur Guðmundsson on 27/11/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    char power;
    
public:
    Person(string name, int age, char power) {
        this->name = name;
        this->age = age;
        this->power = power;
    }
    friend istream& operator >> (istream& ins, Person& person) {
        cout << "Please enter superhero name: ";
        ins >> person.name;
        cout << "Please enter superhero age: ";
        ins >> person.age;
        cout << "Please enter power of superhero: ";
        ins >> person.power;
        return ins;
    }
    friend ostream& operator << (ostream& outs, const Person& person) {
        outs << person.name << " (" << person.age << "): ";
        if (person.power == 'f') {
            outs << "Flying";
        }
        else if (person.power == 'g') {
            outs << "Giant";
        }
        else if (person.power == 'h') {
            outs << "Hacker";
        }
        else if (person.power == 'n') {
            outs << "None";
        }
        else
            outs << "Weakling";
        outs << endl;
        return outs;
    }
    
};

int main(int argc, const char * argv[]) {
    Person hero (" ", 0, 'n');
    cin >> hero;
    
    ofstream fout;
    fout.open("txtFile.txt", ios::app);
    if (fout.is_open()) {
        fout << hero;
        fout.close();
    }
    cout << hero;
    ifstream fin;
    string str;
    fin.open("txtFile.txt");
    if (fin.is_open()) {
        while(!fin.eof()) {
            getline(fin,str);
            cout << str << endl;
        }
        fin.close();
    }
    else {
        cout << "Unable to read frome file! " << endl;
    }
    return 0;
}
