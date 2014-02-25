/* 
 * File:   HeadPredicate.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 5:36 PM
 */

#include "HeadPredicate.h"

// ID LEFT_PAREN ID idList RIGHT_PAREN
HeadPredicate::HeadPredicate(TokensReader& tokenReader) {
    if(tokenReader.getCurrent()->getTokenType() != ID) {
        throw ParsingException(tokenReader.getCurrent());
    }
    Node* id = new Node(tokenReader.getCurrent());
    this->setLeftChild(id);
    if(tokenReader.getNext()->getTokenType() != LEFT_PAREN) {
        throw ParsingException(tokenReader.getCurrent());
    }
    Node* leftParen = new Node(tokenReader.getCurrent());
    id->setRightSibling(leftParen);
    if(tokenReader.getNext()->getTokenType() != ID) {
        throw ParsingException(tokenReader.getCurrent());
    }
    Node* nextId = new Node(tokenReader.getCurrent());
    leftParen->setRightSibling(nextId);
    nextId->setRightSibling(new IdList(tokenReader));
    
    if(tokenReader.getCurrent()->getTokenType() != RIGHT_PAREN) {
        throw ParsingException(tokenReader.getCurrent());
    }
    Node* rightParen = new Node(tokenReader.getCurrent());
    nextId->getRightSibling()->setRightSibling(rightParen);
}

HeadPredicate::HeadPredicate(const HeadPredicate& orig) {
}

HeadPredicate::~HeadPredicate() {
}

