//
//  SalaRepo.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "SalaRepo.hpp"
#include <fstream>
using namespace std;

SalaRepo::SalaRepo() {

}

void SalaRepo::storePizza(const Pizza& pizza) {
    ofstream fout;
    fout.open("pizza.bin", ios::binary);

    pizza.write(fout);

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

Topping SalaRepo::retrieveprice() {
    ifstream fin;
    fin.open("pizza.bin", ios::binary);
    
    if (fin.is_open()) {
        Topping price;
        
        price.read(fin);

        if (price.getprice() == true) {
            price.read(fin);
        }
        fin.close();
        return price;
    }
    throw FileNotFoundException();
}
