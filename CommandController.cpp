#include "CommandController.h"
#include "AddPlanetCommand.h"
#include "CloseCommand.h"
#include "CreateJediCommand.h"
#include "DemoteJediCommand.h"
#include "ExitCommand.h"
#include "GetMostUsedSaberColor.h"
#include "GetStrongestJediCommand.h"
#include "GetYoungestJediCommand.h"
#include "HelpCommand.h"
#include "OpenCommand.h"
#include "OperatorPlusCommand.h"
#include "PrintCommand.h"
#include "PromoteJediCommand.h"
#include "RemoveJediCommand.h"
#include "SaveAsCommand.h"
#include "SaveCommand.h"


void CommandController::execute_command(GalaxyManager& cosmos) {

	for (unsigned i = 0; i < m_commands.size(); ++i) {

		try {
			m_commands[i]->execute(cosmos);

		} catch (...) {
			std::cout << "\nError during the execution of commands!\n";
		}
	}
}

void CommandController::register_command(Command* register_command) {

	m_commands.push_back(register_command);
}

void CommandController::init_command(GalaxyManager& cosmos) {

	std::cout << ">Enter file name:";
	String file;
	std::cin >> file;

	cosmos.set_file_name(file);

	String input;
	do {
		std::cout << ">command:";
		std::cin >> input;

		if (input == String("open")) {

			try {
				Command* c_open = new OpenCommand();
				register_command(c_open);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("close")) {

			try {
				Command* c_close = new CloseCommand();
				register_command(c_close);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("save")) {

			try {
				Command* c_save = new SaveCommand();
				register_command(c_save);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("saveas")) {

			try {
				Vector<String> file_name;
				std::cin >> file_name[0];

				file = file_name[0];

				//cosmos.set_file_name(file_name[0]);

				Command* c_saveas = new SaveAsCommand(input, file_name);
				register_command(c_saveas);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		}
		else if (input == String("help")) {

			try {
				Command* c_help = new HelpCommand();
				register_command(c_help);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("exit")) {

			try {
				Command* c_exit = new ExitCommand();
				register_command(c_exit);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("add_planet")) {

			try {
				Vector<String> args;
				std::cin >> args[0];

				Command* c_add = new AddPlanetCommand(input, args);
				register_command(c_add);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("create_jedi")) {

			try {
				Vector<String> args;
				unsigned i = 0;
				do {
					std::cin >> args[i];
					++i;
				} while (i < 6);

				Command* c_create = new CreateJediCommand(input, args);
				register_command(c_create);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("remove_jedi")) {

			try {
				Vector<String> args;
				unsigned i = 0;
				do {
					std::cin >> args[i];
					++i;
				} while (i < 2);

				Command* c_remove = new RemoveCommand(input, args);
				register_command(c_remove);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("promote_jedi")) {

			try {
				Vector<String> args;
				unsigned i = 0;
				do {
					std::cin >> args[i];
					++i;
				} while (i < 2);

				Command* c_promote = new PromoteJediCommand(input, args);
				register_command(c_promote);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("demote_jedi")) {

			try {
				Vector<String> args;
				unsigned i = 0;
				do {
					std::cin >> args[i];
					++i;
				} while (i < 2);

				Command* c_demote = new DemoteJediCommand(input, args);
				register_command(c_demote);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("get_strongest_jedi")) {

			try {
				Vector<String> args;
				std::cin >> args[0];

				Command* c_strong = new GetStrongestJediCommand(input, args);
				register_command(c_strong);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("get_youngest_jedi")) {

			try {
				Vector<String> args;
				unsigned i = 0;
				do {
					std::cin >> args[i];
					++i;
				} while (i < 2);

				Command* c_young = new GetYoungestJediCommand(input, args);
				register_command(c_young);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("get_most_used_saber_color")) {

			try {
				Vector<String> args;
				unsigned i = 0;
				std::cout << "\n>Enter y(yes) if you want to enter rank of jedi and n(no) only for GRAND_MASTER rank:";
				char ch;
				std::cin.get(ch);
				std::cin.ignore();

				do {
					if (ch == 'n') {
						std::cin >> args[i];
						break;
					}

					std::cin >> args[i];
					++i;
				} while (i < 2);

				Command* c_saber = new GetMostUsedSaberColorCommand(input, args);
				register_command(c_saber);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("print")) {

			try {
				std::cout << "\n>Enter first type of object which want to print(jedi(or JEDI)- printing jedi informations and planet(or PLANET)- printing planet informations):";
				Vector<String> args;
				unsigned i = 0;
				do {
					std::cin >> args[i];
					++i;
				} while (i < 2);

				Command* c_print = new PrintCommand(input, args);
				register_command(c_print);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("+")) {

			try {
				Vector<String> args;
				unsigned i = 0;
				do {
					std::cin >> args[i];
					++i;
				} while (i < 2);

				Command* c_plus = new OperatorPlusCommand(input, args);
				register_command(c_plus);

			} catch (std::runtime_error& e) {
				std::cerr << e.what();
			}
		} 

	} while (input !=  String("exit"));

	execute_command(cosmos);
}