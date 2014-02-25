/* 
 * File:   Predicate.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 5:37 PM
 */

#include "Predicate.h"

// ID LEFT_PAREN parameter parameterList RIGHT_PAREN
Predicate::Predicate(TokensReader& tokenReader) {
    if(tokenReader.getNext()->getTokenType() != ID) {
        throw ParsingException(tokenReader.getCurrent());
    }
    Node* id = new Node(tokenReader.getCurrent());
    this->setLeftChild(id);
    if(tokenReader.getNext()->getTokenType() != LEFT_PAREN) {
        throw ParsingException(tokenReader.getCurrent());
    }
    Node* leftParen = new Node(tokenReader.getCurrent());
    id->setRightSibling(leftParen);
    leftParen->setRightSibling(new Parameter(tokenReader));
    ParameterList* parameterList = new ParameterList(tokenReader);
    leftParen->getRightSibling()->setRightSibling(parameterList);
    if(tokenReader.getCurrent()->getTokenType() != RIGHT_PAREN) {
        throw ParsingException(tokenReader.getCurrent());
    }
    Node* rightParen = new Node(tokenReader.getCurrent());
    parameterList->setRightSibling(rightParen);
}

Predicate::Predicate(const Predicate& orig) {
}

Predicate::~Predicate() {
}

