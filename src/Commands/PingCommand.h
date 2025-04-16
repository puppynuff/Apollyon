#pragma once


// ----- DEPENDENCIES -----
#include <dpp/dpp.h>
#include <string>
#include "../BaseCommand.h"

// ----- CLASSES -----
class PingCommand: public BaseCommand {
  public:
    void run(const dpp::slashcommand_t& event) {
      event.reply("Pong!");
      return;
    };

    std::string getCommandName() {
        return "ping";
    };
};
