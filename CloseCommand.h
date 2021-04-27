#ifndef __CLOSE_COMMAND_H__
#define __CLOSE_COMMAND_H__
#include "Command.h"

class CloseCommand : public Command {

public:
	CloseCommand() :Command(String("close")) {};

	inline void execute(GalaxyManager& manager)override {

		if (!is_valid()) {
			return;
		}

		manager.close_file();
	}


	inline bool is_valid()const override {

		if (m_command_name != String("close")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (!m_parameters.empy()) {
			std::cerr << "\nThis command do not need arguments!\n";
			return false;
		}

		if (!m_types.empy()) {
			std::cerr << "\nThis command do not need types of arguments!\n";
			return false;
		}

		return true;
	}

};

#endif //__CLOSE_COMMAND_H__