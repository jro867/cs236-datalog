#ifndef DATALOGPROGRAM_H
#define	DATALOGPROGRAM_H

#include "Token.h"
#include "TokenType.h"
#include "TokensReader.h"
#include "Node.h"
#include "SchemesList.h"
#include "FactList.h"
#include "RuleList.h"
#include "QueryList.h"
#include <vector>
#include <iostream>
using namespace std;

class DatalogProgram: public Node {
public:
    DatalogProgram();
    DatalogProgram(TokensReader&);
    DatalogProgram(const DatalogProgram& orig);
    virtual ~DatalogProgram();
private:
    Node* readSchemes(TokensReader&);
    Node* readFacts(TokensReader&, Node* schemeList);
    Node* readRules(TokensReader&, Node* factList);
    Node* readQueries(TokensReader&, Node* ruleList);
    Node* addDomain(Node*);
    
    Node* generateListSize(int size, Node*& last);
};

#endif	/* DATALOGPROGRAM_H */

