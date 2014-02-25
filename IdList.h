#ifndef IDLIST_H
#define	IDLIST_H

#include "Scheme.h"
#include "Node.h"
#include <vector>

using namespace std;

class IdList: public Node{
public:
    IdList(TokensReader&);
    IdList(const IdList& orig);
    virtual ~IdList();
private:

};

#endif
