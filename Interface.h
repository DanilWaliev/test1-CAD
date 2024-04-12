#pragma once

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "Algorithms.h"

void ShowInfo(void);

void ShowMenu(void);

void ShowMainMenu(void);

void ShowInputMenu(void);

void ShowOutputMenu(void);

void ShowFilterMenu(void);

int GetInt(
    std::string promptMessage = "Введите целочисленное значение: ",
    std::string errorMessage = "Некорректный ввод");

double GetDouble(
    std::string promptMessage = "Введите число: ",
    std::string errorMessage = "Некорректный ввод");

std::string GetWord(
    std::string promptMessage = "Введите строку: ",
    std::string errorMessage = "Некорректный ввод");

bool Prompt(std::string message);