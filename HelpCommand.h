#ifndef __HELP_COMMAND_H__
#define __HELP_COMMAND_H__
#include "Command.h"

class HelpCommand : public Command {

public:
	HelpCommand() :Command(String("help")) {};

	inline void execute(GalaxyManager& manager) override {

		if (!is_valid()) {
			return;
		}

		manager.help();
	}

private:
	inline bool is_valid()const override {

		if (m_command_name != String("help")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (!m_parameters.empy()) {
			std::cerr << "\nThis command do not need arguments!\n";
			return false;
		}

		if (!m_types.empy()) {
			std::cerr << "\nThis command do not need types of arguments!\n";
			return false;
		}

		return true;
	}

};

#endif //__HELP_COMMAND_H__