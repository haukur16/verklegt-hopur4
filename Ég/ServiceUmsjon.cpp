//
//  ServiceUmsjon.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "ServiceUmsjon.hpp"
#include <fstream>

ServiceUmsjon::ServiceUmsjon() {
    
}

ServiceUmsjon::ServiceUmsjon(string topping_name, double toppingprice) {
    this ->topping_name = topping_name;
    this ->toppingprice = toppingprice;
}


void ServiceUmsjon::write(ofstream& fout) const {
    int stringlength = topping_name.length() +1;
    
    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(topping_name.c_str(), stringlength);
    
    fout.write((char*)(&toppingprice), sizeof(double));
}

void ServiceUmsjon::read(ifstream& fin) {
    int stringlength;
    
    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];
    
    fin.read(str, stringlength);
    
    topping_name = str;
    
    fin.read((char*)(&toppingprice), sizeof(double));
    
    delete [] str;
    
    
}
istream& operator >>(istream& in, ServiceUmsjon& topp) {
    cout << "Input topping: ";
    in >> topp.topping_name;
    cout << "Input topping price: ";
    in >> topp.toppingprice;
    
    return in;
}
ostream& operator << (ostream& out, const ServiceUmsjon& topp) {
    out << topp.topping_name << " " << topp.toppingprice << endl;
    return out;
}
