/* 
 * File:   StringList.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 4:28 PM
 */

#ifndef STRINGLIST_H
#define	STRINGLIST_H

#include "Domain.h"
#include "Node.h"

class StringList : public Node {
public:
    StringList(TokensReader&);
    virtual ~StringList();
private:

};

#endif	/* STRINGLIST_H */

