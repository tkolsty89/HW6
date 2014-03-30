//----------------------------------------------------------
//  Tim Kolstrom
//  trk10@psu.edu
//  CMPSC 121 section 001
//  HW #6
//  2014-03-28
//  This program runs a multiplication-based game for children that prompts the user
//	for an answer to the randomly generated math problem and then responds if the user
//	is correct or incorrect.
//----------------------------------------------------------


#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

//Function prototypes
void askQuestion(int, int);
void correctMessage();
void incorrectMessage();

//Declares the variable for when the program ends
int quit = 0;


//---------------------------------
//The main function
//---------------------------------

int main()
{
    
	//Title message
	cout << "----------------------------------------------------------";
	cout << endl << "Welcome to the Multiplication Game" << endl;
	cout << "----------------------------------------------------------";
	cout << endl;
	cout << "Enter the number 999 at any time to quit the program.";
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
    
	//Seeds the random number function so the questions will be different each time the user runs the program
	srand(time(0));
    
	//Keeps asking the user questions until they enter the number 999
	while(quit != 999)
	{
		//Sets the num1 and num2 variables to integers between 0 and 9
        int num1 = rand() % 10;
		int num2 = rand() % 10;
        
        //Runs the askQuestion function using the two random numbers
		askQuestion(num1, num2);
        
        
	}
    
    //Once the loop that runs the questions is exited using the exit input of 999, the program
    //displays a goodbye message and ends
    
	cout << endl;
	cout << "Thank you for playing the multiplication game.  Goodbye!";
	cout << endl;
	return 0;
    
}

//---------------------------------
//The askQuestion function
//---------------------------------

void askQuestion(int num1, int num2)
{
    
    //Declares the local variable, answer
	int answer;
    
    //Starts a do-while loop asking the user the multiplication question
	do
	{
		cout << endl;
		
        //Asks the user the question using the two randomly generated numbers
        cout << "How much is " << num1 << " times " << num2 << "? ";
		cin >> answer;
        
        //First, if the user input is 999, the program returns to the main function and ends
		if(answer == 999)
		{
			quit = 999;
			return;
		}
        
        //Tests to see if the answer the user entered is equal to the right answer
		if(answer == (num1 * num2))
		{
            //Runs the correct message function
			correctMessage();
			return;
		}
		else
		{
            //Runs the incorrectMessage function if the user answers the question incorrectly
			incorrectMessage();
		}
        
	}while(answer != (num1 * num2)); //Keeps asking the same question until the question is answered correctly
    
	return;
    
}

//---------------------------------
//The function that is run if the user answers correctly
//---------------------------------

void correctMessage()
{
	cout << endl;
    
    //Seeds the random number function so the responses will be different each time the user runs the program
	srand(time(0));
    
    //Generates a random number between 1 and 4 in order to decide what response message to display
	int message = rand() % 4 + 1;
    
    //Switch statement that displays the response messages
	switch(message)
	{
		case 1:
			cout << endl << "Very good!";
			break;
		case 2:
			cout << endl <<"Perfect!";
			break;
		case 3:
			cout << endl <<"Awesome job!";
			break;
		case 4:
			cout << endl <<"Good work dude!";
			break;
		default:
			cout << endl <<"Unknown error";
	}
	
	return;
    
    
}

//---------------------------------
//The function that is run if the user answers incorrectly
//---------------------------------

void incorrectMessage()
{
    
	cout << endl;
    
    //Seeds the random number function so the responses will be different each time the user runs the program
	srand(time(0));
    
    //Generates a random number between 1 and 4 in order to decide what response message to display
	int message = rand() % 4 + 1;
    
    //Switch statement that displays the response messages
	switch(message)
	{
		case 1:
			cout << endl << "Sorry, try again!";
			break;
		case 2:
			cout << endl <<"Incorrect, give it another go!";
			break;
		case 3:
			cout << endl <<"Hmmm, that's not quite right!";
			break;
		case 4:
			cout << endl << "Try again, that's not correct!";
			break;
		default:
			cout << endl <<"Unknown error";
	}
	
	return;
    
}
