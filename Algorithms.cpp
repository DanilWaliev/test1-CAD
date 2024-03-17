#include "Algorithms.h"

// проверяет содержит ли строка только буквы
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

// проверяет является ли строка десятичным числом
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