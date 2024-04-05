#pragma once

#include "Employee.h"
#include "MyFunctions.h"
#include "Interface.h"

void FileInput(std::vector<Employee>& company, std::string source);

void ConsoleInput(std::vector<Employee>& company);

void ShowData(std::vector<Employee>& company);

void SaveAsFile(std::vector<Employee>& company);

std::vector<Employee> FilterByWorkExperience(std::vector<Employee>& company);

std::vector<Employee> FilterBySalary(std::vector<Employee>& company);

std::vector<Employee> FilterByPosition(std::vector<Employee>& company);