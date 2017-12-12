//
//  PizzaType.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 09/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "PizzaType.hpp"
#include <fstream>
#include <iostream>

PizzaType::PizzaType() {
    
}
void PizzaType::setbase(string b) {
    base = b;
}
string PizzaType::getbase() {
    return this -> base;
}
void PizzaType::setsize(int s) {
    size = s;
}
int PizzaType::getsize() {
    return this -> size;
}
void PizzaType::setprice(double p) {
    price = p;
}
double PizzaType::getprice() {
    return this -> price;
}
void PizzaType::write(ofstream& fout) const {
    int stringlength = base.length() +1;
    
    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(base.c_str(), stringlength);
    fout.write((char*)(&size), sizeof(int));
    fout.write((char*)(&price), sizeof(double));
}
void PizzaType::read(ifstream& fin) {
    int stringlength;
    
    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];
    
    fin.read(str, stringlength);
    
    base = str;
    
    fin.read((char*)(&size), sizeof(int));
    fin.read((char*)(&price), sizeof(double));
    
    delete [] str;
}
istream& operator >>(istream& in, PizzaType& type) {
    cout << "Input base: ";
    in >> type.base;
    cout << "Input size (in inches): ";
    in >> type.size;
    cout << "Input base price: ";
    in >> type.price;
    
    return in;
}
ostream& operator << (ostream& out, const PizzaType& type) {
    out << type.base << " " << type.size << " inches " << type.price << " kr." << endl;
    return out;
}
