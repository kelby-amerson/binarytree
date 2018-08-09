#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char *argv[]){

	BinaryTree list;
        ItemType item4;
        int input;
        fstream fs;//opens up file
        if(argv[1] != NULL){//opens up passed text file to input numbers in list
                fs.open(argv[1],fstream::in);
                if(fs.is_open()){
                        fs >> input;
                        while(!fs.eof()){
                                ItemType item4(input);
                                list.insert(item4);
                                fs >> input;
                        }
                }else{
                        cout << "Failed to open the input file" << endl;
                }
        }


	//interface 
        cout << "Commands: insert (i), delete (d), retrieve (r), length (l), in-order (n),pre-order (p), post-order (o), quit (q), getSameLevelNonSiblings (c), quit (q)" << endl;
        cout << endl;
        while(true){

                string s1;
                cout << "Enter a command: ";//gets command from user, and stores it in a string
                getline(cin, s1);

                if(s1 == "q"){//probably could've been in switch statement, but whatever
                        cout << "Quitting program.." << endl;//quits program
                        exit(EXIT_SUCCESS);
                }else if(s1=="i"){//inserts object
                        //list.print();
                        cout << "Enter a number: ";
                        int val;
                        cin >> val;
                        cin.ignore(1,'\n');
                        ItemType item(val);
                        list.insert(item);
			cout << endl;
			cout << "In-Order: ";
                        list.inOrder();
			cout << endl;
                }else if(s1=="d"){//deletes object
                        //list.print();
                        cout << "Item to delete: ";
                        int val;
                        cin >> val;
                        cin.ignore(1,'\n');
                        ItemType item2(val);
                        list.deleteItem(item2);
			cout << endl;
			cout << "In-Order: ";
                        list.inOrder();
			cout << endl;
                }else if(s1=="r"){//retrieves object
                        //list.print();
                        cout << "Item to be retrieved: ";
                        int val;
                        cin >> val;
                        cin.ignore(1,'\n');
                        ItemType item2(val);
			bool found = false;
                        list.retrieve(item2, found);
			cout << endl;
                }else if(s1=="c"){//samelevelnonsiblings
			cout << "Item to find level for: ";
			int val;
			cin >> val;
                        cin.ignore(1,'\n');
			ItemType item3(val);
			list.getSameLevelNonSiblings(item3);	
			cout << endl;
                }else if(s1=="o"){//post-order
			cout << "Post-Order: ";
			list.postOrder();
			cout << endl;
                }else if(s1=="p"){//pre-order
			cout << "Pre-Order: ";
			list.preOrder();
			cout << endl;
                }else if(s1=="n"){//in-order
			cout << "In-Order: ";
			list.inOrder();
			cout << endl;
                       // cout << "Length: " << list.getLength() << endl;
                }else if(s1=="l"){//returns length
                        cout << "Length: " << list.getLength() << endl;
                }else{//if it's not a command, print it out and go through the loop again
                        cout << "Command not recognized. Try again" << endl;
                }
                cout << endl;
        }

}
