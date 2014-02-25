/* 
 * File:   Parameter.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 5:38 PM
 */

#include "Parameter.h"

Parameter::Parameter(TokensReader& tokenReader) {
    if(tokenReader.getNext()->getTokenType() == STRING || 
            tokenReader.getCurrent()->getTokenType() == ID) {
        this->setLeftChild(new Node(tokenReader.getCurrent()));
    } else {
        this->setLeftChild(new Expression(tokenReader));
    }
}

Parameter::Parameter(const Parameter& orig) {
}

Parameter::~Parameter() {
}

