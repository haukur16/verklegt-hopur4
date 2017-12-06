//
//  SalaRepo.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef SalaRepo_hpp
#define SalaRepo_hpp

#include "ServiceSala.hpp"
class FileNotFoundException{};
class SalaRepo {
private:
    
public:
    SalaRepo();
    
    void storePizza(const ServiceSala& pizza);
    ServiceSala retrievePizza();
};

#endif /* SalaRepo_hpp */
