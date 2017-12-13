//
//  OtherOrder.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 13/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "OtherOrder.hpp"
#include <fstream>
using namespace std;
OtherOrder::OtherOrder(){
    
}
void OtherOrder::addOtherStuff(Other_stuff otherStuff) {
    other_stuff.push_back(otherStuff);
}
void OtherOrder::addPlace(PizzaPlace pizzaplace) {
    pizzaPlace.push_back(pizzaplace);
}
void OtherOrder::write(ofstream& fout) const {
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
void OtherOrder::read(ifstream& fin) {
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
istream& operator >> (istream& in, OtherOrder& order) {
    int otherStuffCount;
    in >> otherStuffCount;
    Other_stuff otherStuff;
    for (unsigned int i = 0; i<order.other_stuff.size(); i++) {
        in >> otherStuff;
        order.addOtherStuff(otherStuff);
    }
    int placeCount;
    in >> placeCount;
    PizzaPlace pizzaplace;
    for (unsigned int i = 0; i<order.pizzaPlace.size(); i++) {
        in >> pizzaplace;
        order.addPlace(pizzaplace);
    }
    
    return in;
}
ostream& operator << (ostream& out, const OtherOrder& order) {
    
    cout << "------------------------" << endl;
    out << "Other products:" << endl;
    for (unsigned int i=0; i<order.other_stuff.size(); i++) {
        out << order.other_stuff[i];
    }
    cout << "------------------------" << endl;
    out << "Pizza Place:" << endl;
    for (unsigned int i=0; i<order.pizzaPlace.size(); i++) {
        out << order.pizzaPlace[i];
    }
    return out;
}
vector<Other_stuff> OtherOrder::othStuff() {
    return this -> other_stuff;
}

