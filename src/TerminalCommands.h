#pragma once
// ----- LICENSE -----
// Copyright (C) 2025 Kokabiel
// Licensed under the GNU General Public License v3.0
// Please look at ./main.cpp for more information.

// ----- DEPENDANCIES -----
#include "./main.h"
#include <iostream>

// ----- FUNCTIONS -----
#ifdef _WIN32
// UNTESTED. MIGHT NOT WORK AS EXPECTED.
inline void clearConsole() { std::system("cls"); }
#else
inline void clearConsole() { std::cout << "\x1b[2J\x1b[H"; }
#endif

// ----- FUNCTIONS -----
void handleConsole();
