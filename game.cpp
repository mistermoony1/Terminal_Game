#include <iostream>
#include "hero.cpp"

using namespace std;

int combat_instance(hero h1, orc o1); //Instances combat with an orc
int random_gen();                     //Generates a Random number between 1 - 100
void game();
void init();

int main()
{
  orc o1;

  init();
  game();

  return 0;

}

void init(){
  cout << "You awaken in a dark room, holding in your hand a rusty sword. How did you get here? Where is here? What is happening to you?" << endl;
  cout << "Before we begin there are a few things to sort out:" <<endl;
}

void game()
{
  hero h1;
  orc o1;

  string command;

  while(1){





  combat_instance(h1, o1);
  return;
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
