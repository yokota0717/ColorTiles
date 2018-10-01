#pragma once
#include "../Node/Node.h"
#include "../Math/Math.h"

class Block : public Node {
	int red_;
	int green_;
	int blue_;

	Math::Vec pos_;

public:
	Block();
	~Block();

	void render() override;

	void setColor(const int red, const int green, const int blue);
	void setPos(Math::Vec& pos);
};
