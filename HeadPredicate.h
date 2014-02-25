/* 
 * File:   HeadPredicate.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 5:36 PM
 */

#ifndef HEADPREDICATE_H
#define	HEADPREDICATE_H

#include "IdList.h"
#include "Node.h"

class HeadPredicate : public Node {
public:
    HeadPredicate(TokensReader&);
    HeadPredicate(const HeadPredicate& orig);
    virtual ~HeadPredicate();
private:

};

#endif	/* HEADPREDICATE_H */

