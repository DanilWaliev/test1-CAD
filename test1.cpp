#include <iostream>
#include <string>
#include "employee.h"

int main()
{
    std::vector<Employee> myCompany = Employee::MakeCompany(10);

    std::cout << myCompany[3].GetName() << std::endl;

}


