#pragma once
#include"Compile.h"
class Game
{
public:
	void Judgement(const Dealer& dealer, const Player& player);
	void ShowCard(const Participant& card);
	void gameStart(Shoe& shoe, Dealer& dealer, Player& player);
	const char* CardValueToString(CardValue value);
	const char* CardSuitToString(CardSuit suit);
private:
	
};
