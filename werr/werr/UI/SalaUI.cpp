//
//  SalaUI.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include <vector>
#include <iostream>
#include "SalaUI.hpp"
#include "Topping.hpp"
#include "Pizza.hpp"
#include "Other_stuff.hpp"
#include "TotalPrice.hpp"
using namespace std;

SalaUI::SalaUI() {

}

void SalaUI::startUI() {
    char select = '\0';

    cout << "m: make pizza" << endl;
    cout << "r: read pizza" << endl;

    cin >> select;

    if (select == 'm') {
        vector<Topping> toppings = topprepo.retriveAllToppings();
        vector<Other_stuff> other_stuff = stuffrepo.retriveAllOtherStuff();
        vector<PizzaType> pizzatype = typerepo.retrivePizaType();
        Pizza pizza;
        int toppingselection = -1;
        int otherStuffSelection = -1;
        int pizzaTypeSelection = -1;
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
        for (int i = 0; i<1; i++) {
            cout << "Please enter ID for pizza type and size (0 for no more)" << endl;
            for (unsigned int i=0; i<pizzatype.size(); i++) {
                cout << "[" << i+1 << "]" << pizzatype[i];
            }
            cin >> pizzaTypeSelection;
            if (pizzaTypeSelection > 0 && pizzaTypeSelection <= (int)pizzatype.size()) {
                pizza.addType(pizzatype[pizzaTypeSelection - 1]);
            }
        }
        while (otherStuffSelection != 0) {
            cout << "Please enter ID for other products to add (0 for no more)" << endl;
            for (unsigned int i=0; i<other_stuff.size(); i++) {
                cout << "[" << i+1 << "]" << other_stuff[i];
            }
            cin >> otherStuffSelection;
            if (otherStuffSelection > 0 && otherStuffSelection <= (int)other_stuff.size()) {
                pizza.addOtherStuff(other_stuff[otherStuffSelection - 1]);
            }
        }


        pizzarepo.storePizza(pizza);
        cout << endl;
    }
        else if(select == 'r') {
            try {
                Pizza pizza = pizzarepo.retrievePizza();
                cout << pizza;
                TotalPrice price;
                double totalp = 0.0;
                double totalb = 0.0;
                totalp = price.toppingPrice(pizza);
                totalb = price.typePrice(pizza);
                cout << "========================" << endl;
                cout << "Price for pizza: " << totalp+totalb << endl;
                double totalo = 0.0;
                totalo = price.otherPrice(pizza);
                cout << "Price for extra: " << totalo << endl;
                cout << "========================" << endl;
                cout << "Total price: " << totalo+totalp+totalb << endl;
                cout << endl;
                
            }
            catch (FileNotFoundException e){
            cout << "Pizza file not found" << endl;
        }
    }
    
}


