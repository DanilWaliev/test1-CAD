#include <iostream>
#include <string>
#include "Employee.h"
#include "Interface.h"
#include "Algorithms.h"

enum class Menu { Exit, FileInput, ConsoleInput };

int main()
{
    setlocale(LC_CTYPE, "Russian");

    Employee danil("Danil Valiev Lenarovich 2025");


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

            danil.ShowInfo();

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


