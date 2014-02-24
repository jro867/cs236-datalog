#ifndef DATALOGPROGRAM_H
#define	DATALOGPROGRAM_H

#include "Token.h"
#include "TokenType.h"
#include "TokensReader.h"
#include "Node.h"
#include "SchemesList.h"
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
    Node* readFacts(TokensReader&, Node* start);
    Node* readRules(TokensReader&, Node* start);
    Node* readQueries(TokensReader&, Node* start);
};

#endif	/* DATALOGPROGRAM_H */

