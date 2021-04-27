#ifndef __GET_YOUNGEST_JEDI_COMMAND_H__
#define __GET_YOUNGEST_JEDI_COMMAND_H__
#include "Command.h"

class GetYoungestJediCommand : public Command {

public:
	GetYoungestJediCommand() :Command(String("get_youngest_jedi")) {};

	inline void execute(GalaxyManager& manager) override {

		if (!is_valid()) {
			return;
		}

		Rank rank = m_parameters[1].convert_to_rank(m_parameters[1].get_string());
		manager.get_youngest_jedi(m_parameters[0], rank);
	}

	
	inline bool is_valid()const override {

		if (m_command_name != String("get_youngest_jedi")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy() || m_types.empy()) {
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

		if (m_types[0] != TypeParameters::STRING || m_types[1] != TypeParameters::RANK) {
			std::cerr << "\nTypes of the given argument is not valid!\n";
			return false;
		}

		return true;
	}

};

#endif //__GET_YOUNGEST_JEDI_COMMAND_H__