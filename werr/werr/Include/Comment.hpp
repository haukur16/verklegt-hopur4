//
//  Comment.hpp
//  werr
//
//  Created by Haukur Guðmundsson on 14/12/2017.
//  Copyright © 2017 Haukur Guðmundsson. All rights reserved.
//

#ifndef Comment_hpp
#define Comment_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class Comment {
public:
    Comment();
    void setWord(string word);
    string getWord();
    void write(ofstream& fout) const;
    void read(ifstream& fin);
    friend istream& operator >>(istream& in, Comment& comment);
    friend ostream& operator << (ostream& out, const Comment& comment);
private:
    string word;
};
#endif /* Comment_hpp */

