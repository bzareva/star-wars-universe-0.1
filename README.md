# Star Wars Universe 0.1
## *Brief information*

Vankata is a big fan of Star Wars, so he decided to make a small project on OOP on this topic.
To this end, he wants to recreate the universe of the series.<br/>
He first started with the Jedi, deciding that everyone should have: 
- jedi name
- ank, the following are arranged in ascending order - YOUNGLING,
INITIATE, PADAWAN, KNIGHT-ASPIRANT, KNIGHT, MASTER, BATTLE_MASTER и GRAND_MASTER
- age
- the color of the lightsaber (a string entered by keyboard) 
- force (set by some number of type double)<br/> 

He then decided to create the planets and moons, each with a name and a Jedi, who inhabit it.
Create an application that supports the following commands:<br/> 

 - **_add_planet [planet_name]:_**<br/>
Adds a new planet.<br/>

- **_create_jedi [planet_name] [jedi_name] [jedi_rank] [jedi_age] [saber_color] [jedi_strength]:_**<br/>
The function to display a message whether the addition was successful or not
(there is a Jedi with such a name on this or that planet, or not there is a planet with such a name).<br/>

- **_removeJedi [jedi_name] [planet_name]:_**<br/>
The function to display a message whether the removal was successful or not (the Jedi did not inhabits this planet).<br/> 

- **_promote_jedi [jedi_name] [multiplier]:_**<br/>
Raises the given Jedi by one rank up in ladder and increases its strength by the formula
jedi_strength + = (multiplier * jedi_strength) (cannot be increased any more)
of rank GRAND_MASTER and must be multiplier positive number of type double).<br/> 

- **_demote_jedi [jedi_name] [multiplier]:_**<br/>
Reduced the rank of the submitted Jedi by one rank down the ladder and lowers its strength by
formula jedi_strength - = (multiplier * jedi_strength) (cannot be lowered further)
of rank YOUNGLING and multiplier must be positive number of type double).<br/>

- **_get_strongest_jedi [planet_name]:_**<br/>
Displays information about the strongest Jedi of the submitted planet (with the greatest force).<br/> 

- **_get_youngest_jedi [planet_name] [jedi_rank]:_**<br/>
Brings out the youngest Jedi inhabiting the given planet and has the corresponding rank
(if they are more than one, to display the first on alphabetical order if none will be displayed appropriate message).<br/> 

- **_get_most_used_saber_color [planet_name] [jedi_rank]:_**<br/>
Returns the most common color to light sword in the given rank of the respective planet.<br/> 

- **_get_most_used_saber_color [planet_name]:_**<br/>
Returns the most common color to light sword planet that enjoys at least one GRAND_MASTER.<br/>

- **_print [planet_name]:_**<br/>
Displays the name of the planet appropriately and the Jedi inhabiting it, sorted first in
ascending order by rank, then by second key - lexicographically by name.<br/> 

- **_print [jedi_name]:_**<br/>
Displays the information for the Jedi, as well as which planet it currently inhabits.<br/>

- **_[planet_name] + [planet_name]:_**<br/>
Displays the screen in assorted form (lexicographically) information about the inhabitants the two Jedi planets.<br/> 

Vankata also wanted to be able to keep the information he had entered in
your program for later and be able to reload it. That is, the program must
store information the planets and the Jedi inhabiting them in a file and to
support the commands for working with files described in the Working with the command line section.
All commands are in lowercase Latin letters, and the arguments are separated by one interval.<br/> 

