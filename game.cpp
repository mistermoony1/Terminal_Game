#include <iostream>
#include "hero.cpp"

using namespace std;

int combat_instance(hero h1, orc o1); //Instances combat with an orc
int random_gen();                     //Generates a Random number between 1 - 100
void game();
void init();

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

	if(i == 5){
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
        return 0;
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
    }
    else{
      cout << "You died!" << endl;
    }
    return 0 ;

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

	cin >> path;

	while(1){
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
	}

}

int room2(){

	cout << "Hello There im room 2" << endl;
	key = 1;
	return 1;
}

int room3(hero h1, orc o1){

	cout << "Hi im room 3" << endl;

	combat_instance(h1, o1);

	return 1;
}



