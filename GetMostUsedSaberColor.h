#ifndef __GET_MOST_USED_SABER_COLOR_COMMAND_H__
#define __GET_MOST_USED_SABER_COLOR_COMMAND_H__
#include "Command.h"

class GetMostUsedSaberColorCommand : public Command {

public:
	GetMostUsedSaberColorCommand() :Command(String("get_most_used_saber_color")) {};

	inline void execute(GalaxyManager& manager) override {

		if (!is_valid()) {
			return;
		}

		if (m_parameters.size() == 1) {
			manager.get_most_used_saber_color(m_parameters[0]);
		}

		if (m_parameters.size() == 2) {
			Rank rank = m_parameters[1].convert_to_rank(m_parameters[1].get_string());
			manager.get_most_used_saber_color(m_parameters[0], rank);
		}
	}


	inline bool is_valid()const override {

		if (m_command_name != String("get_most_used_saber_color")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy() || m_types.empy()) {
			std::cerr << "List of arguments is empty!\n";
			return false;
		}

		if (m_parameters.size() != 1 && m_parameters.size() != 2) {
			std::cerr << "\nArguments are not correct!\n";
			return false;
		}

		if (m_types.size() == 1 && (m_types[0] != TypeParameters::STRING)) {
			std::cerr << "\nTypes of the given argument is not valid!\n";
			return false;
		}

		if (m_types.size() == 2 && (m_types[0] != TypeParameters::STRING || m_types[1] != TypeParameters::RANK)) {
			std::cerr << "\nTypes of the given argument is not valid!\n";
			return false;
		}

		return true;
	}

};

#endif //__GET_MOST_USED_SABER_COLOR_COMMAND_H__