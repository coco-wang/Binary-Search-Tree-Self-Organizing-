#include <iostream>
#include <string>
#include "bst.h"

using namespace std;
using namespace cop4530;

int main() {
    string input;

    // get a list of integer values
    cout << "Enter a list of integer values in one line: "<<endl;
    getline(cin, input);

    // create a binary search tree
    BST<int> bst1(input);

    if (!bst1.empty()) {
        cout << "Inorder traversal: ";
        bst1.printInOrder();
        cout << "Level order traversal: ";
        bst1.printLevelOrder();

        // test copy constructor
        BST<int> bst2(bst1);
        cout << "Testing copy constructor: ";
        bst2.printLevelOrder();

        // test assignment operator
        BST<int> bst3;
        bst3 = bst1;
        cout << "Testing copy assignment operator: ";
        bst3.printLevelOrder();


        // test move constructor
        BST<int> bst4(std::move(bst2));
        cout << "Testing move constructor: ";
        bst4.printLevelOrder();
        bst2.printLevelOrder();


        // test move assignment operator
        BST<int> bst5;
        bst5 = std::move(bst3);
        cout << "Testing move assignment operator: ";
        bst5.printLevelOrder();
        bst3.printLevelOrder();
      }

 // get a list of string values
    cout << "Enter a list of string values in one line: ";
    getline(cin, input);

    // create a binary search tree
    BST<string> bsts1(input);
    if (!bsts1.empty()) {
        cout << "Inorder traversal: ";
        bsts1.printInOrder();
        cout << "Level order traversal: ";
        bsts1.printLevelOrder();


        // test copy constructor
        BST<string> bst2(bsts1);
        cout << "Testing copy constructor: ";
        bst2.printLevelOrder();


        // test assignment operator
        BST<string> bst3;
        bst3 = bsts1;
        cout << "Testing assignment operator: ";
        bst3.printLevelOrder();

        // test move constructor
        BST<string> bst4(std::move(bst2));
        cout << "Testing move constructor: ";
        bst4.printLevelOrder();
        bst2.printLevelOrder();

        // test move assignment operator
        BST<string> bst5;
        bst5 = std::move(bst3);
        cout << "Testing move assignment operator: ";
        bst5.printLevelOrder();
        bst3.printLevelOrder();
     }

    cout << "Enter a list of integer values: ";
    getline(cin, input);
    bst1.buildFromInputString(input);
    cout << "Level order traversal: ";
    bst1.printLevelOrder();

    cout << "\n===================\n";
    cout << "Operation Manual:" << endl;
    cout << "d: delete value;\ti: insert value;" << endl;
    cout << "h: height of tree; \tn: number of nodes" << endl;
    cout << "o: in order print; \tl: level order print" << endl;
    cout << "s: search value;\tq: quit" << endl;
 cout << "===================\n";
    cout << "choice: ";
    int tmp;
    while (getline(cin, input)) {
        if (input == "q")
            break;
        if (input == "d") {
            cout << "Type value to delete: ";
            cin >> tmp;
            cin.ignore();
            bst1.remove(tmp);
        } else if (input == "i") {
            cout << "Type value to insert: ";
            cin >> tmp;
            cin.ignore();
            bst1.insert(tmp);
        } else if (input == "o") {
            cout << "In order traversal: ";
            bst1.printInOrder();
        } else if (input == "l") {
            cout << "Level order traversal: ";
            bst1.printLevelOrder();
        } else if (input == "h") {
            cout << "Height: ";
            cout << bst1.height() << endl;
        } else if (input == "n") {
            cout << "Number of nodes: ";
            cout << bst1.numOfNodes() << endl;
        } else if (input == "s") {
            cout << "Type value to search: ";
            cin >> tmp;
            cin.ignore();
            if (bst1.contains(tmp)) {
                cout << "contains " << tmp << endl;
            } else {
                cout << "does not contains " << tmp << endl;
            }
        }

        cout << "\n===================\n";
        cout << "Operation Manual:" << endl;
        cout << "d: delete value;\ti: insert value;" << endl;
        cout << "h: height of tree; \tn: number of nodes" << endl;
        cout << "o: in order print; \tl: level order print" << endl;
        cout << "s: search value;\tq: quit" << endl;
        cout << "===================\n";
        cout << "choice: ";
    }
    return 0;
}
