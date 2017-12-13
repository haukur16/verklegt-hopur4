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

void Pizza::addOtherStuff(Other_stuff otherStuff) {
    other_stuff.push_back(otherStuff);
}

void Pizza::addType(PizzaType pizzatype) {
    pizzaType.push_back(pizzatype);
    
}
void Pizza::addPlace(PizzaPlace pizzaplace) {
    pizzaPlace.push_back(pizzaplace);
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

    int oscount = other_stuff.size();
    fout.write((char*)(&oscount), sizeof(int));
    for(int i = 0; i<oscount; i++) {
        other_stuff[i].write(fout);
    }
    int pcount = pizzaPlace.size();
    fout.write((char*)(&pcount), sizeof(int));
    for(int i = 0; i<pcount; i++) {
        pizzaPlace[i].write(fout);
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
    int oscount;
    fin.read((char*)(&oscount), sizeof(int));
    Other_stuff otherStuff;
    for (int i = 0; i < oscount; i++) {
        otherStuff.read(fin);
        addOtherStuff(otherStuff);
    }
    int pcount;
    fin.read((char*)(&pcount), sizeof(int));
    PizzaPlace pizzaplace;
    for (int i = 0; i < pcount; i++) {
        pizzaplace.read(fin);
        addPlace(pizzaplace);
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
    int otherStuffCount;
    in >> otherStuffCount;
    Other_stuff otherStuff;
    for (unsigned int i = 0; i<pizza.other_stuff.size(); i++) {
        in >> otherStuff;
        pizza.addOtherStuff(otherStuff);
    }
    int placeCount;
    in >> placeCount;
    PizzaPlace pizzaplace;
    for (unsigned int i = 0; i<pizza.pizzaPlace.size(); i++) {
        in >> pizzaplace;
        pizza.addPlace(pizzaplace);
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
    cout << "------------------------" << endl;
    out << "Other products:" << endl;
    for (unsigned int i=0; i<pizza.other_stuff.size(); i++) {
        out << pizza.other_stuff[i];
    }
    cout << "------------------------" << endl;
    out << "Pizza Place:" << endl;
    for (unsigned int i=0; i<pizza.pizzaPlace.size(); i++) {
        out << pizza.pizzaPlace[i];
    }
    return out;
}

vector<Topping> Pizza::getTopping() {
    return this -> toppings;
}
vector<PizzaType> Pizza::getType() {
    return this -> pizzaType;
}
vector<Other_stuff> Pizza::othStuff() {
    return this -> other_stuff;
}
