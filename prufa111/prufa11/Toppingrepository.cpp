//
//  Toppingrepository.cpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 02/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//
#include <fstream>
#include <vector>
#include "Toppingrepository.hpp"
using namespace std;

ToppingRepository::ToppingRepository() {
    
}

void ToppingRepository::storeAllToppings(const vector<Topping> &toppings) {
    ofstream fout;
    fout.open("toppings.bin", ios::binary);
    
    int toppingcount = toppings.size();
    
    fout.write((char*)(&toppingcount), sizeof(int));
    
    for (int i=0; i<toppingcount; i++) {
        toppings[i].write(fout);
    }
    fout.close();
}

vector<Topping> ToppingRepository::retriveAllToppings() {
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
