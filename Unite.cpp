#include "Unite.h"

void Unite::run() {

	std::cout << ">Enter file name:";
	String file;
	std::cin >> file;

	Galaxy universe;

	m_manager = GalaxyManager(file, universe);
	m_controller.init_command(m_manager);

}