#include <iostream>
#include "MainUI.hpp"
#include "UmsjonUi.hpp"
#include "SalaUI.hpp"
using namespace std;

MainUI::MainUI() {

}

void MainUI::startUI() {
    char select = '\0';

    while(select != 'q') {
        cout << "==========================" << endl;
        cout << "What are you? " << endl;
        cout << "==========================" << endl;
        cout << "M - Manager" << "| S - Salesman" << endl;
        cout << "--------------------------" << endl;
        cout << "B - Baker" << "  | D - Delivery " << endl;
        cout << "--------------------------" << endl;
        cout << "Q - quit   |" << endl;
        cout << "==========================" << endl;

        char select;
        cin >> select;

        UmsjonUI umsjonui;
        SalaUI salaui;
        switch (select) {
            case 'm': case 'M':
                umsjonui.startUI();
                cout << endl;
                break;
            case 's': case 'S':
                salaui.startUI();
                cout << endl;
                break;
            case 'b': case 'B':
                cout << "vantar" << endl;
                break;
            case 'd': case 'D':
                cout << "vantar" << endl;
                break;

            default:
                break;
        }
    }
}
