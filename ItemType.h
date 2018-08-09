#include <string>
#pragma once

typedef enum {GREATER, LESS, EQUAL} Comparison;

class ItemType{

public:
	ItemType();
	ItemType(int value);
	void print();
	void initialize(int number);
	int getValue() const;
private:
	int value;

};

