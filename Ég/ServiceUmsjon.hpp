//
//  ServiceUmsjon.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef ServiceUmsjon_hpp
#define ServiceUmsjon_hpp

#include <iostream>
#include <vector>

using namespace std;

class ServiceUmsjon {
private:
    string topping_name;
    double toppingprice;
    
public:
    ServiceUmsjon();
    ServiceUmsjon(string toppings, double toppingprice);
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >>(istream& in, ServiceUmsjon& topp);
    friend ostream& operator << (ostream& out, const ServiceUmsjon& topp);
    
};

#endif /* ServiceUmsjon_hpp */
