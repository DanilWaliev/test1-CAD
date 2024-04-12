#include "Algorithms.h"

enum class InputMenuOptions
{
    MainMenu,
    Console,
    File
};

enum class OutputMenuOptions
{
    MainMenu,
    Console,
    File
};

enum class FilterMenuOptions
{
    MainMenu,
    ByWorkExperience,
    BySalary,
    ByPosition
};

// ��������� � ������ company �����������, ���������� � ����� ��������� �������������
void FileInput(std::vector<Employee>& company)
{
    size_t was = company.size();
    int counter = 0;
    std::string inputString;
    std::string source;

    while (true)
    {
        std::cout << "������� �������� �����, 0 ����� ��������� ���� ";
        std::cin >> source;

        // ��� ����� ������������� 0 ���������� ������� �����������
        if (source == "0")
        {
            std::cout << std::endl;
            return;
        }

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
}

// ��������� ������ � ������� � ��������� ���������� � ������ company
void ConsoleInput(std::vector<Employee>& company)
{
    std::cout << "������� ������ � ����������� ����� ������ � �������: "
    << "��� ������� �������� ��������� ���(�������� �� ������) ��������" << std::endl
    << "0, ����� ��������� ����" << std::endl;

    std::string inputString;

    while (true)
    {
        getline(std::cin, inputString);

        if (inputString == "0")
        {
            std::cout << std::endl;
            return;
        }

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

// ������� ������� ����������� ������� company � ����� out
void PrintTable(std::vector<Employee>& company, std::ostream& out)
{
    if (company.size() == 0)
    {
        out << "��� ������" << std::endl << std::endl;
        return;
    }

    out << " ���                  "
              << " �������              "
              << " ��������             "
              << " ���������            "
              << " ���  "
              << " ��������   " << std::endl;

    for (int i = 0; i < 108; i++)
    {
        out << "-";
    }

    out << std::endl;

    for (int i = 0; i < company.size(); i++)
    {
        out << " " << std::left << std::setw(20) << company.at(i).GetName() << " "
            << " " << std::left << std::setw(20) << company.at(i).GetSurname() << " "
            << " " << std::left << std::setw(20) << company.at(i).GetPatronymic() << " "
            << " " << std::left << std::setw(20) << company.at(i).GetPosition() << " "
            << " " << std::left << std::setw(4) << company.at(i).GetEntryYear() << " "
            << " " << std::left << std::setw(10) << company.at(i).GetSalary() << std::endl;
    }
    

    out << "���������� �����������: " << company.size() << std::endl << std::endl;;
}

// ������� ������ company
void ClearData(std::vector<Employee>& company)
{
    company.clear();
    std::cout << "������ �������" << std::endl << std::endl;

}

// ��������� ������ � ����������� ������� company � ��������� ����
void SaveAsFile(std::vector<Employee>& company)
{
    // ������ �������� ����� � ������� ����� �������� ������
    std::string fileName;

    // true - ��������� ���� ��� ���������� ��� �� ������ ��� ������
    //false - ����� � ����� �������� �� ����������
    bool isValid;

    while (true)
    {
        std::cout << "������� �������� �����, 0 ����� ��������� ���������� � ����: ";
        std::cin >> fileName;

        // ��� ����� ������������� 0 ���������� ������� �����������
        if (fileName == "0")
        {
            std::cout << std::endl;
            return;
        }

        // �������� ����� �� ������������� ��� ������ ��� ������
        std::ifstream check(fileName);
        isValid = (!check.is_open()) ? true : false;
        check.close();

        if (!isValid)
        {
            std::cout << "��������� ���� ��� ���������� ��� ������ ��� ������" << std::endl;
            
            if (Prompt("������������ ����? ��/��� (�/�):"))
            {
                std::ofstream ofs(fileName);
                PrintTable(company, ofs);
                ofs.close();
                std::cout << "������ �������� � ����" << std::endl << std::endl;
                return;
            }
        }
        else
        {
            std::ofstream ofs(fileName);
            PrintTable(company, ofs);
            ofs.close();
            std::cout << "������ �������� � ����" << std::endl << std::endl;
            return;
        }
    }
}

// ��������� ������ � ����������� ���������������� ������� filtred,
// �������� ����� ���� �������� ������ source � ������ ��������� message
void SaveFiltredDataAsFile(
    std::vector<Employee>& source,
    std::vector<Employee>& filtred,
    std::string message)
{
    // ������ �������� ����� � ������� ����� �������� ������
    std::string fileName;

    // true - ���p����� ���� ��� ���������� ��� �� ������ ��� ������
    // false - ����� � ����� �������� �� ����������
    bool isValid;

    while (true)
    {
        std::cout << "������� �������� �����, 0 ����� ��������� ���������� � ����: ";
        std::cin >> fileName;

        // ��� ����� ������������� 0 ���������� ������� �����������
        if (fileName == "0")
        {
            std::cout << std::endl;
            return;
        }

        // �������� ����� �� ������������� ��� ������ ��� ������
        std::ifstream check(fileName);
        isValid = (!check.is_open()) ? true : false;
        check.close();

        if (!isValid)
        {
            std::cout << "��������� ���� ��� ���������� ��� ������ ��� ������" << std::endl;

            if (Prompt("������������ ����? ��/��� (�/�):"))
            {
                std::ofstream ofs(fileName);
                ofs << "�������� ������:" << std::endl;
                PrintTable(source, ofs);
                ofs << message << std::endl;
                PrintTable(filtred, ofs);
                ofs.close();
                std::cout << "������ �������� � ����" << std::endl << std::endl;
                return;
            }
        }
        else
        {
            std::ofstream ofs(fileName);
            ofs << "�������� ������:" << std::endl;
            PrintTable(source, ofs);
            ofs << message << std::endl;
            PrintTable(filtred, ofs);
            ofs.close();
            std::cout << "������ �������� � ����" << std::endl << std::endl;
            return;
        }
    }
}

// ����������� � ������������ ����� ���, ������� ������ ��������� ���� ����������
// ���������� ������� � ������� ��������� � ��������� ��� � ���� � ��������� �������
void FilterByWorkExperience(std::vector<Employee>& company)
{
    if (company.size() == 0)
    {
        std::cout << "������������ ������" << std::endl << std::endl;
        return;
    }

    // ������ � ������� ����� ��������� ��������������� ����������
    std::vector<Employee> filtred;

    int workExperienceFilter = GetInt("������� ����� ���, ������� ������ ��������� ���� ����������: ");

    // ������� ����� ������� company � ���������� ��������������� ����������� � filtred
    for (auto i = company.begin(); i != company.end(); i++)
    {
        if ((2024 - (*i).GetEntryYear()) > workExperienceFilter)
        {
            filtred.push_back(*i);
        }
    }

    if (filtred.size() == 0)
    {
        std::cout << "��� �����������, ��������������� ���� ���������" << std::endl << std::endl;
        return;
    }

    if ( Prompt("������� ��������� � �������? ��/��� (�/�): ") )
    {
        PrintTable(filtred, std::cout);
    }

    if ( Prompt("��������� ��������������� ������ � ����? ��/��� (�/�): ") )
    {
        SaveFiltredDataAsFile(
            company, 
            filtred, 
            "C���������, ��� ���� ��������� " + std::to_string(workExperienceFilter) + " ���");
    }
}

// ����������� � ������������ �����, ������� ������ ��������� �������� ����������
// ���������� ������� � ������� ��������� � ��������� ��� � ���� � ��������� �������
void FilterBySalary(std::vector<Employee>& company)
{
    if (company.size() == 0)
    {
        std::cout << "������������ ������" << std::endl << std::endl;
        return;
    }

    // ������ � ������� ����� ��������� ��������������� ����������
    std::vector<Employee> filtred;

    double salaryFilter = GetDouble("������� �����, ������� ������ ��������� �������� ����������: ");

    // ������� ����� ������� company � ���������� ��������������� ����������� � filtred
    for (auto i = company.begin(); i != company.end(); i++)
    {
        if ((*i).GetSalary() > salaryFilter)
        {
            filtred.push_back(*i);
        }
    }

    if (filtred.size() == 0)
    {
        std::cout << "��� �����������, ��������������� ���� ���������" << std::endl << std::endl;
        return;
    }

    if ( Prompt("������� ��������� � �������? ��/��� (�/�): ") )
    {
        PrintTable(filtred, std::cout);
    }

    if ( Prompt("��������� ��������������� ������ � ����? ��/��� (�/�): ") )
    {
        SaveFiltredDataAsFile(
            company,
            filtred,
            "C���������, ��� �������� ��������� " + std::to_string(salaryFilter));
    }
}

// ����������� � ������������ ��������� �� ������� ��������� �����������
// ���������� ������� � ������� ��������� � ��������� ��� � ���� � ��������� �������
void FilterByPosition(std::vector<Employee>& company)
{
    if (company.size() == 0)
    {
        std::cout << "������������ ������" << std::endl << std::endl;
        return;
    }

    // ������ � ������� ����� ��������� ��������������� ����������
    std::vector<Employee> filtred;

    std::string positionFilter = GetWord("������� ��������� �� ������� ����������� �����������: ");


    // ������� ����� ������� company � ���������� ��������������� ����������� � filtred
    for (auto i = company.begin(); i != company.end(); i++)
    {
        if ( ToLowerCase((*i).GetPosition()) == ToLowerCase(positionFilter) )
        {
            filtred.push_back(*i);
        }
    }

    if (filtred.size() == 0)
    {
        std::cout << "��� �����������, ��������������� ���� ���������" << std::endl << std::endl;
        return;
    }

    if ( Prompt("������� ��������� � �������? ��/��� (�/�): ") )
    {
        PrintTable(filtred, std::cout);
    }

    if ( Prompt("��������� ��������������� ������ � ����? ��/��� (�/�): ") )
    {
        SaveFiltredDataAsFile(
            company,
            filtred,
            "C���������, ���������� ��������� " + positionFilter);
    }
}

void Input(std::vector<Employee>& company)
{
    InputMenuOptions inputMenuChoice;

    while (true)
    {
        ShowInputMenu();
        inputMenuChoice = static_cast<InputMenuOptions>(GetInt("������� ������ �����: "));

        switch (inputMenuChoice)
        {
        case InputMenuOptions::Console:
            ConsoleInput(company);
            break;
        case InputMenuOptions::File:
            FileInput(company);
            break;
        case InputMenuOptions::MainMenu:
            return;
            break;
        default:
            std::cout << "������ ������ � ���� ���" << std::endl << std::endl;
        }
    }
}

void Output(std::vector<Employee>& company)
{
    OutputMenuOptions outputMenuChoice;

    while (true)
    {
        ShowOutputMenu();

        outputMenuChoice = static_cast<OutputMenuOptions>(GetInt("������� ������ �����: "));

        switch (outputMenuChoice)
        {
        case OutputMenuOptions::Console:
            PrintTable(company, std::cout);
            break;
        case OutputMenuOptions::File:
            SaveAsFile(company);
            break;
        case OutputMenuOptions::MainMenu:
            return;
            break;
        default:
            std::cout << "������ ������ � ���� ���" << std::endl << std::endl;
        }
    }
}

void Filter(std::vector<Employee>& company)
{
    FilterMenuOptions filterMenuChoice;

    while (true)
    {
        ShowFilterMenu();

        filterMenuChoice = static_cast<FilterMenuOptions>(GetInt("������� ����� ������ ���������: "));

        switch (filterMenuChoice)
        {
        case FilterMenuOptions::ByWorkExperience:
            FilterByWorkExperience(company);
            break;
        case FilterMenuOptions::BySalary:
            FilterBySalary(company);
            break;
        case FilterMenuOptions::ByPosition:
            FilterByPosition(company);
            break;
        case FilterMenuOptions::MainMenu:
            return;
            break;
        default:
            std::cout << "������ ������ � ���� ���" << std::endl << std::endl;
        }
    }
}