//
//  SalaUI.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef SalaUI_hpp
#define SalaUI_hpp
#include "UmsjonRepo.hpp"
#include "SalaRepo.hpp"
class SalaUI {
private:
    UmsjonRepo topprepo;
    SalaRepo pizzarepo;
    UmsjonRepo stuffrepo;
public:
    SalaUI();
    void startUI();
};
#endif /* SalaUI_hpp */
