//
//  PizzaPlace.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 13/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef PizzaPlace_hpp
#define PizzaPlace_hpp

#include <stdio.h>
#include <string>
using namespace std;

class PizzaPlace {
private:
    string name;
    int sendPick;
public:
    PizzaPlace();
    void setname(string name);
    string getname();
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >>(istream& in, PizzaPlace& place);
    friend ostream& operator << (ostream& out, const PizzaPlace& place);
};

#endif /* PizzaPlace_hpp */
