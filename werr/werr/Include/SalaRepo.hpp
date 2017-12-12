//
//  SalaRepo.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef SalaRepo_hpp
#define SalaRepo_hpp

#include "Pizza.hpp"
class FileNotFoundException{};
class SalaRepo {
private:
    
public:
    SalaRepo();
    
    void storePizza(const Pizza& pizza);
    Pizza retrievePizza();
    Topping retrieveprice();
};

#endif /* SalaRepo_hpp */
