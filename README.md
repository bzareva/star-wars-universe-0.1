# Star Wars Universe 0.1
[Doxygen documentation]
<file:///C:/Users/USER/source/repos/bzareva/star-wars-universe-0.1/documentation/html/index.html>

## *Brief information*

Vankata is a big fan of Star Wars, so he decided to make a small project on OOP on this topic.
For the purpose, he wants to recreate the universe of the series.<br/>
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
The function brings out a message whether the addition was successful or not
(there is a Jedi with such a name on this or that planet, or not there is a planet with such a name).<br/>

- **_removeJedi [jedi_name] [planet_name]:_**<br/>
The function brings out a message whether the removal was successful or not (the Jedi did not inhabits this planet).<br/> 

- **_promote_jedi [jedi_name] [multiplier]:_**<br/>
Raises the given Jedi by one rank up in ladder and increases its strength by the formula
jedi_strength + = (multiplier * jedi_strength) (cannot be increased any more)
of rank GRAND_MASTER and must be multiplier positive number of type double).<br/> 

- **_demote_jedi [jedi_name] [multiplier]:_**<br/>
Decreases the rank of the given Jedi by one rank down the ladder and lowers its strength by
formula jedi_strength -= (multiplier * jedi_strength) (cannot be lowered further
of rank YOUNGLING and multiplier must be positive number of type double).<br/>

- **_get_strongest_jedi [planet_name]:_**<br/>
Outputs information about the strongest Jedi of the submitted planet (with the greatest force).<br/> 

- **_get_youngest_jedi [planet_name] [jedi_rank]:_**<br/>
Brings out the youngest Jedi inhabiting the given planet and has the corresponding rank
(**if they are more than one, to display the first on alphabetical order if none will be displayed appropriate message**).<br/> 

- **_get_most_used_saber_color [planet_name] [jedi_rank]:_**<br/>
Returns the most common color to light sword in the given rank of the respective planet.<br/> 

- **_get_most_used_saber_color [planet_name]:_**<br/>
Returns the most common color to light sword planet which is used by at least one **GRAND_MASTER**.<br/>

- **_print [planet_name]:_**<br/>
Bring out of the name of the planet appropriately and the Jedi inhabiting it, **sorted first in 
growing order by rank, then by second key - lexicographically by name**.<br/>

- **_print [jedi_name]:_**<br/>
Brings out of the information about the Jedi appropriately, as well as which planet it currently inhabits.<br/>

- **_[planet_name] + [planet_name]:_**<br/>
Outputs on the screen in sorted type(**lexicographically**) information about the inhabitants the two Jedi planets.<br/> 

Vankata also wanted to be able to keep the information which he input 
in the program for later and be able to load it again.
That is, the program must store information on the planet and the Jedi inhabiting 
them **in a file** and to supports commands for working with files described in the
working with the **command line section. All commands are lowercase latin letters,
and the arguments are separated by one interval.**<br/><br/> 

The program allows you to perform various transformations on the files in given session.
When session transformations are applied, they apply for all loaded images for the current session.
Transformations are applied over images only after the "save" or "saveas" command is executed.
The "save" command saves all loaded in the current user session images after applying 
all transformations, and the "saveas" command saves under the new name only the image that was loaded first.<br/>
Once the application opens a file, it can perform the following operations:

- **_open:_**<br/> 
Loads the contents of a file. If one does not exist, a new one is created with empty content. 
All other commands can be executed only if there is a successfully loaded file. Once the file is 
opened and read, it closes and your application no longer needs to work with it, unless the user does 
not want to save the changes made again (see the save command below), in which case the file must be reopened. 
To do this, you must select an appropriate presentation of the information in the file. If your application 
detects an error while loading the data, it should display an appropriate error message and terminate its execution.<br/><br/>
Example:<br/>
**cmd:** open C:\Temp\file.xml<br/>
*Successfully opened file.xml*<br/><br/>

- **_close:_**<br/>
Closes the currently open document. Closing clears the currently loaded
information and then the program cannot execute commands other than opening a file (Open).<br/><br/>
Example:<br/>
**cmd:** close<br/>
*Successfully closed file.xml*<br/><br/>

- **_save:_**<br/> 
Saves done changes back to the same file from which the data was read.<br/><br/>
Example:<br/>
**cmd:** save<br/>
*Successfully saved file.xml*<br/><br/>

- **_saveas:_**<br/>
Saves done changes to a file, also allowing the user to specify its path.<br/><br/>
Example:<br/>
**cmd:** saveas "C:\Temp\another file.xml"<br/>
*Successfully saved another file.xml*<br/><br/>

- **_help:_**<br/>
Outputs brief information about the commands supported by the program.<br/>
**cmd:** help
*The following commands are supported:<br/>
open [file] opens [file]<br/>
close closes currently opened file<br/>
save saves the currently open file<br/>
saveas [file] saves the currently open file in [file]<br/>
help prints this information<br/>
exit exists the program*<br/><br/>

- **_exit:_**<br/> 
Exit the program.<br/><br/>
Example:<br/>
**cmd:** exit<br/>
*Exiting the program...*<br/><br/>
