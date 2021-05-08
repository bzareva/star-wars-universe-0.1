#ifndef __GET_STRONGEST_JEDI_COMMAND_H__
#define __GET_STRONGEST_JEDI_COMMAND_H__
#include "Command.h"
///
/// Get strongest jedi 
/// All methods which implements are from abstract base class Command
///
class GetStrongestJediCommand : public Command {

public:
	GetStrongestJediCommand() :Command(String("get_strongest_jedi")) {};

	GetStrongestJediCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		manager.get_strongest_jedi(m_parameters[0]);
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("get_strongest_jedi")) {
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

		if (!m_parameters[0].is_only_alpha()) { //planet name
			std::cerr << "\nName of planet contains invalid symbols! Must to contains only letters.!\n";
			return false;
		}

		return true;
	}

};

#endif //__GET_STRONGEST_JEDI_COMMAND_H__