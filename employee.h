#pragma once

#include <string>
#include <iostream>
#include <vector>

class Employee
{
private:
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string position;
    int entryYear;
    int salary;
public:
    Employee(std::string name, std::string surname, std::string patronymic,
        std::string position, int entryYear, int salary)
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
        salary = 0;
    }

    // создает вектор экземл€ров класса Employee 
    static std::vector<Employee> MakeCompany(size_t size);

    void ShowInfo();

    void SetName(std::string name);

    void SetEntryYear(int age);

    void SetSalary(int salary);

    std::string GetName(void);

    int GetEntryYear(void);

    int GetSalary(void);
};

