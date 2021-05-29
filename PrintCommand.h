#ifndef __PRINT_COMMAND_H_
#define __PRINT_COMMAND_H_
#include "Command.h"
///
/// Print inoformation about Galaxy
/// All methods which implements are from abstract base class Command
///
class PrintCommand : public Command {

public:
	PrintCommand() :Command(String("print")) {};

	PrintCommand(const String& cmd, const Vector<String>& args) :Command(cmd, args) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		manager.print(m_parameters[0]);
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("print")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy()) {
			std::cerr << "List of arguments is empty!\n";
			return false;
		}

		if (m_parameters.size() != 1) {
			std::cerr << "\nInvalid parameters!\n";
			return false;
		}

		if (!m_parameters[0].is_only_alpha()) { //name of object
			std::cerr << "\nEnter string contains invalid symbols! Must to contains only letters!\n";
			return false;
		}

		return true;
	}

};
#endif //__PRINT_COMMAND_H_