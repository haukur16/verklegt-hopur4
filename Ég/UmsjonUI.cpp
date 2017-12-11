//
//  UmsjonUI.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "UmsjonUI.hpp"
#include "ServiceUmsjon.hpp"

#include <vector>
#include <iostream>


using namespace std;

UmsjonUI::UmsjonUI() {

}

void UmsjonUI::startUI () {
    char select = '\0';

    cout << "t: add toppings" << endl;
    cout << endl;

    cin >> select;

    if (select == 't' || select == 'T') {
        vector<ServiceUmsjon> toppings = topprepo.retriveAllToppings();

        cout << "These are the current toppings in the system: " << endl;
        for (unsigned int i=0; i<toppings.size(); i++) {
            cout << "["<< i+1 << "]" << toppings[i];
        }

        char select = 'y';
        ServiceUmsjon topping;
        while(select == 'y') {
            cout << endl;
            cout << "Add another topping (y/n)? ";
            cin >> select;
            if (select == 'y' || select == 'Y') {
                cin >> topping;
                toppings.push_back(topping);
            }
        }
        topprepo.storeAllToppings(toppings);

    }
}
