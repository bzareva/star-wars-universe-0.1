#include "Unite.h"

void Unite::run() {

	//std::cout << ">Enter file name:";
	//String file;
	//std::cin >> file;

	//std::ifstream fin(file.get_string());

	//Galaxy test;
	//test.read_from_file(fin);
	//std::cout << test;


	std::ifstream fin("galaxy_information.txt", std::ios::in);
	if (!fin || !fin.is_open()) {
		std::cerr << "\nProblem with opening file!\n";
	}

	Galaxy cosmos;
	cosmos.read_from_file(fin);

	//cosmos.print_jedi(String("RyoDurame"));
	//cosmos.promote_jedi(String("RyoDurame"), 0.5);
	//cosmos.print_jedi(String("RyoDurame"));

	String moon("Moon");
	String mars("Mars");
	cosmos.operator_plus(moon, mars);


	fin.clear();
	fin.close();

//	m_controller.init_command(m_manager);
}