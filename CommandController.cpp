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


void CommandController::execute_command(const String& file_name) {

	GalaxyManager curr(file_name);
	for (unsigned i = 0; i < m_commands.size(); ++i) {
		m_commands[i]->execute(curr);
	}
}

void CommandController::register_command(Command* register_command) {

	m_commands.push_back(register_command);
}

void CommandController::init_command() {

	std::cout << ">Enter file name:";
	String file;
	std::cin >> file;

	String input;
	do {

		std::cout << ">command:";
		std::cin >> input;

		if (input == String("open")) {

			OpenCommand* c_open = new OpenCommand();
			register_command(c_open);

		} else if (input == String("close")) {

			CloseCommand* c_close = new CloseCommand();
			register_command(c_close);

		} else if (input == String("save")) {

			SaveCommand* c_save = new SaveCommand();
			register_command(c_save);

		} else if (input == String("saveas")) {

			Vector<String> file_name;
			unsigned i = 0;
			do {
				std::cin >> file_name[i];
				++i;
			} while (i < 1);

			SaveAsCommand* c_saveas = new SaveAsCommand(input, file_name);
			register_command(c_saveas);

		} else if (input == String("help")) {

			HelpCommand* c_help = new HelpCommand();
			register_command(c_help);

		} else if (input == String("exit")) {

			ExitCommand* c_exit = new ExitCommand();
			register_command(c_exit);

		} else if (input == String("add_planet")) {

			Vector<String> args;
			std::cin >> args[0];
			/*unsigned i = 0;
			do {
				std::cin >> args[i];
				++i;
			} while (i < 1);*/

			AddPlanetCommand* c_add = new AddPlanetCommand(input, args);
			register_command(c_add);

		} else if (input == String("create_jedi")) {

			Vector<String> args;
			unsigned i = 0;
			do {
				std::cin >> args[i];
				++i;
			} while (i < 6);

			CreateJediCommand* c_create = new CreateJediCommand(input, args);
			register_command(c_create);

		} else if (input == String("remove_jedi")) {

			Vector<String> args;
			unsigned i = 0;
			do {
				std::cin >> args[i];
				++i;
			} while (i < 2);

			RemoveCommand* c_remove = new RemoveCommand(input, args);
			register_command(c_remove);

		} else if (input == String("promote_jedi")) {

			Vector<String> args;
			unsigned i = 0;
			do {
				std::cin >> args[i];
				++i;
			} while (i < 2);

			PromoteJediCommand* c_promote = new PromoteJediCommand(input, args);
			register_command(c_promote);

		} else if (input == String("demote_jedi")) {

			Vector<String> args;
			unsigned i = 0;
			do {
				std::cin >> args[i];
				++i;
			} while (i < 2);

			DemoteJediCommand* c_demote = new DemoteJediCommand(input, args);
			register_command(c_demote);

		} else if (input == String("get_strongest_jedi")) {

			Vector<String> args;
			std::cin >> args[0];
			/*unsigned i = 0;
			do {
				std::cin >> args[i];
				++i;
			} while (i < 1);*/

			GetStrongestJediCommand* c_strong = new GetStrongestJediCommand(input, args);
			register_command(c_strong);

		} else if (input == String("get_youngest_jedi")) {

			Vector<String> args;
			unsigned i = 0;
			do {
				std::cin >> args[i];
				++i;
			} while (i < 2);

			GetYoungestJediCommand* c_young = new GetYoungestJediCommand(input, args);
			register_command(c_young);

		} else if (input == String("get_most_used_saber_color")) {

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

		} else if (input == String("print")) {

			std::cout << "\n>Enter first type of object which want to print(jedi(or JEDI)- printing jedi informations and planet(or PLANET)- printing planet informations):";
			Vector<String> args;
			unsigned i = 0;
			do {
				std::cin >> args[i];
				++i;
			} while (i < 2);

			PrintCommand* c_print = new PrintCommand(input, args);
			register_command(c_print);

		} else if (input == String("+")) {

			Vector<String> args;
			unsigned i = 0;
			do {
				std::cin >> args[i];
				++i;
			} while (i < 2);

			OperatorPlusCommand* c_plus = new OperatorPlusCommand(input, args);
			register_command(c_plus);

		} 

	} while (input !=  String("exit"));

	execute_command(file);
}