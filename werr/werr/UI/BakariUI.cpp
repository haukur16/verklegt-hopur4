#include <iostream>
#include <fstream>
#include <string>
#include "BakariUi.h"
#include "Pizza.hpp"
#include "SalaUI.hpp"
#include "TotalPrice.hpp"
using namespace std;
BakariUi:: BakariUi(){

};
char BakariUi:: get_character(){
    char a;
    cin >> a;
    return a;
    }

void BakariUi:: startUI(){
    char c;
    do{
    cout << "press 1 to view orders"<< endl;
    cout << "press 2 to work on order (bakers can only work on 1 order at a time right now) "<< endl;
    cout << "press 3 to quit"<< endl;
    cout << "press 4 to finish orders"<< endl;
     c =get_character();
    if (c == '1'){
            SalaUI sala;
                Pizza pizza = sala.pizzarepo.retrievePizza();
                cout << pizza;
                TotalPrice price;
                double totalp = 0.0;
                double totalb = 0.0;
                totalp = price.toppingPrice(pizza);
                totalb = price.typePrice(pizza);
                cout << "========================" << endl;
                cout << "Price for pizza: " << totalp+totalb << endl;
                double totalo = 0.0;
                totalo = price.otherPrice(pizza);
                cout << "Price for extra: " << totalo << endl;
                cout << "========================" << endl;
                cout << "Total price: " << totalo+totalp+totalb << endl;
                cout << endl;

    }else if (c == '2'){
        working_on();
    }else if (c == '4'){
        finish_order();
    }else {};


    }while(c != '3');
}

    void BakariUi:: working_on(){
        ofstream fout;
        fout.open("working_on.bin", ios::binary);
        pizza.write(fout);
        fout.close();
        }

    void BakariUi:: finish_order(){

        ifstream fout;
        fout.open("working_on.bin", ios::binary);
        pizza.read(fout);
        fout.close();
        ifstream fin;
        fin.open("finished_orders.bin", ios::binary);
        pizza.read(fin);
        fin.close();
  }
    void BakariUi::StartUi2(char a){
        char c;
    do{
    cout << "press 1 to view all orders"<< endl;
    cout << "press 2 to finish order"<< endl;
     c =get_character();
    if (c == '1'){
                        SalaUI sala;
                Pizza pizza = sala.pizzarepo.retrievePizza();
                cout << pizza;
                TotalPrice price;
                double totalp = 0.0;
                double totalb = 0.0;
                totalp = price.toppingPrice(pizza);
                totalb = price.typePrice(pizza);
                cout << "========================" << endl;
                cout << "Price for pizza: " << totalp+totalb << endl;
                double totalo = 0.0;
                totalo = price.otherPrice(pizza);
                cout << "Price for extra: " << totalo << endl;
                cout << "========================" << endl;
                cout << "Total price: " << totalo+totalp+totalb << endl;
                cout << endl;
    }else if (c == '2'){
        finish_order();
    }
    }while(c != 3);
    }
