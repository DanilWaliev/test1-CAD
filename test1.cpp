#include <iostream>
#include <string>
#include "employee.h"
#include "Interface.h"

int main()
{
    setlocale(LC_CTYPE, "Russian");
   
    ShowInfo();

    //testInput();

    int a = 0;
    a = GetInt();

    std::cout << "Введенное число: " << a << std::endl;
}


