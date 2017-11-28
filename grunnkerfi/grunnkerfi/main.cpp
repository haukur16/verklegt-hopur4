//
//  main.cpp
//  grunnkerfi
//
//  Created by Haukur Guðmundsson on 28/11/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pizza {
private:
    string topping;
    double toppingprice;
    double baseprice;
    
    
public:
    Pizza() {
        topping = ' ';
        toppingprice = 0.0;
        baseprice = 0.0;
    }
    
    
friend istream& operator >>(istream& in, Pizza& pizza) {
    cout << "Input price of base pizza: ";
    in >> pizza.baseprice;
        
        return in;
    }
friend ostream& operator << (ostream& out, const Pizza& pizza) {
    out << "Baseprice: " << pizza.baseprice;
    return out;
    }
};



int main(int argc, const char * argv[]) {
    
    int pick;
    cout << "1 - price of basepizza " << endl;
    cout << "2 - input topping" << endl;
    cin >> pick;
    
    if (pick == 1) {
    Pizza pizza1;
    cin >> pizza1;
    
    ofstream fout;
    fout.open("text_file_Pizza.txt");
    fout << pizza1;
    fout.close();
    
    Pizza pizza2;
    
    ifstream fin;
    fin.open("text_file_Pizza.txt");
    if(fin.is_open()) {
        fin >> pizza2;
    }
    else{
        cout << "cant open file";
    }
    fin.close();
        
    }
    
    
    return 0;
}
