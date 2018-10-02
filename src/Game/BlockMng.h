#pragma once
#include "../Node/Node.h"
#include "Block.h"
#include <sstream>
#include <fstream>

class BlockMng : public Node {
	int row_;
	int column_;

	std::vector<std::vector<Block*>> blocks_;

public:
	BlockMng();
	~BlockMng();

	void init() override;
	void update() override;
	void render() override;

	void setBlockNum(const int row, const int column);
	bool loadTile(const std::string& path);
};