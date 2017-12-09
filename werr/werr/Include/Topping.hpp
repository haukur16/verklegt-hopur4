//
//  Topping.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 08/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef Topping_hpp
#define Topping_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Topping {
private:
    string name;
    double price;
public:
    Topping();
    void setname(string name);
    string getname();
    void setprice(double price);
    double getprice();
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >>(istream& in, Topping& topp);
    friend ostream& operator << (ostream& out, const Topping& topp);
    
};

#endif /* Topping_hpp */
