#ifndef BAKARIUI_H
#define BAKARIUI_H
#include "Pizza.hpp"


class BakariUi
{
    public:
    BakariUi();
    char get_character();
    void startUI();
    void working_on();
    void finish_order();
    void StartUi2(char a);
    Pizza pizza;
    private:
};

#endif // BAKARIUI_H
