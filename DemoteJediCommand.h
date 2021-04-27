#ifndef __DEMOTE_JEDI_COMMAND_H__
#define __DEMOTE_JEDI_COMMAND_H__
#include "Command.h"

class DemoteJediCommand : public Command {

public:
	DemoteJediCommand() :Command(String("demote_jedi")) {};

	inline void execute(GalaxyManager& manager) override {

		if (!is_valid()) {
			return;
		}

		double multiplier = m_parameters[1].convert_to_double(m_parameters[1].get_string());
		manager.demote_jedi(m_parameters[0], multiplier);
	}


	inline bool is_valid()const override {

		if (m_command_name != String("demote_jedi")) {
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

		if (m_types[0] != TypeParameters::STRING || m_types[1] != TypeParameters::DOUBLE) { 
			std::cerr << "\nTypes of the given argument is not valid!\n";
			return false;
		}

		return true;
	}

};

#endif //__DEMOTE_JEDI_COMMAND_H__