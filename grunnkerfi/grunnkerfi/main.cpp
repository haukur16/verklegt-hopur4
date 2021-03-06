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





int main(int argc, const char * argv[]) {
    
    int pick;
    cout << "1 - price of basepizza " << endl;
    cout << "2 - input topping" << endl;
    cin >> pick;
    
    
    if (pick == 1) {
    ifstream fin;
    int baseprice = 0;
        cout << "Enter price of base pizza: ";
        cin >> baseprice;
        ofstream fout;
        fout.open("text_file_Pizza.txt", ios::app);
        fout << baseprice << endl;
        fout.close();
    }
    
    if (pick == 2) {
    Pizza pizza1;
    cin >> pizza1;
    
    ofstream fout;
        fout.open("text_file_Pizza.txt", ios::app);
    fout << pizza1;
    fout.close();
    }
    
    return 0;
}
