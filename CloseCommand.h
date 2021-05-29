#ifndef __CLOSE_COMMAND_H__
#define __CLOSE_COMMAND_H__
#include "Command.h"
///
/// Closes file with which is works 
/// All methods which implements are from abstract base class Command
///
class CloseCommand : public Command {

public:
	CloseCommand() :Command(String("close")) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		try {
			manager.close_file();

		} catch (std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
		}
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("close")) {
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

#endif //__CLOSE_COMMAND_H__