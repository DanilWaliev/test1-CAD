#pragma once

#include <iostream>
#include <string>

void testInput(void);

void ShowInfo(void);

int GetInt(std::string promptMessage = "Введите целочисленное значение: ",
    std::string errorMessage = "Некорректный ввод!");

double GetDouble(std::string promptMessage = "Введите число: ",
    std::string errorMessage = "Некорректный ввод!");