#ifndef __PRINT_COMMAND_H_
#define __PRINT_COMMAND_H_
#include "Command.h"

class PrintCommand : public Command {

public:
	PrintCommand() :Command(String("print")) {};

	inline void execute(GalaxyManager& manager) override {

		if (!is_valid()) {
			return;
		}

		manager.print(m_parameters[0], m_parameters[1]);
	}


	inline bool is_valid()const override {

		if (m_command_name != String("print")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy() || m_types.empy()) {
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

		if (m_types[0] != TypeParameters::STRING || m_types[1] != TypeParameters::STRING) {
			std::cerr << "\nTypes of the given argument is not valid!\n";
			return false;
		}

		return true;
	}

};
#endif //__PRINT_COMMAND_H_