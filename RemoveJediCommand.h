#ifndef __REMOVE_COMMAND_H__
#define __REMOVE_COMMAND_H__
#include "Command.h"
///
/// Remove jedi form given planet
/// All methods which implements are from abstract base class Command
///
class RemoveCommand : public Command {

public:
	RemoveCommand() :Command(String("remove_jedi")) {};

	RemoveCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		manager.remove_jedi(m_parameters[0], m_parameters[1]);
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("remove_jedi")) {
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
#endif //__REMOVE_COMMAND_H__