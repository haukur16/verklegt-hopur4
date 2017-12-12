//
//  Pizza.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 08/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef Pizza_hpp
#define Pizza_hpp

#include <vector>
#include <iostream>
#include "Topping.hpp"
#include "Other_stuff.hpp"
#include "PizzaType.hpp"
using namespace std;

class Pizza {
public:
    Pizza();
    void addTopping(Topping topping);
    void addOtherStuff(Other_stuff otherStuff);
    void addType(PizzaType pizzaType);
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >> (istream& in, Pizza& pizza);
    friend ostream& operator << (ostream& out, const Pizza& pizza);
    vector<Topping> getTopping();
    vector<PizzaType> getType();
    vector<Other_stuff> othStuff();
private:
    vector<Other_stuff> other_stuff;
    vector<PizzaType> pizzaType;
    vector<Topping> toppings;
    friend class Pizza;
    
    friend class Topping;
};
#endif /* Pizza_hpp */
