//	Node.h
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#pragma once
#include <cstdio>
#include <memory>
using namespace std;

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
class Node {
public:
    Node();
    Node(const ItemType&);
    Node(const ItemType&, static std::shared_ptr<typename Node<ItemType>>);
    void setItem(const ItemType&);
    void setNext(Node<ItemType>*);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
    virtual ~Node();

private:
    ItemType        item{};			 // A data item
    shared_ptr<typename Node<ItemType>> next{ nullptr }; // smart pointer to next node
};