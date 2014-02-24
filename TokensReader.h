#ifndef TOKENSREADER_H
#define	TOKENSREADER_H

#include "Token.h"
#include "TokenType.h"
#include <iostream>
#include <vector>

using namespace std;

class TokensReader {
public:
    TokensReader();
    TokensReader(vector <Token*>* tokens);
    TokensReader(const TokensReader& orig);
    virtual ~TokensReader();
    
    Token* getNext();
    Token* getCurrent();
    bool hasNext();
    
private:
    int curIndex;
    vector <Token*>* tokens;
};

#endif	/* TOKENSREADER_H */

