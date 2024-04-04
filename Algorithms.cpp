#include "Algorithms.h"

// проверяет содержит ли строка только буквы
bool IsWord(std::string str)
{
    std::locale loc("Russian");
    bool isWord = true;
    for (const char ch : str)
    {
        if (!std::isalpha(ch, loc))
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