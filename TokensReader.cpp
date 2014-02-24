#include "TokensReader.h"

TokensReader::TokensReader() : curIndex(0) {}
TokensReader::TokensReader(vector <Token*>* _tokens) : curIndex(0), tokens(_tokens) {}

Token* TokensReader::getCurrent(){
    return tokens->at(curIndex);
}
Token* TokensReader::getNext(){
    return tokens->at(++curIndex);
}
bool TokensReader::hasNext(){
    return curIndex < tokens->size()-1;
}
TokensReader::TokensReader(const TokensReader& orig) {
}

TokensReader::~TokensReader() {
}

