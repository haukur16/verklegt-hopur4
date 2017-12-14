//
//  SalaRepo.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "SalaRepo.hpp"
#include <fstream>
#include <iostream>
using namespace std;

SalaRepo::SalaRepo() {

}

void SalaRepo::storePizza(const Pizza& pizza) {
    ofstream fout;
    fout.open("pizza.bin", ios::binary);

    pizza.write(fout);
    cout << endl;

    fout.close();
}

Pizza SalaRepo::retrievePizza() {
    ifstream fin;

    fin.open("pizza.bin", ios::binary);

    if (fin.is_open()) {
        Pizza pizza;

        pizza.read(fin);
        fin.close();

        return pizza;
    }
    throw FileNotFoundException();
}

void SalaRepo::storeOther(const OtherOrder& other) {
    ofstream fout;
    fout.open("other_order.bin", ios::binary);
    
    other.write(fout);
    cout << endl;
    fout.close();
}

OtherOrder SalaRepo::retrieveOther() {
    ifstream fin;
    
    fin.open("other_order.bin", ios::binary);
    
    if (fin.is_open()) {
        OtherOrder order;
        
        order.read(fin);
        fin.close();
        
        return order;
    }
    throw FileNotFoundException();
}

