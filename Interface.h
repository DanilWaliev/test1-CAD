#pragma once

#include <iostream>
#include <string>

void testInput(void);

void ShowInfo(void);

int GetInt(std::string promptMessage = "������� ������������� ��������: ",
    std::string errorMessage = "������������ ����!");

double GetDouble(void);