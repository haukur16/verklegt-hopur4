#include "Other_stuff.hpp"
#include <fstream>
#include <iostream>

Other_stuff::Other_stuff()
{

}

void Other_stuff::setname(string n){
    n = name;
}

string Other_stuff::getname(){
    return this -> name;
}

void Other_stuff::setprice(double p){
    p = price;
}

double Other_stuff::getprice(){
    return this -> price;
}

void Other_stuff::write(ofstream& fout) const {
    int stringlength = name.length() +1;

    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(name.c_str(), stringlength);

    fout.write((char*)(&price), sizeof(double));
}

void Other_stuff::read(ifstream& fin) {
    int stringlength;

    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];

    fin.read(str, stringlength);

    name = str;

    fin.read((char*)(&price), sizeof(double));

    delete [] str;
}

istream& operator >>(istream& in, Other_stuff& stuff) {
    cout << "Input item: ";
    in >> stuff.name;
    cout << "Input price of item: ";
    in >> stuff.price;

    return in;
}

ostream& operator << (ostream& out, const Other_stuff& stuff) {
    out << stuff.name << " " << stuff.price << endl;
    return out;
}
