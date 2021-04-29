#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "GalaxyManager.h"
/*!
 * 
 */
enum class TypeParameters {

    STRING  = 1,
    RANK    = 2,
    INTEGER = 3,
    DOUBLE  = 4
};
/*!
 *
 */
class Command {

public:

    Command() = default;

    virtual ~Command() = default;

    Command(const String& command_name) : m_command_name(command_name) {};

    Command(const String& command_name, const Vector<String>& parameters) : m_command_name(command_name) {

        set_parameters(parameters);

        if (command_name == String("add")                   || command_name == String("open")
            || command_name == String("print")              || command_name == String("saveas") 
            || command_name == String("get_strongest_jedi") || command_name == String("get_most_used_saber_color")) {

            push_add_open_print_saveAs_strongestJedi_grandMasterSaberColor();
        } else if (command_name == String("create_jedi")) {

            push_create();
        } else if (command_name == String("remote") || command_name == String("demote")) {

            push_remote_demote();
        } else if (command_name == String("+") || command_name == String("remove_jedi")) {

            push_operatorPlus_removeJedi();
        } else if (command_name == String("get_most_used_saber_color") || command_name == String("get_youngest_jedi")) {

            push_youngestJedi_mostUsedSaberColor();
        }
    };


    Command(const String& command_name, const Vector<String>& parameters, const Vector<TypeParameters>& types) : m_command_name(command_name) {

        set_parameters(parameters);
        set_types(types);
    };

    virtual void execute(GalaxyManager& manager) {};

    virtual bool is_valid()const = 0;

private:
    inline void set_parameters(const Vector<String>& parameters) {

        m_parameters = parameters;
    }

    inline void set_types(const Vector<TypeParameters>& types) {

       m_types = types;
    }

    inline void push_create() {

        m_types.push_back(TypeParameters::STRING);
        m_types.push_back(TypeParameters::STRING);
        m_types.push_back(TypeParameters::RANK);
        m_types.push_back(TypeParameters::INTEGER);
        m_types.push_back(TypeParameters::STRING);
        m_types.push_back(TypeParameters::DOUBLE);
    }

    inline void push_add_open_print_saveAs_strongestJedi_grandMasterSaberColor() {

        m_types.push_back(TypeParameters::STRING);
    }

    inline void push_remote_demote() {

        m_types.push_back(TypeParameters::STRING);
        m_types.push_back(TypeParameters::DOUBLE);
    }

    inline void push_youngestJedi_mostUsedSaberColor() {

        m_types.push_back(TypeParameters::STRING);
        m_types.push_back(TypeParameters::RANK);
    }

    inline void push_operatorPlus_removeJedi() {

        m_types.push_back(TypeParameters::STRING);
        m_types.push_back(TypeParameters::STRING);
    }

protected:
	String                 m_command_name;
	Vector<String>         m_parameters;
    Vector<TypeParameters> m_types;

};

#endif //__COMMAND_H_