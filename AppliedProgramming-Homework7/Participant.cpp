#include "Participant.h"
#include"Common.h"
#include"Shoe.h"
#include <iostream>
using namespace std;

void Participant::ShowCard(const Participant& card)const//残骸、ホントはこれでカード表示する気でいたがgame.cppのShowCardでやった方が個人的に納まりがよかった
{
	
}

void Participant::Hit(Shoe& shoe)
{
	int tmp = shoe.TakeCard();
	Card = static_cast<CardValue>((tmp % 13) + 1); //カードの値をCardValueに変換
	Suit = static_cast<CardSuit>(tmp / 13); //カードのスートをCardSuitに変換
}

CardValue Participant::GetCardValue()const
{
	return Card;
}
CardSuit Participant::GetCardSuit()const
{
	return Suit;
}