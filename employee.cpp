#include "employee.h"

std::vector<Employee> Employee::MakeCompany(size_t size) {
    std::vector<Employee> company(size);
    for (auto i = company.begin(); i != company.end(); i++)
    {
        *i = Employee();
    }

    return company;
}

void Employee::ShowInfo()
{
    std::cout << "Name: " << name << std::endl;
}

void Employee::SetName(std::string name)
{
    // добавить логику ввода имени
    this->name = name;
}

void Employee::SetEntryYear(int age)
{
    // добавить логику ввода года принятия на работу
    this->entryYear = entryYear;
}

void Employee::SetSalary(int salary)
{
    this->salary = salary;
}

std::string Employee::GetName(void)
{
    return name;
}

int Employee::GetEntryYear(void)
{
    return entryYear;
}

int Employee::GetSalary(void)
{
    return salary;
}