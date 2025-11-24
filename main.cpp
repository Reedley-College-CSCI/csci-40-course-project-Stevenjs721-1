// CSCI-40 Final Project
// Author: [Steven Sumaya]

/* 
 * Description:
 * A movie library that allows users to input, store, and filter a through
 * movies. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

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
        ofstream movFile("LibraryMemory.txt", ios::app);

        movFile << ">" << name << endl;
        movFile << "Genre: " << genre << endl;
        movFile << "Year: " << year << endl << endl;

        cout << "\nMovie saved!\n\n";
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
    struct currLibrary {
        string name;
        string genre;
        string year;
        int size = 0;
    };
public:
    void printMain() const{
        cout << "-------------------------\n";
        cout << "      Movie Library      \n";
        cout << "-------------------------\n";
        cout << "Enter: \n";
        cout << "1 to print Library \n";
        cout << "2 to enter a movie \n";
        cout << "3 to remove a movie \n";
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
    cout << endl;
    while (choice != 5) {
        switch (choice) {
        case 1:
            Library.printLibrary();
            main();
            break;
        case 2:
            cout << "Input name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, currName);

            cout << "Input genre: ";
            cin >> currGenre;
            cout << "Input year: ";
            cin >> currYear;
            currMovie.setMovieInfo(currName, currGenre, currYear);
            currMovie.saveMovie();
            main();
            break;
        case 3:

            main();
            break;
        }
    }
    return 0;
}
