#include "Interface.h"

// выводит в консоль информацию по заданию
void ShowInfo(void)
{
    std::cout << " /*******************************************\\" << std::endl
        << " | ФИО: Валиев Данил Ленарович, Группа: 4304 |" << std::endl
        << " | Контрольная работа №1, Вариант №5         |" << std::endl
        << " | Задание: разработать класс для указанной  |" << std::endl
        << " | предметной области                        |" << std::endl
        << " \\*******************************************/" << std::endl
        << std::endl;
}

// выводит пункты меню в консоль
void ShowMenu(void)
{
    std::cout << " 1 - Ввести данные через файл" << std::endl
        << " 2 - Ввести данные через консоль" << std::endl
        << " 3 - Показать данные о сотрудниках" << std::endl
        << " 4 - Очистить все данные" << std::endl
        << " 5 - Сохранить данные о сотрудниках в файл" << std::endl
        << " 6 - Отфильтровать сотрудников по стажу" << std::endl
        << " 7 - Отфильтровать сотрудников по зарплате" << std::endl
        << " 8 - Отфильтровать сотрудников по должности" << std::endl
        //<< "9 - Удалить сотрудника" << std::endl
        << " 0 - Завершить работу программы" << std::endl
        << std::endl;
}

// получает целочисленное значение с консоли
// предлагает ввести пользователю значение до тех пор, пока значени не окажется корректным
// promptMessage - приглашение к вводу (по умолчанию = "Введите целочисленное значение: ")
// errorMessage - сообщение об ошибке считывания числа (по умолчанию = "Некорректный ввод: ")
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

// получает число с плавающей точкой с консоли
// предлагает ввести пользователю значение до тех пор, пока значени не окажется корректным
// promptMessage - приглашение к вводу (по умолчанию = "Введите целочисленное значение: ")
// errorMessage - сообщение об ошибке считывания числа (по умолчанию = "Некорректный ввод: ")
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

// получает одно слово с консоли
// предлагает ввести пользователю значение до тех пор, пока значени не окажется корректным
// promptMessage - приглашение к вводу (по умолчанию = "Введите целочисленное значение: ")
// errorMessage - сообщение об ошибке считывания числа (по умолчанию = "Некорректный ввод: ")
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

// спрашивает у пользователя да/нет до тех пор пока не получит корректный ответ
// при ответе да возвращает true, нет - false
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

        if (inputString == "да" || inputString == "д") return true;
        if (inputString == "нет" || inputString == "н") return false;

        std::cout << "Некорректный ввод" << std::endl;
    }
}