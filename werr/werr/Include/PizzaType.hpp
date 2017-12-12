//
//  PizzaType.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 09/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef PizzaType_hpp
#define PizzaType_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class PizzaType {
private:
    string base;
    int size;
    double price;
public:
    PizzaType();
    void setbase(string base);
    string getbase();
    void setsize(int size);
    int getsize();
    void setprice(double price);
    double getprice();
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >>(istream& in, PizzaType& type);
    friend ostream& operator << (ostream& out, const PizzaType& type);

};
#endif /* PizzaType_hpp */
