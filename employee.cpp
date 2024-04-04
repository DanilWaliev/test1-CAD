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

Employee::Employee(std::string inputString)
{
    // ��������� �������� ������ � ������ �����
    std::vector<std::string> splitted;
    std::stringstream stringStream(inputString);
    std::string tempString;

    while (stringStream >> tempString)
    {
        splitted.push_back(tempString);
    }

    if (splitted.size() < 6)
    {
        throw std::string("������������ ������ � ������������");
    }

    // ���������� ������� employee �������� �� �������
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
    this->name = "Undefined";
    this->surname = "Undefined";
    this->patronymic = "Undefined";
    this->position = "Undefined";
    this->entryYear = 0;
    this->salary = 0.0;
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

void Employee::SetName(std::string inputName)
{
    if (IsWord(inputName))
    {
        name = inputName;
        return;
    }

    throw std::string("������������ ���");
}

void Employee::SetSurname(std::string inputSurname)
{
    if (IsWord(inputSurname))
    {
        surname = inputSurname;
        return;
    }

    throw std::string("������������ �������");
}

void Employee::SetPatronymic(std::string inputPatronymic)
{
    if (IsWord(inputPatronymic))
    {
        patronymic = inputPatronymic;
        return;
    }

    throw std::string("������������ ��������");
}

void Employee::SetPosition(std::string inputPosition)
{
    if (IsWord(inputPosition))
    {
        position = inputPosition;
        return;
    }

    throw std::string("������������ ���������");
}

void Employee::SetEntryYear(int inputEntryYear)
{
    // �������� ������ ����� ���� �������� �� ������
    entryYear = inputEntryYear;
}

void Employee::SetEntryYear(std::string inputEntryYear)
{
    if (IsNumber(inputEntryYear))
    {
        SetEntryYear(std::stoi(inputEntryYear));
        return;
    }
    throw std::string("������������ ���");
}

void Employee::SetSalary(double inputSalary)
{
    // �������� ������ ����� ��������
    salary = inputSalary;
}

void Employee::SetSalary(std::string inputSalary)
{
    if (IsNumber(inputSalary))
    {
        SetSalary(std::stod(inputSalary));
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