#pragma once

// ----- LICENSE -----
// Copyright (C) 2025 Kokabiel
// Licesed under the GNU General Public License v3.0
// Please look at ./main.cpp for more information.

// ----- DEPENDANCIES -----
#include "./BaseCommand.h"
#include "./Commands/AboutCommand.h"
#include "./Commands/PingCommand.h"
#include "./TerminalCommands.h"
#include <dpp/dpp.h>
#include <thread>

// ----- FUNCTIONS -----
inline void printLicenseInfo() {
  std::cout
      << "Apollyon Copyright (C) 2025 Kokabiel \n"
      << "This program comes with ABSOLUTELY NO WARRANTY; for details type "
         "`show w` \n"
      << "This is free software, and you are welcome to redistribute it \n"
      << "under certain conditions; type `show c` for details. \n"
      << "This software is licensed under the GNU General Public License "
         "v3.0 \n\n";
}
