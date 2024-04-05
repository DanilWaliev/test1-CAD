#include "Algorithms.h"

void FileInput(std::vector<Employee>& company, std::string source)
{
    int was = company.size();
    int counter = 0;
    std::string inputString;
    std::ifstream in(source);

    while (getline(in, inputString))
    {
        counter++;

        try
        {
            company.push_back(Employee(inputString));
        }
        catch (std::string errorMessage)
        {
            std::cout << errorMessage << std::endl;
        }

    }

    std::cout << "Считано " << counter << " строк, добавлено " << company.size() - was << " сотрудников" << std::endl;

    in.close();
}

void ConsoleInput(std::vector<Employee>& company)
{
    std::cout << "Введите данные о сотрудникев через пробел в формате:" << std::endl;
    std::cout << "Имя Фамилия Отчество Должность Год(принятия на работу) Зарплата" << std::endl;
    std::cout << "0 - Закончить ввод с консоли" << std::endl;

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

void ShowData(std::vector<Employee>& company)
{
    //
}

void SaveAsFile(std::vector<Employee>& company)
{
    //
}

std::vector<Employee> FilterByWorkExperience(std::vector<Employee>& company)
{
    //
}

std::vector<Employee> FilterBySalary(std::vector<Employee>& company)
{
    //
}

std::vector<Employee> FilterByPosition(std::vector<Employee>& company)
{
    //
}