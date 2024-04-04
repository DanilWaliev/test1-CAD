#include <iostream>
#include <string>
#include "Employee.h"
#include "Interface.h"
#include "Algorithms.h"

enum class Menu { Exit, FileInput, ConsoleInput };

void ConsoleInput(std::vector<Employee> &company)
{
    setlocale(LC_CTYPE, "Russian");
    std::string inputString;

    while(true)
    {
        getline(std::cin, inputString);
        std::cout << inputString << std::endl;

        if (inputString == "0") break;
         
        try
        {
            company.push_back(Employee(inputString));
        }
        catch (std::string errorMessage)
        {
            std::cout << errorMessage << std::endl;
        }

    }
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

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

            while (true)
            {
                std::getline(std::cin, inputString);
                std::cout << inputString << std::endl;

                if (inputString == "0") break;

                try
                {
                    myCompany.push_back(Employee(inputString));
                }
                catch (std::string errorMessage)
                {
                    std::cout << errorMessage << std::endl;
                }

            }

            myCompany.at(0).ShowInfo();

            break;
        case Menu::FileInput:
            std::cout << "ввод файлом" << std::endl;

            getline(std::cin, inputString);
            std::cout << inputString << std::endl;

            break;
        case Menu::Exit:
            return EXIT_SUCCESS;
            break;
        default:
            std::cout << "Такого пункта в меню нет" << std::endl;
        }

    } while (menuChoice != Menu::Exit);
}


