#pragma once

#include "Common.h"
#include "Shoe.h"
class Participant
{
public:
	const char* name;
	void ShowCard(const Participant& card)const;
	void Hit(Shoe& shoe);
	CardValue GetCardValue()const;
	CardSuit GetCardSuit()const;
protected:
	CardValue Card;
	CardSuit Suit;

};

