//Name: Hany, Aleeza, and Tuniphn
// Date: 9/1/2026
//Descripion: Module 2 - ADT Assignments

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "input.h"
#include "quadratic.h"
#include "Statistician.h"

using namespace std;

// Function prototypes
char displayMenu();
char option2menu();
char option3menu();
char option4menu();

int main()
{
    char option;
    bool running = true;
	srand(time(0)); // Seed the random number generator

    while (running)
    {
		system("cls");
        option = displayMenu();
        switch (option)
        {
        case '1':
        {
			system("cls");
			Statistician stat; // Create an instance of the Statistician class
            int size = inputInteger("\n\tEnter the number of random numbers to generate: ", 1, 100);
			cout << "\n";
            for (int i = 0; i < size; i++)
            {
                double number = (rand() % 20000 * 0.1) - 1000; // range from -1000 to 1000
				stat.next_number(number); // Add the number to the Statistician object
			    cout << "\t" << number << "\n";
			}
			cout << stat << "\n\n"; // Display the statistics using the overloaded << operator

			stat.erase(); // Reset the Statistician object
            system("pause");
		}
            break;
        case '2':
        {
            quadratic q; // Create an instance of the quadratic class
            bool option1Running = true;
            while (option1Running)
            {
                char option1 = option2menu();
                switch (option1)
                {
                case 'D':
                {
					// Call the function to display the quadratic expression
                    cout << "\n\t" << q.get_a() << "x^2 + " << q.get_b() << "x + " << q.get_c() << "\n\n";
                }

				system("pause");
                    break;
                case 'A':
                {
					// Call the function to set coefficient (a)
					double a_value = inputDouble("\n\tEnter a value and set coefficient (a): ", 0.0,100.0);
					// Set the coefficient (a) of the quadratic expression
					q.set_coefficients(a_value, q.get_b(), q.get_c());
                }
				cout << "\n\n";
				system("pause");
 
                    break;
                case 'B':
                {
					// Call the function to set coefficient (b)
					double b_value = inputDouble("\n\tEnter a value and set coefficient (b): ", 0.0,100.0);
					// Set the coefficient (b) of the quadratic expression
					q.set_coefficients(q.get_a(), b_value, q.get_c());
                }
				cout << "\n\n";
				system("pause");
                    
                    break;
                case 'C':
                {
					// Call the function to set coefficient (c)
					double c_value = inputDouble("\n\tEnter a value and set coefficient (c): ", 0.0,100.0);
					// Set the coefficient (c) of the quadratic expression
					q.set_coefficients(q.get_a(), q.get_b(), c_value);
                }
				cout << "\n\n";
				system("pause");
 
                    break;
                case 'E':
                {
                    // Call the function to get evaluation (x)
                    double x_value = inputDouble("\n\tEnter a value of x: ");
					// Evaluate the quadratic expression for the given value of x
                    double result = q.evaluate(x_value);
					cout << "\n\tEvaluation result: " << result << "\n\n";
                }
				system("pause");

                    break;
                case 'N':
                {
                    // Call the function to get the number of real roots
                    int roots = q.number_of_real_roots();

                    if (roots == 3)
                        cout << "\n\tnumber of real roots: infinity\n";
                    else
                        cout << "\n\tnumber of real roots: " << roots << "\n\n";
                }
				system("pause");

                    break;
                case 'R':
                {
                    // Call the function to get real root(s)
                    int roots = q.number_of_real_roots();
                    if (roots == 0)
                        cout << "\n\tNo real roots.\n\n";
                    else if (roots == 1)
                        cout << "\n\tReal root: " << q.real_root1() << "\n\n";
                    else if (roots == 2)
                        cout << "\n\tReal roots: " << q.real_root1() << " and " << q.real_root2() << "\n\n";
                    else
						cout << "\n\tevery value of x is a real root.\n\n";
                }
				system("pause");

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