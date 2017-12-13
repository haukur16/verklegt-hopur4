//
//  MenuTopp.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 12/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "MenuTopp.hpp"
#include <fstream>
#include <iostream>
MenuTopp::MenuTopp() {
    
}
void MenuTopp::setname(string t) {
    topp = t;
}
string MenuTopp::getname() {
    return this -> topp;
}

void MenuTopp::write(ofstream& fout) const {
    int stringlength = topp.length() +1;
    
    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(topp.c_str(), stringlength);
    
}

void MenuTopp::read(ifstream& fin) {
    int stringlength;
    
    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];
    
    fin.read(str, stringlength);
    
    topp = str;
    
    
    delete [] str;
}

istream& operator >>(istream& in, MenuTopp& toppi) {
    cout << "Input topping: ";
    in >> toppi.topp;
    
    return in;
}

ostream& operator << (ostream& out, const MenuTopp& toppi) {
    out << toppi.topp << endl;
    return out;
}
