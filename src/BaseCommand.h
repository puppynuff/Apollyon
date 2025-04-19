#pragma once

// ----- LICENSE -----
// Copyright (C) 2025 Kokabiel
// Licensed under the GNU Public License v3.0
// Please look at ./main.cpp for more details.

// ----- DEPENDANCIES -----
#include <dpp/dpp.h>
#include <string>

// ----- CLASSES ------
class BaseCommand {
public:
  virtual void run(const dpp::slashcommand_t &event) {
    event.reply("In development!");
    return;
  };

  virtual void run(const dpp::slashcommand_t &event, const dpp::cluster &bot) {
    event.reply("In development!");
    return;
  }

  virtual dpp::slashcommand buildCommand(dpp::cluster &bot) {
    dpp::slashcommand emptycommand("null", "null", bot.me.id);

    return emptycommand;
  };

  virtual bool needsBot() { return false; }

  virtual std::string getCommandName() { return "Not defined"; };
};
