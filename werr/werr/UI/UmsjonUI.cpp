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

#include <vector>
#include <iostream>


using namespace std;

UmsjonUI::UmsjonUI() {

}

void UmsjonUI::startUI () {
    char select = '\0';

    cout << "t: add toppings" << endl;
    cout << "o: add other products" << endl;
    cout << "p: add to Pizza Menu " << endl;

    cin >> select;

    if (select == 't') {
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
    else if(select == 'o'){
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
    else if (select == 'p') {
        vector<PizzaMenu> pizzaMenu = menurepo.retrivePizzaMenu();

        cout << "These are the current items on the menu: " << endl;
        for (unsigned int i = 0; i < pizzaMenu.size(); i++) {
            cout << "[" << i+1 << "]" << pizzaMenu[i];
        }

        char select = 'y';
        PizzaMenu pizzamenu;
        while(select == 'y') {
            cout << endl;

            cout << "Add another item (y/n)? ";
            cin >> select;
            if (select == 'y') {
                cin >> pizzamenu;
                pizzaMenu.push_back(pizzamenu);
            }
        }
        menurepo.storePizzaMenu(pizzaMenu);


    }
}

