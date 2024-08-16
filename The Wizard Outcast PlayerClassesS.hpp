using namespace std;

class RPGGameClasses {
  public:
  int hp;   
  int dmg;
  int atkSpeed;
  int critChance;
};
void createClasses(){
  ;//if(level>1){skillPoints=skillPointsSpent-(level*skillPoints);}
  RPGGameClasses swordsman;
  swordsman.hp = 90;
  swordsman.dmg = 25;
  swordsman.critChance = 20;
  RPGGameClasses mage;
  mage.hp = 95;
  mage.dmg = 15;
  mage.critChance = 75;
  RPGGameClasses tank;
  tank.hp = 150;
  tank.dmg = 7;
  tank.critChance = 15;
  RPGGameClasses archer;
  archer.hp = 80;
  archer.dmg = 35;
  archer.critChance = 20;
}