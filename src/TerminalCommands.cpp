// ----- LICENSE -----
// Copyright (C) 2025 Kokabiel
// Licensed under the GNU General Public License v3.0
// Please look at ./main.cpp for more information.

// ----- DEPENDANCIES -----
#include "./TerminalCommands.h"
#include "main.h"

// ----- FUNCTIONS -----
void handleConsole() {
  std::string userInput;
  std::cout << "> ";
  std::getline(std::cin, userInput);

  if (userInput == "show c") {
    std::cout << "YOU ARE ALLOWED TO MODIFY OR PROPOGATE THIS SOFTWARE HOWEVER "
                 "YOU SEE FIT, AS LONG AS IT FOLLOWS THIS LICENSE, AND THE "
                 "SOFTWARE USING IT IS \n1. OPEN SOURCE \n2. YOU LEAVE ALL "
                 "LICENSE AND COPYRIGHT NOTICES INTACT\n3. YOU STATE CHANGES "
                 "TO THE SOFTWARE\n4. THE SOFTWARE DEVELOPED USING THIS IS "
                 "USING THE GNU GENERAL PUBLIC LICENSE V3.0\n5. AND YOU "
                 "DISCLOSE THE ORIGINAL SOURCE OF THE SOFTWARE."
              << "\n";
  } else if (userInput == "show w") {
    std::cout
        << "15. Disclaimer of warranty.\n"
        << "THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTEND PERMITTED BY "
           "APPLICABLE LAW. EXCEPT WHEN OTHERWISE STATED IN WRITING THE "
           "COPYRIGHT HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM \"AS "
           "IS\" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, "
           "INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF "
           "MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE ENTIRE "
           "RISK AS TO THE THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH "
           "YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF "
           "ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n"
        << "16. Disclaimer of Liability.\n"
        << "IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN "
           "WRITING WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES "
           "AND/OR CONVEYS THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU "
           "FOR DAMAGES, INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR "
           "CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE "
           "THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA "
           "BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD "
           "PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER "
           "PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF "
           "THE POSSIBILITY OF SUCH DAMAGES.\n";
  } else if (userInput == "exit") {
    std::cout << "Closing!" << "\n";
    std::exit(0);
  } else if (userInput == "clear") {
    clearConsole();
    printLicenseInfo();
  } else {
    std::cout << "Unknown command!" << "\n";
  }

  handleConsole();
}
