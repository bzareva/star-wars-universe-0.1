#ifndef __PROMOTE_JEDI_COMMAND_H__
#define __PROMOTE_JEDI_COMMAND_H__
#include "Command.h"
///
/// Promote jedi
/// All methods which implements are from abstract base class Command
///
class PromoteJediCommand : public Command {

public:
	PromoteJediCommand() :Command(String("promoote_jedi")) {};

	PromoteJediCommand(const String& cmd, const Vector<String>& args) :Command(cmd, args) {};

	inline virtual void execute(GalaxyManager& manager)final {

		if (!is_valid()) {
			throw std::runtime_error("Obscure command!");
		}

		double multiplier = m_parameters[1].convert_to_double(m_parameters[1].get_string());
		manager.promote_jedi(m_parameters[0], multiplier);
	}

private:
	inline virtual bool is_valid()const final {

		if (m_command_name != String("promote_jedi")) {
			std::cerr << "\nCommand name is not valid!\n";
			return false;
		}

		if (m_parameters.empy()) {
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

		if (!m_parameters[0].is_only_alpha()) { //jedi name
			std::cerr << "\nName of jedi contains invalid symbols! Must to contains only letters.!\n";
			return false;
		}

		if (!m_parameters[1].is_only_digits()) { //multiplier
			std::cerr << "\nMultiplier contains invalid symbols! Must to contains only digits.!\n";
			return false;
		}

		return true;
	}

};

#endif //__PROMOTE_JEDI_COMMAND_H__