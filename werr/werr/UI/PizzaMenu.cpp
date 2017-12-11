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
void PizzaMenu::setname(string n) {
    name = n;
}


string PizzaMenu::getname() {
    return this -> name;
}
void PizzaMenu::setprice(double p) {
    price = p;
}

double PizzaMenu::getprice() {
    return this -> price;
}
void PizzaMenu::settoppings(string t) {
    toppings = t;
}
string PizzaMenu::gettoppings() {
    return this -> toppings;
}
void PizzaMenu::write(ofstream& fout) const {
    int stringlength = name.length() +1;
    
    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(name.c_str(), stringlength);
    
    int stringlength2 = toppings.length() +1;
    
    fout.write((char*)(&stringlength2), sizeof(int));
    fout.write(toppings.c_str(), stringlength2);
    fout.write((char*)(&price), sizeof(double));
}

void PizzaMenu::read(ifstream& fin) {
    int stringlength;
    
    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];
    
    fin.read(str, stringlength);
    
    name = str;
    
    fin.read((char*)(&price), sizeof(double));
    
    delete [] str;
}

istream& operator >>(istream& in, PizzaMenu& menu) {
    cout << "Input pizza name: ";
    in >> menu.name;
    int many;
    cout << "How many toppings do you want ?";
    cin >> many;
    for (int i=0; i<many; i++) {
        cout << "Topping " << i++ << ": ";
        in >> menu.toppings[i];
    }
    cout << "Input pizza price: ";
    in >> menu.price;
    
    
    return in;
}

ostream& operator << (ostream& out, const PizzaMenu& menu) {
    out << menu.name << endl;
    for (int i=0; i<menu.toppings.size(); i++) {
        cout << "Topping " << i++ << ": ";
        out << menu.toppings[i];
    }
    out <<menu.price << endl;
    return out;
}
