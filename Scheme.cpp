#include "Scheme.h"

Scheme::Scheme() {
}
Scheme::Scheme(TokensReader& tokenReader) {
    this->printNL = true;
    if(tokenReader.getCurrent()->getTokenType() == ID){
        Node * idNode = new Node(tokenReader.getCurrent());
        this->setLeftChild(idNode);
        if (tokenReader.getNext()->getTokenType() == LEFT_PAREN) {
            Node * lParenNode = new Node(tokenReader.getCurrent());
            idNode->setRightSibling(lParenNode);
            if (tokenReader.getNext()->getTokenType() == ID) {
                Node * idNode = new Node(tokenReader.getCurrent());
                lParenNode->setRightSibling(idNode);
                idNode->setRightSibling(new IdList(tokenReader));
                if(tokenReader.getCurrent()->getTokenType() == RIGHT_PAREN) {
                    idNode->getRightSibling()->setRightSibling(new Node(tokenReader.getCurrent()));
                } else {
                    throw ParsingException(tokenReader.getCurrent());
                }
            }else{
                throw ParsingException(tokenReader.getCurrent());
            }
        }else{
            throw ParsingException(tokenReader.getCurrent());
        }
    }else{
        throw ParsingException(tokenReader.getCurrent());
    }
}

Scheme::Scheme(const Scheme& orig) {
}

Scheme::~Scheme() {
}

