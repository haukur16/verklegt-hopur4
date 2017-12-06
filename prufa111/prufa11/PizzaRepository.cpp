//
//  PizzaRepository.cpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 02/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include <fstream>
#include "PizzaRepository.hpp"
#include "Pizza.hpp"
using namespace std;

PizzaRepository::PizzaRepository() {
    
}

void PizzaRepository::storePizza(const Pizza& pizza) {
    ofstream fout;
    fout.open("pizza.bin", ios::binary);
    
    pizza.write(fout);
    
    fout.close();
}

Pizza PizzaRepository::retrievePizza() {
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
