/* 
 * File:   Domain.cpp
 * Author: nuxer
 * 
 * Created on February 25, 2014, 9:25 AM
 */

#include "Domain.h"

set<string> Domain::domain;

Domain::Domain() {
}

Domain::Domain(const Domain& orig) {
}

Domain::~Domain() {
}

void Domain::addToDomain(string _domain) {
    Domain::domain.insert(_domain);
}
set<string> Domain::getDomain() {
    return Domain::domain;
}