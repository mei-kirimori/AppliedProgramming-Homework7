#pragma once

class Shoe
{
public:
	void SetCardDeck();
	void ShuffleCardDeck();
	bool CheckCardDeck();
	int GetDeckSize() const;
	void ShowCard() const;//確認用
	int TakeCard();
	Shoe();
private:
	int CardDeck[52];
	int CardIndex;
};