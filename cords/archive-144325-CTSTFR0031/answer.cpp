/*******
 * Read input from cin
 * Use cout to output your result.
 * Use:
 *  localPrint( string mystring)
 * to display variable in a dedicated area.
 * ***/
#include <iostream>
#include <limits>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
   std::string line;
    while (std::getline(std::cin, line))
    {
        /*Lisez les données ici et effectuez votre traitement ici */
    }
    
    /* Vous pouvez aussi effectuer votre traitement une fois que vous avez lu toutes les données.*/
}

/* 
 * DO NOT PASTE THIS UTILITY CODE BACK INTO THE BROWSER WINDOW
 */
void ContestExerciseImpl::localEcho(string line){
	std::cout << line;
}
			
int str2int (const string &str) {
    stringstream ss(str);
    int num;
    if((ss >> num).fail())
    { 
        return 0;
    }
    return num;
}