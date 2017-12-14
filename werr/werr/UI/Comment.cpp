//
//  Comment.cpp
//  werr
//
//  Created by Haukur Guðmundsson on 14/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#include "Comment.hpp"
#include <fstream>
#include <iostream>
Comment::Comment() {
    
}
void Comment::setWord(string w) {
    word = w;
}
string Comment::getWord() {
    return this ->word;
}

void Comment::write(ofstream& fout) const {
    int stringlength = word.length() +1;
    
    fout.write((char*)(&stringlength), sizeof(int));
    fout.write(word.c_str(), stringlength);
}
void Comment::read(ifstream& fin) {
    int stringlength;
    
    fin.read((char*)(&stringlength), sizeof(int));
    char *str = new char[stringlength];
    
    fin.read(str, stringlength);
    
    word = str;
    
    delete [] str;
}

istream& operator >>(istream& in, Comment& comment) {
    in >> comment.word;
    return in;
}
ostream& operator << (ostream& out, const Comment& comment) {
    out << comment.word << " ";
    return out;
}
