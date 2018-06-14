#pragma once



class Dice
{

public:
	
	static void InitializeDice();
	static int RollDice(int num, int type);
	static bool CriticalSuccess(int effectiveSkill, int diceRoll);
	static bool CriticalFailure(int effectiveSkill, int diceRoll);

private:
	
};