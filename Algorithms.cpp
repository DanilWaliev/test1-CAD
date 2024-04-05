#include "Algorithms.h"

// need to finish !!!!!
void FileInput(std::vector<Employee> &company)
{
    std::string inputString;

    while (true)
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

void ConsoleInput(std::vector<Employee> &company)
{
    std::string inputString;

    while (true)
    {
        getline(std::cin, inputString);

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

