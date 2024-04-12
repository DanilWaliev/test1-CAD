#pragma once

#include <iomanip>
#include <conio.h>
#include "Employee.h"
#include "MyFunctions.h"
#include "Interface.h"

void FileInput(std::vector<Employee>& company);

void ConsoleInput(std::vector<Employee>& company);

void PrintTable(std::vector<Employee>& company, std::ostream& out);

void ClearData(std::vector<Employee>& vector);

void SaveAsFile(std::vector<Employee>& company);

void FilterByWorkExperience(std::vector<Employee>& company);

void FilterBySalary(std::vector<Employee>& company);

 void FilterByPosition(std::vector<Employee>& company);

 void Input(std::vector<Employee>& company);

 void Output(std::vector<Employee>& company);

 void Filter(std::vector<Employee>& company);