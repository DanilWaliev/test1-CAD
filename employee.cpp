#include "employee.h"

// создает вектор экземл€ров класса Employee 
std::vector<Employee> MakeCompany(size_t size) {
    std::vector<Employee> company(size);
    for (auto i = company.begin(); i != company.end(); i++)
    {
        *i = Employee();
    }

    return company;
}

// выводит информацию о работнике
void Employee::ShowInfo()
{
    std::cout << "Name: " << name << std::endl;
}

bool Employee::SetName(std::string name)
{
    if (IsWord(name))
    {
        this->name = name;
        return true;
    }

    return false;
}

bool Employee::SetSurname(std::string surname)
{
    if (IsWord(surname))
    {
        this->surname = surname;
        return true;
    }

    return false;
}

bool Employee::SetPatronymic(std::string patronymic)
{
    if (IsWord(patronymic))
    {
        this->patronymic = patronymic;
        return true;
    }

    return false;
}

bool Employee::SetEntryYear(int entryYear)
{
    // добавить логику ввода года прин€ти€ на работу
    this->entryYear = entryYear;

    return true;
}

bool Employee::SetEntryYear(std::string entryYear)
{
    if (IsNumber(entryYear))
    {
        SetEntryYear(std::stoi(entryYear));
        return true;
    }
    return false;
}

bool Employee::SetSalary(double salary)
{
    // добавить логику ввода зарплаты
    this->salary = salary;

    return true;
}

bool Employee::SetSalary(std::string salary)
{
    if (IsNumber(salary))
    {
        SetSalary(std::stod(salary));
    }

    return true;
}

std::string Employee::GetName(void)
{
    return name;
}

int Employee::GetEntryYear(void)
{
    return entryYear;
}

double Employee::GetSalary(void)
{
    return salary;
}

// принимает строку str и преобразует ее в экземл€р класса Employee
Employee StringToEmployee(std::string str)
{
    Employee employee;
    return employee;
}