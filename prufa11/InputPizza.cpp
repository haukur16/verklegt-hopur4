//
//  InputPizza.cpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 29/11/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>
#include "InputPizza.hpp"
using namespace std;

Pizza::Pizza() {
    topping = ' ';
    toppingprice = 0.0;
}

istream& operator >>(istream& in, Pizza& topp) {
    cout << "Input topping: ";
    in >> topp.topping;
    cout << "Input topping price: ";
    in >> topp.toppingprice;
    
    return in;
}
ostream& operator << (ostream& out, const Pizza& topp) {
    out << topp.topping << " " << topp.toppingprice << endl;
    return out;
}

