//
//  Pizza.hpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 02/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef Pizza_hpp
#define Pizza_hpp

#include <iostream>
#include <vector>

using namespace std;
#include "Topping.hpp"

class Pizza {
private:
    vector<Topping> toppings;
public:
    Pizza();
    
    void addTopping(Topping topping);
    
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    
    friend istream& operator >> (istream& in, Pizza& pizza);
    friend ostream& operator << (ostream& out, const Pizza& pizza);
};
#endif /* Pizza_hpp */
