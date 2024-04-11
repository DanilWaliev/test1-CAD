#pragma once

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "Algorithms.h"

void ShowInfo(void);

void ShowMenu(void);

int GetInt(
    std::string promptMessage = "������� ������������� ��������: ",
    std::string errorMessage = "������������ ����");

double GetDouble(
    std::string promptMessage = "������� �����: ",
    std::string errorMessage = "������������ ����");

std::string GetWord(
    std::string promptMessage = "������� ������: ",
    std::string errorMessage = "������������ ����");

bool Prompt(std::string message);