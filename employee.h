#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Algorithms.h"

// класс сотрудника
class Employee
{
private:
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string position;
    int entryYear;
    double salary;
public:
    Employee(std::string name, std::string surname, std::string patronymic,
        std::string position, int entryYear, double salary)
    {
        this->name = name;
        this->surname = surname;
        this->patronymic = patronymic;
        this->position = position;
        this->entryYear = entryYear;
        this->salary = salary;
    }

    Employee(void)
    {
        name = "Undefined";
        surname = "Undefined";
        patronymic = "Undefined";
        position = "Undefined";
        entryYear = 0;
        salary = 0.0;
    }

    void ShowInfo();

    bool SetName(std::string name);

    bool SetSurname(std::string surname);

    bool SetPatronymic(std::string patronymic);

    bool SetEntryYear(int entryYear);

    bool SetEntryYear(std::string entryYear);
    
    bool SetSalary(double salary);

    bool SetSalary(std::string salary);

    std::string GetName(void);

    int GetEntryYear(void);

    double GetSalary(void);
};

std::vector<Employee> MakeCompany(size_t size);

Employee StringToEmployee(std::string str);

