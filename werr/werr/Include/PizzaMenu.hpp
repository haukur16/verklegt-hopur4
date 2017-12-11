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
    string toppings;
public:
    PizzaMenu();
    void setname(string name);
    string getname();
    void setprice(double price);
    double getprice();
    void settoppings(string toppings);
    string gettoppings();
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >>(istream& in, PizzaMenu& menu);
    friend ostream& operator << (ostream& out, const PizzaMenu& menu);
    
};

#endif /* PizzaMenu_hpp */
