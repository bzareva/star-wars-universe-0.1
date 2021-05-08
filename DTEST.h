#ifndef __DTEST_H__
#define __DTEST_H__
#define DOCTEST_CONFIG_IMPLEMENT
///#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "GalaxyManager.h"
///
/// Doctests for parts of the program
/// 
TEST_CASE("Jedi and Planet basic operations") {

	Jedi jedi[7] = { {23, 334.5, Rank::INITIATE, String("John1"), String("blue")},
					 {135, 433.5, Rank::GRAND_MASTER, String("Rick1"), String("pink")},
					 {83, 334.5, Rank::PADAWAN, String("Pesho"), String("white")},
					 {100, 353.5, Rank::KNIGHT, String("Ivan"), String("black")},
					 {95, 324.4, Rank::BATTLE_MASTER, String("Ivanka"), String("yellow")},
					 {53, 87.7, Rank::MASTER, String("Miky"), String("green")},
					 {67, 104.5, Rank::BATTLE_MASTER, String("Stefan"), String("red")} };

	Vector<Jedi> vec_jedi;
	CHECK(vec_jedi.size() == 0);

	for (unsigned i = 0; i < 7; ++i) {
		vec_jedi.push_back(jedi[i]);
	}

	CHECK(vec_jedi.size() == 7);
	//CHECK(vec_jedi.size() != 7);
	CHECK(!vec_jedi.empy());


	Planet planet(vec_jedi, String("Earth"));
	CHECK(planet.get_count_jedi() == 7);
	CHECK(planet.get_planet_name() != String("Mars"));
	CHECK(planet.get_planet_name() == String("Earth"));
}

TEST_CASE("Adding in Galaxy planets and jedi") {

	Jedi jedi[7] = { {23, 334.5, Rank::INITIATE, String("John1"), String("blue")},
				     {25, 433.5, Rank::INITIATE, String("Rick1"), String("black")},
					 {83, 334.5, Rank::PADAWAN, String("Pesho"), String("white")},
					 {100, 353.5, Rank::INITIATE, String("Ivan"), String("black")},
					 {95, 324.4, Rank::BATTLE_MASTER, String("Ivanka"), String("yellow")},
					 {53, 87.7, Rank::MASTER, String("Miky"), String("green")},
					 {67, 104.5, Rank::BATTLE_MASTER, String("Stefan"), String("red")} };

	Vector<Jedi> vec_jedi(jedi, 7);
	Planet planet(vec_jedi, String("Earth"));

	Galaxy p;
	p.add_planet(planet);
	CHECK(p.get_count_planet() == 2);

	p.add_vec_jedi(vec_jedi, String("Mars"));
	CHECK(p.get_count_planet() == 2);
	CHECK(p.get_count_planet() != 0);
}

TEST_CASE("Successfully added planets and testing some basic operations for Galaxy") {

	Jedi jedi_one[7] = { {233, 334.5, Rank::INITIATE, String("John"), String("blue")},
						 {25, 10.5, Rank::INITIATE, String("Stefan"), String("red")},
					     {83, 33.5, Rank::PADAWAN, String("Pesho"), String("white")},
					     {100, 353.5, Rank::INITIATE, String("Ivan"), String("black")},
					     {95, 324.4, Rank::BATTLE_MASTER, String("Ivanka"), String("yellow")},
					     {53, 87.7, Rank::MASTER, String("Miky"), String("green")},
					     {67, 104.5, Rank::BATTLE_MASTER, String("Stefan"), String("red")} };

	Vector<Jedi> vec_jedi_one(jedi_one, 7);
	Planet planet1(vec_jedi_one, String("Earth"));


	Jedi jedi_two[7] = { {17, 321.5, Rank::INITIATE, String("Rick1"), String("blue2")},
						 {35, 165.4, Rank::KNIGHT_ASPIRANT, String("Aleks"), String("pink2")},
						 {93, 33.5, Rank::GRAND_MASTER, String("Pesho2"), String("white2")},
						 {140, 456, Rank::GRAND_MASTER, String("Ivan2"), String("black2")},
						 {95, 424.4, Rank::BATTLE_MASTER, String("Mimi"), String("yellow2")},
						 {83, 387.7, Rank::MASTER, String("Miky"), String("green2")},
						 {117, 133.5, Rank::YOUNGLING, String("Pablo"), String("red2")} };

	Vector<Jedi> vec_jedi_two(jedi_two, 7);
	Planet planet2(vec_jedi_two, String("Mars"));


	Jedi jedi_three[7] = { {83, 34.5, Rank::KNIGHT, String("John"), String("blue3")},
						   {135, 43.5, Rank::KNIGHT_ASPIRANT, String("Rick3"), String("pink3")},
						   {33, 456, Rank::INITIATE, String("Rick1"), String("black")},
						   {98, 33.5, Rank::YOUNGLING, String("Ivan3"), String("black3")},
						   {35, 34.4, Rank::GRAND_MASTER, String("Asen3"), String("yellow3")},
						   {76, 8.7, Rank::PADAWAN, String("Aleks"), String("green3")},
						   {25, 10.5, Rank::INITIATE, String("Stefan"), String("red")} };


	Vector<Jedi> vec_jedi_three(jedi_three, 7);
	Planet planet3(vec_jedi_three, String("Jupiter"));

	CHECK(planet1.get_count_jedi() == planet2.get_count_jedi());
	CHECK(planet2.get_count_jedi() == planet3.get_count_jedi());

	CHECK(planet1[0].get_name_jedi() == planet3[0].get_name_jedi());
	CHECK(planet2[1].get_name_jedi() == planet3[5].get_name_jedi());


	Galaxy universe(planet1);
	universe.add_planet(planet2);
	universe.add_planet(planet3);

	CHECK(universe.get_strongest_jedi(planet1.get_planet_name()) != universe.get_strongest_jedi(planet2.get_planet_name()));
	CHECK(universe.get_youngest_jedi(planet1.get_planet_name(), Rank::INITIATE)[0] == universe.get_youngest_jedi(planet3.get_planet_name(), Rank::INITIATE)[0]);

	universe.demote_jedi(String("Pesho"), 5);
	universe.demote_jedi(String("Ivan3"), 5);
	CHECK(universe[0].get_jedi(2).get_force() == universe[2].get_jedi(3).get_force());

	CHECK(universe[0].get_count_jedi() == universe[2].get_count_jedi());
	universe.remove_jedi(String("Stefan"), String("Jupiter"));
	CHECK(universe[0].get_count_jedi() != universe[2].get_count_jedi());

	Jedi curr(344, 345.5, Rank::GRAND_MASTER, String("Will"), String("red"));
	universe.create_jedi(String("Jupiter"), String("Will"), Rank::GRAND_MASTER, 344, String("red"), 345.5);
	CHECK(curr == universe[2].get_jedi(6));
}

///TEST_CASE("Work with jedi and files") { }

//TEST_CASE("Work with planets and files") { }

//TEST_CASE("Work with galaxy and files") { }

#endif //__DTEST_H__