#include <iostream>

#include <vector>

#include <ctime>

#include <chrono>

#include <thread>

#include "MonstersS.hpp"

#include "PlayerClassesS.hpp"

using namespace std;
//world record is 31.41
bool outlawKilled = 0;

class RandomMonster {
  public: string rMonsterName;
  int rLevel;
  int rHp;
  int rDmg;
  int rXp;
  int rCoins;

  RandomMonster(string name, int aLevel, int hpMod, int dmgMod, int xpMod, int xpSubtract, int coinsMod) {
    rMonsterName = name;
    rLevel = aLevel;
    rHp = aLevel * hpMod;
    rDmg = aLevel * dmgMod;
    rXp = aLevel * xpMod - xpSubtract;
    rCoins = aLevel * coinsMod;
  }
};
void battleFunction(int enemyDmg, int crtChnce, int dmg, int heals, int playerHealth, int enemyHealth) {
  int randomTest;
  int a = playerHealth / 10;
  int counters = 6;
  int enemyHeals = 5;
  int healNumber;
  int damage;
  char decision;
  int enemyCounters = 5;
  int enemyDecision;
  int runChance = 79;
  int i;
  bool run1 = true;
  bool run = false;
  bool crit = false;
  srand(time(NULL));

  while (!run) {
    cout << "1)attack\n2)counter\n3)heal\n4)run";
    cin >> decision;
    system("clear");
    enemyDecision = rand() % 3 + 1;
    if (enemyDecision == 3 && enemyHeals == 0) {
      enemyDecision--;
    }
    if (enemyDecision == 2 && enemyCounters == 0) {
      enemyDecision--;
    }

    switch (decision) {
      //----------------------------------------------------------------//
    case '1':
      if (enemyDecision == 2) {
        cout << "You have been countered.\n";
        if (rand() % 100 >= crtChnce) {
          damage = rand() % dmg + (dmg / 2) * 2;
        } else {
          damage = rand() % dmg + (dmg / 2);
        }
        damage = damage * 2;
        playerHealth = playerHealth - damage;
        cout << "It did " << damage << " damage. You have " << playerHealth <<
          " HP left.";
      } else if (enemyDecision == 3) {
        cout << "He attempted to heal.\n";
      } else if (enemyDecision == 1) {
        if (rand() % 100 + 1 >= crtChnce) {
          cout << "CRITICAL HIT!!!\n";
          damage = (rand() % dmg + 1) * 2;
        } else {
          damage = rand() % dmg + 1;
        }
        cout << "You did " << damage << " damage\n";
        enemyHealth = enemyHealth - damage;
        cout << "It has " << enemyHealth << " HP left.\n";
      }
      break;
      //----------------------------------------------------------------//
    case '2':
      if (counters == 0) {
        cout << "You tried to counter and failed.\n";
      } else {
        counters--;
        cout << "You have " << counters - 1 << " counters left.\n";
      }
      break;
      //----------------------------------------------------------------//
    case '3':
      if (heals == 0) {
        cout << "You "
        "tried to "
        "heal but "
        "failed.\n";
      } else if (enemyDecision == 1) {} else {
        heals--;
        cout << "You have " << heals << " heals left.\n";
        healNumber = rand() % (playerHealth / 10) + 1;
        playerHealth = playerHealth + healNumber;
        cout << "You healed " << healNumber << " HP. You have " << playerHealth <<
          " HP left\n";
      }
    case '4':
      if (rand() % 100 <= runChance) {
        cout << "you succesfully ran";
        enemyDecision = 4;
      }
      break;
      //----------------------------------------------------------------//
    }

    switch (enemyDecision) {
      //----------------------------------------------------------------//
    case 1:
      if (decision == '2' && counters == 0) {
        cout << "He attacked!\n";
        damage = rand() % enemyDmg + (enemyDmg / 2);
        playerHealth = playerHealth - damage;
        cout << "He did " << damage << " damage. You have " << playerHealth <<
          " HP left.\n";
      } else if (decision == '2') {
        cout << "You countered it.\n";
        damage = rand() % enemyDmg + (enemyDmg / 2);
        damage = damage * 2;
        enemyHealth = enemyHealth - damage;
        cout << "You did " << damage << " damage. He has " << enemyHealth <<
          " HP left.\n";
      } else if (enemyDecision == '1') {
        cout << "He attacked!\n";
        damage = rand() % enemyDmg + (enemyDmg / 2);
        playerHealth = playerHealth - damage;
        cout << "He did " << damage << " damage. You have " << playerHealth <<
          " HP left\n";
      } else {
        damage = rand() % enemyDmg + (enemyDmg / 2);
        cout << "The enemy did " << damage << " damage.\n";
        playerHealth = playerHealth - damage;
        cout << "You have " << playerHealth << " HP left.\n";
      }
      break;
      //----------------------------------------------------------------//
    case 2:
      enemyCounters--;
      cout << "\nEnemy has " << enemyCounters << " counters left.\n";
      break;
      //----------------------------------------------------------------//
    case 3:
      if (decision == '1') {
        cout << "You attacked!\n";
        damage = rand() % dmg + (dmg / 2);
        damage = damage * 2;
        enemyHealth = enemyHealth - damage;
        cout << "You did " << damage << " damage. Enemy has " << enemyHealth <<
          " HP left.\n";
      } else {
        enemyHeals--;
        cout << "He has " << enemyHeals << " heals left.\n";
        healNumber = rand() % a + 1;
        enemyHealth = enemyHealth + healNumber;
        cout << "Enemy healed " << healNumber << " HP. It has " << enemyHealth <<
          " HP left.\n";
      }
      break;
    case 4:
      break;

    }
    if (enemyHealth <= 0 && playerHealth <= 0) {
      cout << "It was a draw.";
    } else if (enemyHealth == 0 || enemyHealth < 0) {
      cout << "Victory!";
      run = true;
    } else if (playerHealth == 0 || playerHealth < 0) {
      cout << "Defeat...";
      run = true;
    }
    //----------------------------------------------------------------//
  }
}
string playerClass;
int vectorTest;
int exp;
int expRequired;
int level;
int skillPoints;

int requestedStoryline, doYouWantToHelp, classSelection, optionList, leaveHideoutOrStay, randomMonsterInt;
string randomMonster;

void foundBlueSlime() {
  cout << endl << "You encountered a wild blue slime!\n";
}
void foundSmallSpider() {
  cout << endl << "You encountered a wild small spider!\n";
}
void foundRedSlime() {
  cout << endl << "You encountered a wild red slime!\n";
}
void foundLargeSpider() {
  cout << endl << "You encountered a wild large spider!\n";
}
void foundFireDragon() {
  cout << endl << "You encountered a wild fire dragon!\n";
}
void foundWizSoldier() {
  cout << endl << "You encountered a wild evil wizard soldier!\n";
}
void foundWizOutlaw() {
  cout << endl << "You encountered the Wizard Outlaw!\n";
};

void sleep(int time) {
  this_thread::sleep_for(chrono::seconds(time));
}
void enteredHideout() {
  system("clear"),
    cout << endl << "𝘠𝘰𝘶 𝘦𝘯𝘵𝘦𝘳 𝘵𝘩𝘦 𝘩𝘪𝘥𝘦𝘰𝘶𝘵...\n";
  sleep(2);
  system("clear");
}

void leftHideout() {
  system("clear"),
    cout << endl << "𝘠𝘰𝘶 𝘭𝘦𝘢𝘷𝘦 𝘵𝘩𝘦 𝘩𝘪𝘥𝘦𝘰𝘶𝘵...\n";
  sleep(2);
  system("clear");
}

/*void statistics(){if(playerClass=="swordsman"){cout<<"hp:";cout<<swordsman.hp<<endl<<"dmg:"<<swordsman.dmg<<"\ncrit chance:"<<swordsman.critChance;}
else if(playerClass=="mage"){cout<<"hp:";cout<<mage.hp<<endl<<"dmg:"<<mage.dmg<<"\ncrit chance:"<<mage.critChance;}
else if(playerClass=="tank"){cout<<"hp:";cout<<tank.hp<<endl<<"dmg:"<<tank.dmg<<"\ncrit chance:"<<tank.critChance;}
else if(playerClass=="archer"){cout<<"hp:";cout<<archer.hp<<endl<<"dmg:"<<archer.dmg<<"\ncrit chance:"<<archer.critChance;};}*/

void leftHideoutOptions() {
  cout << "What would you like to do?\n" << "  1) Return to Hideout\n" << "  2) Fight some Monsters\n" << "  3) Open Shop\n";
  cin >> optionList;
  switch (optionList) {
  case 1:
    enteredHideout();
    if (outlawKilled == 0) {
      cout << "Wizard: 'Oh, hello. It does not seem you have anything proving the outlaw's death. Please return when you have obtained it.'\n";
      cout << "  1) leave\n" << "  2) stay\n";
      cin >> leaveHideoutOrStay;
      switch (leaveHideoutOrStay) {
      case 1:
        sleep(4);
        leftHideout();
        while (true){
        leftHideoutOptions();
        }
        break;
      case 2:
        cout << "Wizard: *sigh* 'I told you I don't need you here... Please leave.\n'";
        sleep(4);
        leftHideout();
        while (true){
        leftHideoutOptions();
        }
      }
    } else {
      cout << "Wizard: *in awe* 'Wow, you did it... I'm so glad I chose you to help me kill the Wizard Outlaw. Congratulations, adventurer. Also, here is an easter egg. :) Thank you for playing!\n";
      break;
    }
  case 2:
    randomMonsterInt = rand() % 100 + 1;
    if (randomMonsterInt == 1) {
      randomMonster = "\nYou encountered the Wizard Outlaw!\n\n";
    } else if (randomMonsterInt > 1 && randomMonsterInt < 6) {
      randomMonster = "\nYou encountered a wild evil wizard soldier!\n\n";
    } else if (randomMonsterInt >= 6 && randomMonsterInt <= 10) {
      randomMonster = "\nYou encountered a wild fire dragon!\n\n";
    } else if (randomMonsterInt > 10 && randomMonsterInt <= 20) {
      randomMonster = "\nYou encountered a wild red slime!\n\n";
    } else if (randomMonsterInt > 20 && randomMonsterInt <= 45) {
      randomMonster = "\nYou encountered a wild small spider!\n\n";
    } else if (randomMonsterInt > 45) {
      randomMonster = "\nYou encountered a wild blue slime!\n\n";
    }
      cout << randomMonster;
      sleep(1);
      
      while (true){
      leftHideoutOptions();
      }break;
    //battle thing here
  case 3:
    cout << "PUT SHOP HERE\n";
    break;
  }
}

int main() {
  srand(time(NULL));
  level = 1;
  createMonsters();
  createClasses();
  cout << endl << "You wake up in a dimly lit room and look around, confused.\n";
  sleep(3);
  cout << endl << "You see an old wizard standing at the door of the mysterious room.\n";
  sleep(3);
  cout << endl << "Wizard: 'Ah, so you're finally awake! If you're confused on where you are, I can tell you how you got here.'\n";
  sleep(5);
  cout << endl << "𝘞𝘰𝘶𝘭𝘥 𝘺𝘰𝘶 𝘭𝘪𝘬𝘦 𝘵𝘰 𝘭𝘦𝘢𝘳𝘯 𝘩𝘰𝘸 𝘺𝘰𝘶 𝘨𝘰𝘵 𝘵𝘰 𝘸𝘩𝘦𝘳𝘦 𝘺𝘰𝘶 𝘢𝘳𝘦?" << endl << "  1) yes\n" << "  2) no\n";
  cin >> requestedStoryline;
  switch (requestedStoryline) {
  case 1:
    cout << endl << "Wizard: 'Well, an extremely powerful wizard cast a destructive spell on the whole town of Azush, the biggest wizard town in the world. I witnessed the destruction, and tried to save as many people as I could. Unfortunately, I could only save one person, which was you. I brought you here, to my emergency hideout. We need your help defeating the evil wizard. Will you help me?'\n";
    break;
  case 2:
    cout << endl << "Wizard: '... Alright then. Will you help my cause, which you... don't even know?'\n";
  }
  sleep(7);
  cout << endl << "𝘞𝘪𝘭𝘭 𝘺𝘰𝘶 𝘩𝘦𝘭𝘱?" << endl << "  1) yes\n" << "  2) no\n";
  cin >> doYouWantToHelp;
  switch (doYouWantToHelp) {
  case 1:
    cout << "\nWizard: 'Great. Here is my old sword. It is good as a beginner weapon, but you can go purchase more powerful swords at the local store. Good luck adventurer. You will need it.\n";
    sleep(4);
    break;
  case 2:
    cout << "\nWizard: *sigh* 'Alright then. Goodnight.'\n" << endl << "He hits your head with a staff, and it all goes black...";
    return 0;
    break;
  }
  sleep(3);
  leftHideout();
  system("clear");
  leftHideoutOptions();
}
/*options: kill monsters, open shop, enter hideout. eventually find wizard outcast and kill him. if u lose, game ends. DO LEVELING SYSTEM.
 */

void leveling() {
  expRequired = level * 2;
  if (exp >= expRequired) {
    level++;
    skillPoints = skillPoints + 3;
  }
}
