#include "IdList.h"

IdList::IdList() {
}

IdList::IdList(TokensReader& tokenReader) {
    if(tokenReader.getNext()->getTokenType() == COMMA){
        Node * comma = new Node(tokenReader.getCurrent());
        this->setLeftChild(comma);
        if(tokenReader.getNext()->getTokenType() == ID) {
            comma->setRightSibling(new Node(tokenReader.getCurrent()));
            comma->getRightSibling()->setRightSibling(new IdList(tokenReader));
        } else {
            throw ParsingException(tokenReader.getCurrent());
        }
    } else {
        // empty
    }
}

IdList::IdList(const IdList& orig) {
}

IdList::~IdList() {
}

