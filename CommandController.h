#ifndef __COMMAND_CONTROLLER_H__
#define __COMMAND_CONTROLLER_H__
#include "Command.h"

class CommandController {

public:
	CommandController() = default;

	~CommandController() = default;

	//! execute registered commands
	void execute_command(const String& command_name, std::ofstream& fout, const String& file_name);

	//! registers commands
	void register_command(Command* register_command);

	//! the created commands are registered
	void init_command();

private:
	Vector<Command*> m_commands;

};

#endif //__COMMAND_CONTROLLER_H__