#ifndef __SAVE_AS_COMMAND_H__
#define __SAVE_AS_COMMAND_H__
#include "Command.h"
///
/// Saves information in new file, which is given from user
/// All methods which implements are from abstract base class Command
///
class SaveAsCommand : public Command {

public:
	SaveAsCommand() :Command(String("saveas")) {};

	SaveAsCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		manager.save_as(m_parameters[0]);
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("saveas")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy()) {
			std::cerr << "List of arguments is empty!\n";
			return false;
		}

		if (m_parameters.size() < 1) {
			std::cerr << "\nThere are some missing arguments for execution to this command!\n";
			return false;
		}

		if (m_parameters.size() > 1) {
			std::cerr << "\nToo much arguments for execution to this command!\n";
			return false;
		}
		
		return true;
	}

};

#endif //__SAVE_AS_COMMAND_H__