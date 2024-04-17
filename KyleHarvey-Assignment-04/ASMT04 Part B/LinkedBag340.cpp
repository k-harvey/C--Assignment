//	LinkedBag340.cpp
//	Created by: CSC340

/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===

/*
* 
* 
* */

#include <iostream>
#include <cstddef>
#include "LinkedBag.h"
#include "Node.h"
#include <cstdlib>

/*template<typename ItemType>
LinkedBag<ItemType>::LinkedBag() : *headptr(nullptr), itemCount(0) {}*/


/*template<typename ItemType>
bool LinkedBag<ItemType>:: removeSecondNode340();*/

// 1. removeSecondNode340
//
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
    Node<ItemType>* curPtr; // cursor: curPtr head:headPtr
    curPtr = headPtr->getNext();       // gets the 2nd node
    return remove(curPtr->getItem()); // takes out 2nd node content
};

// 2. addEnd340
//
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {

    Node<ItemType>* curPtr = headPtr; //This is where it starts from the head to the last pointer

    //The copy constructor
    while (curPtr->getNext() != nullptr) {
        curPtr = curPtr->getNext(); //This will stop at the last node.
    }
    Node<ItemType>* endNodePtr = new Node<ItemType>;//Puts newEntry in this endNodePtr.

    //Adds Item to the Linked List node.
    endNodePtr->setItem(newEntry);

    curPtr->setNext(endNodePtr); //A new node will be pointing to nullptr as its next value, 
                                 //No need to declare it here.

    itemCount++;
    return true;
};


// 3. getCurrentSize340Iterative
//

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;
    while (curPtr != nullptr) {      //Traverse
        curPtr = curPtr->getNext();   // counts # of nodes
        counter++;           // counts # of node for all steps
    }
    return counter;
};


// 4. getCurrentSize340Recursive
//    getCurrentSize340
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {

    static Node<ItemType>* curPtr = headPtr; //made static so it doesn't get redeclared leading to an error.
    if (curPtr == nullptr) {
        curPtr = headPtr;//Both starts and ends at headPtr, starting from the base.
        return 0;//Valid return type which is the value for an empty list.
    }
    else {
        curPtr = curPtr->getNext();//iterates the curPtr Node forward.
        return getCurrentSize340RecursiveHelper(curPtr);
    }
};

// 5. getCurrentSizeRecursiveHelper
//    getCurrentSize340RecursiveNoHelper

template <typename ItemType>
int LinkedBag<ItemType> ::getCurrentSize340RecursiveHelper(Node<ItemType>*) const {
    // It does the same thing as the function, helping except here is where it keeps track of count.

    Node<ItemType>* curPtr = headPtr; //As said before, very similar.
    int counter = 0;
    if (curPtr == nullptr) {
        curPtr = headPtr;
        return 0;
    }
    else {
        curPtr = curPtr->getNext();
        counter++;
        return (counter + getCurrentSize340Recursive());

    }
};

   

template <typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    static Node<ItemType>* curPtr = headPtr;
    static int counter = 0;
    if (curPtr == nullptr) {
        curPtr = headPtr;
        return counter;
    }
    else {
        curPtr = curPtr->getNext();
        counter++;
        return getCurrentSize340RecursiveNoHelper();
    }
    return counter;

}

    //  7. getFrequenceyOf340RecursiveNoHelper
    //


template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const {
    static Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    if (curPtr == nullptr) {
        curPtr = headPtr;
        return 0;
    }
    else if (curPtr->getItem() == anEntry) {
        curPtr = curPtr->getNext();
        counter++;
        return (counter + getFrequencyOf340RecursiveNoHelper(anEntry));
    }
    else {
        curPtr = curPtr->getNext();
        return (counter + getFrequencyOf340RecursiveNoHelper(anEntry));
    }
}

    //  6. getFrequencyOf340Recursive
    //


template<typename ItemType>
int  LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {
    //same as getCurrentSize recursion; starts the analysis at the head of the LinkedList.

    static Node<ItemType>* curPtr = headPtr;

    //Establishes the base case
    if (curPtr == nullptr) {
        curPtr = headPtr;
        return 0;// the least amount of times an item can be in a Linked List
    }
    //general case
    else {
        return getFrequencyOf340RecursiveHelper(curPtr, anEntry); //most of the recursion work will be done here.
    }
};


template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType& anEntry) const {
    int counter = 0; //this is to keep track of frequency
    static Node<ItemType>* curPtr = headPtr;

    //three cases here: base, for if the entry IS IN the Bag, and if it IS NOT in the bag.
    //Base Case
    if (curPtr == nullptr) {
        curPtr = headPtr;
        return 0;
    }
    else if (curPtr->getItem() == anEntry) {
        curPtr = curPtr->getNext();
        counter++;
        return (counter + getFrequencyOf340Recursive(anEntry));
    }
    else {
        curPtr = curPtr->getNext();
        return (counter + getFrequencyOf340Recursive(anEntry)); //Returns the same thing in either case because need the counter to carry over regardless.
    }
};

//  8. removeRandom340
//


template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {

    int currentSize = getCurrentSize340Iterative();
    int removeIndex = rand() % currentSize;

    Node<ItemType>* currPtr = headPtr;
    Node<ItemType>* prevPtr = nullptr;

    int curIndex = 0;

    if (currPtr == nullptr)
        return ItemType();

    if (removeIndex == 0) {
        headPtr = headPtr->getNext();
        ItemType info = currPtr->getItem();
        delete currPtr;
        return info;
    }
    while (curIndex < removeIndex) {
        prevPtr = currPtr;
        currPtr = currPtr->getNext();
        curIndex++;
    }

    ItemType info = currPtr->getItem();

    prevPtr->setNext(currPtr->getNext());

    delete currPtr;
    return info;
};
