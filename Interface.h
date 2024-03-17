#pragma once

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "Algorithms.h"

void ShowInfo(void);

void ShowMenu(void);

int GetInt(std::string promptMessage = "Введите целочисленное значение: ",
    std::string errorMessage = "Некорректный ввод!");

double GetDouble(std::string promptMessage = "Введите число: ",
    std::string errorMessage = "Некорректный ввод!");

void ReadFile(std::string source);