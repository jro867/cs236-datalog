#include "TokensReader.h"

TokensReader::TokensReader() : curIndex(0) {}
TokensReader::TokensReader(vector <Token*>* _tokens) : curIndex(0), tokens(_tokens) {}

Token* TokensReader::getCurrent(){
    return tokens->at(curIndex);
}
Token* TokensReader::getNext(){
    Token* next = tokens->at(++curIndex); 
    while(next->getTokenType() == COMMENT) {
        next = tokens->at(++curIndex); 
    }
    return next;
}
bool TokensReader::hasNext(){
    return curIndex < tokens->size()-1;
}
TokensReader::TokensReader(const TokensReader& orig) {
}

TokensReader::~TokensReader() {
}

