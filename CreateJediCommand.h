#ifndef __CREATE_JEDI_COMMAND_H__
#define __CREATE_JEDI_COMMAND_H__
#include "Command.h"
/*!
 * Create jedi
 */
class CreateJediCommand : public Command {

public:
	CreateJediCommand() :Command(String("create_jedi")) {};

	CreateJediCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline void execute(GalaxyManager& manager) override {

		if (!is_valid()) {
			return;
		}

		Rank rank            = m_parameters[2].convert_to_rank(m_parameters[2].get_string());
		unsigned jedi_age    = m_parameters[3].convert_to_integer(m_parameters[3].get_string());
		double jedi_strength = m_parameters[5].convert_to_double(m_parameters[5].get_string());

		manager.create_jedi(m_parameters[0], m_parameters[1], rank, jedi_age, m_parameters[4], jedi_strength);
	}
	
private:
	inline bool is_valid()const override {

		if (m_command_name != String("create_jedi")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy() || m_types.empy()) {
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

		if (m_types[0] != TypeParameters::STRING  //planet name
			|| m_types[1] != TypeParameters::STRING // jedi name
			|| m_types[2] != TypeParameters::RANK // jedi rank
			|| m_types[3] != TypeParameters::INTEGER // jedi age
			|| m_types[4] != TypeParameters::STRING // saber color
			|| m_types[5] != TypeParameters::DOUBLE) { // jedi strength

			std::cerr << "\nTypes of the given argument is not valid!\n";
			return false;
		}

		return true;
	}

};

#endif //__CREATE_JEDI_COMMAND_H__