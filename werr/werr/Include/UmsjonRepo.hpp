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
#include "PizzaMenu.hpp"
#include "PizzaType.hpp"
#include "PizzaPlace.hpp"
#include "Comment.hpp"

using namespace std;

class UmsjonRepo
{
public:
    UmsjonRepo();
    void storeAllToppings(const vector<Topping> &toppings);
    vector<Topping> retriveAllToppings();
    vector<Other_stuff> retriveAllOtherStuff();
    void storeAllOtherStuff(const vector<Other_stuff> &other_stuff);
    void storePizzaMenu(const vector<PizzaMenu> &pizzaMenu);
    vector<PizzaMenu> retrivePizzaMenu();
    vector<PizzaType> retrivePizaType();
    void storePizzaType(const vector<PizzaType> &pizzaType);
    vector<PizzaPlace> retrivePizzPlace();
    void storePizzaPlace(const vector<PizzaPlace> &pizzaPlace);
    vector<Comment> retriveComment();
    void storeComment(const vector<Comment> &commeNT);
private:

};

#endif /* UmsjonRepo_hpp */
