#include "BlockMng.h"
#include "Block.h"
#include "../Math/Math.h"


BlockMng::BlockMng()
	:
	Node("BlockMng", Node::State::Run)
{
}


BlockMng::~BlockMng()
{}

void BlockMng::init() {
	for (int col = 0; col < column_; ++col) {
		for (int row = 0; row < row_; ++row) {
			auto block = new Block();
			insertAsChild(block);
			block->setPos(Math::Vec(100 + 50 * row, 80 + 50 * col));
			block->setColor(10 * col, 10 * row, 30 * (row + col));
		}
	}
}

void BlockMng::setBlockNum(const int row, const int column) {
	row_ = row;
	column_ = column;
}
