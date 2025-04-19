#pragma once

// ----- LICENSE -----
// Copyright (C) 2025 Kokabiel
// Licensed under the GNU General Public License v3.0
// Please check ../main.cpp for more information.

// ----- DEPENDANCIES -----
#include "../BaseCommand.h"
#include <dpp/appcommand.h>
#include <dpp/dpp.h>
#include <string>

// ----- CLASS -----
class EmbedCommand : public BaseCommand {
public:
  void run(const dpp::slashcommand_t &event) override;

  std::string getCommandName() override { return "embed"; };

  bool needsBot() override { return false; };

  dpp::slashcommand buildCommand(dpp::cluster &bot) override {
    dpp::slashcommand embedcommand("embed", "Embeds a message!", bot.me.id);

    // NOTE: I NEED TO IMPLEMENT THE DASHBOARD FOR THIS COMMAND.
    // This will just do a bsic embed for the user.
    embedcommand.add_option(dpp::command_option(dpp::co_string, "message",
                                                "The message to embed", true));

    return embedcommand;
  }
};
