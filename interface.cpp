#include "Interface.h"

// выводит в консоль информацию по заданию
void ShowInfo(void)
{
    std::cout << "/*******************************************\\" << std::endl;
    std::cout << "| ФИО: Валиев Данил Ленарович, Группа: 4304 |" << std::endl;
    std::cout << "| Контрольная работа №1, Вариант №5         |" << std::endl;
    std::cout << "| Задание: разработать класс для указанной  |" << std::endl;
    std::cout << "| предметной области                        |" << std::endl;
    std::cout << "\\*******************************************/" << std::endl;
    std::cout << std::endl;
}

// выводит пункты меню в консоль
void ShowMenu(void)
{
    std::cout << "1 - Ввести данные через файл" << std::endl;
    std::cout << "2 - Ввести данные через консоль" << std::endl;
    std::cout << "0 - Завершить работу программы" << std::endl;
    std::cout << std::endl;
}

// получает целочисленное значение с консоли
// предлагает ввести пользователю значение до тех пор, пока значени не окажется корректным
// promptMessage - приглашение к вводу (по умолчанию = "Введите целочисленное значение: ")
// errorMessage - сообщение об ошибке считывания числа (по умолчанию = "Некорректный ввод: ")
int GetInt(std::string promptMessage, std::string errorMessage)
{
    std::string str;

    while (true)
    {
        std::cout << promptMessage;
        std::cin >> str;

        if (IsNumber(str))
        {
            while (getchar() != '\n');
            return std::stoi(str);
            std::cout << std::endl;
        }

        while (getchar() != '\n');
        std::cout << errorMessage << std::endl;
        std::cout << std::endl;
    }
}

// получает число с плавающей точкой с консоли
// предлагает ввести пользователю значение до тех пор, пока значени не окажется корректным
// promptMessage - приглашение к вводу (по умолчанию = "Введите целочисленное значение: ")
// errorMessage - сообщение об ошибке считывания числа (по умолчанию = "Некорректный ввод: ")
double GetDouble(std::string promptMessage, std::string errorMessage)
{
    std::string str;

    while (true)
    {
        std::cout << promptMessage;
        std::cin >> str;

        if (IsNumber(str))
        {
            while (getchar() != '\n');
            std::cout << std::endl;
            return std::stod(str);
        }

        while (getchar() != '\n');
        std::cout << errorMessage << std::endl;
        std::cout << std::endl;
    }
}

