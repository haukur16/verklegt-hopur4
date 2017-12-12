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
        cout << "M - Manager" << endl;
        cout << "S - Salesman" << endl;
        cout << "B - Baker" << endl;
        cout << "D - Delivery " << endl;
        cout << "Q - quit" << endl;

        cin >> select;

        UmsjonUI umsjonui;
        SalaUI salaui;
        switch (select) {
            case 'm':
                umsjonui.startUI();
                cout << endl;
                break;
            case 's':
                salaui.startUI();
                cout << endl;
                break;
            case 'b':
                cout << "vantar" << endl;
                break;
            case 'd':
                cout << "vantar" << endl;
                break;
            default:
                break;
        }
    }
}
