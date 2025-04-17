#pragma once

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
};
