//
//  OtherOrder.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 13/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "OtherOrder.hpp"
#include <iostream>
#include <fstream>
using namespace std;
OtherOrder::OtherOrder(){
    
}
void OtherOrder::addOtherStuff(Other_stuff otherStuff) {
    other_stuff.push_back(otherStuff);
}
void OtherOrder::addPlace(PizzaPlace pizzaplace) {
    pizzaPLace.push_back(pizzaplace);
}
void OtherOrder::addComment(Comment comment) {
    commeNT.push_back(comment);
}
void OtherOrder::setPickSend(int ps) {
    pickSend = ps;
}
int OtherOrder::getPickSend() {
    return this -> pickSend;
}
void OtherOrder::setIsPaid(int ip) {
    ispaid = ip;
}
int OtherOrder::getIsPaid() {
    return this -> ispaid;
}

void OtherOrder::write(ofstream& fout) const {
    int oscount = other_stuff.size();
    fout.write((char*)(&oscount), sizeof(int));
    for(int i = 0; i<oscount; i++) {
        other_stuff[i].write(fout);
        cout << endl;
    }
    int pcount = pizzaPLace.size();
    fout.write((char*)(&pcount), sizeof(int));
    for(int i = 0; i<pcount; i++) {
        pizzaPLace[i].write(fout);
        cout << endl;
    }
    
    fout.write((char*)(&pickSend), sizeof(int));
    fout.write((char*)(&ispaid), sizeof(int));
    
    int ccount = commeNT.size();
    fout.write((char*)(&ccount), sizeof(int));
    for(int i = 0; i<ccount; i++) {
        commeNT[i].write(fout);
        cout << endl;
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
    fin.read((char*)(&pickSend), sizeof(int));
    fin.read((char*)(&ispaid), sizeof(int));
    int ccount;
    fin.read((char*)(&ccount), sizeof(int));
    Comment comment;
    for (int i = 0; i < ccount; i++) {
        comment.read(fin);
        addComment(comment);
    
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
    for (unsigned int i = 0; i<order.pizzaPLace.size(); i++) {
        in >> pizzaplace;
        order.addPlace(pizzaplace);
    }
    
    in >> order.pickSend;
    in >> order.ispaid;
    
    int commentCount;
    in >> commentCount;
    Comment comment;
    for (unsigned int i = 0; i<order.commeNT.size(); i++) {
        in >> comment;
        order.addComment(comment);
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
    for (unsigned int i=0; i<order.pizzaPLace.size(); i++) {
        out << order.pizzaPLace[i];
    }
    cout << "------------------------" << endl;
    cout << "Pizza is :" << endl;
    if (order.pickSend == 1) {
        out << "PickUp" << endl;
    }
    else if (order.pickSend == 2) {
        out << "Send" << endl;
    }
    cout << "------------------------" << endl;
    cout << "Pizza is :" << endl;
    if (order.ispaid == 1) {
        out << "Paid" << endl;
    }
    else if (order.ispaid == 2) {
        out << "Unpaid" << endl;
    }
    cout << "------------------------" << endl;
    cout << "Comment on order:" << endl;
    for (unsigned int i=0; i<order.commeNT.size(); i++) {
        out << order.commeNT[i];
    }
    cout << endl;
   
    return out;
}
vector<Other_stuff> OtherOrder::othStuff() {
    return this -> other_stuff;
}
vector<PizzaPlace> OtherOrder::pizzaPlace() {
    return this -> pizzaPLace;
}
vector<Comment> OtherOrder::commen() {
    return this -> commeNT;
}

