#ifndef __COMMAND_CONTROLLER_H__
#define __COMMAND_CONTROLLER_H__
#include "Command.h"
/*!
 * Container with commands
 */
class CommandController {

public:
	//! default constructor
	CommandController() = default;

	//! default destructor
	~CommandController() = default;

	//! execute registered commands
	void execute_command(const String& file_name, GalaxyManager cosmos);

	//! registers commands
	void register_command(Command* register_command);

	//! created commands are registered in container
	void init_command(GalaxyManager cosmos);

private:
	Vector<Command*> m_commands;

};

#endif //__COMMAND_CONTROLLER_H__