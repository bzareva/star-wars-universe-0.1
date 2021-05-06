#ifndef __UNITE_H__
#define __UNITE_H__
#include "CommandController.h"
///
/// Unites all in one
///
class Unite {

public:
	/// default constructor
	Unite() = default;

	/// example for executing program
	void run();

private:
	GalaxyManager     m_manager;
	CommandController m_controller;

};

#endif //__UNITE_H__