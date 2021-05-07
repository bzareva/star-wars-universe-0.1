#ifndef __HELP_COMMAND_H__
#define __HELP_COMMAND_H__
#include "Command.h"
///
/// Prints message about all supported commands
/// All methods which implements are from abstract base class Command
///
class HelpCommand : public Command {

public:
	HelpCommand() :Command(String("help")) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		manager.help();
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("help")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (!m_parameters.empy()) {
			std::cerr << "\nThis command do not need arguments!\n";
			return false;
		}

		return true;
	}

};

#endif //__HELP_COMMAND_H__