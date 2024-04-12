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

enum class MainMenuOptions
{
    Exit,
    Input,
    Output,
    Clear,
    Filter
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Employee> myCompany;
    std::string inputString;

    ShowInfo();
    /*ShowMenu();

    Menu menuChoice;

    while (true)
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
        }
    }*/


    MainMenuOptions mainMenuChoice;

    while (true)
    {
        ShowMainMenu();

        mainMenuChoice = static_cast<MainMenuOptions>(GetInt("Введите пункт меню: "));

        switch (mainMenuChoice)
        {
        case MainMenuOptions::Input:
            Input(myCompany);
            break;
        case MainMenuOptions::Output:
            Output(myCompany);
            break;
        case MainMenuOptions::Clear:
            ClearData(myCompany);
            break;
        case MainMenuOptions::Filter:
            Filter(myCompany);
            break;
        case MainMenuOptions::Exit:
            return EXIT_SUCCESS;
            break;
        default:
            std::cout << "Такого пункта в меню нет" << std::endl;
        }
    }
}


