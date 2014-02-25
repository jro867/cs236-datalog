#ifndef FACTLIST_H
#define	FACTLIST_H

#include "Fact.h"
#include "Node.h"
#include <vector>

using namespace std;

class FactList: public Node{
public:
    FactList();
    FactList(TokensReader&);
    FactList(const FactList& orig);
    virtual ~FactList();
    
    static int getSize();
private:
    static vector<Fact*> facts;
};
#endif	/* SCHEMESLIST_H */

