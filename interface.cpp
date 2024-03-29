#include "Interface.h"

// ������� � ������� ���������� �� �������
void ShowInfo(void)
{
    std::cout << "/*******************************************\\" << std::endl;
    std::cout << "| ���: ������ ����� ���������, ������: 4304 |" << std::endl;
    std::cout << "| ����������� ������ �1, ������� �5         |" << std::endl;
    std::cout << "| �������: ����������� ����� ��� ���������  |" << std::endl;
    std::cout << "| ���������� �������                        |" << std::endl;
    std::cout << "\\*******************************************/" << std::endl;
    std::cout << std::endl;
}

// ������� ������ ���� � �������
void ShowMenu(void)
{
    std::cout << "1 - ������ ������ ����� ����" << std::endl;
    std::cout << "2 - ������ ������ ����� �������" << std::endl;
    std::cout << "0 - ��������� ������ ���������" << std::endl;
    std::cout << std::endl;
}

// �������� ������������� �������� � �������
// ���������� ������ ������������ �������� �� ��� ���, ���� ������� �� �������� ����������
// promptMessage - ����������� � ����� (�� ��������� = "������� ������������� ��������: ")
// errorMessage - ��������� �� ������ ���������� ����� (�� ��������� = "������������ ����: ")
int GetInt(std::string promptMessage, std::string errorMessage)
{
    std::string str;

    while (true)
    {
        std::cout << promptMessage << std::endl;
        std::cin >> str;

        if (IsNumber(str))
        {
            while (getchar() != '\n');
            return std::stoi(str);
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
    std::string str;

    while (true)
    {
        std::cout << promptMessage << std::endl;
        std::cin >> str;

        if (IsNumber(str))
        {
            while (getchar() != '\n');
            return std::stod(str);
        }

        while (getchar() != '\n');
        std::cout << errorMessage << std::endl;
    }
}

//void ReadFile(std::string source)
//{
//    std::string str;
//
//    std::ifstream in(source);
//
//    while (std::getline(in, str))
//    {
//        
//    }
//
//    in.close();
//
//}

