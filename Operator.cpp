/* 
 * File:   Operator.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 5:38 PM
 */

#include "Operator.h"

Operator::Operator(TokensReader& tokenReader) {
    if(tokenReader.getNext()->getTokenType() == ADD || 
            tokenReader.getCurrent()->getTokenType() == MULTIPLY)
        this->setLeftChild(new Node(tokenReader.getCurrent()));
    else 
        throw ParsingException(tokenReader.getCurrent());
}

Operator::Operator(const Operator& orig) {
}

Operator::~Operator() {
}

