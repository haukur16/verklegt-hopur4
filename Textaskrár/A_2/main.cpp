#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout;
    string str;
    fout.open("TextFile.txt", ios::app);

    do
    {
        cin >> str;
        if(str[0] == '\\')
        {
            return 0;
        }
        fout << str << endl;
    }
    while(str[0] != '\\');
    return 0;
}
