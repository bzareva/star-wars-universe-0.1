#ifndef __DEMOTE_JEDI_COMMAND_H__
#define __DEMOTE_JEDI_COMMAND_H__
#include "Command.h"
///
/// Demote jedi 
/// All methods which implements are from abstract base class Command
///
class DemoteJediCommand : public Command {

public:
	DemoteJediCommand() :Command(String("demote_jedi")) {};

	DemoteJediCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		double multiplier = m_parameters[1].convert_to_double(m_parameters[1].get_string());
		manager.demote_jedi(m_parameters[0], multiplier);
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("demote_jedi")) {
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

#endif //__DEMOTE_JEDI_COMMAND_H__