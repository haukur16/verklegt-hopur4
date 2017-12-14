//
//  OtherOrder.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 13/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef OtherOrder_hpp
#define OtherOrder_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Other_stuff.hpp"
#include "PizzaPlace.hpp"
using namespace std;
class OtherOrder {
public:
    OtherOrder();
    void addOtherStuff(Other_stuff otherStuff);
    void addPlace(PizzaPlace pizzaplace);
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >> (istream& in, OtherOrder& order);
    friend ostream& operator << (ostream& out, const OtherOrder& order);
    vector<Other_stuff> othStuff();
    vector<PizzaPlace> pizzaPlace();
private:
    vector<Other_stuff> other_stuff;
    vector<PizzaPlace> pizzaPLace;
};
#endif /* OtherOrder_hpp */
