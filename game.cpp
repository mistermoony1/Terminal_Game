#include <iostream>
#include <cstdio>
#include "hero.cpp"

using namespace std;

int combat_instance(hero h1, orc o1); //Instances combat with an orc
int random_gen();                     //Generates a Random number between 1 - 100
void game();
void init();
void gameend();

int room1(hero h1, orc o1);
int room2();
int room3(hero h1, orc o1);

int key;		// if they have the key

int main()
{

  init();
  game();

  return 0;

}

void init(){
  cout << "You awaken in a dark room, holding in your hand a rusty sword. How did you get here? Where is here? What is happening to you?" << endl;
  cout << "Before we begin there are a few things to sort out:" << endl;

  key = 0;
  return;
}

void game()
{
  hero h1;
  orc o1;

  string command;

  int direction = 1;


  int i = 0;	//debug only

  while(1){

  	if(direction == 1){
	  direction = room1(h1, o1);
	}
	else if(direction == 2){
		direction = room2();
	}
	else if(direction == 3){
		direction = room3(h1, o1);
	}

	i++;

	if(direction == 4){
		gameend();
		return;
	}
	else if(direction == 5){
		cout << "You dead motherfucker";
		return;

	}

  }

}

int combat_instance(hero h1, orc o1)
{

  string command;
  cout << "You have been attacked by an Orc!" << endl;

  int tempdmg;

  while(h1.health() > 0 && o1.health() > 0){

    cout << "What would you like to do: Fight, Run or Talk?" << endl << endl;
    cin >> command;

    if(command == "Fight" || command == "fight" || command == "f" || command == "F"){
      tempdmg = h1.damage();
      cout << "You attack for " << tempdmg << " damage!" << endl;
      o1.mutatehealth(tempdmg);
      if(o1.health() <= 0){
        continue;
      }

      tempdmg = o1.DMG();
      //cout << "The orc attacks back for " << tempdmg << " damage!" << endl;
      h1.mutatehealth(tempdmg);
    }
    else if(command == "Run" || command == "run" || command == "r" || command == "R"){
      if(random_gen() > 50){
        cout << "You successfuly flee!" << endl;
        return 2;
      }
      else{
        cout << "You fail to escape." << endl;

        tempdmg = o1.DMG();
        h1.mutatehealth(tempdmg);
      }
    }
    else if(command == "Talk"){
      cout << "The beast shows no interest in civil conversation." << endl << endl;

      tempdmg = o1.DMG();
      h1.mutatehealth(tempdmg);
    }
    else{
      cout << "Invalid Command." << endl;
    }

    }

    if(o1.health() <= 0){
      cout << "You have slain the beast!" << endl;
          return 0 ;
    }
    else{
      cout << "You died!" << endl;
      return 5;
    }


}

void gameend()
{
	cout << "Having slain the orc you take a look around the room. In the corner is a large chest, and a passage leads to the north." << endl;
	cout << "Inside the chest is a rusty shield, which you take. Now to continue onwards, and hopefully find the answers to the questions that plague you." << endl << endl;

	cout << "You have completed this basic trial, please gib me £50 for next installment. Much AAA promise." << endl << endl;

	cout << "Enter Quit to leave." << endl;

	string leave;

	while(1){
		cin >> leave;
	if(leave == "Quit"){
		return;
	}
	else{
		cout << "Theres nothing you can do Speng, enter Quit" << endl;
	}
}
}

int random_gen()
{
  srand(time(NULL));

  return((rand() % 100)+1);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// rooms

int room1(hero h1, orc o1){

	string path;

	cout << "Looking around the room you are in you can see there are two options, a heavy looking door to the north and a path to the east:" << endl;
	cout << "Which route do you take?" << endl;



	while(1){
    	cin >> path;

	if((path == "north" || path == "North" || path == "n") && key == 1){

		cout << "You use the key in the lock, and the door swings open." << endl;
		return 3;
	}
	else if(path == "north" || path == "North" || path == "n" && h1.classtype() == 0){

		cout << "The door is locked, but thanks to your great strength you are able to force it open." << endl << endl;
		return 3;
	}
	else if(path == "north" || path == "North" || path == "n" && h1.classtype() == 2){

		cout << "You realise that the door is locked, but you are able to pick it using your superior intelligence." << endl;
		return 3;
	}
	else if(path == "north" || path == "North" || path == "n" && h1.classtype() == 1){

		cout << "The door appears to be locked, but you have neither the strength to force it or the smarts to pick it." << endl;
		return 1;
	}
	else if(path == "east" || path == "East" || path == "e"){
		cout << "You travel down the path leading east." << endl;
		return 2;
	}
  else{
    cout << "Invalid Command" << endl;
  }
	}

}

int room2(){

  string command;
  int i = 0;

	cout << "The passage leads to a small dark room, with no other exits. A small key sits in the middle of the floor." << endl;
  cout << "What would you like to do?" << key << endl;

  while(1){
  getline(cin, command);
  //cout << "command is =" << int(command[0]) << "=" << endl;

  if((command ==  "Take Key" || command == "take key" || command =="Pick up key" || command == "pick up key" || command == "Take key" || command == "take") && key == 0){
    cout << endl << "You pick up the Key." << endl;
    key = 1;
    continue;
  }
  else if(command ==  "back" || command == "Back" || command =="West" || command == "west"){
    return 1;
  }
  else if(i != 0){
    cout << "Invalid command" << endl;
  }
  i++;
  }
}

int room3(hero h1, orc o1){

	cout << "You enter a stone room, and immediately in your face is a loathsome orc." << endl;

	int temp = combat_instance(h1, o1);

	if(temp == 2){
		return 1;
	}
	else if(temp == 5){
		return 5;
	}
	else{
		return 4;
	}
}
