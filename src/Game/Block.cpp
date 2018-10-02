#include "Block.h"
#include "DxLib.h"


Block::Block()
	:
	Node("Block", Node::State::Run)
{
	//changePriority(0.5f);
}


Block::~Block(){}

void Block::render() {
	Math::DrawBox2D(pos_, 50.f, 50.f, GetColor(red_, green_, blue_), true);
}

void Block::setColor(const int red, const int green, const int blue){
	red_ = red;
	green_ = green;
	blue_ = blue;
}

void Block::setPos(const Math::Vec & pos){
	pos_ = pos;
}

