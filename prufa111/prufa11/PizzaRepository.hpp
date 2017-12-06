//
//  PizzaRepository.hpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 02/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef PizzaRepository_hpp
#define PizzaRepository_hpp

#include "Pizza.hpp"
class FileNotFoundException{};
class PizzaRepository {
private:

public:
    PizzaRepository();
    
    void storePizza(const Pizza& pizza);
    Pizza retrievePizza();
};
#endif /* PizzaRepository_hpp */
