/* 
 * File:   ParsingException.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 1:15 PM
 */

#include "ParsingException.h"

ParsingException::ParsingException() {
}

ParsingException::ParsingException(const ParsingException& orig) {
}

ParsingException::~ParsingException() throw() {
}

ParsingException::ParsingException(Token* token) : errorToken(token) {}

