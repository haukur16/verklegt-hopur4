#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string str;
    ifstream fin;
    char answer;
    int counter = 0;

    fin.open("test.txt");
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            if(counter % 10 == 0 && counter != 0)
            {
                do
                {
                    cout << "Do you wish to continue (y/n)? ";
                    cin >> answer;
                    if(answer == 'y' || answer == 'Y')
                    {
                        break;
                    }
                    else if(answer == 'n' || answer == 'N')
                    {
                        return 0;
                    }
                }
                while(answer != 'y' || answer != 'Y' || answer != 'n' || answer !='N');
            }
            counter ++;
            getline(fin, str);
            cout << str << endl;
        }
        fin.close();
    }
    else
    {
        cout << "Unable to read from file" << endl;
    }
    return 0;
}
