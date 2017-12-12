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
using namespace std;

class Pizza {
public:
    Pizza();
    void setTotal(double total);
    double getname();
    void addTopping(Topping topping);
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >> (istream& in, Pizza& pizza);
    friend ostream& operator << (ostream& out, const Pizza& pizza);
private:
    vector<Topping> toppings;
    friend class Pizza;
    double total;
    
};
#endif /* Pizza_hpp */
