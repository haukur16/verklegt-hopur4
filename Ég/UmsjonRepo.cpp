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

void UmsjonRepo::storeAllToppings(const vector<ServiceUmsjon> &toppings) {
    ofstream fout;
    fout.open("toppings.bin", ios::binary);
    
    int toppingcount = toppings.size();
    
    fout.write((char*)(&toppingcount), sizeof(int));
    
    for (int i=0; i<toppingcount; i++) {
        toppings[i].write(fout);
    }
    fout.close();
}

vector<ServiceUmsjon> UmsjonRepo::retriveAllToppings() {
    vector<ServiceUmsjon> toppings;
    ServiceUmsjon topping;
    
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
