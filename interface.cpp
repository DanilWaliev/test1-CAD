#include "Interface.h"

void ShowInfo(void)
{
    std::cout << "/*******************************************\\" << std::endl;
    std::cout << "| ���: ������ ����� ���������, ������: 4304 |" << std::endl;
    std::cout << "| ����������� ������ �1, ������� �5         |" << std::endl;
    std::cout << "| �������: ����������� ����� ��� ���������  |" << std::endl;
    std::cout << "| ���������� �������                        |" << std::endl;
    std::cout << "\\*******************************************/" << std::endl;
}

int GetInt(std::string promptMessage, std::string errorMessage)
{
    std::string str;
    bool isNum = true;

    while (true)
    {
        std::cout << promptMessage << std::endl;
        std::cin >> str;

        // ������������ �������� ���������� ������ �� �����
        isNum = true;
        for (const char ch : str)
        {
            if (!isdigit(ch))
            {
                isNum = false;
                break;
            }
        }

        if (isNum)
        {
            while (getchar() != '\n');
            return std::stoi(str);
        }

        while (getchar() != '\n');
        std::cout << errorMessage << std::endl;
    }
}

double GetDouble(void)
{
    return 0.;
}