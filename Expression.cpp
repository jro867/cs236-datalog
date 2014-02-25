/* 
 * File:   Expression.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 5:38 PM
 */

#include "Expression.h"

Expression::Expression(TokensReader& tokenReader) {
    if(tokenReader.getCurrent()->getTokenType() != LEFT_PAREN) {
        throw ParsingException(tokenReader.getCurrent());
    }
    this->setLeftChild(new Node(tokenReader.getCurrent()));
    this->getLeftChild()->setRightSibling(new Parameter(tokenReader));
    Node* op = new Operator(tokenReader);
    this->getLeftChild()->getRightSibling()->setRightSibling(op);
    op->setRightSibling(new Parameter(tokenReader));
    if(tokenReader.getNext()->getTokenType() != RIGHT_PAREN) {
        throw ParsingException(tokenReader.getCurrent());
    }
    op->getRightSibling()->setRightSibling(new Node(tokenReader.getCurrent()));
}

Expression::Expression(const Expression& orig) {
}

Expression::~Expression() {
}

