#include "Employee.h"

// создает вектор экземляров класса Employee 
std::vector<Employee> MakeCompany(size_t size) {
    std::vector<Employee> company(size);
    for (auto i = company.begin(); i != company.end(); i++)
    {
        *i = Employee();
    }

    return company;
}

Employee::Employee(std::string name, std::string surname, std::string patronymic,
    std::string position, int entryYear, double salary)
{
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->position = position;
    this->entryYear = entryYear;
    this->salary = salary;
}

Employee::Employee(void)
{
    name = "Undefined";
    surname = "Undefined";
    patronymic = "Undefined";
    position = "Undefined";
    entryYear = 0;
    salary = 0.0;
}

Employee::Employee(std::string inputString)
{
    // парсинг исходной строки в вектор строк
    std::vector<std::string> parsed;
    std::stringstream stringStream(inputString);
    std::string tempString{};

    while (stringStream >> tempString)
    {
        parsed.push_back(tempString);
    }

    if (parsed.size() < 5)
    {
        throw std::string("Недостаточно данных о пользователе");
    }

    // заполнение объекта employee строками из вектора
    try
    {
        SetName(parsed.at(0));
    }
    catch (std::string errorMessage)
    {
        std::cout << errorMessage << std::endl;
    }

    try
    {
        SetSurname(parsed.at(1));
    }
    catch (std::string errorMessage)
    {
        std::cout << errorMessage << std::endl;
    }

    try
    {
        SetPatronymic(parsed.at(2));
    }
    catch (std::string errorMessage)
    {
        std::cout << errorMessage << std::endl;
    }

    try
    {
        SetPosition(parsed.at(3));
    }
    catch (std::string errorMessage)
    {
        std::cout << errorMessage << std::endl;
    }

    try
    {
        SetEntryYear(parsed.at(4));
    }
    catch (std::string errorMessage)
    {
        std::cout << errorMessage << std::endl;
    }

    try
    {
        SetSalary(parsed.at(5));
    }
    catch (std::string errorMessage)
    {
        std::cout << errorMessage << std::endl;
    }
}

// выводит информацию о работнике
void Employee::ShowInfo()
{
    std::cout << "Имя: " << name << std::endl;
    std::cout << "Фамилия: " << surname << std::endl;
    std::cout << "Отчество: " << patronymic << std::endl;
    std::cout << "Должность: " << position << std::endl;
    std::cout << "Год принятия на работу: " << entryYear << std::endl;
    std::cout << "Зарплата: " << salary << std::endl;
}

void Employee::SetName(std::string name)
{
    if (IsWord(name))
    {
        this->name = name;
        return;
    }

    throw std::string("Некорректное имя");
}

void Employee::SetSurname(std::string surname)
{
    if (IsWord(surname))
    {
        this->surname = surname;
        return;
    }

    throw std::string("Некорректная фамилия");
}

void Employee::SetPatronymic(std::string patronymic)
{
    if (IsWord(patronymic))
    {
        this->patronymic = patronymic;
        return;
    }

    throw std::string("Некорректное отчество");
}

void Employee::SetPosition(std::string position)
{
    if (IsWord(position))
    {
        this->position = position;
        return;
    }

    throw std::string("Некорректная должность");
}

void Employee::SetEntryYear(int entryYear)
{
    // добавить логику ввода года принятия на работу
    this->entryYear = entryYear;
}

void Employee::SetEntryYear(std::string entryYear)
{
    if (IsNumber(entryYear))
    {
        SetEntryYear(std::stoi(entryYear));
        return;
    }
    throw std::string("Некорректный год");
}

void Employee::SetSalary(double salary)
{
    // добавить логику ввода зарплаты
    this->salary = salary;
}

void Employee::SetSalary(std::string salary)
{
    if (IsNumber(salary))
    {
        SetSalary(std::stod(salary));
        return;
    }

    throw std::string("Некорректная зарпалата");
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

// принимает строку str и преобразует ее в экземляр класса Employee
//Employee StringToEmployee(std::string inputString)
//{
//    Employee employee;
//
//    // парсинг исходной строки в вектор строк
//    std::vector<std::string> parsed;
//    std::stringstream stringStream(inputString);
//    std::string tempString{};
//
//    while (stringStream >> tempString)
//    {
//        parsed.push_back(tempString);
//    }
//
//    // заполнение объекта employee строками из вектора
//    try
//    {
//        employee.SetName(parsed.at(0));
//    }
//    catch (std::string errorMessage)
//    {
//        throw errorMessage;
//    }
//
//    try
//    {
//        employee.SetSurname(parsed.at(1));
//    }
//    catch (std::string errorMessage)
//    {
//        throw errorMessage;
//    }
//
//    try
//    {
//        employee.SetPatronymic(parsed.at(2));
//    }
//    catch (std::string errorMessage)
//    {
//        throw errorMessage;
//    }
//
//    try
//    {
//        employee.SetEntryYear(parsed.at(3));
//    }
//    catch (std::string errorMessage)
//    {
//        throw errorMessage;
//    }
//
//    try
//    {
//        employee.SetSalary(parsed.at(4));
//    }
//    catch (std::string errorMessage)
//    {
//        throw errorMessage;
//    }
//
//    return employee;
//};