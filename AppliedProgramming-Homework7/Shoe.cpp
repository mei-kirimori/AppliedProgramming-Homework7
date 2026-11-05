#include "Shoe.h"
#include <iostream>
using namespace std;

Shoe::Shoe()
{
	CardIndex = 0;
	memset(CardDeck, 1, sizeof(CardDeck));
}

void Shoe::SetCardDeck() //下記ShuffleCardDeckとセットで初期化するための関数、こっちは一旦52枚のカードを配列に入れるだけ
{
	for (int i = 0; i < 52; i++)
	{
		CardDeck[i] = i;
	}
	ShuffleCardDeck();
	cout << "=============================" << endl;
	cout << "Card Deck is set! (or reset)" << endl;
	cout << "=============================" << endl;
}

void Shoe::ShuffleCardDeck()  //配列の中身をシャッフルするやつ
{
	for (int i = 0; i < GetDeckSize(); i++)
	{
		int j = rand() % GetDeckSize();
		int temp = CardDeck[i];
		CardDeck[i] = CardDeck[j];
		CardDeck[j] = temp;
	}	
}


bool Shoe::CheckCardDeck() //二重確認用
{
	for (int i= 0;GetDeckSize()>i;++i)
	{
		if (!(CardDeck[i]==-1))
		{
			CardIndex = i;  //引かれてないカードがあればそのインデックスを返す
			return false;
		}
	}
	return true;
}

int Shoe::GetDeckSize() const	//配列の要素数を返す関数
	{
		int DeckSize = sizeof(CardDeck) / sizeof(CardDeck[0]);
		return DeckSize;
	}

void Shoe::ShowCard() const//確認用
{
	for (int j = 0; j < GetDeckSize(); j++)
	{
		cout << CardDeck[j] << endl;
	}
}

int Shoe::TakeCard() //カードを1枚引く関数
{
	if (CardIndex < GetDeckSize()) 
	{
		int tmp = CardDeck[CardIndex];
		CardDeck[CardIndex] = -1; //引いたカードを-1にすることで二重確認用にする
		CardIndex++;
		return tmp;
	}
	else //上の条件式にはじかれたらカードをリセットする
	{
		if (CheckCardDeck()) //二重確認
		{
			CardIndex = 0;
			SetCardDeck();
			int tmp = CardDeck[CardIndex];//山札リセット後カードを引く
			CardDeck[CardIndex] = -1; 
			CardIndex++;
			return tmp;
		}
		else
		{
			return CardDeck[CardIndex];  //二重確認で引かれていないカードがあればそのカードを返す
		}
	}
}
