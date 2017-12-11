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
#include "ServiceUmsjon.hpp"
#include "ServiceSala.hpp"

using namespace std;

SalaUI::SalaUI() {

}

void SalaUI::startUI() {
    char select = '\0';

    cout << "m: make pizza" << endl;
    cout << "r: read pizza" << endl;
    cout << endl;

    cin >> select;

    if (select == 'm') {
        vector<ServiceUmsjon> toppings = topprepo.retriveAllToppings();

        ServiceSala pizza;

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
            ServiceSala pizza = pizzarepo.retrievePizza();
            cout << pizza; // kemur villa ef ég tek út &

            cout << endl;
        }
        catch (FileNotFoundException e){
            cout << "Pizza file not found" << endl;
        }
    }
}
