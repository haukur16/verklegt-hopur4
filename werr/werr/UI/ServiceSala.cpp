//
//  ServiceSala.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "ServiceSala.hpp"
#include <stddef.h>
#include <fstream>
using namespace std;

ServiceSala::ServiceSala() {
    
}

void ServiceSala::addTopping(ServiceUmsjon topping){
    toppings.push_back(topping);
}

void ServiceSala::write(ofstream& fout) const {
    int tcount = toppings.size();
    
    fout.write((char*)(&tcount), sizeof(int));
    
    for (int i=0; i<tcount; i++) {
        toppings[i].write(fout);
    }
}

void ServiceSala::read(ifstream& fin) {
    int tcount;
    fin.read((char*)(&tcount), sizeof(int));
    
    ServiceUmsjon topping;
    for (int i=0; i<tcount; i++) {
        topping.read(fin);
        addTopping(topping);
    }
}

ifstream& operator >>(ifstream& in, ServiceSala& pizza) {
    int toppingcount;
    in >> toppingcount;
    
    ServiceUmsjon topping;
    
    for (unsigned int i = 0; i<pizza.toppings.size(); i++) {
        in >> topping;
        pizza.addTopping(topping);
    }
    return in;
}

ofstream& operator <<(ofstream& out, const ServiceSala& pizza) {
    out << "Pizza with toppings:" << endl;
    
    for (unsigned int i=0; i<pizza.toppings.size(); i++) {
        out << pizza.toppings[i] << endl;
    }
    return out;
}
