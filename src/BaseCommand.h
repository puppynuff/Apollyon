#pragma once

// ----- DEPENDANCIES -----
#include <dpp/dpp.h>
#include <string>

// ----- CLASSES ------
class BaseCommand {
  public:
    virtual void run(const dpp::slashcommand_t& event) {
      event.reply("In development!");
      return;
    };

    virtual std::string getCommandName() {
      return "Not defined";
    };
};
