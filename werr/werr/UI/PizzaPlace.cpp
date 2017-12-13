//
//  PizzaPlace.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 13/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "PizzaPlace.hpp"
#include <fstream>
#include <iostream>
PizzaPlace::PizzaPlace() {
    
}
void PizzaPlace::setname(string n) {
    name = n;
}
string PizzaPlace::getname() {
    return this -> name;
}

void PizzaPlace::write(ofstream& fout) const {
    int stringlength = name.length() +1;
    
    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(name.c_str(), stringlength);
}
void PizzaPlace::read(ifstream& fin) {
    int stringlength;
    
    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];
    
    fin.read(str, stringlength);
    
    name = str;
}
istream& operator >>(istream& in, PizzaPlace& place) {
    cout << "Input name of pizza place: ";
    in >> place.name;
    return in;
}
ostream& operator << (ostream& out, const PizzaPlace& place) {
    out << place.name << endl;
    return out;
}
