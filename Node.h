#ifndef NODE_H
#define	NODE_H

#include "Token.h"
#include "TokenType.h"
#include "TokensReader.h"
#include "ParsingException.h"
#include "Node.h"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class Node {
public:
    Node();
    Node(Token*);
    Node(string);
    Node(int);
    Node(vector <Token*>* tokens);
    Node(const Node& orig);
    virtual ~Node();
    
    void setLeftChild(Node*);
    void setRightSibling(Node*);
    void setValue(int);
    void setNL(bool);
    void setLevel(int);
    Node* getLeftChild();
    Node* getRightSibling();
    string toString();
private:
    Node* leftChild = NULL;
    Node* rightSibling = NULL;
    string value;
    
    string toString(int level);
protected:
    bool printNL = false;
    int level = 0;
};

#endif	/* NODE_H */

