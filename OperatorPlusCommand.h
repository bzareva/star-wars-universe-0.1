#ifndef __OPERATOR_PLUS_COMMAND_H__
#define __OPERATOR_PLUS_COMMAND_H__
#include "Command.h"
/*!
 * Console outputs is sorted form(lexicographic) information about the inhabitants two Jedi planetsle
 * All methods which implements are from abstract base class Command
 */
class OperatorPlusCommand : public Command {

public:
	OperatorPlusCommand() :Command(String("+")) {};

	OperatorPlusCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline void execute(GalaxyManager& manager) override {

		if (!is_valid()) {
			return;
		}

		manager.operator_plus(m_parameters[0], m_parameters[1]);
	}

private:
	inline bool is_valid()const override {

		if (m_command_name != String("+")) {
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
#endif //__OPERATOR_PLUS_COMMAND_H__