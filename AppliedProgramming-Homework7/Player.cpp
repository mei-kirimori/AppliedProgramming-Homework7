#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const char* name)//いつもの引数つきコンストラクタ
{
	if (name != nullptr)
	{
		this->name = name;
	}
	else
	{
		this->name = "unknown";
	}
}
