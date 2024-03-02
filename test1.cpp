#include <iostream>
#include <string>

class Employee 
{
private:
    std::string name{ "Undefined" };
    std::string surname{ "Undefined" };
    std::string patronymic{ "Undefined" };
    std::string position{ "Undefined" };
    int entryYear{ 0 };
    int salary{ 0 };
public:
    void ShowInfo() 
    {
        std::cout << "Name: " << name << std::endl;
    }

    void SetName(std::string name) 
    {
        // добавить логику ввода имени
        this->name = name;
    }
    
    void SetEntryYear(int age) 
    {    
        // добавить логику ввода года принятия на работу
        this->entryYear = entryYear;
    }

    void SetSalary(int salary)
    {
        this->salary = salary;
    }

    std::string GetName(void)
    {
        return this->name;
    }

    int GetEntryYear(void)
    {
        return this->entryYear;
    }

    int GetSalary(void)
    {
        return this->salary;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

}


