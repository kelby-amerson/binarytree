#include "BinaryTree.h"
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

/**
 * Constructor for BinaryTree
 */
BinaryTree::BinaryTree(){
	length = 0;
	root = NULL;
}
/**
 * Deconstructor. Calls clearAll and deletes postOrder traversal
 */
BinaryTree::~BinaryTree(){
	clearAll(root);
}

/**
 * Deletes all nodes postOrder Traversal recursively
 * @param tree recursive node that traverses preorder-ly through tree 
 */
void BinaryTree::clearAll(Node *tree){
	if(tree == NULL)
		return;
	if(tree->left !=NULL)
		clearAll(tree->left);
	if(tree->right !=NULL)
		clearAll(tree->right);
	delete tree;
	return;	
}

/**
 * Calls putItem and increases length
 * @param key item to insert into tree
 */
void BinaryTree::insert(ItemType &key){
	bool found = false;
	putItem(key, root, found);	
	if(found)
		length++;
}

/**
 * PutItem find node to put in recursively, then puts it in.
 * @param item item to insert
 * @param node node pointer to traverse and insert
 * @param found whether it was inserted or not
 */
void BinaryTree::putItem(ItemType item, Node*& node, bool& found){
	if(node==NULL){//base case
		node = new Node;
		node->right = NULL;
		node->left = NULL;
		node->key = item;
		found = true;
	}
	else if(item.getValue() < node->key.getValue()){//if Item is less than compared node, traverse left
		putItem(item, node->left, found);
	}
	else if(item.getValue() > node->key.getValue()){//if item is more than compared node, traverse right
		putItem(item, node->right, found);
	}
	else{
		cout << "item already in tree." << endl;//Case if the item is equal to one put in.
		return;
	}
}

/**
 * deleteItem looks for item. If found, call Delete function to delete and decrement length
 * @param key item to deleted
 */
void BinaryTree::deleteItem(ItemType &key){
	bool found = false;
	retrieve(key, found);
	if(found){
		Delete(root, key);
		length--;
	}
}

/**
 * Delete is a recursive function to find the node to delete, then calls the deletenode function when found
 * @param root node that's traversing
 * @param item item to delete
 */
void BinaryTree::Delete(Node*& root, ItemType& item){
	if(item.getValue()<root->key.getValue())
		Delete(root->left, item);
	else if(item.getValue()>root->key.getValue())
		Delete(root->right, item);
	else
		DeleteNode(root);
}

/**
 * DeleteNode deletes the node and deletes it based on its position
 * @param tree node to be deleted
 */
void BinaryTree::DeleteNode(Node*& tree){
	ItemType data;
	Node* tempPtr;
	tempPtr = tree;//assigning a tempPtr to delete later
	if(tree->left==NULL){
		tree = tree->right;//points to right child
		delete tempPtr;
	}
	else if(tree->right == NULL){
		tree = tree->left;
		delete tempPtr;
	}
	else{
		getPredecessor(tree->left, data);//if it has two childs, find a predecessor
		tree->key = data;
		Delete(tree->left, data);//goes to delete the predecessor
	}
}

/**
 * finds the predecessor by traversing right. What's passed in is the
 * root's left child, so the furthest right is the predecessor
 * @param node node to traverse
 * @param data the predecessor of passed node's parent
 */
void BinaryTree::getPredecessor(Node*& node, ItemType& data){
	while(node->right != NULL){
		node = node->right;
	}
	data = node->key;
}

/**
 * getSameLevelNonSiblings finds nodes on the same level that aren't siblings
 * It's a little buggy. It calls findLevel to find the level, then printLevel prints out
 * the same level non siblings
 * @param key item to find same level non siblings for
 */
void BinaryTree::getSameLevelNonSiblings(ItemType &key){
	bool found = false;
	Node* node;
	int val2 = findLevel(key, root, 0);
	printSameLevelNonSiblings(root, key, val2+1, found);
	if(!found)
		cout << "No same level non siblings found" << endl;

}

/**
 * prints out the same level non siblings. Also uses recursion to traverse down the level needed. 
 * @param tree node to traverse
 * @param item item to compare.
 * @param level number of level passed
 * @param found boolean variable to check whether the item has same level non siblings or not
 */
void BinaryTree::printSameLevelNonSiblings(Node*& tree, ItemType& item, int level, bool &found){
	if(level < 2 || tree == NULL){//base
		return;
	}
	if(level ==2){//general
		if(tree->left == NULL)
			return;
		if(tree->right == NULL)
			return;
		if(tree->left->key.getValue() == item.getValue() || tree->right->key.getValue() == item.getValue())
			return;
		if(tree->left != NULL && tree->left->key.getValue() != item.getValue()){
			cout << tree->left->key.getValue() << " ";
			found = true;
		}
		if(tree->right != NULL && tree->right->key.getValue() != item.getValue()){
			cout << tree->right->key.getValue() << " ";
			found=true;
		}
	
	}
	else if(level >2){//recursive
		printSameLevelNonSiblings(tree->left, item, level-1, found);
		printSameLevelNonSiblings(tree->right, item, level-1, found);
	}
	
	

}

/**
 * finds the level the item is on
 * @param item item to find
 * @param level returns the level they're on. First passed is 0, obviously.
 * @return int number of level
 */
int BinaryTree::findLevel(ItemType& item, Node*& tree, int level){
	if(tree == NULL){
		return 0;
	}	
	if(tree->key.getValue() == item.getValue())
		return level;
	int traverseLevel = findLevel(item, tree->left, level+1);
	if(traverseLevel !=0)
		return traverseLevel;
	else 
		return findLevel(item, tree->right, level+1);
}

/**
 * retrieves the item and tells whether its found or not
 * @param item item to find
 * @param found whether it's found or not
 */
void BinaryTree::retrieve(ItemType &item, bool &found) {
	getItem(root, item, found);
	if(found)
		cout << "Item found in tree." << endl;
	else
		cout << "Item not in tree." << endl;
}

/**
 * getItem recursively traverses the trees for the item, and returns whether found or not
 * @param node node to traverse. Starts at root
 * @param item item being searched
 * @param found whether if found or not
 */
void BinaryTree::getItem(Node* node, ItemType& item, bool&found) {
	if(node==NULL)
		found = false;
	else if(item.getValue()< node->key.getValue())
		getItem(node->left, item, found);
	else if(item.getValue()>node->key.getValue())
		getItem(node->right, item, found);
	else{
		item = node->key;
		found = true;
	}			
}

/**
 * preOrder calls printPreOrder, which is recursive
 */
void BinaryTree::preOrder(){
	printPreOrder(root);	
}
/**
 * starts at root, then traverses left and right
 * @param root node to traverse. First pass is the actual root
 */
void BinaryTree::printPreOrder(Node* root){
	if(root != NULL){
		cout << root->key.getValue() << " ";
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

/**
 * inOrder calls printInOrder, which is recursive
 */
void BinaryTree::inOrder(){
	printInOrder(root);
}

/**
 * printInOrder prints all of left side of tree, the root, then the right side of tree
 * @param root node to traverse. First pass is actual root
 */
void BinaryTree::printInOrder(Node* root){
	if(root !=NULL){
		printInOrder(root->left);
		cout << root->key.getValue() << " ";
		printInOrder(root->right);
	}
}

/**
 * postOrder calls printPostOrder, which is recursive
 */
void BinaryTree::postOrder(){
	printPostOrder(root);
}

/**
 * printPostOrder prints left subtree, right subtree, then root.
 * @param root node to traverse. First pass is actual root
 */
void BinaryTree::printPostOrder(Node* root){
	if(root!=NULL){
		printPostOrder(root->left);
		printPostOrder(root->right);
		cout << root->key.getValue() << " ";
	}
}

/**
 * returns length
 * @return int length
 */
int BinaryTree::getLength() const{
	return length;
}
