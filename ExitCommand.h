#ifndef __EXIT_COMMAND_H__
#define __EXIT_COMMAND_H__
#include "Command.h"
///
/// Exit program 
/// All methods which implements are from abstract base class Command
///
class ExitCommand : public Command {

public:
	ExitCommand() :Command(String("exit")) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		manager.exit_command();
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("exit")) {
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

#endif //__EXIT_COMMAND_H__