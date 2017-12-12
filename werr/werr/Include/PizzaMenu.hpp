//
//  PizzaMenu.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 11/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef PizzaMenu_hpp
#define PizzaMenu_hpp

#include <stdio.h>
#include <string>
using namespace std;
class PizzaMenu {
private:
    string name;
    double price;
    string pizzaTopp;
    
public:
    PizzaMenu();
    PizzaMenu(string name, double price, string pizzaTopp);
    string getname();
    double getprice();
    string gettopping();
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >> (istream& in, PizzaMenu& menu);
    friend ostream& operator << (ostream& out, const PizzaMenu& menu);
    
};

#endif /* PizzaMenu_hpp */
