#ifndef __ADD_PLANET_COMMAND_H__
#define __ADD_PLANET_COMMAND_H__
#include "Command.h"

class AddPlanetCommand : public Command {

public:
	AddPlanetCommand() :Command(String("add_planet")) {};

	AddPlanetCommand(const String& cmd, const Vector<String> args) :Command(cmd, args) {};

	inline void execute(GalaxyManager& manager) override {

		if (!is_valid()) {
			return;
		}

		manager.add_planet(m_parameters[0]);
	}

private:
	inline bool is_valid()const override {

		if (m_command_name != String("add_planet")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy() || m_types.empy()) {
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

		if (m_types[0] != TypeParameters::STRING) {
			std::cerr << "\nTypes of the given argument is not valid!\n";
			return false;
		}

		return true;
	}
	 
};

#endif //__ADD_PLANET_COMMAND_H__