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
    void setMovieInfo(string currName, string currGenre, string currYear) {
        movie.name = currName;
        movie.genre = currGenre;
        movie.year = currYear;
    };
    void const saveMovie() {
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
    void printMain() const{
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
        fstream movFile("LibraryMemory.txt");
        string blankLine;
        while (getline(movFile, Movies[librarySize].name)
            && getline(movFile, Movies[librarySize].genre)
            && getline(movFile, Movies[librarySize].year)) {
            getline(movFile, blankLine);
            ++librarySize;

            if (librarySize == Capacity) {
                int newCapacity = Capacity + 20;
                movieStruct* newMovies = new movieStruct[newCapacity];
                for (int i = 0; i < Capacity; ++i) { *(newMovies + i) = *(Movies + i); }
                delete[] Movies;
                Movies = newMovies;
                Capacity = newCapacity;
            }
        }
    };
    void printLibrary() {
        cout << "-------------------------\n";
        cout << "        Movie List       \n";
        cout << "-------------------------\n";

        for (i = 0; i < librarySize; ++i) {
            cout << Movies[i].name << endl;
            cout << Movies[i].genre << endl;
            cout << Movies[i].year << endl << endl;
        };
        cout << "-------------------------\n";
        cout << "Enter: \n";
        cout << "1 to sort\n";
        cout << "2 to search\n";
        cout << "0 to quit\n";
    };
    void removeMovie() {
        string movieR;
        char confirm = 'N';
        int desiredMovie = 0;
        cout << "Enter movie name to be removed: \n";
        cin >> movieR;
        for (i = 0; i < librarySize; i++) {
            if (">" + movieR == Movies[i].name) {
                cout << "-------------------------\n";
                cout << Movies[i].name << endl;
                cout << Movies[i].genre << endl;
                cout << Movies[i].year << endl << endl;
                cout << "-------------------------\n";
                cout << "Is this the movie your looking for? (Y/N)\n";
                cin >> confirm;
                desiredMovie = i;
            };
        };
        if (confirm == 'Y' || confirm == 'y') {
            for (i = desiredMovie; i < librarySize; ++i) {
                Movies[i + 1] = Movies[i];
            };
            cout << "Done!\n";
        }
    }
   
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
    string currYear;
    Library.setLibrary();

    
    Library.printMain();
    cin >> choice;
    cout << endl;
    while (choice != 0) {
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
            Library.removeMovie();
            main();
            break;
        case 4:
            main();
            break;
        default:
            cout << "Invalid Input! Try again.";
            cin >> choice;
            break;
        }
    }
    return 0;
}
