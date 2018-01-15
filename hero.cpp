#include <iostream>
#include <cstdlib>

using namespace std;

class creature
{
protected:
  int HP, MAXHP;
  creature();
public:
  int health();
  void mutatehealth(int a);
};

creature::creature(void)
{
  HP = 10;
  MAXHP = 10;
}

int creature::health()
{
  return HP;
}

void creature::mutatehealth(int a)
{
  HP -= a;
}

class hero: public creature         ////////////////////////////////////////////////////////////////////////////////////////HERO
{
private:
  int speed, crit_chance;
  string type;


public:
  int damage(); ///////////////////////////////////////////////////////////////////////////////////////to be done

  void print_stats();
  hero();


};

hero::hero(void)
{
  while(1){
    cout << "What type of character are you: Strong, Fast or Smart" << endl << endl;
    cin >> type;
    cout << endl;

    if(type == "Strong" || type == "strong" || type == "S" || type == "s"){
      HP = 15;
      speed = 5;
      crit_chance = 10;
      return;
    }
    else if(type == "Fast" || type == "fast" || type == "F" || type == "f"){
      HP = 10;
      speed = 15;
      crit_chance = 5;
      return;
    }
    else if(type == "Smart" || type == "smart"){
      HP = 5;
      speed = 10;
      crit_chance = 15;
      return;
    }
    else{
      cout << "Sorry that is an invalid class type" << endl;
    }
  }
}

void hero::print_stats()
{
  cout << "HP: " << HP << " Speed: " << speed << " Critical Chance: " << crit_chance << endl;
}

int hero::damage()
{
  srand(time(NULL));

  if((rand() / RAND_MAX ) < (crit_chance / 100)){
    return (((speed / 5) + 2) * 2);
  }
  else{
    return ((speed / 5)+2);
  }
}



class orc:public creature         /////////////////////////////////////////////////////////////////////////////////////////////////////ORC
{
public:
  int DMG();
};

int orc::DMG()
{
  srand(time(NULL));
  int dam = (2 * ((rand() % 3)+1));
  cout << "The orc takes a swing at you for " << dam << " damage." << endl;
  return dam;
}
