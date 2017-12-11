//
//  UmsjonRepo.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef UmsjonRepo_hpp
#define UmsjonRepo_hpp

#include <vector>
#include "Topping.hpp"
#include "Other_stuff.hpp"

using namespace std;

class UmsjonRepo
{
public:
    UmsjonRepo();
    void storeAllToppings(const vector<Topping> &toppings);
    vector<Topping> retriveAllToppings();
    vector<Other_stuff> retriveAllOtherStuff();
    void storeAllOtherStuff(const vector<Other_stuff> &other_stuff);
private:

};

#endif /* UmsjonRepo_hpp */
