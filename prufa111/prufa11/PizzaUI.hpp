//
//  PizzaUI.hpp
//  prufa11
//
//  Created by Haukur Guðmundsson on 02/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef PizzaUI_hpp
#define PizzaUI_hpp

#include "PizzaRepository.hpp"
#include "Toppingrepository.hpp"

class PizzaUI {
private:
    PizzaRepository pizzarepo;
    ToppingRepository topprepo;
    
public:
    PizzaUI();
    void startUI();
};
#endif /* PizzaUI_hpp */
