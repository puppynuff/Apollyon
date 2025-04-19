#pragma once

// ----- LICENSE -----
// Copyright (C) 2025 Kokabiel
// Licensed under the GNU General Public License v3.0
// Please check ../main.cpp for more information.

// ----- DEPENDANCIES -----
#include "../BaseCommand.h"
#include <dpp/dpp.h>

// ----- CLASSES -----
class AboutCommand : public BaseCommand {
public:
  std::string getCommandName() override { return "about"; }

  void run(const dpp::slashcommand_t &event, const dpp::cluster &bot) override {
    dpp::embed embed =
        dpp::embed()
            .set_color(dpp::colors::black)
            .set_title("About Apollyon")
            .set_url("https://github.com/puppynuff/apollyon")
            .set_author("Kokabiel", "https://github.com/puppynuff",
                        "https://avatars.githubusercontent.com/u/67881941?v=4")
            .set_description("Information about the bot and the developer")
            .set_thumbnail(bot.me.get_avatar_url())
            .add_field("Developer", "Kokabiel / Ari")
            .add_field("Development language", "C++")
            .add_field("Version", "0.10")
            .set_timestamp(time(0));

    event.edit_original_response(embed);

    return;
  };

  bool needsBot() override { return true; }

  dpp::slashcommand buildCommand(dpp::cluster &bot) override {
    dpp::slashcommand aboutcommand("about", "Sends information about the bot",
                                   bot.me.id);

    return aboutcommand;
  }
};
