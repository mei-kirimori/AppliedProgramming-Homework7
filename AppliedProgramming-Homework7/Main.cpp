#include "Compile.h"
#include <iostream>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));//いつもの
	cout << "please enter your name" << endl;
	char name[32];
	cin >> name;
	Player player(name);//とりまオブジェクト作る（下も同じ）
	Dealer dealer;
	cout << "Welcome to " << player.name << "!" << endl << "let's start Hight-and-Low Game!!" << endl;
	Shoe shoe;
	Game game;
	cout << "please enter the number of times you would like to play" << endl;
	int playvalue;
	cin >> playvalue;
	shoe.SetCardDeck();//最初のシャッフル
	for (int i = 0; i <playvalue ; i++)
	{
		game.gameStart(shoe, dealer, player);
	}
	
	//ここのcoutとかは前回の課題からそのまま引っ張てきた
}	