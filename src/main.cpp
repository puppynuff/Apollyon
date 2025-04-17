// ----- LICENSE -----
// Copyright (c) 2025 Kokabiel
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MARCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not,see <https://www.gnu.org/licenses/>
//
// If you need to contact me, please contact me at ari@shirodev.dev
// I will see if I can reply.

// ----- DEPENDANCIES -----
#include "./BaseCommand.h"
#include "./Commands/AboutCommand.h"
#include "./Commands/PingCommand.h"
#include <dpp/dpp.h>

// ----- MAIN FUNCTION -----
int main() {
  std::string BOT_TOKEN = std::getenv("BOT_TOKEN");

  std::vector<BaseCommand *> COMMANDS = {new PingCommand(), new AboutCommand()};

  dpp::cluster bot(BOT_TOKEN);

  std::vector<dpp::slashcommand> REGISTERED_COMMANDS = {
      {"ping", "Replies with pong!", bot.me.id},
      {"about", "Sends information about the bot", bot.me.id}};

  bot.on_ready([&bot, &REGISTERED_COMMANDS](const dpp::ready_t &event) {
    if (dpp::run_once<struct register_bot_commands>()) {
      bot.global_bulk_command_create(REGISTERED_COMMANDS);
    }

    std::cout << "Logged in as " + bot.me.username << "\n";
  });

  //  bot.on_log(dpp::utility::cout_logger());

  bot.on_slashcommand([&COMMANDS,
                       &bot](const dpp::slashcommand_t &event) -> void {
    for (int i = 0; i < COMMANDS.size(); i++) {
      if (COMMANDS[i]->getCommandName() == event.command.get_command_name()) {
        event.thinking();
        if (COMMANDS[i]->needsBot()) {
          COMMANDS[i]->run(event, bot);
          return;
        }
        COMMANDS[i]->run(event);
        return;
      }
    }
    return;
  });

  bot.start(dpp::st_wait);
  return 0;
}
