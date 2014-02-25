#ifndef SCHEMESLIST_CPP
#define	SCHEMESLIST_CPP
#include "SchemesList.h"

vector<Scheme*> SchemesList::schemes;
SchemesList::SchemesList() {
}

SchemesList::SchemesList(TokensReader& tokenReader){
    if(tokenReader.getCurrent()->getTokenType() == ID){
        Scheme* schemeNode = new Scheme(tokenReader);  
        this->schemes.push_back(schemeNode);
        this->setLeftChild(schemeNode);
        tokenReader.getNext();
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