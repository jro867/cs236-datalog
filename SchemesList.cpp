#ifndef SCHEMESLIST_CPP
#define	SCHEMESLIST_CPP
#include "SchemesList.h"

vector<Scheme*> SchemesList::schemes;
SchemesList::SchemesList() {
}

SchemesList::SchemesList(TokensReader& tokenReader){
    if(tokenReader.getNext()->getTokenType() == ID){
        Scheme* schemeNode = new Scheme(tokenReader);  
        this->schemes.push_back(schemeNode);
        this->setLeftChild(schemeNode);
        schemeNode->setRightSibling(new SchemesList(tokenReader));
    } else {
        // empty
    }
}

SchemesList::SchemesList(const SchemesList& orig) {
}

SchemesList::~SchemesList() {
}

int SchemesList::getSize() {
    return schemes.size();
}
#endif