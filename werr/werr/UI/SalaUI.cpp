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
#include "OtherOrder.hpp"
#include "Other_stuff.hpp"
#include "TotalPrice.hpp"
#include "PizzaPlace.hpp"
#include "Comment.hpp"
using namespace std;

SalaUI::SalaUI() {

}

void SalaUI::startUI() {
    char select = '\0';
    cout << "========================" << endl;
    cout << "What do you want to do? " << endl;
    cout << "========================" << endl;
    cout << "M: Make order" << endl;
    cout << "------------------------" << endl;
    cout << "R: Read order" << endl;
    cout << "========================" << endl;

    cin >> select;

    if (select == 'm'|| select == 'M') {
        vector<Topping> toppings = topprepo.retriveAllToppings();
        vector<Other_stuff> other_stuff = stuffrepo.retriveAllOtherStuff();
        vector<PizzaType> pizzatype = typerepo.retrivePizaType();
        vector<PizzaPlace> pizzaplace = placerepo.retrivePizzPlace();
        vector<Comment> comment = commentrepo.retriveComment();
        Pizza pizza;
        OtherOrder order;
        int toppingselection = -1;
        int otherStuffSelection = -1;
        int pizzaTypeSelection = -1;
        int pizzaPlaceSelection = -1;
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
                while (true) {
                    cin >> pizzaTypeSelection;
            if (pizzaTypeSelection > 0 && pizzaTypeSelection <= (int)pizzatype.size()) {
                pizza.addType(pizzatype[pizzaTypeSelection - 1]);
                break;
            }
                    
                }
        }

        while (otherStuffSelection != 0) {
            cout << "Please enter ID for other products to add (0 for no more)" << endl;
            for (unsigned int i=0; i<other_stuff.size(); i++) {
                cout << "[" << i+1 << "]" << other_stuff[i];
            }
            cin >> otherStuffSelection;
            if (otherStuffSelection > 0 && otherStuffSelection <= (int)other_stuff.size()) {
                order.addOtherStuff(other_stuff[otherStuffSelection - 1]);
            }
        }
        for (int i = 0; i<1; i++) {
            cout << "Please enter ID for pizza Pizza Place" << endl;
            for (unsigned int i=0; i<pizzaplace.size(); i++) {
                cout << "[" << i+1 << "]" << pizzaplace[i];
            }
            while (true) {
            cin >> pizzaPlaceSelection;
            if (pizzaPlaceSelection > 0 && pizzaPlaceSelection <= (int)pizzaplace.size()) {
                order.addPlace(pizzaplace[pizzaPlaceSelection - 1]);
                break;
            }
        }
        }
        for (int i = 0; i<1; i++) {
            cout << "Please enter if pizza is pickup or send" << endl;
            for (unsigned int i=0; i<1; i++) {
                while (true) {
                int picksend;
                cin >> picksend;
                    if (picksend>0 && picksend<3) {
                        order.setPickSend(picksend);
                        break;
                    }
            }
            }
        }
        for (int i = 0; i<1; i++) {
            cout << "Please enter if pizza is paid or not" << endl;
            for (unsigned int i=0; i<1; i++) {
                while (true) {
                    int ispaid;
                    cin >> ispaid;
                    if (ispaid>0 && ispaid<3) {
                        order.setIsPaid(ispaid);
                        break;
                    }
                }
            }
        }
        cout << "Write comment: input many words" << endl;
        int words;
        cin >> words;
        Comment comm;
        for (unsigned int i=0; i<words; i++) {
            cin >> comm;
            order.addComment(comm);
        }
        
        pizzarepo.storeOther(order);
        pizzarepo.storePizza(pizza);
        cout << endl;
  }

        else if(select == 'r'|| select == 'R') {
            try {
                Pizza pizza = pizzarepo.retrievePizza();
                OtherOrder other = otherrepo.retrieveOther();
                cout << pizza;
                cout << other;
                TotalPrice price;
                double totalp = 0.0;
                double totalb = 0.0;
                totalp = price.toppingPrice(pizza);
                totalb = price.typePrice(pizza);
                cout << "========================" << endl;
                cout << "Price for pizza: " << totalp+totalb << endl;
                double totalo = 0.0;
                totalo = price.otherPrice(other);
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


