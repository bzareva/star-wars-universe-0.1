#ifndef __JEDI_H__
#define __JEDI_H__

class Jedi {




public:
	enum Rank {
		YOUNGLING = 1,
		INITIATE,
		PADAWAN,
		KNIGHT_ASPIRANT,
		KNIGHT,
		MASTER, 
		BATTLE_MASTER,
		GRAND_MASTER
	};


private:	
	int    m_age;
	double m_force;
	char*  m_name_jedi;
	char*  m_color_of_lightsaber;
	Rank   m_rank;


};

#endif ///__JEDI_H__
