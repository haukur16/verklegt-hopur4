//
//  PizzaMenu.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 11/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "PizzaMenu.hpp"
#include "MenuTopp.hpp"
#include <fstream>
#include <iostream>

PizzaMenu::PizzaMenu() {

}


PizzaMenu::PizzaMenu(string n, double p) {
    this ->name = n;
    this ->price = p;
}
string PizzaMenu::getname() {
    return this->name;
}
double PizzaMenu::getprice() {
    return this->price;
}


void PizzaMenu::write(ofstream& fout) const {
    int stringlength = name.length() +1;

    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(name.c_str(), stringlength);

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
istream& operator >> (istream& in, PizzaMenu& menu) {
    MenuTopp menutopp;
    cout << "Input Toppings: ";
    in >> menutopp;
    cout << "Input pizza name: ";
    in >> menu.name;
    cout << "Input price of pizza: ";
    in >> menu.price;
    return in;
}
ostream& operator << (ostream& out, const PizzaMenu& menu) {
    out << menu.name << endl;
    out << menu.price << endl;
    return out;
}
