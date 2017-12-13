//
//  TotalPrice.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 12/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef TotalPrice_hpp
#define TotalPrice_hpp

#include <stdio.h>
#include "Pizza.hpp"
#include "OtherOrder.hpp"
#include "PizzaType.hpp"
using namespace std;
class TotalPrice {
public:
    TotalPrice();
    double toppingPrice(Pizza& pizza);
    double typePrice(Pizza& type);
    double otherPrice(OtherOrder& other);
private:
};

#endif /* TotalPrice_hpp */
