#ifndef __GET_MOST_USED_SABER_COLOR_COMMAND_H__
#define __GET_MOST_USED_SABER_COLOR_COMMAND_H__
#include "Command.h"
///
/// Get most used saber color of jedi  
/// All methods which implements are from abstract base class Command
///
class GetMostUsedSaberColorCommand : public Command {

public:
	GetMostUsedSaberColorCommand() :Command(String("get_most_used_saber_color")) {};

	GetMostUsedSaberColorCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		if (m_parameters.size() == 1) {
			manager.get_most_used_saber_color(m_parameters[0]);
		}

		if (m_parameters.size() == 2) {
			Rank rank = m_parameters[1].convert_to_rank(m_parameters[1].get_string());
			manager.get_most_used_saber_color(m_parameters[0], rank);
		}
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("get_most_used_saber_color")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy()) {
			std::cerr << "List of arguments is empty!\n";
			return false;
		}

		if (m_parameters.size() != 1 && m_parameters.size() != 2) {
			std::cerr << "\nArguments are not correct!\n";
			return false;
		}
		
		if (!m_parameters[0].is_only_alpha()) { //planet name
			std::cerr << "\nName of planet contains invalid symbols! Must to contains only letters.!\n";
			return false;
		}

		if (m_parameters.size() == 2) {

			if (!m_parameters[1].is_valid_rank()) { //jedi rank
				std::cerr << "\nJedi rank contains invalid symbols! Must to contains only letters.!\n";
				return false;
			}
		}

		return true;
	}

};

#endif //__GET_MOST_USED_SABER_COLOR_COMMAND_H__