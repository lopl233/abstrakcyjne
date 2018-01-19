#include "Hero.h"
#include "constants.cpp"

Hero::~Hero() {}
Hero::Hero(int maxHp, int maxMp,std::string filename):lvl(1),exp(0),next_lvl_exp(100),maxHp(maxHp),maxMp(maxMp), direction(SOUTH), currentHp(maxHp), currentMp(maxMp), x(STARTING_X), y(STARTING_Y), filename(filename){}