#include "Algorithms.h"

// ��������� �������� �� ������ ������ �����
bool IsWord(std::string str)
{
    bool isWord = true;
    for (const char ch : str)
    {
        if (!isalpha(ch))
        {
            isWord = false;
            break;
        }
    }

    return isWord;
}

// ��������� �������� �� ������ ���������� ������
bool IsNumber(std::string str)
{
    bool isNumber = true;
    for (const char ch : str)
    {
        if (!isdigit(ch) && ch != '-' && ch != '.')
        {
            isNumber = false;
            break;
        }
    }

    return isNumber;
}