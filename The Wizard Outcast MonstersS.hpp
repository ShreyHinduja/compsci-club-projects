//change firedragon and wizsoldier to actually do 10-20, as well as the others. USE FUNCTION TO CHANGE MONSTER LIST//

using namespace std;

class Monster {
  public:
  string monsterName;
  int level;
  int hp;
  int dmg;
  int xp;
  int coins;
  Monster(string name, int aLevel, int hpMod, int dmgMod, int xpMod, int xpSubtract, int coinsMod){
    monsterName = name;
    level = aLevel;
    hp = level*hpMod;
    dmg = level*dmgMod;
    xp = level*xpMod-xpSubtract;
    coins = level*coinsMod;
  }
};

void createMonsters (){
  //------------------------------------------------------//
  Monster blueSlime ("blueSlime", rand()%5 + 1, 10, 5, 1, 0, 1);
  //------------------------------------------------------//
  Monster smallSpider ("smallSpider", rand()%5 + 1, 5, 7, 1, 3, 1);
  //------------------------------------------------------//
  Monster redSlime ("redSlime", rand()%6 + 5, 5, 7, 1, 0, 1);
  //------------------------------------------------------//
  Monster fireDragon ("fireDragon", rand()%11 + 10, 10, 7, 1, 0, 1);
  //------------------------------------------------------//
  Monster evilWizardSoldier ("evilWizardSoldier", rand()%11 + 20, 7, 7, 1, 0, 1);
  //------------------------------------------------------//
  Monster wizardOutlaw ("wizardOutlaw", 35, 10, 7, 14, 0, 1);
  //------------------------------------------------------//
}