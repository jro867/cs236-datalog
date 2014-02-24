#ifndef SCHEMESLIST_H
#define	SCHEMESLIST_H

#include "Scheme.h"
#include "Node.h"
#include <vector>

using namespace std;

class SchemesList: public Node{
public:
    SchemesList();
    SchemesList(TokensReader&);
    SchemesList(const SchemesList& orig);
    virtual ~SchemesList();
    
    static int getSize();
private:
    static vector<Scheme*> schemes;
};
#endif	/* SCHEMESLIST_H */

