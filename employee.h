#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "MyFunctions.h"

// класс сотрудника
class Employee
{
private:
    std::string name = "Undefined";
    std::string surname = "Undefined";
    std::string patronymic = "Undefined";
    std::string position = "Undefined";
    int entryYear = 0;
    double salary = 0.0;
public:
    Employee(std::string name, std::string surname, std::string patronymic,
        std::string position, int entryYear, double salary);

    Employee(std::string inputString);

    Employee();

    void ShowInfo();

    void SetName(std::string name);

    void SetSurname(std::string surname);

    void SetPatronymic(std::string patronymic);

    void SetPosition(std::string position);

    void SetEntryYear(int entryYear);

    void SetEntryYear(std::string entryYear);
    
    void SetSalary(double salary);

    void SetSalary(std::string salary);

    std::string GetName(void);

    int GetEntryYear(void);

    double GetSalary(void);
};

//Employee StringToEmployee(std::string inputString);

std::vector<Employee> MakeCompany(size_t size);

