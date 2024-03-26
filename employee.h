#pragma once

#include <string>
#include <sstream>
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
        std::string position, int entryYear, double salary);

    Employee(std::string inputString);

    Employee(void);

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

