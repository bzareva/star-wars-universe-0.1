#include  "Unite.h"


void Unite::run() {
	
	Jedi jedi_one[7] = { {23, 334.5, Rank::INITIATE, String("John1"), String("blue")}, 
	                     {135, 433.5, Rank::GRAND_MASTER, String("Rick1"), String("pink")},
	                     {83, 334.5, Rank::PADAWAN, String("Pesho"), String("white")},
	                     {100, 353.5, Rank::KNIGHT, String("Ivan"), String("black")},
	                     {95, 324.4, Rank::BATTLE_MASTER, String("Asen"), String("yellow")},
	                     {53, 87.7, Rank::MASTER, String("Miky"), String("green")},
	                     {67, 104.5, Rank::BATTLE_MASTER, String("Stefan"), String("red")} };

	Vector<Jedi> vec_jedi_one(jedi_one, 7);
	Planet planet1(vec_jedi_one, String("Earth"));


	Jedi jedi_two[7] = { {57, 321.5, Rank::INITIATE, String("Rick1"), String("blue2")},
					     {35, 165.4, Rank::KNIGHT_ASPIRANT, String("Rick2"), String("pink2")},
					     {93, 234, Rank::GRAND_MASTER, String("Pesho2"), String("white2")},
					     {140, 456, Rank::GRAND_MASTER, String("Ivan2"), String("black2")},
					     {95, 424.4, Rank::BATTLE_MASTER, String("Asen2"), String("yellow2")},
					     {83, 387.7, Rank::MASTER, String("Miky2"), String("green2")},
					     {117, 133.5, Rank::YOUNGLING, String("Stefan2"), String("red2")} };

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
	Planet planet3(vec_jedi_three, String("Saturn"));

	Planet more[3] = { planet1, planet2, planet3 };

	Vector<Planet> vec_planets(more, 3);

    Galaxy cosmos(vec_planets);

	std::cout << ">Enter file name:";
	String file;
	std::cin >> file;

	m_manager = GalaxyManager(file.get_string(), cosmos);

	m_controller.init_command(m_manager);

}