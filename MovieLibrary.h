#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct movieStruct {
    string name = "N/A";
    string genre = "N/A";
    string year = "N/A";
    double rating = 0.0;
    bool watchStatus = false;
};

class Movie {
private:
    movieStruct movie;
public:
    bool setMovieInfo(string currName, string currGenre, string currYear) {
        char confirm;

        //conform information to save

        cout << "-------------------------\n";
        cout << "Name: " << currName << endl;
        cout << "Genre: " << currGenre << endl;
        cout << "Year: " << currYear << endl;
        cout << "-------------------------\n";
        cout << "\nIs information given correct(Y/N)\n";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            movie.name = currName;
            movie.genre = currGenre;
            movie.year = currYear;
            return true;
        }
        else if (confirm == 'n' || confirm == 'N') {
            cout << "\nMovie not saved\n";
            return false;
        }
    };
    void const saveMovie() {
        //appends information to file
        ofstream movFile("LibraryMemory.txt", ios::app);

        movFile << ">" << movie.name << endl;
        movFile << "Genre: " << movie.genre << endl;
        movFile << "Year: " << movie.year << endl << endl;

        cout << "\nMovie saved!\n\n";
        movFile.close();
    }
    void const print() {
        cout << "Name: " << movie.name << endl;
        cout << "Genre: " << movie.genre << endl;
        cout << "Year: " << movie.year << endl;
    }
};

class MovieLibrary {
private:
    int Capacity = 10;
    movieStruct* Movies = new movieStruct[Capacity];
    int librarySize = 0;
    int i = 0;
public:
    void printMain() const {
        cout << "-------------------------\n";
        cout << "      Movie Library      \n";
        cout << "-------------------------\n";
        cout << "Enter: \n";
        cout << "1 to print Library \n";
        cout << "2 to enter a movie \n";
        cout << "3 to remove a movie \n";
        cout << "4 to update a movie \n";
        cout << "0 to quit \n";
    };
    /*void printLibrary() {
        cout << "-------------------------\n";
        cout << "        Movie List       \n";
        cout << "-------------------------\n";
        ifstream movFile("LibraryMemory.txt");
        string line;
        while (getline(movFile, line)) {
            cout << line << endl;
        }
    };*/
    void setLibrary() {

        // file to array
        fstream movFile("LibraryMemory.txt");
        string blankLine;
        while (getline(movFile, Movies[librarySize].name)
            && getline(movFile, Movies[librarySize].genre)
            && getline(movFile, Movies[librarySize].year)) {
            getline(movFile, blankLine);
            ++librarySize;

            //Dynamic Allocation 
            if (librarySize == Capacity) {
                int newCapacity = Capacity + 20;
                movieStruct* newMovies = new movieStruct[newCapacity];
                for (int i = 0; i < Capacity; ++i) { *(newMovies + i) = *(Movies + i); }
                delete[] Movies;
                Movies = newMovies;
                Capacity = newCapacity;
            }
        }
        movFile.close();
    };
    void printLibrary() {
        int choice;
        cout << "-------------------------\n";
        cout << "        Movie List       \n";
        cout << "-------------------------\n";

        for (i = 0; i < librarySize; ++i) {
            cout << Movies[i].name << endl;
            cout << Movies[i].genre << endl;
            cout << Movies[i].year << endl << endl;
        };
        cout << "-------------------------\n";

        //Library options
        cout << "Enter: \n";
        cout << "1 to sort\n";
        cout << "2 to search\n";
        cout << "0 to go back to main menu\n";

        //invalid inputs
        while (!(cin >> choice) || choice < 0 || choice > 2) {
            cout << "Error: invalid input! Try again." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        };

        //choices
        switch (choice) {
        case 1:
            sortLibrary();
            break;
        case 2:
            searchLibrary();
            break;
        }

    };

    void searchLibrary() {
        string search;
        char confirm = 'n';
        bool nofindings;
        int desiredLine;
        bool movieFound = false;
        cin.ignore();

        //simple selection search
        while (movieFound == false) {
            nofindings = true;
            cout << "Enter movie name or 0 to exit:\n";
            getline(cin, search);
            if (search == "0") { return; }

            for (i = 0; i < librarySize; i++) {
                if (">" + search == Movies[i].name) {
                    desiredLine = i;
                    cout << "-------------------------\n";
                    cout << Movies[i].name << endl;
                    cout << Movies[i].genre << endl;
                    cout << Movies[i].year << endl;
                    cout << "Movie spot: " << desiredLine + 1 << endl;
                    cout << "-------------------------\n";
                    //confirm movie
                    cout << "Is this the movie your looking for? (Y/N)\n";
                    cin >> confirm;
                    movieFound = true;
                    nofindings = false;
                }
            }
            //if no movie found then output message
            if (nofindings == true) {
                cout << "\n---couldn't find movie---\n\n";
            }
        }

        //if found incorrect movie try again
        if (confirm == 'n' || confirm == 'N') {
            cout << "\n---You may try again---\n\n";
            return searchLibrary();

        }
    }


    void sortLibrary() {
        int choice;
        cout << "Sort by: \n\n";
        //choices 
        cout << "1 Name\n2 Year\n3 Genre\n0 exit\n";

        //invalid inputs
        while (!(cin >> choice) || choice < 0 || choice > 3) {
            cout << "Error: invalid input! Try again." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        };

        switch (choice) {
        case 1:
            SortName();
            break;
        case 2:
            SortYear();
            break;
        case 3:
            SortGenre();
            break;
        case 0:
            return;
            break;
        }
    }
    void SortName() {
        int j;
        int indexSmallest;
        movieStruct temp;      // Temporary variable for swap


        for (i = 0; i < librarySize; ++i) {

            // Find index of smallest remaining element
            indexSmallest = i;
            for (j = i + 1; j < librarySize; ++j) {

                if (Movies[j].name.at(1) < Movies[indexSmallest].name.at(1)) {
                    indexSmallest = j;
                }
            }

            //orders sort
            temp = Movies[i];
            Movies[i] = Movies[indexSmallest];
            Movies[indexSmallest] = temp;
        }
        //prints sort
        cout << "-------------------------\n";
        cout << "  Movie List - By Name   \n";
        cout << "-------------------------\n";

        for (i = 0; i < librarySize; ++i) {
            cout << Movies[i].name << endl;
            cout << Movies[i].genre << endl;
            cout << Movies[i].year << endl << endl;
        };
    }

    void SortYear() {
        int j;
        int indexSmallest;
        movieStruct temp;      // Temporary variable for swap


        for (i = 0; i < librarySize; ++i) {

            // Find index of smallest remaining element
            indexSmallest = i;
            for (j = i + 1; j < librarySize; ++j) {

                if (Movies[j].year.substr(6, 4) > Movies[indexSmallest].year.substr(6, 4)) {
                    indexSmallest = j;
                }
            }
            //orders sort
            temp = Movies[i];
            Movies[i] = Movies[indexSmallest];
            Movies[indexSmallest] = temp;
        }

        //prints sort

        cout << "-------------------------\n";
        cout << "  Movie List - By Year   \n";
        cout << "-------------------------\n";

        for (i = 0; i < librarySize; ++i) {
            cout << Movies[i].name << endl;
            cout << Movies[i].genre << endl;
            cout << Movies[i].year << endl << endl;
        };

    }
    void SortGenre() {
        int j;
        int indexSmallest;
        movieStruct temp;      // Temporary variable for swap


        for (i = 0; i < librarySize; ++i) {

            // Find index of smallest remaining element
            indexSmallest = i;
            for (j = i + 1; j < librarySize; ++j) {

                if (Movies[j].genre.at(7) < Movies[indexSmallest].genre.at(7)) {
                    indexSmallest = j;
                }
            }

            //orders sort
            temp = Movies[i];
            Movies[i] = Movies[indexSmallest];
            Movies[indexSmallest] = temp;
        }

        //prints sort
        cout << "-------------------------\n";
        cout << "  Movie List - By Genre  \n";
        cout << "-------------------------\n";

        for (i = 0; i < librarySize; ++i) {
            cout << Movies[i].name << endl;
            cout << Movies[i].genre << endl;
            cout << Movies[i].year << endl << endl;
        };

    }
    void removeMovie() {
        string movieToRemove;
        char confirm = 'N';
        int desiredLine = 0;
        bool nofindings;
        bool movieFound = false;

        cin.ignore();
        //search for movie to be removed
        while (movieFound == false) {
            nofindings = true;
            cout << "Enter movie name to be removed or 0 to exit:\n";
            getline(cin, movieToRemove);
            if (movieToRemove == "0") { return; }

            for (i = 0; i < librarySize; i++) {
                if (">" + movieToRemove == Movies[i].name) {
                    desiredLine = i;
                    cout << "-------------------------\n";
                    cout << Movies[i].name << endl;
                    cout << Movies[i].genre << endl;
                    cout << Movies[i].year << endl;
                    cout << "Movie spot: " << desiredLine + 1 << endl;
                    cout << "-------------------------\n";
                    desiredLine = (i * 4);
                    cout << "Is this the movie your looking for? (Y/N)\n";
                    cin >> confirm;
                    movieFound = true;
                    nofindings = false;
                }
            }
            if (nofindings == true) {
                cout << "\n---couldn't find movie---\n\n";
            }
        }

        if (confirm == 'n' || confirm == 'N') {
            cout << "\n---You may try again---\n\n";
            return searchLibrary();

        }
        //new file with movie removed
        fstream movFile("LibraryMemory.txt");
        ofstream tempFile("Temp.txt");
        string line;
        int currLine = 0;
        if (confirm == 'Y' || confirm == 'y') {
            while (getline(movFile, line)) {
                if (currLine != desiredLine && currLine != (desiredLine + 1)
                    && currLine != (desiredLine + 2) && currLine != (desiredLine + 3)) {
                    tempFile << line << endl;
                }
                currLine++;
            }
            cout << "\nMovie Removed!\n";
            movFile.close();
            tempFile.close();
            remove("LibraryMemory.txt");
            rename("temp.txt", "LibraryMemory.txt");
        };
    }
    void updateMovie() {
        string movieToUpdate;
        char confirm = 'N';
        string currName;
        string currGenre;
        string currYear;
        int desiredLine = 0;
        Movie currMovie;
        bool nofindings;
        bool movieFound = false;

        cin.ignore();

        //search for movie
        while (movieFound == false) {
            nofindings = true;
            cout << "Enter movie to update or 0 to exit:\n";
            getline(cin, movieToUpdate);
            if (movieToUpdate == "0") { return; }

            for (i = 0; i < librarySize; i++) {
                if (">" + movieToUpdate == Movies[i].name) {
                    desiredLine = i;
                    cout << "-------------------------\n";
                    cout << Movies[i].name << endl;
                    cout << Movies[i].genre << endl;
                    cout << Movies[i].year << endl;
                    cout << "Movie spot: " << desiredLine + 1 << endl;
                    cout << "-------------------------\n";
                    desiredLine = (i * 4);
                    cout << "Is this the movie your looking for? (Y/N)\n";
                    cin >> confirm;
                    movieFound = true;
                    nofindings = false;
                }
            }
            if (nofindings == true) {
                cout << "\n---couldn't find movie---\n\n";
            }
        }

        if (confirm == 'n' || confirm == 'N') {
            cout << "\n---You may try again---\n\n";
            return searchLibrary();

        }
        //information to re-enter
        if (confirm == 'Y' || confirm == 'y') {
            cout << "<Re-enter information>\n";

            cout << "Input name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, currName);

            cout << "Input genre: ";
            cin >> currGenre;
            cout << "Input year: ";
            cin >> currYear;

            fstream movFile("LibraryMemory.txt");
            ofstream tempFile("Temp.txt");
            string line;
            int currLine = 0;
            if (currName == "0") {
                cout << "\n\n-Error: '0' may not be used as a movie name. Try again!-\n\n";
                return;
            }
            //saves movie to new file made
            while (getline(movFile, line)) {
                if (currLine != desiredLine && currLine != (desiredLine + 1)
                    && currLine != (desiredLine + 2) && currLine != (desiredLine + 3)) {
                    tempFile << line << endl;
                }
                if (currLine == desiredLine) {
                    tempFile << ">" << currName << endl;
                    tempFile << "Genre: " << currGenre << endl;
                    tempFile << "Year: " << currYear << endl << endl;
                }
                currLine++;
            }
            cout << "\nMovie Updated!\n";
            movFile.close();
            tempFile.close();
            remove("LibraryMemory.txt");
            rename("temp.txt", "LibraryMemory.txt");
        }
    };
};
#endif