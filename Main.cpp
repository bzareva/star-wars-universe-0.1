#include "Unite.h"
#include "DTEST.h"
///
/// - Star wars universe 0.1 is project from the Object-oriented programming course at FMI(2020-2021).
/// - data 05.21
/// - author Blagovesta Zareva
/// - brief The program can save the information that is entered
///         from the console and also be able to reload it.
///         That is, the program must store the information of 
///         the planets and the Jedi inhabiting them in a file and 
///         support the commands for working with files described in the 
///         section Working with the command line. All commands 
///         are in lowercase Latin letters, and the arguments are separated by a space. 
///
int main() {

	Unite runner;
	runner.run();

	doctest::Context().run();

	return 0; 
}