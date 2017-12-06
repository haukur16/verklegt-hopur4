//
//  Toppingrepository.hpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 02/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef Toppingrepository_hpp
#define Toppingrepository_hpp

#include <vector>
#include "Topping.hpp"

using namespace std;
#include <stdio.h>

class ToppingRepository
{
public:
    ToppingRepository();
    void storeAllToppings(const vector<Topping> &toppings);
    vector<Topping> retriveAllToppings();
private:
    
};

#endif /* Toppingrepository_hpp */
