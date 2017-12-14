//
//  Pizza.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 08/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "Pizza.hpp"
#include <stddef.h>
#include <fstream>
using namespace std;
Pizza::Pizza() {

}



void Pizza::addTopping(Topping topping) {
    toppings.push_back(topping);
}

void Pizza::addType(PizzaType pizzatype) {
    pizzaType.push_back(pizzatype);
    
}


void Pizza::write(ofstream& fout) const {
    int tcount = toppings.size();
    fout.write((char*)(&tcount), sizeof(int));
    for (int i=0; i<tcount; i++) {
        toppings[i].write(fout);
    }
    
    int btcount = pizzaType.size();
    fout.write((char*)(&btcount), sizeof(int));
    for(int i = 0; i<btcount; i++) {
        pizzaType[i].write(fout);
    }

    
}
void Pizza::read(ifstream& fin) {
    int tcount;

    fin.read((char*)(&tcount), sizeof(int));
    Topping topping;
    for (int i=0; i<tcount; i++) {
        topping.read(fin);
        addTopping(topping);
    }
    
    int btcount;
    fin.read((char*)(&btcount), sizeof(int));
    PizzaType pizzatype;
    for (int i = 0; i < btcount; i++) {
        pizzatype.read(fin);
        addType(pizzatype);
    }
}

istream& operator >> (istream& in, Pizza& pizza) {
    int toppingcount;
    in >> toppingcount;
    Topping topping;
    for (unsigned int i = 0; i<pizza.toppings.size(); i++) {
        in >> topping;
        pizza.addTopping(topping);
    }
    int typeCount;
    in >> typeCount;
    PizzaType pizzatype;
    for (unsigned int i = 0; i<pizza.pizzaType.size(); i++) {
        in >> pizzatype;
        pizza.addType(pizzatype);
    }
    return in;
}
ostream& operator << (ostream& out, const Pizza& pizza) {
    out << "Pizza with toppings:" << endl;
    for (unsigned int i=0; i<pizza.toppings.size(); i++) {
        out << "Topping " << i+1 << ": " << pizza.toppings[i];
    }
    cout << "------------------------" << endl;
    out << "Pizza type and size" << endl;
    for (unsigned int i=0; i<pizza.pizzaType.size(); i++) {
        out << pizza.pizzaType[i];
    }
    return out;
}

vector<Topping> Pizza::getTopping() {
    return this -> toppings;
}
vector<PizzaType> Pizza::getType() {
    return this -> pizzaType;
}

