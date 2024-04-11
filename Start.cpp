#include <iostream>
#include <string>
#include <windows.h>
#include "Employee.h"
#include "Interface.h"
#include "MyFunctions.h"
#include "Algorithms.h"

enum class Menu 
{   
    Exit,
    FileInput,
    ConsoleInput,
    ShowData,
    ClearData,
    SaveAsFile,  
    FilterByWorkExperience, 
    FilterBySalary,
    FilterByPosition
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Employee> myCompany;
    std::string inputString;

    ShowInfo();
    ShowMenu();

    Menu menuChoice;

    do
    {
        menuChoice = static_cast<Menu>(GetInt("Введите пункт меню: "));

        switch (menuChoice)
        {
        case Menu::ConsoleInput:
            ConsoleInput(myCompany);
            break;
        case Menu::FileInput:
            FileInput(myCompany);
            break;
        case Menu::ShowData:
            PrintTable(myCompany, std::cout);
            break;
        case Menu::ClearData:
            ClearData(myCompany);
            break;
        case Menu::SaveAsFile:
            SaveAsFile(myCompany);
            break;
        case Menu::FilterByWorkExperience:
            FilterByWorkExperience(myCompany);
            break;
        case Menu::FilterBySalary:
            FilterBySalary(myCompany);
            break;
        case Menu::FilterByPosition:
            FilterByPosition(myCompany);
            break;
        case Menu::Exit:
            return EXIT_SUCCESS;
            break;
        default:
            std::cout << "Такого пункта в меню нет" << std::endl;
            std::cin >> inputString;
            std::cout << ToLowerCase(inputString) << std::endl;
        }

    } while (menuChoice != Menu::Exit);
}


