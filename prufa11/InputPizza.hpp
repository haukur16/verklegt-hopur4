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

class Pizza {
private:
    double baseprice;
    string topping;
    double toppingprice;
    
public:
    Pizza();
    friend istream& operator >>(istream& in, Pizza& topp);
    friend ostream& operator << (ostream& out, const Pizza& topp);
    
};

#endif /* InputPizza_hpp */
