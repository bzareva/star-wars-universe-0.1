#include  "Unite.h"


void Unite::run() {
	
	Jedi jedi_one[7] = { {23, 334.5, Rank::INITIATE, String("John1"), String("blue")}, 
	                     {25, 433.5, Rank::INITIATE, String("Rick1"), String("black")},
	                     {83, 334.5, Rank::PADAWAN, String("Pesho"), String("white")},
	                     {100, 353.5, Rank::INITIATE, String("Ivan"), String("black")},
	                     {95, 324.4, Rank::BATTLE_MASTER, String("Ivanka"), String("yellow")},
	                     {53, 87.7, Rank::MASTER, String("Miky"), String("green")},
	                     {67, 104.5, Rank::BATTLE_MASTER, String("Stefan"), String("red")} };

	Vector<Jedi> vec_jedi_one(jedi_one, 7);
	Planet planet1(vec_jedi_one, String("Earth"));

	Jedi jedi_two[7] = { {57, 321.5, Rank::INITIATE, String("Rick1"), String("blue2")},
					     {35, 165.4, Rank::KNIGHT_ASPIRANT, String("Aleks"), String("pink2")},
					     {93, 234, Rank::GRAND_MASTER, String("Pesho2"), String("white2")},
					     {140, 456, Rank::GRAND_MASTER, String("Ivan2"), String("black2")},
					     {95, 424.4, Rank::BATTLE_MASTER, String("Mimi"), String("yellow2")},
					     {83, 387.7, Rank::MASTER, String("Miky2"), String("green2")},
					     {117, 133.5, Rank::YOUNGLING, String("Pablo"), String("red2")} };

	Vector<Jedi> vec_jedi_two(jedi_two, 7);
	Planet planet2(vec_jedi_two, String("Mars"));
	

	Jedi jedi_three[7] = { {83, 34.5, Rank::KNIGHT, String("John3"), String("blue3")},
					       {135, 43.5, Rank::KNIGHT_ASPIRANT, String("Rick3"), String("pink3")},
		                   {33, 34.5, Rank::PADAWAN, String("Pesho3"), String("white3")},
					       {98, 33.5, Rank::YOUNGLING, String("Ivan3"), String("black3")},
					       {35, 34.4, Rank::GRAND_MASTER, String("Asen3"), String("yellow3")},
					       {76, 8.7, Rank::PADAWAN, String("Miky3"), String("green3")},
					       {127, 10.5, Rank::GRAND_MASTER, String("Stefan3"), String("red3")} };


	Vector<Jedi> vec_jedi_three(jedi_three, 7);
	Planet planet3(vec_jedi_three, String("Jupiter"));
	 
//----------------------------------------------------------------------------------------------------------------

	Vector<Planet> t;
	t.push_back(planet1);

	std::cout << t;
	//std::cout << t.size();
	


//-----------------------------------------------------------------------------------------------------------------
	//Vector<Base*> vec;
	//vec.push_back(planet1.clone());
	//for (unsigned i = 0; i < planet1.get_count_jedi(); ++i) {
	//	vec.push_back(planet1);
	//}

	//vec += planet1;
	//std::cout << planet1.get_jedi();
	//vec.push_back(planet1);
	//std::cout << vec;

	//Galaxy test;
	//test.add_planet(planet1);
	//std::cout << test[0];

	//vec_planets.push_back(planet1);
	//std::cout << planet1;
	//std::cout << vec_planets;
	//std::cout << vec_planets[0];

	//vec_planets += planet1;
	//std::cout << vec_planets << std::endl;
	//std::cout << planet1.get_count_jedi

	//vec_planets.push_back(planet1);
	//vec_planets.push_back(planet2);
	//vec_planets.push_back(planet3);

	//std::cout << planet1;
	//std::cout << vec_planets[0] << std::endl;
	//std::cout << vec_planets[0].get_count_jedi() << std::endl;

	//Galaxy cosmos(vec_planets);
	//std::cout << cosmos[0] << std::endl;

	//std::cout << p1.get_youngest_jedi(String("Saturn"), Rank::INITIATE) << std::endl;
	//std::cout << p1.get_strongest_jedi(String("Saturn"))<< std::endl;
	//p1.remove_jedi(String("Rick1"), String("Saturn"));
	//std::cout << p1.get_most_used_saber_color(String("Saturn"), Rank::INITIATE);
	//std::cout << p1[2].get_force() << std::endl;
	//p1.promote_jedi(String("Pesho"), 1);
	//std::cout << p1[2].get_force() << std::endl;

    //vec_jedi_one += vec_jedi_two;
    //vec_jedi_one += vec_jedi_three;

	//std::cout << ">Enter file name:";
	//String file;
	//std::cin >> file;

	//m_manager = GalaxyManager(file.get_string(), cosmos);

	//m_controller.init_command(m_manager);

}