#ifndef OTHER_STUFF_H
#define OTHER_STUFF_H

#include <stdio.h>
#include <string>

using namespace std;

class Other_stuff
{
public:
    Other_stuff();
    void setname(string name);
    string getname();
    void setprice(double price);
    double getprice();
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >>(istream& in, Other_stuff& stuff);
    friend ostream& operator << (ostream& out, const Other_stuff& stuff);

private:
    string name;
    double price;
};

#endif // OTHER_STUFF_H
