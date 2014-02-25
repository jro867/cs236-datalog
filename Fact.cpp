#include "Fact.h"

Fact::Fact() {
}

Fact::Fact(TokensReader& tokenReader) {
    this->printNL = true;
    if(tokenReader.getCurrent()->getTokenType() == ID) {
        Node* id = new Node(tokenReader.getCurrent());
        this->setLeftChild(id);
        if(tokenReader.getNext()->getTokenType() == LEFT_PAREN) {
            Node* leftParen = new Node(tokenReader.getCurrent());
            id->setRightSibling(leftParen);
            if(tokenReader.getNext()->getTokenType() == STRING) {
                Node* string = new Node(tokenReader.getCurrent());
                leftParen->setRightSibling(string);
                string->setRightSibling(new StringList(tokenReader));
                if(tokenReader.getCurrent()->getTokenType() == RIGHT_PAREN) {
                    Node* rightParen = new Node(tokenReader.getCurrent());
                    string->getRightSibling()->setRightSibling(rightParen);
                    if(tokenReader.getNext()->getTokenType() == PERIOD) {
                        rightParen->setRightSibling(new Node(tokenReader.getCurrent()));
                    } else {
                        throw ParsingException(tokenReader.getCurrent());
                    }
                } else {
                    throw ParsingException(tokenReader.getCurrent());
                }
            } else {
                throw ParsingException(tokenReader.getCurrent());
            }
        } else {
            throw ParsingException(tokenReader.getCurrent());
        }
    } else {
        throw ParsingException(tokenReader.getCurrent());
    }
}

Fact::Fact(const Fact& orig) {
}

Fact::~Fact() {
}

