#include "ItemType.h"

struct Node{
	ItemType key;
	Node *left;
	Node *right;
};

class BinaryTree{
	public:
		BinaryTree();
		~BinaryTree();
		void clearAll(Node* tree);
		void insert(ItemType &key);
		void deleteItem(ItemType &key);
		void retrieve(ItemType &item, bool &found);
		void getItem(Node* node, ItemType& item, bool&found);
		void putItem(ItemType item, Node*& node, bool& found);
		void preOrder();
		void inOrder();
		void printInOrder(Node* root);
		void printPreOrder(Node* root);
		void printPostOrder(Node* root);
		void getPredecessor(Node*& node, ItemType& data);
		void DeleteNode(Node*& tree);
		void Delete(Node*& root, ItemType& item);
		void postOrder();
		int getLength() const;
		int findLevel(ItemType& item, Node*& tree, int level);
		void printSameLevelNonSiblings(Node*& tree, ItemType& item, int level, bool&found);
		void getSameLevelNonSiblings(ItemType &key);
		Node *root;
	private:
		int length;
};
