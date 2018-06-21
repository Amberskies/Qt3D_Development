#include "Dice.h"

#include <QDateTime>

void Dice::InitializeDice()
{
	qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
}


int Dice::RollDice(int num, int type)
{
	int ret = 0;
	for (int i = 0; i < num; i++) ret += qrand() % (type)+1;

	return ret;
}

bool Dice::CriticalSuccess(int effectiveSkill, int diceRoll)
{
	bool ret = false;
	int crit = 4;
	if (effectiveSkill > 20) effectiveSkill = 20;
	if (effectiveSkill > 14) crit += (effectiveSkill - 14);
	if (diceRoll <= crit) ret = true;

	return ret;
}

bool Dice::CriticalFailure(int effectiveSkill, int diceRoll)
{
	bool ret = false;
	if (effectiveSkill > 20) effectiveSkill = 20;

	if (diceRoll >= effectiveSkill + 10) ret = true;
	if ((diceRoll == 17) && (effectiveSkill < 16)) ret = true;
	if (diceRoll == 18) ret = true;

	return ret;
}

