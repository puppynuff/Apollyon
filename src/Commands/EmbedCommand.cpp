// ----- LICENSE -----
// Copyright (C) 2025 Kokabiel
// Licensed under the GNU General Public License v3.0
// Please check ../main.cpp for more information.

// ----- DEPENDANCIES -----
#include "./EmbedCommand.h"

// ----- FUNCTIONS -----
void EmbedCommand::run(const dpp::slashcommand_t &event) {
  const std::string input =
      std::get<std::string>(event.get_parameter("message"));

  const dpp::embed embed =
      dpp::embed()
          .set_title(event.command.get_issuing_user().username)
          .set_thumbnail(event.command.get_issuing_user().get_avatar_url())
          .set_description(input);
  event.edit_response(embed);
}
