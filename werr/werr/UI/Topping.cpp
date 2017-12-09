//
//  Topping.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 08/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "Topping.hpp"
#include <fstream>
#include <iostream>

Topping::Topping(){
    
}
void Topping::setname(string n) {
    name = n;
}
string Topping::getname() {
    return this -> name;
}

void Topping::setprice(double p) {
    price = p;
}
double Topping::getprice() {
    return this -> price;
}

void Topping::write(ofstream& fout) const {
    int stringlength = name.length() +1;
    
    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(name.c_str(), stringlength);
    
    fout.write((char*)(&price), sizeof(double));
}

void Topping::read(ifstream& fin) {
    int stringlength;
    
    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];
    
    fin.read(str, stringlength);
    
    name = str;
    
    fin.read((char*)(&price), sizeof(double));
    
    delete [] str;
    
    
}
istream& operator >>(istream& in, Topping& topp) {
    cout << "Input topping: ";
    in >> topp.name;
    cout << "Input topping price: ";
    in >> topp.price;
    
    return in;
}
ostream& operator << (ostream& out, const Topping& topp) {
    out << topp.name << " " << topp.price << endl;
    return out;
}
