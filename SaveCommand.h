#ifndef __SAVE_COMMAND_H__
#define __SAVE_COMMAND_H__
#include "Command.h"
///
/// Save information in current opened file
/// All methods which implements are from abstract base class Command
///
class SaveCommand : public Command {

public:
	SaveCommand(const String& cmd = String("save")) :Command(cmd) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		try {
			manager.save();

		} catch (std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
		}
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("save")) {
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

#endif //__SAVE_COMMAND_H__