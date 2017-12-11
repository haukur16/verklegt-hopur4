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
#include "ServiceUmsjon.hpp"

using namespace std;

class UmsjonRepo
{
public:
    UmsjonRepo();
    void storeAllToppings(const vector<ServiceUmsjon> &toppings);
    vector<ServiceUmsjon> retriveAllToppings();
private:
    
};

#endif /* UmsjonRepo_hpp */
