//
//  ServiceSala.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 06/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef ServiceSala_hpp
#define ServiceSala_hpp

#include <iostream>
#include <vector>

using namespace std;
#include "ServiceUmsjon.hpp"

class ServiceSala {
private:
    vector<ServiceUmsjon> toppings;
public:
    ServiceSala();
    
    void addTopping(ServiceUmsjon topping);
    
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    
    friend ifstream& operator >> (ifstream& in, ServiceSala& pizza);
    friend ofstream& operator << (ofstream& out, const ServiceSala& pizza);
};
#endif /* ServiceSala_hpp */
