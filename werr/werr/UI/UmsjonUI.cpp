//
//  UmsjonUI.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "UmsjonUI.hpp"
#include "Topping.hpp"
#include "Other_stuff.hpp"
#include "PizzaMenu.hpp"
#include "MenuTopp.hpp"

#include <vector>
#include <iostream>


using namespace std;

UmsjonUI::UmsjonUI() {

}

void UmsjonUI::startUI () {
    char select = '\0';
    cout << "===================================" << endl;
    cout << "What do you want to add?" << endl;
    cout << "===================================" << endl;

    cout << "T: Toppings" << "     | O: Other products" << endl;
    cout << "-----------------------------------" << endl;
    cout << "P: Pizza Menu " << "  | B: Base and size" << endl;
    cout << "-----------------------------------" << endl;
    cout << "L: Pizza places |" << endl;
    cout << "===================================" << endl;

    cin >> select;

    if (select == 't' || select == 'T') {
        vector<Topping> toppings = topprepo.retriveAllToppings();

        cout << "These are the current toppings in the system: " << endl;
        for (unsigned int i=0; i<toppings.size(); i++) {
            cout << "["<< i+1 << "]" << toppings[i];
        }

        char select = 'y';
        Topping topping;
        while(select == 'y') {
            cout << endl;

            cout << "Add another topping (y/n)? ";
            cin >> select;
            if (select == 'y') {
                cin >> topping;
                toppings.push_back(topping);
            }
        }
        topprepo.storeAllToppings(toppings);

    }
    else if(select == 'o' || select == 'O'){
        vector<Other_stuff> other_stuff = stuffrepo.retriveAllOtherStuff();

        cout << "These are the current items in the system: " << endl;
        for (unsigned int i = 0; i < other_stuff.size(); i++) {
            cout << "[" << i+1 << "]" << other_stuff[i];
        }

        char select = 'y';
        Other_stuff otherStuff;
        while(select == 'y') {
            cout << endl;

            cout << "Add another item (y/n)? ";
            cin >> select;
            if (select == 'y') {
                cin >> otherStuff;
                other_stuff.push_back(otherStuff);
            }
        }
        stuffrepo.storeAllOtherStuff(other_stuff);
    }
/*/    else if (select == 'p') {
        vector<MenuTopp> menuTopp = menurepo.retrivePizzaMenu();

        cout << "These are the current items on the menu: " << endl;
        for (unsigned int i = 0; i < pizzaMenu.size(); i++) {
            cout << "[" << i+1 << "]" << pizzaMenu[i];
        }

        char select = 'y';
        MenuTopp menutopp;
        while(select == 'y') {
            cout << endl;

            cout << "Add another item (y/n)? ";
            cin >> select;
            if (select == 'y') {
                cin >> menutopp;
                pizzaMenu.push_back(pizzamenu);
            }
        }
        menurepo.storePizzaMenu(pizzaMenu);

    }
 /*/
    else if (select == 'b' || select == 'B') {
        vector<PizzaType> pizzaType = typerepo.retrivePizaType();
        
        cout << "These are the current items in the system: " << endl;
        for (unsigned int i = 0; i < pizzaType.size(); i++) {
            cout << "[" << i+1 << "]" << pizzaType[i];
        }
        
        char select = 'y';
        PizzaType pizzatype;
        while(select == 'y') {
            cout << endl;
            
            cout << "Add another item (y/n)? ";
            cin >> select;
            if (select == 'y') {
                cin >> pizzatype;
                pizzaType.push_back(pizzatype);
            }
        }
        typerepo.storePizzaType(pizzaType);
    }
    
    else if (select == 'l' || select == 'L') {
        vector<PizzaPlace> pizzaPlace = placerepo.retrivePizzPlace();
        
        cout << "These are the current Pizza Places in the system: " << endl;
        for (unsigned int i = 0; i < pizzaPlace.size(); i++) {
            cout << "[" << i+1 << "]" << pizzaPlace[i];
        }
        
        char select = 'y';
        PizzaPlace pizzaplace;
        while(select == 'y') {
            cout << endl;
            
            cout << "Add another item (y/n)? ";
            cin >> select;
            if (select == 'y') {
                cin >> pizzaplace;
                pizzaPlace.push_back(pizzaplace);
            }
        }
        placerepo.storePizzaPlace(pizzaPlace);
    }
}

