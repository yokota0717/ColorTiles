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
	DrawBox(pos_.x, pos_.y, pos_.x + 50, pos_.y + 50, GetColor(red_, green_, blue_), true);
}

void Block::setColor(const int red, const int green, const int blue){
	red_ = red;
	green_ = green;
	blue_ = blue;
}

void Block::setPos(Math::Vec & pos){
	pos_ = pos;
}

