//
//  PizzaMenu.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 11/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "PizzaMenu.hpp"
#include <fstream>
#include <iostream>

PizzaMenu::PizzaMenu() {

}


PizzaMenu::PizzaMenu(string n, double p, string t) {
    this ->name = n;
    this ->price = p;
    this ->pizzaTopp = t;
}
string PizzaMenu::getname() {
    return this->name;
}
double PizzaMenu::getprice() {
    return this->price;
}
string PizzaMenu::gettopping() {
    return this->pizzaTopp;
}

void PizzaMenu::write(ofstream& fout) const {
    int stringlength2 = pizzaTopp.length() +1;
    
    fout.write((char*)(&stringlength2), sizeof(int));
    fout.write(pizzaTopp.c_str(), stringlength2);
    
    int stringlength = name.length() +1;

    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(name.c_str(), stringlength);


    fout.write((char*)(&stringlength2), sizeof(int));
    fout.write(pizzaTopp.c_str(), stringlength2);

    fout.write((char*)(&price), sizeof(double));
}

void PizzaMenu::read(ifstream& fin) {
    int stringlength2;
    
    fin.read((char*)(&stringlength2), sizeof(int));
    char *str2 = new char[stringlength2];
    
    fin.read(str2, stringlength2);
    
    pizzaTopp = str2;
    int stringlength;

    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];

    fin.read(str, stringlength);

    name = str;
    fin.read((char*)(&price), sizeof(double));

    delete [] str;
}
istream& operator >> (istream& in, PizzaMenu& menu) {
    cout << "Input toppings, 0 for no more ";
    string select;
    while (true) {
        in >> menu.pizzaTopp;
        if (menu.pizzaTopp == "0") {
            break;
        }
    }
    cout << "Input pizza name: ";
    in >> menu.name;
    cout << "Input price of pizza: ";
    in >> menu.price;
    return in;
}
ostream& operator << (ostream& out, const PizzaMenu& menu) {

    out << menu.pizzaTopp;

    for (unsigned int i=0; i<menu.pizzaTopp.size(); i++) {
        cout << "Topping " << i+1 << ": ";
        out << menu.pizzaTopp[i];
    }

    out << menu.name << endl;
    out << menu.price << endl;
    return out;
}
