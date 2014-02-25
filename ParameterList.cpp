/* 
 * File:   ParameterList.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 5:38 PM
 */

#include "ParameterList.h"

ParameterList::ParameterList(TokensReader& tokenReader) {
    if(tokenReader.getNext()->getTokenType() == COMMA){
        Node* comma = new Node(tokenReader.getCurrent());
        this->setLeftChild(comma);
        comma->setRightSibling(new Parameter(tokenReader));
        comma->getRightSibling()->setRightSibling(new ParameterList(tokenReader));
    } else {
        // empty
    }
}

ParameterList::ParameterList(const ParameterList& orig) {
}

ParameterList::~ParameterList() {
}

