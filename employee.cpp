#include "Employee.h"

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

Employee::Employee(std::string inputString)
{
    // разбиение исходной строки в вектор строк
    std::vector<std::string> splitted;
    std::stringstream stringStream(inputString);
    std::string tempString;

    while (stringStream >> tempString)
    {
        splitted.push_back(tempString);
    }

    if (splitted.size() < 6)
    {
        throw std::string("Недостаточно данных о пользователе");
    }

    // заполнение объекта employee строками из вектора
    try
    {
        SetName(splitted.at(0));
    }
    catch (std::string errorMessage)
    {
        throw errorMessage;
    }

    try
    {
        SetSurname(splitted.at(1));
    }
    catch (std::string errorMessage)
    {
        throw errorMessage;
    }

    try
    {
        SetPatronymic(splitted.at(2));
    }
    catch (std::string errorMessage)
    {
        throw errorMessage;
    }

    try
    {
        SetPosition(splitted.at(3));
    }
    catch (std::string errorMessage)
    {
        throw errorMessage;
    }

    try
    {
        SetEntryYear(splitted.at(4));
    }
    catch (std::string errorMessage)
    {
        throw errorMessage;
    }

    try
    {
        SetSalary(splitted.at(5));
    }
    catch (std::string errorMessage)
    {
        throw errorMessage;
    }
}

Employee::Employee()
{
    name = "Undefined";
    surname = "Undefined";
    patronymic = "Undefined";
    position = "Undefined";
    entryYear = 0;
    salary = 0.0;
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

void Employee::SetName(std::string inputName)
{
    if (IsWord(inputName))
    {
        name = inputName;
        return;
    }

    throw std::string("Некорректное имя");
}

void Employee::SetSurname(std::string inputSurname)
{
    if (IsWord(inputSurname))
    {
        surname = inputSurname;
        return;
    }

    throw std::string("Некорректная фамилия");
}

void Employee::SetPatronymic(std::string inputPatronymic)
{
    if (IsWord(inputPatronymic))
    {
        patronymic = inputPatronymic;
        return;
    }

    throw std::string("Некорректное отчество");
}

void Employee::SetPosition(std::string inputPosition)
{
    if (IsWord(inputPosition))
    {
        position = inputPosition;
        return;
    }

    throw std::string("Некорректная должность");
}

void Employee::SetEntryYear(int inputEntryYear)
{
    // добавить логику ввода года принятия на работу
    entryYear = inputEntryYear;
}

void Employee::SetEntryYear(std::string inputEntryYear)
{
    if (IsNumber(inputEntryYear))
    {
        SetEntryYear(std::stoi(inputEntryYear));
        return;
    }
    throw std::string("Некорректный год");
}

void Employee::SetSalary(double inputSalary)
{
    // добавить логику ввода зарплаты
    salary = inputSalary;
}

void Employee::SetSalary(std::string inputSalary)
{
    if (IsNumber(inputSalary))
    {
        SetSalary(std::stod(inputSalary));
        return;
    }

    throw std::string("Некорректная зарпалата");
}

std::string Employee::GetName(void)
{
    return name;
}

std::string Employee::GetSurname(void)
{
    return surname;
}

std::string Employee::GetPatronymic(void)
{
    return patronymic;
}

std::string Employee::GetPosition(void)
{
    return position;
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