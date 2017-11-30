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
#include "InputPizza.hpp"
using namespace std;

int many_toppings(string part1, double num1, int num);
void makepizza (string part1, double num1, int num);

int main() {
    
    int pick;
    cout << "1 - price of basepizza " << endl;
    cout << "2 - input topping" << endl;
    cout << "3 - make order" << endl;
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

    if (pick == 3) {
        string part1;
        int num = 0;
        double num1 = 0;
        many_toppings(part1, num1, num);
        makepizza(part1, num1, num);
    }
    return 0;

}
int many_toppings(string part1, double num1, int num) {
    ifstream file;
    file.open( "text_file_Pizza.txt", ios::in );
    
    if( !file )
        cerr << "Cant open " << endl;
    
    while( file >> num >> part1 >> num1)
    {
        cout << num << " " << part1 << endl;
    }
    
    file.close();
return 0;
}

void makepizza (string part1, double num1, int num) {
    ifstream file;
    file.open( "text_file_Pizza.txt", ios::in );

    if( !file )
        cerr << "Cant open " << endl;
    int toppings = 0;
    double price = 65;
    int many;
    cout << "how many toppings" << endl;
    cin >> many;
    for (int i = 0; i<many; i++) {
        cout << "What toppings: " << endl;
        cin >> toppings;
    while(file >> num >> part1 >> num1)
    {
        if (toppings == num) {
            price += num1;
    }
    }
    }
    cout << "Price: " << price;
    file.close();


}
