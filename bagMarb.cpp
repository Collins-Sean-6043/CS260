#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main () {
    unsigned long bag = 0;
    unsigned int selection = 0;
    int  stillPlaying = 1;

    while (stillPlaying == 1){
        cout << "Would you like to (1) Add a marble, (2) Remove a marble," <<
        " or (3) Dump the bag of marbles? "; // Prompt user for input
        cin >> selection; // Recieve user input
        switch (selection) { // Display the result of the user input
            case 1:
                bag = bag + 1;
                cout << "You have added a marble to the bag" << endl;
                cout << "Continue? Type (1) for yes or (0) for no: " << endl;
                cin >> stillPlaying;
                switch (stillPlaying == 1) {
                    case 1:
                        break;
                    default:
                        stillPlaying = 0;
                        break;
                }
                break;
            case 2:
                bag = bag - 1;
                if (bag == -1){
                    bag = bag + 1;
                    break;
                }
                cout << "You have removed a marble from the bag" << endl;
                cout << "Continue? Type (1) for yes or (0) for no: " << endl;
                cin >> stillPlaying;
                switch (stillPlaying == 1) {
                    case 1:
                        break;
                    default:
                        stillPlaying = 0;
                        break;
                }
                break;
            case 3:
                cout << "The bag is now empty, and there are "
                << bag << " marbles on the floor" << endl;
                bag = 0;
                cout << "Continue? Type (1) for yes or (0) for no: " << endl;
                cin >> stillPlaying;
                switch (stillPlaying == 1) {
                    case 1:
                        break;
                    default:
                        stillPlaying = 0;
                        break;
                }
                break;
            default:
                cout << "Invalid Entry" << endl;
                break;
        }
    }
    return 0;
}
