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


void CommandController::execute_command(const String& file_name, GalaxyManager& cosmos) {

	for (unsigned i = 0; i < m_commands.size(); ++i) {
		m_commands[i]->execute(cosmos);
	}
}

void CommandController::register_command(Command* register_command) {

	m_commands.push_back(register_command);
}

void CommandController::init_command(GalaxyManager& cosmos) {

	String file = cosmos.get_file_name();
	String input;
	do {
		std::cout << ">command:";
		std::cin >> input;

		if (input == String("open")) {

			try {
				OpenCommand* c_open = new OpenCommand();
				register_command(c_open);
			}
			catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("close")) {

			try {
				CloseCommand* c_close = new CloseCommand();
				register_command(c_close);
			}
			catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("save")) {

			try {
				SaveCommand* c_save = new SaveCommand();
				register_command(c_save);
			}
			catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("saveas")) {

			try {
				Vector<String> file_name;
				std::cin >> file_name[0];

				file = file_name[0];

				SaveAsCommand* c_saveas = new SaveAsCommand(input, file_name);
				register_command(c_saveas);
			}
			catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		}
		else if (input == String("help")) {

			try {
				HelpCommand* c_help = new HelpCommand();
				register_command(c_help);
			}
			catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("exit")) {

			try {
				ExitCommand* c_exit = new ExitCommand();
				register_command(c_exit);
			}
			catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("add_planet")) {

			try {
				Vector<String> args;
				std::cin >> args[0];

				AddPlanetCommand* c_add = new AddPlanetCommand(input, args);
				register_command(c_add);
			}
			catch (std::runtime_error& e) {
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

				CreateJediCommand* c_create = new CreateJediCommand(input, args);
				register_command(c_create);
			}
			catch (std::runtime_error& e) {
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

				RemoveCommand* c_remove = new RemoveCommand(input, args);
				register_command(c_remove);
			}
			catch (std::runtime_error& e) {
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

				PromoteJediCommand* c_promote = new PromoteJediCommand(input, args);
				register_command(c_promote);
			}
			catch (std::runtime_error& e) {
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

				DemoteJediCommand* c_demote = new DemoteJediCommand(input, args);
				register_command(c_demote);
			}
			catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} else if (input == String("get_strongest_jedi")) {

			try {
				Vector<String> args;
				std::cin >> args[0];

				GetStrongestJediCommand* c_strong = new GetStrongestJediCommand(input, args);
				register_command(c_strong);
			}
			catch (std::runtime_error& e) {
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

				GetYoungestJediCommand* c_young = new GetYoungestJediCommand(input, args);
				register_command(c_young);
			}
			catch (std::runtime_error& e) {
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

				GetMostUsedSaberColorCommand* c_saber = new GetMostUsedSaberColorCommand(input, args);
				register_command(c_saber);
			}
			catch (std::runtime_error& e) {
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

				PrintCommand* c_print = new PrintCommand(input, args);
				register_command(c_print);
			}
			catch (std::runtime_error& e) {
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

				OperatorPlusCommand* c_plus = new OperatorPlusCommand(input, args);
				register_command(c_plus);
			}
			catch (std::runtime_error& e) {
				std::cerr << e.what();
			}

		} 

	} while (input !=  String("exit"));

	execute_command(file, cosmos);
}