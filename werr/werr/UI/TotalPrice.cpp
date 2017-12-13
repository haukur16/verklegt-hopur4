//
//  TotalPrice.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 12/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "TotalPrice.hpp"

TotalPrice::TotalPrice() {
    
}

double TotalPrice::toppingPrice(Pizza& pizza) {
    double totalprice;
    for (int i=0; i<pizza.getTopping().size(); i++) {
        totalprice += pizza.getTopping()[i].getprice();
    }
    return totalprice;
}

double TotalPrice::typePrice(Pizza& type) {
    double totalpr = type.getType()[0].getprice();
    return totalpr;
}

double TotalPrice::otherPrice(OtherOrder& other) {
    double totalp;
    for (int i=0; i<other.othStuff().size(); i++) {
        totalp += other.othStuff()[i].getprice();
    }
    return totalp;
}
