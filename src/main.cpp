// ----- DEPENDANCIES -----
#include <dpp/dpp.h>
#include "./BaseCommand.h"
#include "./Commands/PingCommand.h"

// ----- MAIN FUNCTION -----
int main() {
  std::string BOT_TOKEN = std::getenv("BOT_TOKEN");

  BaseCommand* COMMANDS[1] = { new PingCommand() };


  dpp::cluster bot(BOT_TOKEN);

  std::vector<dpp::slashcommand> REGISTERED_COMMANDS = {
    { "ping", "Replies with pong!", bot.me.id }
  };

  bot.on_ready([&bot, &REGISTERED_COMMANDS](const dpp::ready_t& event) {
      if(dpp::run_once<struct register_bot_commands>()) {
        bot.global_bulk_command_create(REGISTERED_COMMANDS);
      }

      std::cout << "Logged in as " + bot.me.username << "\n";  
  });


  bot.on_slashcommand([&COMMANDS](const dpp::slashcommand_t& event) -> void {
    for(int i = 0; i < sizeof(COMMANDS) / sizeof(COMMANDS[0]); i++) {
      if(COMMANDS[i]->getCommandName() == event.command.get_command_name()) {
        COMMANDS[i]->run(event);
      }
    }

    return;
  });

  bot.start(dpp::st_wait);
  return 0;
}
