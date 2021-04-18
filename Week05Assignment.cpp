// Week05Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cassert>
#include <string>

using namespace std;

// This is the ShowUsage function that will take the user to the directions at the top
void ShowUsage() {
    // Just a series of cout statments including an empty line at the beginning
    cout << endl;
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
}

// The MakePurchase function which will sell the surfboards
// Added XXXS as an option for MakePurchase
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS) {
    // We need two inputs, quantity and size
    int quantity;
    string size;

    // Ask the user for their input
    // Added XXXS as an option for the input
    cout << "Please enter the quantity and type (X=XXXS, S=small, M=medium, L=large) or surfboard you would like to purchase: ";
    cin >> quantity;
    cin >> size; // CAST TO UPPER
    transform(size.begin(), size.end(), size.begin(), ::toupper);

    // We need to keep a count of how many of each type of surfboard was purchased
    // I used an if statement to do this
    // If size is small, add the quantity to the counter iTotalSmall
    if (size == "S") {
        iTotalSmall = iTotalSmall + quantity;
    }
    // If size is medium, add the quantity to the counter iTotalMedium
    else if (size == "M") {
        iTotalMedium = iTotalMedium + quantity;
    }
    // If size is large, add the quantity to the counter iTotalLarge
    else if (size == "L") {
        iTotalLarge = iTotalLarge + quantity;
    }
    // else if statement for the xxxs size
    else if (size == "X") {
        iTotalXXXS = iTotalXXXS + quantity;
    }
    // Default case to exit program if user enters wrong input
    else {
        cout << "Wrong input, exiting program..." << endl;
        system("pause");
    }
}

// The DisplayPurchase function which will display the total number of each surfboard purchased
// Added iTotalXXXS as a parameter
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) {
    // We don't want to display the sizes that haven't received any purchases yet
    // I used if statements to do this
    if (iTotalSmall != 0) {
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    }
    if (iTotalMedium != 0) {
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    }
    if (iTotalLarge != 0) {
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    }
    // if statement for the xxxs size
    if (iTotalXXXS != 0) {
        cout << "The total number of XXXS surfboards is " << iTotalXXXS << endl;
    }
    // had to add xxxs to this as well
    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXXXS == 0) {
        cout << "No purchases made yet." << endl;
    }
}

// The DisplayTotal function which will display the amount of money made
// Added iTotalXXXS as a parameter here
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) {
    // Declare the variables for board prices
    const double smallPrice = 175.00;
    const double mediumPrice = 190.00;
    const double largePrice = 200.00;
    // made up a price for xxxs size
    const double xxxsPrice = 100.00;

    // Declare variables for the size totals
    double smallTotal = 0.0;
    double mediumTotal = 0.0;
    double largeTotal = 0.0;
    // added xxxs here too
    double xxxsTotal = 0.0;

    // We don't want to display prices for sizes that haven't received purchases yet
    // Again, I used if statements to accomplish this
    if (iTotalSmall != 0) {
        smallTotal = iTotalSmall * smallPrice;
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << fixed << setprecision(2) << smallTotal << endl;
    }
    if (iTotalMedium != 0) {
        mediumTotal = iTotalMedium * mediumPrice;
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << fixed << setprecision(2) << mediumTotal << endl;
    }
    if (iTotalLarge != 0) {
        largeTotal = iTotalLarge * largePrice;
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << fixed << setprecision(2) << largeTotal << endl;
    }
    // now to calculate the price for xxxs
    if (iTotalXXXS != 0) {
        xxxsTotal = iTotalXXXS * xxxsPrice;
        cout << "The total number of xxxs surfboards is " << iTotalXXXS << " at a total of $" << fixed << setprecision(2) << xxxsTotal << endl;
    }
    // added xxxs here
    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXXXS == 0) {
        cout << "No purchases made yet." << endl;
    }

    // Now we need to calculate the total money made
    // add the money from xxxs to here as well
    double moneyMade = smallTotal + mediumTotal + largeTotal + xxxsTotal;

    // Only display the amount due if money made is not $0
    if (moneyMade != 0.0) {
        cout << "Amount due: $" << moneyMade << endl;
    }
}


int main()
{
    // Program header
    cout << setw(57) << setfill('*') << "*" << endl;
    cout << setw(57) << setfill('*') << " Welcome to Johnny Utah's PointBreak Surf Shop *****" << endl;
    cout << setw(57) << setfill('*') << "*" << endl;

    // Variable declarations
    string input;
    int smallBoards = 0;
    int mediumBoards = 0;
    int largeBoards = 0;
    // now to incorporate the new size into main
    int xxxsBoards = 0;

    // Calling the ShowUsage() function
    ShowUsage();
 
    // Ask the user to make a selection
    cout << endl;
    cout << "Please enter selection: ";
    cin >> input; // CAST TO UPPER
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    // We need to keep asking the user to make a selection unless they enter 'Q' as their input, so we need a loop
    // I used a while loop to keep on asking for selections until Q is entered
    while (input != "Q") {
        // Here I'm going to use a series of if statements to call the appropriate function depending on the user input
        // Call the ShowUsage function if the user inputs 'S'
        if (input == "S") {
            // Clear the screen when 'S' is chosen as the input
            system("cls");

            cout << setw(57) << setfill('*') << "*" << endl;
            cout << setw(57) << setfill('*') << " Welcome to Johnny Utah's PointBreak Surf Shop *****" << endl;
            cout << setw(57) << setfill('*') << "*" << endl;
            ShowUsage();
        }
        // Call the MakePurchase function if the user inputs 'P'
        else if (input == "P") {
            MakePurchase(smallBoards, mediumBoards, largeBoards, xxxsBoards);
        }
        // Call the DisplayPurchase function if the user inputs 'C'
        else if (input == "C") {
            DisplayPurchase(smallBoards, mediumBoards, largeBoards, xxxsBoards);
        }
        // Call the DisplayTotal function if the user inputs 'T'
        else if (input == "T") {
            DisplayTotal(smallBoards, mediumBoards, largeBoards, xxxsBoards);
        }
        // Default case to immediately end program if user enters invalid value
        else {
            cout << "You entered an incorrect value, ending program..." << endl;
            system("pause");
            return 0;
        }
        // Ask the user to make a selection again after the if statement is done executing
        cout << endl;
        cout << "Please enter selection: ";
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);
    }
    // End program if user inputs 'Q'
    if (input == "Q") {
        cout << "Thank you" << endl;
        system("pause");
        return 0;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
