#pragma once
#include "../Node/Node.h"

class BlockMng : public Node {
	int row_;
	int column_;


public:
	BlockMng();
	~BlockMng();

	void init() override;

	void setBlockNum(const int row, const int column);
};