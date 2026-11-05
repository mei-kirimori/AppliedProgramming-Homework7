#include"Compile.h"


void Game::ShowCard(const Participant& card)//こいつがカードの値とスートを表示してる
{
	cout <<card.name <<"s card is " << CardValueToString(card.GetCardValue()) << "-" << CardSuitToString(card.GetCardSuit()) << endl;
}


void Game::Judgement(const Dealer& dealer, const Player& player)//勝敗判定部、上のやつ使って表示もさせてる
{
	cout << "Game Result" << endl;
	if(player.GetCardValue() == dealer.GetCardValue())
	{
		ShowCard(player);
		ShowCard(dealer);
		cout << "It's a tie!" << endl;
	}
	else if (player.GetCardValue() > dealer.GetCardValue())
	{
		ShowCard(player);
		ShowCard(dealer);
		cout << "Player wins!" << endl;
	}
	else
	{
		ShowCard(player);
		ShowCard(dealer);
		cout << "Dealer wins!" << endl;
	}
	cout << "=============================" << endl;
}

void Game::gameStart(Shoe& shoe, Dealer& dealer, Player& player)//がめスターと、ここからはじまる、ヒットして上に処理投げてるだけ
{
	cout << "=============================" << endl;
	cout << "Game Start!" << endl;
	dealer.Hit(shoe);
	player.Hit(shoe);
	Judgement(dealer, player);
}

const char* Game::CardValueToString(CardValue value) //これとしたのやつで表示する時の変換をしている
{
	const char* names[] = {
		"0", "A", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "J", "Q", "K"
	};
	return names[static_cast<int>(value)];
}

const char* Game::CardSuitToString(CardSuit suit)
{
	const char* names[] = {
		"Spade", "Heart", "Diamond", "Club"
	};
	return names[static_cast<int>(suit)];
}