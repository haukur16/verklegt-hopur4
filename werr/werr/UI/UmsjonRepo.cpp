//
//  UmsjonRepo.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "UmsjonRepo.hpp"
#include <fstream>
#include <vector>
using namespace std;

UmsjonRepo::UmsjonRepo() {

}

void UmsjonRepo::storeAllToppings(const vector<Topping> &toppings) {
    ofstream fout;
    fout.open("toppings.bin", ios::binary);

    int toppingcount = toppings.size();

    fout.write((char*)(&toppingcount), sizeof(int));

    for (int i=0; i<toppingcount; i++) {
        toppings[i].write(fout);
    }
    fout.close();
}

vector<Topping> UmsjonRepo::retriveAllToppings() {
    vector<Topping> toppings;
    Topping topping;

    ifstream fin;
    fin.open("toppings.bin", ios::binary);

    if(fin.is_open()) {
        int toppingcount;

        fin.read((char*)(&toppingcount), sizeof(int));

        for (int i=0; i<toppingcount; i++) {
            topping.read(fin);
            toppings.push_back(topping);
        }
        fin.close();
    }
    return toppings;
}

vector<Other_stuff> UmsjonRepo::retriveAllOtherStuff() {
    vector<Other_stuff> other_stuff;
    Other_stuff otherStuff;

    ifstream fin;
    fin.open("Other_stuff.bin", ios::binary);

    if(fin.is_open()) {
        int otherStuffcount;

        fin.read((char*)(&otherStuffcount), sizeof(int));

        for (int i=0; i<otherStuffcount; i++) {
            otherStuff.read(fin);
            other_stuff.push_back(otherStuff);
        }
        fin.close();
    }
    return other_stuff;
}

void UmsjonRepo::storeAllOtherStuff(const vector<Other_stuff> &other_stuff) {
    ofstream fout;
    fout.open("Other_stuff.bin", ios::binary);

    int otherStuffcount = other_stuff.size();

    fout.write((char*)(&otherStuffcount), sizeof(int));

    for (int i=0; i<otherStuffcount; i++) {
        other_stuff[i].write(fout);
    }
    fout.close();
}
