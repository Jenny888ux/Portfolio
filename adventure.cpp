/*==========================================================
 Author: Blake Capella
 Modified By: -
 Date: 12/6/16

 Course: CSC215
 File:  adventure.cpp
 Rev #: 1.0
 Description:
 ============================================================*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void spacing(int j, int k = 0)// creates a function that allows for consistent spacing of text
{
	int i = 0;

	for (i=0;i<j;i++)// set up loop
	{
		cout << endl; // output a new line
	}// end for

	if (k==1) // if k is included, include indentation --  for UI
	{
		cout << "											";
	}// end if

	if (k==2)// this is for the paragraphs of text, basically another option for spacing
	{
		cout << "				";
	}// end if

	return;
} // end spacing

void help(bool& hasPaper, bool& hasRiddle, bool& hasBook, bool& hasClock, bool& hasKeyTwo, bool& hasKey) // Creates a menu to appear beneath each new text box providing their options and inventory
{
		cout << endl << endl << "					 ------------------------------------------------------------------------------------------------------------------------" << endl;
	 	spacing(3);
	 	cout << "						       Please enter a command in the following format: *command* [secondary command] --> ENTER" << endl << endl;
	 	cout << "							     If you do not wish to input a secondary command, simply enter a random character" << endl << endl;
	 	spacing(1);
	 	cout << "					 		  examine [object]:					Allows you to look closer at an object or location" << endl << endl;
	 	cout << "							  use [object]:						Use or refer to an item in your inventory" << endl << endl;
	 	cout << "							  move [grass, bedroom, shelf, workbench]:		Allows you to move between locations" << endl << endl;
		cout << "							  pickup [object]:					Adds an item into your inventory" << endl << endl;


		spacing(2);
		cout << "								Inventory:    ";

		/* The following if statements check to see what items the user picked up as represented by the bool variables that begin with has (ex. hasKey etc).
		If the user has the item, it is displayed under inventory*/

		if (hasBook == true)
		{
			cout << "Book" << " 	";
		}// end inventory Book

		if (hasClock == true)
		{
			cout << "Clock" << " 	";
		}// end inventory clock

		if (hasPaper == true)
		{
			cout << "Paper" << " 	";
		}// end inventory paper

		if (hasRiddle == true)
		{
			cout << "Riddle" << " 	";
		}// end inventory riddle

		if (hasKey == true )
		{
			cout << "Key" << " 	";
		}// end inventory key 1

		if (hasKeyTwo == true)
		{
			cout << "Fancy Key" << " 	";
		}// end inventory key 2

		cout << endl << endl << "					 ------------------------------------------------------------------------------------------------------------------------" << endl;


		return;
}// end help

void examine(string userInTwo, bool& inGrass, bool& inBed, bool& inShelf, bool& inWork, bool& openWardrobe, bool& openSafe, bool& openChest) // begin examine function
{
	string input;
	string inputTwo;
	int rand; // no initialization of variable to ensure randomness

	system("cls");

	/*the examine function is broken up by location. The first variable the function checks is the location bools (ex. inGrass etc). Once your location has been determined
	the function then checks what the user in was after the examine command was inputted. When a match is found, information is displayed on screen*/

	if(inGrass == true)
	{
		spacing(5,2);
		cout << "As you look at your feet, you notice an outline in the vegetation. After a moment's pause, you realise there is some sort of locked door beneath your feet";

	}// end grass if

	else if(inBed == true)
	{

		if(userInTwo == "Bed" || userInTwo == "bed") // if they ask about the bed
		{
			spacing(5,2);
			cout << "	Upon further inspection, the bed is practically falling apart. Of its four supporting legs, only two remain intact. The others lay in pieces," << endl;
			spacing(0,2);
			cout << "	rotten with decay, along the floor" << endl;

		}// end bed

		else if(userInTwo == "Chest" || userInTwo == "chest") // if they input chest
		{

				spacing(5,2);
				cout << "		  The chest seems to be made of a non organic material. You determine this must be the cause of its durability." << endl;
				spacing(0,2);
				cout << "		  As the chest creaks open, you peer inside and see nothing but some metal scraps and threadbare clothing" << endl;


		}// end chest

		else if(userInTwo == "wardrobe" || userInTwo == "Wardrobe") // if they input wardrobe
		{

				spacing(5,2);
				cout << "	  The wardrobe, although probably at the end of its lifespan, was eerily fascinating." << endl;
				spacing(0,2);
				cout << "	  Throughout the entire wardrobe there seems to be a recurring flower motif, which only adds to its beauty." << endl;
				spacing(0,2);
				cout << "	  After taking a moment to admire the beauty of the furnishing, you notice a small keyhole in the center of the decorated door." << endl;


		}// end wardrobe

		else
		{
			spacing(5,1);
			cout << "Item not Recognized" << endl;
		}// end error else

	}// end bed if


	else if(inShelf == true)
	{

		if(userInTwo == "Paper" || userInTwo == "paper")
		{
			spacing(5,2);
			cout << "				The piece of paper contains a string of characters written in a mechanical text:" << endl;
			spacing(0,1);
			cout << "      " << rand; // output the random number

		}// end paper

		else if(userInTwo == "Book" || userInTwo == "book")
		{
			spacing(5,2);
			cout << "				The ornate book seems to be coated in a slick clear material. The book is titled:" << endl;
			spacing(1,2);
			cout << "							 2 1 0 0 ' s  a n d  T o d a y "<< endl;
			spacing(1,2);
			cout << "				As you flip open the book, you notice hundreds of pages containing some cryptic script." << endl;


		}// end book

		else if(userInTwo == "Key" || userInTwo == "key")
		{
			spacing(5,2);
			cout << "			The key seems to be a relic of a bygone era, its once sheen exterior now covered in rust." << endl;

		}// end book

		else
		{
			spacing(5,1);
			cout << "Item not Recognized" << endl;
		}// end error else


	}// end shelf if

	else if(inWork == true)
	{

		if(userInTwo == "Safe" || userInTwo == "safe") //Safe is a special case, instead of simply providing info, it must also allow for user interaction
		{
			spacing(5,2);
			cout << "		A safe large enough to hold a small loaf of bread rests on the table. Its black sheen speaks of a " << endl;
			spacing(0,2);
			cout << "		newness that is otherwise lacking in this mothridden environment. However, upon closer inspection the " << endl;
			spacing(0,2);
			cout << "		safe is indeed as old as its surroundings. Unlike a conventional safe, this container held a small " << endl;
			spacing(0,2);
			cout << "		alphanumeric keypad." << endl;

			/* manually output help menu due to fact that help function would require to pass in all of the inventory boolean*/

			cout << endl << endl << "					 ------------------------------------------------------------------------------------------------------------------------" << endl;
			spacing(3);
			cout << "						       Please enter a command in the following format: *command* [secondary command] --> ENTER" << endl << endl;
			cout << "							     If you do not wish to input a secondary command, simply enter a random character" << endl << endl;
			spacing(1);
			cout << "					 		  examine [object]:					Allows you to look closer at an object or location" << endl << endl;
			cout << "							  use [object]:						Use or refer to an item in your inventory" << endl << endl;
			cout << "							  move [grass, bedroom, shelf, workbench]:		Allows you to move between locations" << endl << endl;
			cout << "							  pickup [object]:					Adds an item into your inventory" << endl << endl;
			cout << endl << endl << "					 ------------------------------------------------------------------------------------------------------------------------" << endl;

			spacing(2,1);
			cout <<"What would you like to do with the safe?" << endl; // custom prompt to tell user that they are still dealing with the safe
			spacing(0,1);
			cin >> input >> inputTwo; // ask for an additional input to determine if the user intends to interact with the safe.
			//input two to catch any extra words they type

			if( (input == "use" || input == "Use" || input == "examine" || input == "Examine") && (inputTwo == "keyboard" || inputTwo == "Keyboard" || inputTwo == "keypad" || inputTwo == "Keypad"))
			{
				system("cls");

				spacing(5,2);

				cout << "					Youre fingers hover lighlty over the keypad as you begin to type." << endl; // custom prompt to inform the user there is no need for command words

				/* manually output help menu due to fact that help function would require to pass in all of the inventory boolean*/

				cout << endl << endl << "					 ------------------------------------------------------------------------------------------------------------------------" << endl;
				spacing(3);
				cout << "						       Please enter a command in the following format: *command* [secondary command] --> ENTER" << endl << endl;
				cout << "							     If you do not wish to input a secondary command, simply enter a random character" << endl << endl;
				spacing(1);
				cout << "					 		  examine [object]:					Allows you to look closer at an object or location" << endl << endl;
				cout << "							  use [object]:						Use or refer to an item in your inventory" << endl << endl;
				cout << "							  move [grass, bedroom, shelf, workbench]:		Allows you to move between locations" << endl << endl;
				cout << "							  pickup [object]:					Adds an item into your inventory" << endl << endl;
				cout << endl << endl << "					 ------------------------------------------------------------------------------------------------------------------------" << endl;

				spacing(0,1);
				cout << "What do you want to type?" << endl; // custom prompt again to inform user there is no need for command words
				spacing(0,1);
				cin >>  input >> inputTwo;


				if (input == "history" || input == "History")// checking password
				{
					system("cls");
					openSafe = true; // allows for pickup command in later sections

					spacing(5,2);
					cout << "			After inputting the code, you hear small mechanical noises as the door pops open. A rush of stale air exits" << endl;
					spacing (0,2);
					cout << "			the safe as the light reaches the insides of the safe for the first time in centuries. Within the safe" << endl;
					spacing(0,2);
					cout << "			you notice an ornate key engraved with pictures of leaves and animals." << endl;

				}// end passcode if

				else // error message for incorrect passcode
				{
					system("cls");
					spacing(5,1);
					cout << "The machine does not respond to your inputs." << endl;
				}// end error else

			}// end use if

			else // if they do not wish to use keypad let them know they move away from the safe
			{
				system("cls");
				spacing(5,2);
				cout << "				You decide to move along and come back to the safe another time." << endl;
			}// end else

		}// end safe

		else if(userInTwo == "Clock" || userInTwo == "clock")
		{
			spacing(5,2);
			cout << "			The clock on the table is a feat of technology. The entire object is composed of a single gear inscribed" << endl;
			spacing(0,2);
			cout << "			with roman numerals. The second, minute, and hour hands are the only moving objects on the entire thing." << endl;

		}// end clock

		else if(userInTwo == "Plant" || userInTwo == "plant")
		{
			spacing(5,2);
			cout << "			From some vauge recess of your memory you recall these plants are called Aconite." << endl;
			spacing(0,2);
			cout << "			Even the name gives you a sense of foreboding. \"I should probably stay away from that\" you think." << endl;

		}// end plant

		else if(userInTwo == "painting" || userInTwo == "Painting")
		{
			spacing(5,2);
			cout << "		The massive painting seems to portray a majestic landscape. There are vivid colors detailing" << endl;
			spacing(0,2);
			cout << "		mountains, rivers, and wildlife. In the bottom corner of the painting you notice the inscription:" << endl;
			spacing(1,1);
			cout << "-BC" << endl;

		}// end painting

		else // simple error message if userInTwo has an unknown value
		{
			spacing(5,1);
			cout << "Item not Recognized" << endl;
		}// end error else

	}// end workbench if
}// end examine if

void use(string userInTwo, bool& hasPaper, bool& hasRiddle, bool& hasBook, bool& hasClock, bool& hasKeyTwo, bool& hasKey, bool& inBed, bool& inGrass, bool& openChest, bool& openWardrobe)
{
	short randNum; // not defined to ensure originality

	system("cls");
	string buffer; // variable to use when requirng user input to continue the game


	if ( (userInTwo == "Paper" || userInTwo == "paper") && hasPaper == true) // as long as they have the paper and input it correctly
	{
		spacing(5,1);
		cout << "				The small scrap of paper contains a senseless combination of characters: " << endl;
		spacing(0,1);
		cout << randNum << endl; // output a short from a location in the computers memory (whatever was present prior to the program)

	}// end paper use

	else if ( (userInTwo == "riddle" || userInTwo == "Riddle") && hasRiddle == true)// as long as they have the riddle and input it correctly
	{
		spacing(5,2);
		cout << "		The riddle reads: " << endl << endl;
		spacing(0,2);
		cout << "		You will always find me in the past. I can be created in the present, But the future can never taint me. What am I?" << endl << endl;
		spacing(0,2);
		cout << "		After taking a moment to wonder at the simplicity of the question, you notice an odd signature at the bottom of the page:" << endl << endl;
		spacing(0,1);
		cout << "-BC";

	}// end riddle use

	else if ( (userInTwo == "clock" || userInTwo == "Clock") && hasClock == true) // as long as they have the clock and input it correctly
	{
		spacing(5,1);
		cout << "The time is..... exactly 12'o clock" << endl;
		spacing(0,1);
		cout << "\"Huh.. that's odd... the clock seems to have stopped working\"";

	}// end clock use

	else if ( (userInTwo == "Key" || userInTwo == "key") && hasKey == true && inBed == true)// as long as they have the key1 and input it correctly
	{
		spacing(5,2);
		cout << "	You take the key and slide it into the wardrobe's lock. With a resounding 'click' the wardrobe's lock disengages and the door pops open" << endl;
		spacing(0,2);
		cout << "	Very slowly, you are able to open the door, but not without destroying the antuiqe hinges holding the door to the frame. Inside of the" << endl;
		spacing(0,2);
		cout << "	wardrobe is a single, luxurious, robe made of some sort of synthetic polymer resting upon a single wooden peg. You notice out of the corner" << endl;
		spacing(0,2);
		cout << "	of your eye a small slip of paper inside of the robe's pocket." << endl;

		openWardrobe = true;

	}// end key use

	else if ( (userInTwo == "Book" || userInTwo == "book") && hasBook == true)// as long as they have the book and input it correctly
	{
		spacing(5,2);
		cout << "		After examining the book throroughly, you come to the conclusion that the book contains only gibberish!" << endl;

	}// end key use

	else if ( (userInTwo == "Key" || userInTwo == "key") && hasKeyTwo == true && inGrass ==true)// as long as they have the key2 and input it correctly
	{
		spacing(5,2);
		cout << "You shove dirt off of the top of the trapdoor..After a few minutes of work and significant elbow grease, you are able to uncover the keyhole." << endl;
		spacing(0,2);
		cout << "Unnoticed under the dirt, many curious designs and graphics adorn the trapdoor. After a few moments of searching you locate a small keyhole hidden among the designs." << endl;
		spacing(0,2);
		cout << "As you slide the key into the keyhole, you hear a soft click as the bolts catch.You harness your strength and manage to lift the trapdoor, releasing a cool breeze" << endl;
		spacing(0,2);
		cout << "of fresh air. Relishing in your freedom, you look down, and see nothing but bright blue sky." << endl;
		spacing(2,1);
		cout << "-FIN-" << endl;

		spacing(5,1);
		cin >> buffer;

		system("cls");

		spacing(5,1);
		cout << "	Writing: BLAKE CAPELLA" << endl; // give credit where credit is due
		spacing(5,1);
		cout << "	Coding: BLAKE CAPELLA" << endl;
		spacing(5,1);
		cout << "Computer Science 215 - Final Project" << endl;
		spacing(0,1);
		cout << "	Prof. Nakra --- 12/12/16";

		spacing(5,1);
		cin >> buffer;
		system("cls"); // clear screen one last time


		exit(1); // exit program


	}// end key2 use

	else // error message
	{
		spacing(5,1);
		cout << "Unkown object to use, Please try again";
	}// end error

}// end use

int main(void)
{

	string userIn; // initialize
	string userInTwo;


	int i = 0;
	int error = 0;

	//Locations :
	bool inGrass = true; // initialize as true due to it being the starting location
	bool inBed = false;
	bool inShelf = false;
	bool inWork = false;
	//Items :
	bool hasPaper = false;
	bool hasBook = false;
	bool hasKey = false;
	bool hasKeyTwo = false;
	bool hasRiddle = false;
	bool hasClock = false;
	//Puzzles:
	bool openWardrobe = false;
	bool openChest = false;
	bool openSafe = false;


	system("cls");

	spacing(5,1);// tabbing for the title screen is particularly unuiqe, no use for a function
	cout << "    P - u - z - z - l - e " << endl; // very creative title
	spacing(7,1);
	cout << "	\"So it goes.\"" << endl << endl; // add a random quote because I felt like it
	spacing(0,1);
	cout << "	-Kurt Vonnegut" << endl;


	spacing(20,1);
	cout << "Enter a character to continue" << endl; // prompt for input to continue
	spacing(0,1);
	cin >> userIn;

	system("cls");

	spacing(6);
	cout << "					 			examine [object]: 	            Allows you to look closer at an object or location" << endl << endl; //give first control layout
	cout << "								use [object]: 					Use or refer to an item in your inventory" << endl << endl;
	cout << "								move [location]: 				Allows you to move between locations" << endl << endl;
	cout << "								pickup [object]: 				Adds an item into your inventory" << endl << endl;

	spacing(3);
	cout << "										     Enter a character to continue" << endl; // prompt for input to continue
	cout << "                         					                                  ";
	cin >> userIn;

	system("cls");

	spacing(5,2);
	cout << "You open your eyes, slowly, as you groggily gain consciousness. Slowly, a thought crosses your mind \"Where am I..?\". With your eyes still bleary from rest," << endl;
	spacing(0,2);
	cout << "you slowly stumble to your feet. Looking around, you find yourself in a small grass clearing, dimly light by an unknown light source. At the perimeter of the grassy" << endl;
	spacing(0,2);
	cout << "clearing, the vegetation slowly turns to raw stone. At the perimeter of your vision, you are able to make out some semblences of habitation. From this distance," << endl;
	spacing(0,2);
	cout << "all that you are able make out is a small bedroom, shelves, and a workbench.";


	while (true) // Infinite loop
	{
		char beep = 0x007; // for error noise
		userIn = '0'; // reset values
		userInTwo = '0';

		/* this is the main prompt/ help screen that appears after every action*/

		if (error == 0)// to not produce help message again if an incorrect input is placed
		{
			help(hasPaper, hasRiddle, hasBook,  hasClock, hasKeyTwo, hasKey);//status window
		}

			error = 0;

			spacing(3,1);
			cout << "What would you like to do?" << endl; //prompt user input
			cout << "                                                                                               ";
			cin >> userIn >> userInTwo; // userIn three to collect any input past command words

	// if three words were inputted without three variables to catch, the last word would become userIn on the next input, making it hard for the user to input any correct commands

		/*this is the if sequence that determines what the command was*/

		if ( userIn == "examine" || userIn == "Examine")
		{
			examine(userInTwo, inGrass, inBed, inShelf, inWork, openWardrobe, openSafe, openChest); // examine as a function for simplicity
		}// end examine

		if ( userIn == "move" || userIn == "Move" )
		{
			/*When move is trigerred, the bool are reset to the intended location. This is used as a key to unlock
			certain aspects of the if statements, and it also outputs a confirmation that movemnt has occured alongside basic description
			of the environment*/

			system("cls");

			if(userInTwo == "Workbench" || userInTwo == "workbench")
			{
				spacing(5,1);
				cout << "You move over to the workbench" << endl;

				spacing(5,2);
				cout << "			The workbench seems well used, showing many scuff marks and burns along its surface. Among the" << endl;
				spacing(0,2);
				cout << "			strange tools and useless tidbits of electrical components you notice a small clock resting next " << endl;
				spacing(0,2);
				cout << "			to a large safe bordered by potted plants. Behind the plants, you notice a massive oil painting." << endl;

				inGrass = false;
				inBed = false;
				inShelf = false;
				inWork = true;



			}// end work table move

			else if(userInTwo == "Bedroom" || userInTwo == "bedroom")
			{
				spacing(5,1);
				cout << "You walk towards the bedroom" << endl;

				spacing(5,2);
				cout << "The bedroom is oddly tidy. A small bed is situated alonside the far wall, adorned with moth ridden sheets and an empty pillowcase. " <<  endl;
				spacing(0,2);
				cout << "At the foot of the bed is a small chest. Out of all of the things in the room, this chest seems to be the only piece of wood that hasn't rotted away" << endl;
				spacing(0,2);
				cout << "Last, you notice a tall wardrobe flush with the wall perpindicular to the bed. This piece of furniture is particularly exquisite, and you hazard a guess" << endl;
				spacing(0,2);
				cout << "that it would have been a luxury good hundreds of years ago" << endl;


				inGrass = false; // reset where player is located with booleans
				inBed = true;
				inShelf = false;
				inWork = false;


			}// end bed move

			else if(userInTwo == "shelf" || userInTwo == "Shelf")
			{
				spacing(5,1);
				cout << "You saunter towards the shelves" << endl;

				spacing(5,2);
				cout << "		The shelf is dilapidated and worn, it seems to be hanging on by a single thread. Miraculously there are a few objects" << endl;
				spacing(0,2);
				cout << "		still resting upon the shelf. A well preserved novel, hidden among the husks of ruined books, rests upon the shelf." << endl;
				spacing(0,2);
				cout << "		In the folds ofthe book rests a slip of paper. Further along the shelf rests a rusty key surrounded by cobwebs." << endl;

				inGrass = false;
				inBed = false;
				inShelf = true;
				inWork = false;

			}// end shelf move

			else if(userInTwo == "grass" || userInTwo == "Grass")
			{
				spacing(5,1);
				cout << "You move over towards the clearing" << endl;

				spacing(5,2);
				cout << "As you look at your feet, you notice an outline in the vegetation. After a moment's pause, you realise there is some sort of locked door beneath your feet";

				inGrass = true;
				inBed = false;
				inShelf = false;
				inWork = false;

			}// end grass move

		}// end move

		if ( userIn == "use" || userIn == "Use")
		{
			system("cls");
			use(userInTwo, hasPaper, hasRiddle, hasBook, hasClock, hasKeyTwo, hasKey, inBed, inGrass, openChest, openWardrobe); // use as a function for simplicity

		}// end use

		if ( userIn == "pickup" || userIn == "Pickup") //FIXME
		{
			system ("cls");

			/* once conditions are satisfied the bool changes and records that the item has been taken
			The program then outputs a sentence to inform the user, item will now show up in inventory*/

			if((userInTwo == "clock" || userInTwo == "Clock") && inWork == true)
			{
				hasClock = true;

				spacing(5,1);
				cout << " --- CLOCK has been added to your inventory! --- " << endl;

			}// end work table move

			else if((userInTwo == "paper" || userInTwo == "Paper") && inBed == true && openWardrobe == true)
			{
				hasRiddle = true;

				spacing(5,1);
				cout << " --- RIDDLE has been added to your inventory! --- " << endl;

			}// end riddle pickup

			else if(userInTwo == "Paper" || userInTwo == "paper" && inShelf == true)
			{
				hasPaper = true;

				spacing(5,1);
				cout << " --- PAPER has been added to your inventory! --- " << endl;

			}// end paper pickup

			else if((userInTwo == "Book" || userInTwo == "book") && inShelf == true)
			{
				hasBook = true;

				spacing(5,1);
				cout << " --- BOOK has been added to your inventory! --- " << endl;

			}// end book pickup

			else if((userInTwo == "key" || userInTwo == "Key") && inWork == true && openSafe == true)
			{
				hasKeyTwo = true;

				spacing(5,1);
				cout << " --- FANCY KEY has been added to your inventory! --- " << endl;

			}// end key 1 pickup

			else if((userInTwo == "key" || userInTwo == "Key") && inShelf == true)
			{
				hasKey = true;

				spacing(5,1);
				cout << " --- KEY has been added to your inventory! --- " << endl;

			}// end key 2 pickup

			else // error statement if input not matched
			{
				spacing(5,1);
				cout << "No object to pick up / Incorrect input";
			}

		}// end pickup


		else if(userIn != "pickup" && userIn != "Pickup" && userIn != "examine" && userIn != "Examine" && userIn != "move" && userIn != "Move" && userIn != "use" && userIn != "Use")// error statement if the input is not determined to not repeat the help menu
		{
			// cant simply have an else statement because if userInTwo was left blank.. which may happen.. the error message would go off

				cout << beep; // let them know they did something wrong tsk tsk
				spacing (2,2);
				cout << " 					   	    ***PLEASE ENTER A PROPER COMMAND***" << endl; // let user know what is going wrong
				spacing(0,2);
				cout << "	     ***If you accidentally typed in three words, please type in a single random character to reset the error***";
				error ++;

		}//end else


	}// end Infinite loop


 	return 0;
} // end main





