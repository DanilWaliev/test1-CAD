#include <iostream>
#include <string>
#include "employee.h"
#include "Interface.h"

int main()
{
    setlocale(LC_CTYPE, "Russian");
   
    ShowInfo();

    //testInput();

    double a = 0;
    a = GetDouble();

    std::cout << "Введенное число: " << a << std::endl;
}


