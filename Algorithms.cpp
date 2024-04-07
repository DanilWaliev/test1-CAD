#include "Algorithms.h"

void FileInput(std::vector<Employee>& company)
{
    size_t was = company.size();
    int counter = 0;
    std::string inputString;
    std::string source;
    
    std::cout << "������� �������� �����: ";
    std::cin >> source;

    std::ifstream in(source);

    while (getline(in, inputString))
    {
        counter++;

        try
        {
            company.push_back(Employee(inputString));
        }
        catch (std::string errorMessage)
        {
            std::cout << errorMessage << std::endl;
        }

    }
    in.close();

    std::cout << "������� " 
        << counter 
        << " �����, ��������� " 
        << company.size() - was 
        << " �����������" 
        << std::endl 
        << std::endl;

    
}

void ConsoleInput(std::vector<Employee>& company)
{
    std::cout << "������� ������ � ����������� ����� ������ � �������:" << std::endl;
    std::cout << "��� ������� �������� ��������� ���(�������� �� ������) ��������" << std::endl;
    std::cout << "0 - ��������� ���� � �������" << std::endl;

    std::string inputString;

    while (true)
    {
        getline(std::cin, inputString);

        if (inputString == "0") break;

        try
        {
            company.push_back(Employee(inputString));
        }
        catch (std::string errorMessage)
        {
            std::cout << errorMessage << std::endl;
        }

    }
}

// ������� ������ � ����������� � �������
void ShowData(std::vector<Employee>& company)
{
    if (company.size() == 0)
    {
        std::cout << "��� ������" << std::endl << std::endl;
        return;
    }

    std::cout << " ���                  "
              << " �������              "
              << " ��������             "
              << " ���������            "
              << " ���  "
              << " ��������   " << std::endl;

    for (int i = 0; i < 108; i++)
    {
        std::cout << "-";
    }

    std::cout << std::endl;

    for (int i = 0; i < company.size(); i++)
    {
        std::cout << " " << std::left << std::setw(20) << company.at(i).GetName() << " "
            << " " << std::left << std::setw(20) << company.at(i).GetSurname() << " "
            << " " << std::left << std::setw(20) << company.at(i).GetPatronymic() << " "
            << " " << std::left << std::setw(20) << company.at(i).GetPosition() << " "
            << " " << std::left << std::setw(4) << company.at(i).GetEntryYear() << " "
            << " " << std::left << std::setw(10) << company.at(i).GetSalary() << std::endl;
    }
    

    std::cout << "���������� �����������: " << company.size() << std::endl << std::endl;;
}

//void CleanData(std::vector<Employee>& company)
//{
//
//}
//
//void SaveAsFile(std::vector<Employee>& company)
//{
//    //
//}
//
//std::vector<Employee> FilterByWorkExperience(std::vector<Employee>& company)
//{
//    //
//}
//
//std::vector<Employee> FilterBySalary(std::vector<Employee>& company)
//{
//    //
//}
//
//std::vector<Employee> FilterByPosition(std::vector<Employee>& company)
//{
//    //
//}