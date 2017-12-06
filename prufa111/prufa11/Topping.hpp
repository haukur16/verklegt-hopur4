//
//  InputPizza.hpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 29/11/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef InputPizza_hpp
#define InputPizza_hpp
#include <iostream>
#include <vector>

using namespace std;

class Topping {
private:
    string topping_name;
    double toppingprice;
    
public:
    Topping();
    Topping(string toppings, double toppingprice);
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >>(istream& in, Topping& topp);
    friend ostream& operator << (ostream& out, const Topping& topp);
    
};

#endif /* InputPizza_hpp */
