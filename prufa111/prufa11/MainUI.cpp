//
//  MainUI.cpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 01/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "MainUI.hpp"
#include "PizzaUI.hpp"
using namespace std;

MainUI::MainUI() {
    
}

void MainUI::startUI() {
    char select = '\0';
    
    while(select != 'q') {
        cout << "p - Pizza" << endl;
        cout << "q - quit" << endl;
        
        cin >> select;
        
        PizzaUI pizzaui;
        switch (select) {
            case 'p':
                pizzaui.startUI();
                cout << endl;
                break;
                
            default:
                break;
        }
    }
}
