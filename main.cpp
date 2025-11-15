// CSCI-40 Final Project
// Author: [Your Name Here]

/* 
 * Description:
 *
*/

#include <iostream>

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
    void printLibrary();
};

int main() {
    MovieLibrary Library;
    Library.printMain();
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        Library.printLibrary();
    }
    return 0;

}
