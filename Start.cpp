#include <iostream>
#include <string>
#include <windows.h>
#include "Employee.h"
#include "Interface.h"
#include "MyFunctions.h"
#include "Algorithms.h"

enum class Menu { Exit, FileInput, ConsoleInput };

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Employee> myCompany;
    std::string inputString;

    ShowInfo();

    Menu menuChoice;


    do
    {
        ShowMenu();
        menuChoice = static_cast<Menu>(GetInt("Введите пункт меню: "));

        switch (menuChoice)
        {
        case Menu::ConsoleInput:
            std::cout << "ввод с консоли" << std::endl;

            ConsoleInput(myCompany);

            break;
        case Menu::FileInput:
            std::cout << "ввод файлом" << std::endl;

            break;
        case Menu::Exit:
            return EXIT_SUCCESS;
            break;
        default:
            std::cout << "Такого пункта в меню нет" << std::endl;
        }

    } while (menuChoice != Menu::Exit);
}


