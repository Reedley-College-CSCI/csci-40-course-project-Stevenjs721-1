// CSCI-40 Final Project
// Author: [Steven Sumaya]

/* 
 * Description:
 * A movie library that allows users to input, store, and filter a through
 * movies. This allows users to keep track of movies the have watched or may want
 * to watch.There are functions that prints all the movies with their information 
 * according to sorts. It implements a variety of concepts learned from my CSCI 
 * 40 class. 
 * 
 * When the program starts users are prompted to enter 0-4 for different functions.
 * Inputting 1 brings you to the library where you can input 1 to sort, 2 to search,
 * and 0 to exit the library. Within the sort function you can enter 0-3 to sort by
 * name, genre, year or exit to the menu. Entering 2 in the main menu lets you input
 * movies to the function where you input the name, genre, and year. Within the remove 
 * and update section you input a movie name in the library to modify it. There are many
 * confirmations to make sure the user doesn't input errors. You can enter '0' to exit in
 * all inputs that explicitly say so.
 * 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "MovieLibrary.h"

using namespace std;


int main() {
    fstream movFile ("LibraryMemory.txt");

    if (!movFile.is_open()) {
        cout << "Error! Could not read file. Try again" << endl;
        return -1;
    }
    movFile.close();


    MovieLibrary Library;
    Movie currMovie;
    int choice;
    string currName;
    string currGenre;
    string currYear;
    bool saved;

    //file to array
    Library.setLibrary();

    //main menu options
    Library.printMain();
    
   //For invalid inputs
    while (!(cin >> choice) || choice < 0 || choice > 4) {
        cout << "Error: invalid input! Try again." << endl;
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };
    cout << endl;


    switch (choice) {
    case 1:
        //library
        Library.printLibrary();
        main();
        break;
    case 2:
        //enter a movie
        cout << "Fill out information or enter 0 to exit\n";
        cout << "Input name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, currName);
        if (currName == "0") {
            main();
            break;
        }
        cout << "Input genre: ";
        cin >> currGenre;
        if (currName == "0") {
            main();
            break;
        }
        cout << "Input year: ";
        cin >> currYear;
        if (currName == "0") {
            main();
            break;
        }
        
        saved = currMovie.setMovieInfo(currName, currGenre, currYear);
        if (saved == true) {
            currMovie.saveMovie();
        }
        main();
        break;
    case 3:
        //removes movie
        Library.removeMovie();
        main();
        break;
    case 4:
        //updates movie
        Library.updateMovie();
        main();
        break;
    case 0:
        return 0;
        break;
    }
    return 0;
}
