#include "Algorithms.h"

// добавляет в вектор company сотрудников, полученных с файла указанным пользователем
void FileInput(std::vector<Employee>& company)
{
    bool stop;

    size_t was = company.size();
    int counter = 0;
    std::string inputString;
    std::string source;

    while (true)
    {
        std::cout << "Введите название файла, 0 чтобы завершить ввод ";
        std::cin >> source;

        // при вводе пользователем 0 выполнение функции завершается
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

        std::cout << "Считано "
            << counter
            << " строк, добавлено "
            << company.size() - was
            << " сотрудников"
            << std::endl
            << std::endl;
    }
}

// считывает строку с консоли и добавляет сотрудника в вектор company
void ConsoleInput(std::vector<Employee>& company)
{
    std::cout << "Введите данные о сотрудникев через пробел в формате: "
    << "Имя Фамилия Отчество Должность Год(принятия на работу) Зарплата" << std::endl
    << "0, чтобы завершить ввод" << std::endl;

    std::string inputString;

    while (true)
    {
        getline(std::cin, inputString);

        if (inputString == "0") break;

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

// выводит таблицу сотрудников вектора company в поток out
void PrintTable(std::vector<Employee>& company, std::ostream& out)
{
    if (company.size() == 0)
    {
        out << "Нет данных" << std::endl << std::endl;
        return;
    }

    out << " Имя                  "
              << " Фамилия              "
              << " Отчество             "
              << " Должность            "
              << " Год  "
              << " Зарплата   " << std::endl;

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
    

    out << "Количество сотрудников: " << company.size() << std::endl << std::endl;;
}

// очищает вектор company
void ClearData(std::vector<Employee>& company)
{
    company.clear();
    std::cout << "Данные очищены" << std::endl << std::endl;

}

// сохраняет данные о сотрудниках вектора company в указанный файл
void SaveAsFile(std::vector<Employee>& company)
{
    // хранит название файла в которой будут записаны данные
    std::string fileName;

    // true - укащанный файл уже существует или он только для чтения
    //false - файла с таким имененем не существует
    bool isValid;

    while (true)
    {
        std::cout << "Введите название файла, 0 чтобы завершить сохранение в файл: ";
        std::cin >> fileName;

        // при вводе пользователем 0 выполнение функции завершается
        if (fileName == "0")
        {
            std::cout << std::endl;
            return;
        }

        // проверка файла на существование или только для чтения
        std::ifstream check(fileName);
        isValid = (!check.is_open()) ? true : false;
        check.close();

        if (!isValid)
        {
            std::cout << "Указанный файл уже существует или только для чтения" << std::endl;
            
            if (Prompt("Перезаписать файл? Да/Нет (д/н):"))
            {
                std::ofstream ofs(fileName);
                PrintTable(company, ofs);
                ofs.close();
                std::cout << "Данные записаны в файл" << std::endl << std::endl;
                return;
            }
        }
        else
        {
            std::ofstream ofs(fileName);
            PrintTable(company, ofs);
            ofs.close();
            std::cout << "Данные записаны в файл" << std::endl << std::endl;
            return;
        }
    }
}

// сохраняет данные о сотрудниках отфильтрованного вектора filtred,
// сохраняя перед этим исходные данные source и выводя сообщение message
void SaveFiltredDataAsFile(
    std::vector<Employee>& source,
    std::vector<Employee>& filtred,
    std::string message)
{
    // хранит название файла в которой будут записаны данные
    std::string fileName;

    // true - укаpанный файл уже существует или он только для чтения
    // false - файла с таким имененем не существует
    bool isValid;

    while (true)
    {
        std::cout << "Введите название файла, 0 чтобы завершить сохранение в файл: ";
        std::cin >> fileName;

        // при вводе пользователем 0 выполнение функции завершается
        if (fileName == "0")
        {
            std::cout << std::endl;
            return;
        }

        // проверка файла на существование или только для чтения
        std::ifstream check(fileName);
        isValid = (!check.is_open()) ? true : false;
        check.close();

        if (!isValid)
        {
            std::cout << "Указанный файл уже существует или только для чтения" << std::endl;

            if (Prompt("Перезаписать файл? Да/Нет (д/н):"))
            {
                std::ofstream ofs(fileName);
                ofs << "Исходные данные:" << std::endl;
                PrintTable(source, ofs);
                ofs << message << std::endl;
                PrintTable(filtred, ofs);
                ofs.close();
                std::cout << "Данные записаны в файл" << std::endl << std::endl;
                return;
            }
        }
        else
        {
            std::ofstream ofs(fileName);
            ofs << "Исходные данные:" << std::endl;
            PrintTable(source, ofs);
            ofs << message << std::endl;
            PrintTable(filtred, ofs);
            ofs.close();
            std::cout << "Данные записаны в файл" << std::endl << std::endl;
            return;
        }
    }
}

// запрашивает у пользователя число лет, которое должен превышать стаж сотрудника
// предлагает вывести в консоль результат и сохранить его в файл с исходными данными
void FilterByWorkExperience(std::vector<Employee>& company)
{
    if (company.size() == 0)
    {
        std::cout << "Недостаточно данных" << std::endl;
        return;
    }

    // вектор в котором будут храниться отфильтрованные сотрудники
    std::vector<Employee> filtred;

    int workExperienceFilter = GetInt("Введите число лет, которое должен превышать стаж сотрудника: ");

    // перебор всего вектора company и добавление отфильтрованных сотрудников в filtred
    for (auto i = company.begin(); i != company.end(); i++)
    {
        if ((2024 - (*i).GetEntryYear()) > workExperienceFilter)
        {
            filtred.push_back(*i);
        }
    }

    if (filtred.size() == 0)
    {
        std::cout << "Нет сотрудников, удовлетворяющих этим критериям" << std::endl << std::endl;
        return;
    }

    if ( Prompt("Вывести результат в консоль? Да/Нет (д/н): ") )
    {
        PrintTable(filtred, std::cout);
    }

    if ( Prompt("Сохранить отфильтрованный список в файл? Да/Нет (д/н): ") )
    {
        SaveFiltredDataAsFile(
            company, 
            filtred, 
            "Cотрудники, чей стаж превышает " + std::to_string(workExperienceFilter) + " лет");
    }
}

// запрашивает у пользователя сумму, которую должна превышать зарплата сотрудника
// предлагает вывести в консоль результат и сохранить его в файл с исходными данными
void FilterBySalary(std::vector<Employee>& company)
{
    if (company.size() == 0)
    {
        std::cout << "Недостаточно данных" << std::endl;
        return;
    }

    // вектор в котором будут храниться отфильтрованные сотрудники
    std::vector<Employee> filtred;

    double salaryFilter = GetDouble("Введите сумму, которую должна превышать зарплата сотрудника: ");

    // перебор всего вектора company и добавление отфильтрованных сотрудников в filtred
    for (auto i = company.begin(); i != company.end(); i++)
    {
        if ((*i).GetSalary() > salaryFilter)
        {
            filtred.push_back(*i);
        }
    }

    if (filtred.size() == 0)
    {
        std::cout << "Нет сотрудников, удовлетворяющих этим критериям" << std::endl << std::endl;
        return;
    }

    if ( Prompt("Вывести результат в консоль? Да/Нет (д/н): ") )
    {
        PrintTable(filtred, std::cout);
    }

    if ( Prompt("Сохранить отфильтрованный список в файл? Да/Нет (д/н): ") )
    {
        SaveFiltredDataAsFile(
            company,
            filtred,
            "Cотрудники, чья зарплата превышает " + std::to_string(salaryFilter));
    }
}

// запрашивает у пользователя должность по которой фильтрует сотрудников
// предлагает вывести в консоль результат и сохранить его в файл с исходными данными
void FilterByPosition(std::vector<Employee>& company)
{
    if (company.size() == 0)
    {
        std::cout << "Недостаточно данных" << std::endl;
        return;
    }

    // вектор в котором будут храниться отфильтрованные сотрудники
    std::vector<Employee> filtred;

    std::string positionFilter = GetWord("Введите должность по которой фильтровать сотрудников: ");


    // перебор всего вектора company и добавление отфильтрованных сотрудников в filtred
    for (auto i = company.begin(); i != company.end(); i++)
    {
        if ( ToLowerCase((*i).GetPosition()) == ToLowerCase(positionFilter) )
        {
            filtred.push_back(*i);
        }
    }

    if (filtred.size() == 0)
    {
        std::cout << "Нет сотрудников, удовлетворяющих этим критериям" << std::endl << std::endl;
        return;
    }

    if ( Prompt("Вывести результат в консоль? Да/Нет (д/н): ") )
    {
        PrintTable(filtred, std::cout);
    }

    if ( Prompt("Сохранить отфильтрованный список в файл? Да/Нет (д/н): ") )
    {
        SaveFiltredDataAsFile(
            company,
            filtred,
            "Cотрудники, занимающие должность " + positionFilter);
    }
}