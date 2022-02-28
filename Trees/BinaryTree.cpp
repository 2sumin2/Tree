#include "LinkedBinaryTree.h"
#include <list>
using std::list;
list<char> l;

LinkedBinaryTree::LinkedBinaryTree()
	:_root(NULL), n(0) { }
int LinkedBinaryTree::size() const
{
	return n;
}
bool LinkedBinaryTree::empty() const
{
	return size() == 0;
}
LinkedBinaryTree::Position LinkedBinaryTree::root() const
{
	return Position(_root);
}
void LinkedBinaryTree::addRoot(Elem e)
{
	_root = new Node; 
	_root -> elt = e;
	n = 1;
}
void LinkedBinaryTree::expandExternal(const Position& p, Elem left, Elem right) {
	Node* v = p.v;
	v->left = new Node;
	v->left->elt = left;
	v->left->par = v;
	v->right = new Node;
	v->right->elt = right;
	v->right->par = v;
	n += 2;
}

LinkedBinaryTree::Position
LinkedBinaryTree::removeAboveExternal(const Position& p) {
	Node* w = p.v; 	Node* v = w->par;
	Node* sib = (w == v->left ? v->right : v->left);
	if (v == _root) {
		_root = sib;
		sib->par = NULL;
	}
	else {
		Node* gpar = v->par;
		if (v == gpar->left) gpar->left = sib;
		else gpar->right = sib;
		sib->par = gpar;
	}
	delete w; delete v;
	n -= 2;
	return Position(sib);
}
LinkedBinaryTree::PositionList LinkedBinaryTree::prePositions() const {
	PositionList pl;
	preorder(_root, pl);
	return PositionList(pl);
}
LinkedBinaryTree::PositionList LinkedBinaryTree::postPositions() const {
	PositionList pl;
	postorder(_root, pl);
	return PositionList(pl);
}
LinkedBinaryTree::PositionList LinkedBinaryTree::inPositions() const {
	PositionList pl;
	inorder(_root, pl);
	return PositionList(pl);
}

void LinkedBinaryTree::formula() const {
	inorderFormula(_root);
	
	l.front();
	while (!l.empty()) {
		cout << l.front();
		l.pop_front();
	}
	cout << endl;
}

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
	pl.push_back(Position(v));
	if (v->left != NULL)
		preorder(v->left, pl);
	if (v->right != NULL)
		preorder(v->right, pl);
}

void LinkedBinaryTree::postorder(Node* v, PositionList& pl) const {
	if (v->left != NULL)
		postorder(v->left, pl);
	if (v->right != NULL)
		postorder(v->right, pl);
	pl.push_back(Position(v));
}

void LinkedBinaryTree::inorder(Node* v, PositionList& pl) const {
	if (v->left != NULL)
		inorder(v->left, pl);
	pl.push_back(Position(v));
	if (v->right != NULL)
		inorder(v->right, pl);
}

void LinkedBinaryTree::inorderFormula(Node* v) const {
	Node* x = v;
	if (v->left != NULL ) 
		l.push_back('(');
	if (v->left != NULL)
		inorderFormula(v->left);
	l.push_back(*Position(v));
	if (v->right != NULL)
		inorderFormula(v->right);
	if (v->right != NULL)
		l.push_back(')');
}


