//Name: Hany, Aleeza, and Tuniphn
// Date: 9/1/2026
//Descripion: Module 2 - ADT Assignments

#include <iostream>
#include "input.h"

using namespace std;

// Function prototypes
char displayMenu();
char option1menu();
char option2menu();
char option3menu();
char option4menu();

int main()
{
    char option;

    bool running = true;

    while (running)
    {
		system("cls");
        option = displayMenu();
        switch (option)
        {
        case '1':
        {
			bool option1Running = true; //flag to control the loop for option 1
            while (option1Running)
            {
                char option1 = option1menu();
                switch (option1)
                {
                case 'A':
                    // Call the function to get largest
                    break;
                case 'B':
                    // Call the function to get smallest
                    break;
                case 'C':
                    // Call the function to get sum
                    break;
                case 'D':
                    // Call the function to get mean
                    break;
                case '0':
                    option1Running = false; // Exit the loop for option 1
                    cout << "\n\n";
                    system("pause");
                    break;
                default:
                    cout << "Invalid option. Please try again." << "\n";
                    break;
                }
			}
        }
            break;
        case '2':
        {
            bool option1Running = true;
            while (option1Running)
            {
                char option1 = option2menu();
                switch (option1)
                {
                case 'D':
                    // Call the function to display the expression

                    break;
                case 'A':
                    // Call the function to set coefficient (a)

                    break;
                case 'B':
                    // Call the function to set coefficient (b)

                    break;
                case 'C':
                    // Call the function to set coefficient (c)

                    break;
                case 'E':
                    // Call the function to get evaluation (x)

                    break;
                case 'N':
                    // Call the function to get the number of real roots

                    break;
                case 'R':
                    // Call the function to get real root(s)

                    break;
                case '0':
                    option1Running = false; // Exit the loop for option 1
                    cout << "\n\n";
                    system("pause");
                    break;
                default:
                    cout << "Invalid option. Please try again." << "\n";
                    break;
                }
            }


            break;
        }
        case '3':
        {
            bool option2Running = true;
            while (option2Running)
            {
                char option2 = option3menu();
                switch (option2)
                {
                case 'A':
                    // Call the function to get seed
                    break;
                case 'B':
                    // Call the function to set seed
                    break;
                case 'C':
                    // Call the function to get multiplier
                    break;
                case 'D':
                    // Call the function to set multiplier
                    break;
                case 'E':
                    // Call the function to get modulus
                    break;
                case 'F':
                    // Call the function to set modulus
                    break;
                case 'G':
                    // Call the function to get increment
                    break;
                case 'H':
                    // Call the function to set increment
                    break;
                case 'I':
                    // Call the function to get next number
                    break;
                case 'J':
                    // Call the function to get indirect next number
                    break;
                case 'K':
                    // Call the function to run experiment with different values (multiplier, increment, and modulus)
                    break;
                case '0':
                    option2Running = false; // Exit the loop for option 2
                    cout << "\n\n";
                    system("pause");
                    break;
                default:
                    cout << "Invalid option. Please try again." << "\n";
                    break;
                }
            }
            break;
        }



        case '4':
        {
			bool option3Running = true;
            while (option3Running)
            {
                char option3 = option4menu();
                switch (option3)
                {
                case 'A':
                    // Call the function to enter values of rational number R1
                    break;
                case 'B':
                    // Call the function to display R1
                    break;
                case 'C':
                    // Call the function to enter values for rational number R2
                    break;
                case 'D':
                    // Call the function to display R2
                    break;
                case 'E':
                    // Call the function for multiplication of 2 rational numbers (R1 * R2)
                    break;
                case 'F':
                    // Call the function for division of 2 rational numbers (R1 / R2)
                    break;
                case 'G':
                    // Call the function for addition of 2 rational numbers (R1 + R2)
                    break;
                case 'H':
                    // Call the function for subtraction of 2 rational numbers (R1 - R2)
                    break;
                case 'I':
                    // Call the function for (R1 == R2)
                    break;
                case 'J':
                    // Call the function for (R1 < R2)
                    break;
                case '0':
					option3Running = false; // Exit the loop for option 3
                    cout << "\n\n";
                    system("pause");
                    break;
                default:
                    cout << "Invalid option. Please try again." << "\n";
                    break;
                }
			}

            break;
        }
        case 'X':
            running = false; // Exit the loop
            break;
        default:
            cout << "Invalid option. Please try again." << "\n";
            break;
		}
        

    }
	return 0;       
}

// Function to display the main menu and get user input
char displayMenu()
{
    cout << "\tCMPR131 Chapter2 - ADT Assignments by Hany, Aleeza, and Tuniphn  (9/1/2026)" << "\n";
    cout << "\t" << string(80, char(205));
    cout << "\n\t\t1> Statistician" << "\n";
	cout << "\t\t2> Quadratic Expression" << "\n";
    cout << "\t\t3> Pseudorandom" << "\n";
    cout << "\t\t4> Rational number" << "\n";
    cout << "\t" << string(80, char(196)) << "\n";
    cout << "\t\tX. Exit" << "\n";
    cout << "\t" << string(80, char(205)) << "\n";

    char option = toupper(inputChar("\t\tOption: ", static_cast<string>("1,2,3,4,X")));

	return option;
}

// Function to display the option 1 menu and get user input
char option1menu()
{
    system("cls");
    cout << "\n\t1> Statistician" << "\n";
    cout << "\t" << string(80, char(205)) << "\n";
    cout << "\t\tA. Largest " << "\n";
    cout << "\t\tB. Smallest " << "\n";
    cout << "\t\tC. Sum " << "\n";
    cout << "\t\tD. Mean " << "\n";
    cout << "\t" << string(80, char(196)) << "\n";
    cout << "\t\t0. return" << "\n";
    cout << "\t" << string(80, char(205)) << "\n";
    char option = toupper(inputChar("\t\tOption: ", static_cast<string>("A,B,C,D,0")));
    return option;
}

// Function to display the option 2 menu and get user input
char option2menu()
{
	system("cls");
    cout << "\n\t2> Quadratic Menu" << "\n";
    cout << "\t" << string(80, char(205)) << "\n";
    cout << "\t\tD. display the expression" << "\n";
    cout << "\t\tA. set coefficient (a)" << "\n";
    cout << "\t\tB. set coefficient (b)" << "\n";
    cout << "\t\tC. set coefficient (c)" << "\n";
    cout << "\t\tE. get evaluation (x)" << "\n";
    cout << "\t\tN. get the number of real roots" << "\n";
    cout << "\t\tR. get real root(s)" << "\n";
    cout << "\t" << string(80, char(196)) << "\n";
    cout << "\t\t0. return" << "\n";
    cout << "\t" << string(80, char(205)) << "\n";
    char option = toupper(inputChar("\t\tOption: ", static_cast<string>("D,A,B,C,E,N,R,0")));
    return option;
}

// Function to display the option 3 menu and get user input
char option3menu()
{
    system("cls");
    cout << "\n\t3> Pseudorandom menu" << "\n";
    cout << "\t" << string(80, char(205)) << "\n";
    cout << "\t\tA. get seed" << "\n";
    cout << "\t\tB. set seed" << "\n";
    cout << "\t\tC. get multiplier" << "\n";
    cout << "\t\tD. set multiplier" << "\n";
    cout << "\t\tE. get modulus" << "\n";
    cout << "\t\tF. set modulus" << "\n";
    cout << "\t\tG. get increment" << "\n";
    cout << "\t\tH. set increment" << "\n";
    cout << "\t\tI. get next number" << "\n";
    cout << "\t\tJ. get indirect next number" << "\n";
    cout << "\t\tK. run experiment with different values (mutliplier, increment, and modulus)" << "\n";
    cout << "\t" << string(80, char(196)) << "\n";
    cout << "\t\t0. return" << "\n";
    cout << "\t" << string(80, char(205)) << "\n";

    char option = toupper(inputChar("\t\tOption: ", static_cast<string>("A,B,C,D,E,F,G,H,I,J,K,0")));
    return option;
}

// Function to display the option 4 menu and get user input
char option4menu()
{
    system("cls");
    cout << "\n\t4> Rational Number menu" << "\n";
    cout << "\t" << string(80, char(205)) << "\n";
    cout << "\t\tA. enter values of rational number R1" << "\n";
    cout << "\t\tB. display R1" << "\n";
    cout << "\t\tC. enter values for  rational number R2" << "\n";
    cout << "\t\tD. display R2" << "\n";
    cout << "\t\tE. multiplication of 2 rational numbers (R1 * R2)" << "\n";
    cout << "\t\tF. division of 2 rational numbers (R1 / R2)" << "\n";
    cout << "\t\tG. addition of 2 rational numbers (R1 + R2)" << "\n";
    cout << "\t\tH. subtraction 2 rational numbers (R1 - R2)" << "\n";
    cout << "\t\tI. (R1 == R2)" << "\n";
    cout << "\t\tJ. (R1 < R2)" << "\n";
    cout << "\t" << string(80, char(196)) << "\n";
    cout << "\t\t0. return" << "\n";
    cout << "\t" << string(80, char(205)) << "\n";
    char option = toupper(inputChar("\t\tOption: ", static_cast<string>("A,B,C,D,E,F,G,H,I,J,0")));
    return option;
}





