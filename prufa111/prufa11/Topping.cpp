//
//  InputPizza.cpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 29/11/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//
#include <fstream>
#include "Topping.hpp"

Topping::Topping() {
    
}

Topping::Topping(string topping_name, double toppingprice) {
    this ->topping_name = topping_name;
    this ->toppingprice = toppingprice;
}


void Topping::write(ofstream& fout) const {
    int stringlength = topping_name.length() +1;
    
    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(topping_name.c_str(), stringlength);
    
    fout.write((char*)(&toppingprice), sizeof(double));
}

void Topping::read(ifstream& fin) {
    int stringlength;
    
    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];
    
    fin.read(str, stringlength);
    
    topping_name = str;
    
    fin.read((char*)(&toppingprice), sizeof(double));
    
    delete [] str;
    
    
}
istream& operator >>(istream& in, Topping& topp) {
    cout << "Input topping: ";
    in >> topp.topping_name;
    cout << "Input topping price: ";
    in >> topp.toppingprice;
    
    return in;
}
ostream& operator << (ostream& out, const Topping& topp) {
    out << topp.topping_name << " " << topp.toppingprice << endl;
    return out;
}

