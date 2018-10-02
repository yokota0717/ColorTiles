#include "BlockMng.h"
#include "../Math/Math.h"


BlockMng::BlockMng()
	:
	Node("BlockMng", Node::State::Run)
{}


BlockMng::~BlockMng()
{}

void BlockMng::init() {
	blocks_.resize(column_);
	for (auto row : blocks_) {
		row.resize(row_);
	}
	for (int col = 0; col < column_; ++col) {
		for (int row = 0; row < row_; ++row) {
			blocks_[col].push_back(new Block());
			blocks_[col][row]->setPos(Math::Vec(100.f + 50 * row, 50.f + 50 * col));
			blocks_[col][row]->setColor(55 + 40*row, 55 + 40*col, 10*(row+col));
		}
	}
}

void BlockMng::update() {

}

void BlockMng::render() {
	for (auto col : blocks_) {
		for (auto block : col) {
			block->render();
		}
	}
}

void BlockMng::setBlockNum(const int row, const int column) {
	row_ = row;
	column_ = column;
}

bool BlockMng::loadTile(const std::string & path) {
	std::ifstream ifs(path);
	if (!ifs) { return false; }
	//タイルの縦横サイズ読み込み
	//一行分取り出す
	std::string line;
	std::getline(ifs, line);
	std::istringstream is(line);
	//区切り文字(,)までの文字を取り出す
	std::string text;
	std::getline(is, text, ',');
	//横サイズ読み込み
	(std::stringstream)text >> row_;
	std::getline(is, text, ',');
	//縦サイズ読み込み
	(std::stringstream)text >> column_;

	while (std::getline(ifs, line)) {
		std::stringstream ss(line);

	}
	return true;
}

