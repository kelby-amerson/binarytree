#include "ItemType.h"
#include <cstdlib>
#include <iostream>

using namespace std;
/**
 * Constructor for ItemType
 * Post-Condition: ItemType object is created
 */
ItemType::ItemType(){}

/**
 *  * Constructor for ItemType
 *   * Post-Condition: ItemType object is created with value instantiated
 *    */
ItemType::ItemType(int value){
        this->value = value;
}

/**
 * prints out the associated value
 * Pre-Condition: ItemType object has been initialized
 * Post-Condition: value instance variable is printed to stdout
 */
void ItemType::print(){
	cout << getValue() << endl;
}

/**
 * initializes the value member
 * Pre-Condition: number parameter is initialized.
 * Post-Condition: the value instance vairable is set to number
 */
void ItemType::initialize(int number){
	this->value = number;
}

/**
 * Returns the value of the DataType
 * @return int value
 */
int ItemType::getValue() const{
	return value;
}

