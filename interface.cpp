#include "Interface.h"

// ������� � ������� ���������� �� �������
void ShowInfo(void)
{
    std::cout << " /*******************************************\\" << std::endl
        << " | ���: ������ ����� ���������, ������: 4304 |" << std::endl
        << " | ����������� ������ �1, ������� �5         |" << std::endl
        << " | �������: ����������� ����� ��� ���������  |" << std::endl
        << " | ���������� �������                        |" << std::endl
        << " \\*******************************************/" << std::endl
        << std::endl;
}

// ������� ������ ���� � �������
void ShowMenu(void)
{
    std::cout << " 1 - ������ ������ ����� ����" << std::endl
        << " 2 - ������ ������ ����� �������" << std::endl
        << " 3 - �������� ������ � �����������" << std::endl
        << " 4 - �������� ��� ������" << std::endl
        << " 5 - ��������� ������ � ����������� � ����" << std::endl
        << " 6 - ������������� ����������� �� �����" << std::endl
        << " 7 - ������������� ����������� �� ��������" << std::endl
        << " 8 - ������������� ����������� �� ���������" << std::endl
        //<< "9 - ������� ����������" << std::endl
        << " 0 - ��������� ������ ���������" << std::endl
        << std::endl;
}

// �������� ������������� �������� � �������
// ���������� ������ ������������ �������� �� ��� ���, ���� ������� �� �������� ����������
// promptMessage - ����������� � ����� (�� ��������� = "������� ������������� ��������: ")
// errorMessage - ��������� �� ������ ���������� ����� (�� ��������� = "������������ ����: ")
int GetInt(std::string promptMessage, std::string errorMessage)
{
    std::string inputString;

    while (true)
    {
        std::cout << promptMessage;
        std::cin >> inputString;

        if (IsNumber(inputString))
        {
            while (getchar() != '\n');
            std::cout << std::endl;
            return std::stoi(inputString);
        }

        while (getchar() != '\n');
        std::cout << errorMessage << std::endl;
        std::cout << std::endl;
    }
}

// �������� ����� � ��������� ������ � �������
// ���������� ������ ������������ �������� �� ��� ���, ���� ������� �� �������� ����������
// promptMessage - ����������� � ����� (�� ��������� = "������� ������������� ��������: ")
// errorMessage - ��������� �� ������ ���������� ����� (�� ��������� = "������������ ����: ")
double GetDouble(std::string promptMessage, std::string errorMessage)
{
    std::string inputString;

    while (true)
    {
        std::cout << promptMessage;
        std::cin >> inputString;

        if (IsNumber(inputString))
        {
            while (getchar() != '\n');
            std::cout << std::endl;
            return std::stod(inputString);
        }

        while (getchar() != '\n');
        std::cout << errorMessage << std::endl;
        std::cout << std::endl;
    }
}

// �������� ���� ����� � �������
// ���������� ������ ������������ �������� �� ��� ���, ���� ������� �� �������� ����������
// promptMessage - ����������� � ����� (�� ��������� = "������� ������������� ��������: ")
// errorMessage - ��������� �� ������ ���������� ����� (�� ��������� = "������������ ����: ")
std::string GetWord(std::string promptMessage, std::string errorMessage)
{
    std::string inputString;

    while (true)
    {
        std::cout << promptMessage;
        std::cin >> inputString;

        if (IsWord(inputString))
        {
            std::cout << std::endl;
            return inputString;
        }

        std::cout << errorMessage << std::endl;
        std::cout << std::endl;
    }
}

// ���������� � ������������ ��/��� �� ��� ��� ���� �� ������� ���������� �����
// ��� ������ �� ���������� true, ��� - false
bool Prompt(std::string message)
{
    std::string inputString;

    while (true)
    {
        std::cout << message;
        std::cin >> inputString;
        while (getchar() != '\n');
        std::cout << std::endl;

        inputString = ToLowerCase(inputString);

        if (inputString == "��" || inputString == "�") return true;
        if (inputString == "���" || inputString == "�") return false;

        std::cout << "������������ ����" << std::endl;
    }
}