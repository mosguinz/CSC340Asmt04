//  Node.cpp
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "Node.h"
#include <iostream>
#include <memory>

template<typename ItemType>
Node<ItemType>::Node() : item(), next(nullptr) {}

template<typename ItemType>
Node<ItemType>::Node(const ItemType &anItem) : item(anItem), next(nullptr) {}

template<typename ItemType>
Node<ItemType>::Node(const ItemType &anItem, std::unique_ptr<Node<ItemType>> nextNodePtr) :
    item(anItem), next(nextNodePtr) {}

template<typename ItemType>
void Node<ItemType>::setItem(const ItemType &anItem) {
    item = anItem;
}

template<typename ItemType>
void Node<ItemType>::setNext(std::unique_ptr<Node<ItemType>> nextNodePtr) {
    next = nextNodePtr;
}

template<typename ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

template<typename ItemType>
std::unique_ptr<Node<ItemType>> Node<ItemType>::getNext() const {
    return std::move(next);
}

template<typename ItemType>
Node<ItemType>::~Node() {
    std::cout << "[Node \"" << item << "\" at " << this << " is being destroyed.]\n";
}
