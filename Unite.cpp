#include "Unite.h"

void Unite::run() {
	
	Jedi jedi_one[7] = { {23, 334.5, Rank::INITIATE, String("John1"), String("white")}, 
	                     {25, 433.5, Rank::INITIATE, String("Rick1"), String("black")},
	                     {83, 334.5, Rank::PADAWAN, String("Pesho"), String("white")},
	                     {100, 353.5, Rank::INITIATE, String("Ivan"), String("black")},
	                     {95, 324.4, Rank::BATTLE_MASTER, String("Ivanka"), String("yellow")},
	                     {53, 87.7, Rank::MASTER, String("Miky"), String("green")},
	                     {67, 104.5, Rank::BATTLE_MASTER, String("Stefan"), String("white")} };

	Vector<Jedi> vec_jedi_one(jedi_one, 7);
	Planet planet1(vec_jedi_one, String("Earth"));

	//std::cout << planet1;

	Jedi jedi_two[7] = { {57, 321.5, Rank::INITIATE, String("Rick1"), String("blue")},
					     {35, 165.4, Rank::KNIGHT_ASPIRANT, String("Aleks"), String("pink")},
					     {93, 234, Rank::GRAND_MASTER, String("Pesho2"), String("white")},
					     {140, 456, Rank::GRAND_MASTER, String("Ivan2"), String("white")},
					     {95, 424.4, Rank::BATTLE_MASTER, String("Mimi"), String("yellow")},
					     {83, 387.7, Rank::MASTER, String("Miky2"), String("green")},
					     {117, 133.5, Rank::YOUNGLING, String("Pablo"), String("red")} };

	Vector<Jedi> vec_jedi_two(jedi_two, 7);
	Planet planet2(vec_jedi_two, String("Mars"));
	
	//std::cout << planet2;


	Jedi jedi_three[7] = { {83, 34.5, Rank::KNIGHT, String("John3"), String("yellow")},
					       {135, 43.5, Rank::KNIGHT_ASPIRANT, String("Rick3"), String("pink")},
		                   {33, 34.5, Rank::PADAWAN, String("Pesho3"), String("white")},
					       {98, 33.5, Rank::YOUNGLING, String("Ivan3"), String("white")},
					       {35, 34.4, Rank::GRAND_MASTER, String("Asen3"), String("white")},
					       {76, 8.7, Rank::PADAWAN, String("Miky3"), String("green")},
					       {127, 10.5, Rank::GRAND_MASTER, String("Stefan3"), String("yellow")} };

	Vector<Jedi> vec_jedi_three(jedi_three, 7);
	Planet planet3(vec_jedi_three, String("Jupiter"));

	//std::cout << planet3;

	Galaxy universe(planet1);
	universe.add_planet(planet2);
	universe.add_planet(planet3);

	//std::cout << universe;

	//std::cout << ">Enter file name:";
	//String file;
	//std::cin >> file;

	//m_manager = GalaxyManager(file.get_string(), universe);
	//m_controller.init_command(m_manager);

	//std::ofstream foutP("planetoutput.txt", std::ios::out);
	//if (!foutP) {
	//	foutP.close();
	//	return;
	//}

	//planet1.write_to_file(foutP);

	//foutP.clear();
	//foutP.close();

	//std::ifstream finP("planetinput.txt");
	//if (!finP || !finP.is_open()) {
	//	finP.close();
	//	return;
	//}

	//Planet from_file_planet(finP);
	//std::cout << from_file_planet << std::endl;

	//finP.clear();
	//finP.close();


//_______________________write and read Jedi_______________________
	//std::ofstream fout("output.txt", std::ios::out);
	//if (!fout) {
	//	fout.close();
	//	return;
	//}

	//for (unsigned i = 0; i < 7; ++i) {
	//	jedi_one[i].write_to_file(fout);
	//}

	//fout.clear();
	//fout.close();

	//std::ifstream fin("input.txt");
	//if (!fin || !fin.is_open()) {
	//	fin.close();
	//	return;
	//}

	//Jedi inp(fin);
	//std::cout << inp << std::endl;

	//fin.clear();
	//fin.close();

//_______________________________tests for jedi methods and basic operation with files_______________________________
	//std::cout << jedi_one[1].rank_num()<< std::endl;
	//std::cout << jedi_one[1].get_force() << std::endl;
	//jedi_one[1].demote(2);
	//std::cout << jedi_one[1].get_force() << std::endl;
	//std::cout << jedi_one[1].rank_num() << std::endl;

	//jedi_one[1].promote(2);
	//std::cout << jedi_one[1].get_force() << std::endl;
	//std::cout << jedi_one[1].rank_num() << std::endl;

	//std::ofstream fout("output.txt", std::ios::out);
	//if (!fout) {
	//	fout.close();
	//	return;
	//}

	//for (unsigned i = 0; i < 7; ++i) {
	//	jedi_one[i].write_to_file(fout);
	//}

	//fout.clear();
	//fout.close();

	/*std::ifstream fin("input.txt");
	if (!fin) {
		fin.close();
		return;
	}*/

	//Jedi test(fin);
	//std::cout << test.rank_num() << std::endl;
	//test.read_from_file(fin);
	//std::cout << test << std::endl;
	//std::cout << test.rank_num() << std::endl;
	//fin.clear();
	//fin.close();

    //std::cout << planet3.get_youngest_jedi(String("Saaturn"), Rank::INITIATE);

    //vec_jedi_one += vec_jedi_two;
    //vec_jedi_one += vec_jedi_three;

	//Vector<Planet> vec_planets;
	//vec_planets.push_back(planet1);
	//vec_planets.push_back(planet2);
	//vec_planets.push_back(planet3);

	//std::cout << vec_planets.size(); // [0] ;
	//Galaxy cosmos(vec_planets);
//__________________________________________________________________________________________
}