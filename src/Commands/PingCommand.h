#pragma once

// ----- LICENSE -----
// Copyright (C) 2025 Kokabiel
// Licensed under the GNU General Public License v3.0
// Please check ../main.cpp for more information.

// ----- DEPENDENCIES -----
#include "../BaseCommand.h"
#include <dpp/dpp.h>
#include <string>

// ----- CLASSES -----
class PingCommand : public BaseCommand {
public:
  void run(const dpp::slashcommand_t &event) override {
    event.edit_response("Pong!");
    return;
  };

  bool needsBot() override { return false; }

  std::string getCommandName() override { return "ping"; };

  dpp::slashcommand buildCommand(dpp::cluster &bot) override {
    dpp::slashcommand pingcommand("ping", "Replies with pong!", bot.me.id);

    return pingcommand;
  }
};
