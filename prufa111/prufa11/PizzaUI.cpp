//
//  PizzaUI.cpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 02/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//
#include <vector>
#include <iostream>
#include <fstream>
#include "PizzaUI.hpp"
#include "Topping.hpp"
#include "Pizza.hpp"

using namespace std;

PizzaUI::PizzaUI() {
    
}

void PizzaUI::startUI () {
    char select = '\0';
    
    cout << "m: make pizza" << endl;
    cout << "r: read pizza" << endl;
    cout << "t: add toppings" << endl;
    
    cin >> select;
    
    if (select == 'm') {
        vector<Topping> toppings = topprepo.retriveAllToppings();
        
        Pizza pizza;
        
        int toppingselection = -1;
        while (toppingselection != 0) {
            cout << "Please enter ID for toppings to add (0 for no more)" << endl;
            for (unsigned int i=0; i<toppings.size(); i++) {
                cout << "[" << i+1 << "]" << toppings[i];
            }
            cin >> toppingselection;
            
            if (toppingselection > 0 && toppingselection <= (int)toppings.size()) {
                pizza.addTopping(toppings[toppingselection - 1]);
            }
        }
        
        pizzarepo.storePizza(pizza);
        cout << endl;
    }
    
    else if(select == 'r') {
        try {
            Pizza pizza = pizzarepo.retrievePizza();
            cout << pizza;

            cout << endl;
        }
        catch (FileNotFoundException e){
            cout << "Pizza file not found" << endl;
        }
    }
    
    else if (select == 't') {
        vector<Topping> toppings = topprepo.retriveAllToppings();
        
        cout << "These are the current toppings int the system: " << endl;
        for (unsigned int i=0; i<toppings.size(); i++) {
            cout << "["<< i+1 << "]" << toppings[i];
        }
        
        char select = 'y';
        Topping topping;
        while(select == 'y') {
            cout << endl;
            
            cout << "Add another topping (y)? ";
            cin >> select;
            if (select == 'y') {
                cin >> topping;
                toppings.push_back(topping);
            }
        }
        topprepo.storeAllToppings(toppings);
        
    }
}
