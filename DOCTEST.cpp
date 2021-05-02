//#ifndef __DOCTEST_CPP__
//#define __DOCTEST_CPP__
#define DOCTEST_CONFIG_IMPLEMENT
#include "../star-wars-universe-0.1/doctest.h"
#include "GalaxyManager.h"


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

	for(unsigned i = 0; i < 7; ++i) {
		vec_jedi.push_back(jedi[i]);
	}

	CHECK(vec_jedi.size() == 7);
	CHECK(vec_jedi.size() != 7);
	CHECK(vec_jedi.empy());


	Planet planet(vec_jedi, String("Earth"));
	CHECK(planet.get_count_jedi() == 7);
	CHECK(planet.get_planet_name() == String("Mars"));
	CHECK(planet.get_planet_name() == String("Earth"));


}

//#endif //__DOCTEST_CPP__