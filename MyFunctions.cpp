#include "MyFunctions.h"

// ��������� �������� �� ������ ������ �����
bool IsWord(std::string str)
{
    std::locale loc("Russian");
    bool isWord = true;
    for (const char ch : str)
    {
        if (!std::isalpha(ch, loc) && ch != '-')
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

// ���������� ������� ������� ������ str � ������� ��������
std::string ToLowerCase(std::string str)
{
    std::locale loc("Russian");
    for (int i = 0; i < str.size(); i++) str[i] = std::tolower(str[i], loc);
    return str;
}

// ���������� ������� ������� ������ str � �������� ��������
std::string ToLowerCase(std::string str)
{
    std::locale loc("Russian");
    for (int i = 0; i < str.size(); i++) str[i] = std::toupper(str[i], loc);
    return str;
}