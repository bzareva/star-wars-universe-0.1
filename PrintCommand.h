#ifndef __PRINT_COMMAND_H_
#define __PRINT_COMMAND_H_
#include "Command.h"
/*!
 * Print inoformation about Galaxy
 * All methods which implements are from abstract base class Command
 */
class PrintCommand : public Command {

public:
	PrintCommand() :Command(String("print")) {};

	PrintCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline void execute(GalaxyManager& manager) override {

		if (!is_valid()) {
			return;
		}

		manager.print(m_parameters[0], m_parameters[1]);
	}

private:
	inline bool is_valid()const override {

		if (m_command_name != String("print")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy()) {
			std::cerr << "List of arguments is empty!\n";
			return false;
		}

		if (m_parameters.size() < 2) {
			std::cerr << "\nThere are some missing arguments for execution to this command!\n";
			return false;
		}

		if (m_parameters.size() > 2) {
			std::cerr << "\nToo much arguments for execution to this command!\n";
			return false;
		}

		return true;
	}

};
#endif //__PRINT_COMMAND_H_