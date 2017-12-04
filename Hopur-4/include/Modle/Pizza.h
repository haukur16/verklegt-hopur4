#ifndef PIZZA_H
#define PIZZA_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
class Pizza {
private:
    double baseprice;
    string topping;
    double toppingprice;


public:
    Pizza() {
        topping = ' ';
        toppingprice = 0.0;
    }


friend istream& operator >>(istream& in, Pizza& topp) {
    cout << "Input topping: ";
    in >> topp.topping;
    cout << "Input topping price: ";
    in >> topp.toppingprice;

        return in;
    }
friend ostream& operator << (ostream& out, const Pizza& topp) {
    out << topp.topping << " (" << topp.toppingprice << " kr)" << endl;
    return out;
    }



};

#endif // PIZZA_H
