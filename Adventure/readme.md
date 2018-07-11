#PUZZLE

##User Manual

### Blake Capella 12/6/16

This program is a short text-based adventure built primarily on puzzles.  The main premise of the program follows the model of an escape room. The main objective of the game is to escape the room you have woken up in by collecting numerous objects scattered around the room. You then use these objects or hints to unlock a key or other hints. Eventually, you will collect the final key and escape the room.

The game contains four main areas:

	- Grass
	- Bedroom
	- Workbench
	- Shelf

Each of these four areas contains its own individual actions and descriptions associated with each area. In order to beat the game, the user must move throughout each area and commit pre-ordained set of actions in a particular order. Determining this proper order is the main challenge of this program.

The main interaction between the user and program follows the same general model:
	
	[ Command Word ]   -- (space) --   [ Secondary Command ]   – (enter) --

First, the user will type in one of the command words, press space, then type in a secondary command, and finally hit enter. If you do not wish or need to enter a secondary command, simply enter a random character such as ‘a’ or ‘1’ and hit enter. If you simply type in one word and hit enter, the program will not progress, as it is waiting for your input. If you happen to type in three words, you can fix the error by typing in a single word on the next prompt.

The four command words are as follows:

	- Examine: Used to investigate certain objects and gain a more information on certain objects
	- Use: Allows user to look at objects in their inventory or use one of the objects to interact with their environment
	- Move: Allows user to move between the four main areas 
	- Pickup: Adds an item to your inventory

All  of the secondary commands depend on the user’s current location and context in the program. For example, if the program tells you that there is a piece of paper on the ground, possible commands could be:
	
	- Examine Paper
	- Pickup Paper

At all times, there will be a text box detailing these four main commands and what they do, along with indicating what items are in your inventory.

Keep in mind that when the program asks for you to enter a character, you must hit enter.

In the worst case scenario that the game is unresponsive and you are unable to interact with the program, you may hit [Ctrl + C] or exit out of the window.

Finally, this game does not save. It is recommended that you complete this game in one sitting of approx. 20 minutes.
