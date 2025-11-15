// CSCI-40 Final Project
// Author: [Steven Sumaya]

/* 
 * Description:
 *
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Movie {
private:
    string name;
    string genre;
    int year;
    double rating;
    bool watchStatus;
public:
    void setMovieInfo(string currName, string currGenre, int currYear) {
        name = currName;
        genre = currGenre;
        year = currYear;
    };
    void saveMovie() {
        ofstream movFile("LibraryMemory.txt");

        movFile << name << endl;
        movFile << "Genre: " << genre << endl;
        movFile << "Year: " << year << endl;

        cout << "Movie saved!" << endl;
        movFile.close();
    }
    void print() {
        cout << "Name: " << name << endl;
        cout << "Genre: " << genre << endl;
        cout << "Year: " << year << endl;
    }
};

class MovieLibrary {
private:
public:
    void printMain() const{
        cout << "-------------------------\n";
        cout << "      Movie Library      \n";
        cout << "-------------------------\n";
        cout << "Enter: \n";
        cout << "1 to print Library \n";
        cout << "2 to enter a movie \n";
    };
    void printLibrary() {
        cout << "-------------------------\n";
        cout << "        Movie List       \n";
        cout << "-------------------------\n";
        ifstream movFile("LibraryMemory.txt");
        string line;
        while (getline(movFile, line)) {
            cout << line << endl;
        }

    };
    //void saveMovie();
};

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
    int currYear;


    Library.printMain();
    cin >> choice;

    if (choice == 1) {
        Library.printLibrary();
    }
    else if (choice == 2) {
        cout << "Input name: ";
        cin >> currName;
        cout << "Input genre: ";
        cin >> currGenre;
        cout << "Input year: ";
        cin >> currYear;
        currMovie.setMovieInfo(currName, currGenre, currYear);
        currMovie.print();
        currMovie.saveMovie();
    };

    return 0;

}
