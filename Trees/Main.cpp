#include "LinkedBinaryTree.h"
#include <iostream>
using namespace std;

int main(void) {
	LinkedBinaryTree* tree = new LinkedBinaryTree();
	tree->addRoot('-');
	LinkedBinaryTree::Position p = tree->root();
	tree->expandExternal(p, '/', '+');
	p = p.left();
	tree->expandExternal(p, 'x', '+');
	p = p.left();
	tree->expandExternal(p, '+', '3');
	p = p.left();
	tree->expandExternal(p, '3', '1');
	p = p.parent(); p = p.parent(); p = p.right();
	tree->expandExternal(p, '-', '2');
	p = p.left();
	tree->expandExternal(p, '9', '5');
	p = tree->root();
	p = p.right();
	tree->expandExternal(p, 'x', '6');
	p = p.left();
	tree->expandExternal(p, '3', '-');
	tree->expandExternal(p.right(), '7', '4');

	LinkedBinaryTree::PositionList preList = tree->prePositions();
	p=tree->prePositions().front();
	cout << "preorder : ";
	while (!preList.empty()) {
		cout << *preList.front() << " ";
		preList.pop_front();
	}
	cout << endl;

	LinkedBinaryTree::PositionList postList = tree->postPositions();
	p = tree->postPositions().front();
	cout << "postorder : ";
	while (!postList.empty()) {
		cout << *postList.front() << " ";
		postList.pop_front();
	}
	cout << endl;

	LinkedBinaryTree::PositionList inList = tree->inPositions();
	p = tree->inPositions().front();
	cout << "inorder : ";
	while (!inList.empty()) {
		cout << *inList.front() << " ";
		inList.pop_front();
	}
	cout << endl;

	cout << "formula : ";
	tree->formula();
}
