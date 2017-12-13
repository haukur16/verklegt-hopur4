//
//  MenuTopp.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 12/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef MenuTopp_hpp
#define MenuTopp_hpp

#include <stdio.h>
#include <string>
using namespace std;

class MenuTopp {
public:
    MenuTopp();
    void setname(string topp);
    string getname();
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >>(istream& in, MenuTopp& toppi);
    friend ostream& operator << (ostream& out, const MenuTopp& toppi);
private:
    string topp;
};
#endif /* MenuTopp_hpp */
