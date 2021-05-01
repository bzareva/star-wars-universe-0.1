#ifndef __GET_YOUNGEST_JEDI_COMMAND_H__
#define __GET_YOUNGEST_JEDI_COMMAND_H__
#include "Command.h"
/*!
 * Get youngest jedi
 * All methods which implements are from abstract base class Command
 */
class GetYoungestJediCommand : public Command {

public:
	GetYoungestJediCommand() :Command(String("get_youngest_jedi")) {};

	GetYoungestJediCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline void execute(GalaxyManager& manager) override {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		Rank rank = m_parameters[1].convert_to_rank(m_parameters[1].get_string());
		manager.get_youngest_jedi(m_parameters[0], rank);
	}

private:	
	inline bool is_valid()const override {

		if (m_command_name != String("get_youngest_jedi")) {
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

#endif //__GET_YOUNGEST_JEDI_COMMAND_H__