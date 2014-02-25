/* 
 * File:   StringList.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 4:28 PM
 */

#include "StringList.h"

StringList::StringList(TokensReader& tokenReader){
    // comma
    if(tokenReader.getNext()->getTokenType() == COMMA) {
        Node* comma = new Node(tokenReader.getCurrent());
        this->setLeftChild(comma);
        // string
        if(tokenReader.getNext()->getTokenType() == STRING) {
            comma->setRightSibling(new Node(tokenReader.getCurrent()));
            // stringList
            comma->getRightSibling()->setRightSibling(new StringList(tokenReader));
        }
    } else {
        // empty
    }
}
StringList::~StringList() {
}

