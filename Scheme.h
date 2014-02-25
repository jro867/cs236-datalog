#ifndef SCHEMES_H
#define	SCHEMES_H

#include "Token.h"
#include "Node.h"
#include "TokensReader.h"
#include "IdList.h"
#include <vector>
#include <iostream>

using namespace std;
class Scheme : public Node {
public:
    Scheme();
    Scheme(TokensReader&);
    Scheme(const Scheme& orig);
    virtual ~Scheme();
private:

};

#endif	/* SCHEMES_H */

