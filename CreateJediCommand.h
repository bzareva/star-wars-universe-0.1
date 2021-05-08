#ifndef __CREATE_JEDI_COMMAND_H__
#define __CREATE_JEDI_COMMAND_H__
#include "Command.h"
///
/// Create jedi
/// Only methods which implements are from abstract base class Command
///
class CreateJediCommand : public Command {

public:
	CreateJediCommand() :Command(String("create_jedi")) {};

	CreateJediCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		Rank rank            = m_parameters[2].convert_to_rank(m_parameters[2].get_string());
		unsigned jedi_age    = m_parameters[3].convert_to_integer(m_parameters[3].get_string());
		double jedi_strength = m_parameters[5].convert_to_double(m_parameters[5].get_string());

		manager.create_jedi(m_parameters[0], m_parameters[1], rank, jedi_age, m_parameters[4], jedi_strength);
	}
	
private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("create_jedi")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy()) {
			std::cerr << "List of arguments is empty!\n";
			return false;
		}

		if (m_parameters.size() < 6) {
			std::cerr << "\nThere are some missing arguments for execution to this command!\n";
			return false;
		}

		if (m_parameters.size() > 6) {
			std::cerr << "\nToo much arguments for execution to this command!\n";
			return false;
		}

		if (!m_parameters[0].is_only_alpha()) { //planet name
			std::cerr << "\nName of planet contains invalid symbols! Must to contains only letters.!\n";
			return false;
		}

		if (!m_parameters[1].is_only_alpha()) { //jedi name
			std::cerr << "\nName of Jedi contains invalid symbols! Must to contains only letters.!\n";
			return false;
		}

		if (!m_parameters[2].is_valid_rank()) { //jedi rank
			std::cerr << "\nJedi rank contains invalid symbols! Must to contains only letters.!\n";
			return false;
		}

		if (!m_parameters[3].is_only_digits()) { //jedi age
			std::cerr << "\nJedi age contains invalid symbols! Must to contains only digits.!\n";
			return false;
		}
		
		if (!m_parameters[4].is_only_alpha()) { //saber color
			std::cerr << "\nJedi age contains invalid symbols! Must to contains only letters.!\n";
			return false;
		}

		if (!m_parameters[5].is_only_digits()) { //jedi force
			std::cerr << "\nJedi force contains invalid symbols! Must to contains only digits.!\n";
			return false;
		}

		return true;
	}

};

#endif //__CREATE_JEDI_COMMAND_H__