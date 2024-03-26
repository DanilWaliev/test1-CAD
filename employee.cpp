#include "Employee.h"

// ������� ������ ���������� ������ Employee 
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
    // ������� �������� ������ � ������ �����
    std::vector<std::string> parsed;
    std::stringstream stringStream(inputString);
    std::string tempString{};

    while (stringStream >> tempString)
    {
        parsed.push_back(tempString);
    }

    if (parsed.size() < 5)
    {
        throw std::string("������������ ������ � ������������");
    }

    // ���������� ������� employee �������� �� �������
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

// ������� ���������� � ���������
void Employee::ShowInfo()
{
    std::cout << "���: " << name << std::endl;
    std::cout << "�������: " << surname << std::endl;
    std::cout << "��������: " << patronymic << std::endl;
    std::cout << "���������: " << position << std::endl;
    std::cout << "��� �������� �� ������: " << entryYear << std::endl;
    std::cout << "��������: " << salary << std::endl;
}

void Employee::SetName(std::string name)
{
    if (IsWord(name))
    {
        this->name = name;
        return;
    }

    throw std::string("������������ ���");
}

void Employee::SetSurname(std::string surname)
{
    if (IsWord(surname))
    {
        this->surname = surname;
        return;
    }

    throw std::string("������������ �������");
}

void Employee::SetPatronymic(std::string patronymic)
{
    if (IsWord(patronymic))
    {
        this->patronymic = patronymic;
        return;
    }

    throw std::string("������������ ��������");
}

void Employee::SetPosition(std::string position)
{
    if (IsWord(position))
    {
        this->position = position;
        return;
    }

    throw std::string("������������ ���������");
}

void Employee::SetEntryYear(int entryYear)
{
    // �������� ������ ����� ���� �������� �� ������
    this->entryYear = entryYear;
}

void Employee::SetEntryYear(std::string entryYear)
{
    if (IsNumber(entryYear))
    {
        SetEntryYear(std::stoi(entryYear));
        return;
    }
    throw std::string("������������ ���");
}

void Employee::SetSalary(double salary)
{
    // �������� ������ ����� ��������
    this->salary = salary;
}

void Employee::SetSalary(std::string salary)
{
    if (IsNumber(salary))
    {
        SetSalary(std::stod(salary));
        return;
    }

    throw std::string("������������ ���������");
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

// ��������� ������ str � ����������� �� � �������� ������ Employee
//Employee StringToEmployee(std::string inputString)
//{
//    Employee employee;
//
//    // ������� �������� ������ � ������ �����
//    std::vector<std::string> parsed;
//    std::stringstream stringStream(inputString);
//    std::string tempString{};
//
//    while (stringStream >> tempString)
//    {
//        parsed.push_back(tempString);
//    }
//
//    // ���������� ������� employee �������� �� �������
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