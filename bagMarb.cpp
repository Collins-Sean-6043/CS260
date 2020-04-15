#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

unsigned long bag = 0;
unsigned int selection = 0;
int  stillPlaying = 1;

// This function gives the option to end the program.
// For some reason if I try to move the two lines above where I call this
// function inside here it isn't ending the program.
// For reference:
// cout << "Enter (1) to continue: " << endl;
// cin >> stillPlaying;
// Might be an issue with not setting the stillPlaying variable globally?
// But I should be returning the updated value with "return(stillPlaying);"?
int contFunc (int stillPlaying) {
    switch (stillPlaying) {
        case 1:
            stillPlaying = 1;
            break;
        default:
            stillPlaying = 0;
            break;
    };
    return(stillPlaying);
};

int main () {
    // This creates a loop to interact with the bag multiple times.
    while (stillPlaying == 1){
        // Prompt user for input; options include: add a marble, remove a marble, or dump bag.
        cout << "Would you like to (1) Add a marble, (2) Remove a marble," <<
        " or (3) Dump the bag of marbles? ";
        // Recieve user input
        cin >> selection;
        // Display the result of the user input
        switch (selection) {
            // This case adds a marble to the bag.
            case 1:
                ++ bag;
                cout << "You have added a marble to the bag" << endl;
                cout << "Enter (1) to continue: " << endl;
                cin >> stillPlaying;
                contFunc(stillPlaying);
                break;
            // This case removes a marble from the bag.
            case 2:
                -- bag;
                if (bag == -1){
                    cout << "Oops! There wasn't a marble to remove!" << endl;
                    bag = bag + 1;
                } else {
                    cout << "You have removed a marble from the bag" << endl;
                }
                cout << "Enter (1) to continue: " << endl;
                cin >> stillPlaying;
                contFunc(stillPlaying);
                break;
            // Print the number of marbles that were in the bag
            // then reset bag variable to 0.
            case 3:
                cout << "The bag is now empty, and there are "
                << bag << " marbles on the floor" << endl;
                bag = 0;
                cout << "Enter (1) to continue: " << endl;
                cin >> stillPlaying;
                contFunc(stillPlaying);
                break;
            // Default case for misinput.
            default:
                cout << "Invalid Entry" << endl;
                cout << "Enter (1) to continue: " << endl;
                cin >> stillPlaying;
                contFunc(stillPlaying);
                break;
        }
    }
    return 0;
}
