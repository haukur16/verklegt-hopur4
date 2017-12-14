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
#include <iostream>
using namespace std;

UmsjonRepo::UmsjonRepo() {

}

void UmsjonRepo::storeAllToppings(const vector<Topping> &toppings) {
    ofstream fout;
    fout.open("topping.bin", ios::binary);

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
    fin.open("topping.bin", ios::binary);
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
        cout << endl;
    }
    fout.close();
}

void UmsjonRepo::storePizzaMenu(const vector<PizzaMenu> &pizzaMenu) {
    ofstream fout;
    fout.open("pizza_menu.bin", ios::binary);
    
    int pizzaMenucount = pizzaMenu.size();
    
    fout.write((char*)(&pizzaMenucount), sizeof(int));
    
    for (int i=0; i<pizzaMenucount; i++) {
        pizzaMenu[i].write(fout);
    }
    fout.close();
}

vector<PizzaMenu> UmsjonRepo::retrivePizzaMenu() {
    vector<PizzaMenu> pizzaMenu;
    PizzaMenu pizzamenu;
    ifstream fin;
    fin.open("pizza_menu.bin", ios::binary);
    
    if(fin.is_open()) {
        int menuToppcount;
        
        fin.read((char*)(&menuToppcount), sizeof(int));
        
        for (int i=0; i<menuToppcount; i++) {
            pizzamenu.read(fin);
            pizzaMenu.push_back(pizzamenu);
        }
        fin.close();
    }
    return pizzaMenu;
}


vector<PizzaType> UmsjonRepo::retrivePizaType() {
    vector<PizzaType> pizzaType;
    PizzaType pizzatype;
    ifstream fin;
    fin.open("pizza_type.bin", ios::binary);
    
    if(fin.is_open()) {
        int pizzaTypecount;
        
        fin.read((char*)(&pizzaTypecount), sizeof(int));
        
        for (int i=0; i<pizzaTypecount; i++) {
            pizzatype.read(fin);
            pizzaType.push_back(pizzatype);
        }
        fin.close();
    }
    return pizzaType;
}
void UmsjonRepo::storePizzaType(const vector<PizzaType> &pizzaType) {
    ofstream fout;
    fout.open("pizza_type.bin", ios::binary);
    
    int pizzaTypecount = pizzaType.size();
    
    fout.write((char*)(&pizzaTypecount), sizeof(int));
    
    for (int i=0; i<pizzaTypecount; i++) {
        pizzaType[i].write(fout);
    }
    fout.close();
}
vector<PizzaPlace> UmsjonRepo::retrivePizzPlace() {
    vector<PizzaPlace> pizzaPlace;
    PizzaPlace pizzaplace;
    ifstream fin;
    fin.open("pizza_place.bin", ios::binary);
    
    if(fin.is_open()) {
        int pizzaPlacecount;
        
        fin.read((char*)(&pizzaPlacecount), sizeof(int));
        
        for (int i=0; i<pizzaPlacecount; i++) {
            pizzaplace.read(fin);
            pizzaPlace.push_back(pizzaplace);
        }
        fin.close();
    }
    return pizzaPlace;
}
void UmsjonRepo::storePizzaPlace(const vector<PizzaPlace> &pizzaPlace) {
    ofstream fout;
    fout.open("pizza_place.bin", ios::binary);
    
    int pizzaPlacecount = pizzaPlace.size();
    
    fout.write((char*)(&pizzaPlacecount), sizeof(int));
    cout << endl;
    
    for (int i=0; i<pizzaPlacecount; i++) {
        pizzaPlace[i].write(fout);
        cout << endl;
    }
    fout.close();
}
