#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "GalaxyManager.h"
/*!
 * Abstract base class for all commands classes which has to supports the program
 */
class Command {

public:
    Command() = default;

    virtual ~Command() = default;

    Command(const String& command_name) : m_command_name(command_name) {};

    Command(const String& command_name, const Vector<String>& parameters) : m_command_name(command_name) {

        m_parameters = parameters;
    };

    /*!
     * Each of heirs implementing it to a different way
     * @ param manager Calls methods for successful execution of program through the given command
     */
    virtual void execute(GalaxyManager& manager) {};

private:
    /*!
     * Pure virtual method
     * Each of heirs implementing it to a different way
     * @returns True if the given command is valid, otherwise False
     */
    virtual bool is_valid()const = 0;

protected:
	String         m_command_name;
	Vector<String> m_parameters;

};

#endif //__COMMAND_H_