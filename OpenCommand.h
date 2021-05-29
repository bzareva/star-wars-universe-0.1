#ifndef __OPEN_COMMAND_H__
#define __OPEN_COMMAND_H__
#include "Command.h"
///
/// Open file
/// All methods which implements are from abstract base class Command
///
class OpenCommand : public Command {

public:
	OpenCommand(const String& cmd = String("open")) :Command(cmd) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		try {
			manager.open_file();

		} catch (std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
		}
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("open")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (!m_parameters.empy()) {
			std::cerr << "List of arguments is not empty!\n";
			return false;
		}

		return true;
	}

};

#endif //__OPEN_COMMAND_H__