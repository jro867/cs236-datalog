/* 
 * File:   PredicateList.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 5:37 PM
 */

#include "PredicateList.h"

PredicateList::PredicateList(TokensReader& tokenReader) {
    if(tokenReader.getNext()->getTokenType() == COMMA){
        Node* comma = new Node(tokenReader.getCurrent());
        this->setLeftChild(comma);
        comma->setRightSibling(new Predicate(tokenReader));
        comma->getRightSibling()->setRightSibling(new PredicateList(tokenReader));
    } else {
        // empty
    }
}

PredicateList::PredicateList(const PredicateList& orig) {
}

PredicateList::~PredicateList() {
}

