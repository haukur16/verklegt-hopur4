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


PizzaMenu::PizzaMenu(string n, double ps, double pm, double pl, string t) {
    this ->name = n;
    this ->priceS = ps;
    this ->priceM = pm;
    this ->priceL = pl;
    this ->topping = t;
}
string PizzaMenu::getname() {
    return this->name;
}
double PizzaMenu::getprice() {
    return this->priceS;
    return this->priceM;
    return this->priceL;
}
string PizzaMenu::gettopping() {
    return this ->topping;
}


void PizzaMenu::write(ofstream& fout) const {
    int stringlength = name.length() +1;

    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(name.c_str(), stringlength);
    
    int stringlength2 = topping.length() +1;
    
    fout.write((char*)(&stringlength2), sizeof(int));
    fout.write(topping.c_str(), stringlength2);

    fout.write((char*)(&priceS), sizeof(double));
    fout.write((char*)(&priceM), sizeof(double));
    fout.write((char*)(&priceL), sizeof(double));
}

void PizzaMenu::read(ifstream& fin) {
    int stringlength;

    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];

    fin.read(str, stringlength);

    name = str;
    
    int stringlength2;
    
    fin.read((char*)(&stringlength2), sizeof(int));
    char *str2 = new char[stringlength2];
    
    fin.read(str2, stringlength2);
    
    topping = str2;
    fin.read((char*)(&priceS), sizeof(double));
    fin.read((char*)(&priceM), sizeof(double));
    fin.read((char*)(&priceL), sizeof(double));
    delete [] str;
    delete [] str2;
}
istream& operator >> (istream& in, PizzaMenu& menu) {
    cout << "Input pizza name: ";
    in >> menu.name;
    cout << "Input Toppings(put , between and no spaces: ";
    in >> menu.topping;
    cout << "Input price of small pizza: ";
    in >> menu.priceS;
    cout << "Input price of medium pizza: ";
    in >> menu.priceM;
    cout << "Input price of large pizza: ";
    in >> menu.priceL;
    return in;
}
ostream& operator << (ostream& out, const PizzaMenu& menu) {
    out << "-------------"<< endl;
    out << menu.name << endl;
    out << "-------------"<< endl;
    out << "Toppings: " << menu.topping << endl;
    out << "-------------"<< endl;
    out << "Small: " << menu.priceS << "$| Medium: " << menu.priceM << "$| Large: " << menu.priceL <<"$"<< endl;
    out << "============="<< endl;
    return out;
}
