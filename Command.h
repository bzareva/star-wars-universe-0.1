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

    Command(const String& command_name) : m_command_name(command_name) {};

    //Command(const String& command_name, const Vector<String>& parameters, const Vector<TypeParameters>& types) : m_command_name(command_name) {

    //    set_parameters(parameters);
    //    set_types(types);
    //};

    virtual ~Command() = default;

    virtual void execute(GalaxyManager& manager) {};

    virtual bool is_valid()const {};

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