#include "Game.h"
#include "BlockMng.h"

Root::Root()
	:
	Node("Root", Node::State::Run),
	frame_(0)
{}
Root::~Root() {
	deleteChildren();
}

void Root::init(Node* thisptr) {
	setSelfPtr(thisptr);
	auto blockMng = new BlockMng();
	insertAsChild(blockMng);
	blockMng->setBlockNum(5, 5);
}
void Root::update() {
	++frame_;
}
void Root::render() {
}
int Root::frame() {
	return frame_;
}
int Root::receiveMsg(Node* sender, const std::string & msg)
{
	return 0;
}
Game::Game() 
	:
	pad(0)
{
	//grafac = new GraphFactory();
	root = new Root();
	root->init(root);
}

Game::~Game(){
	delete root;
	//delete grafac;
}

void Game::doAll() {
	kb.update();
	mouse.update();
	pad.update();
	if (kb.Down(Q)) { debug_ = !debug_; }
	root->updateWithChildren();
	root->renderWithChildren();
}
void Game::fin() {}

bool Game::DebugMode() {
	return debug_;
}

extern Game* game = new Game();