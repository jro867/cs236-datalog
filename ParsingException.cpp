/* 
 * File:   ParsingException.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 1:15 PM
 */

#include "ParsingException.h"

ParsingException::ParsingException() : runtime_error("Parsing Exception") {
}

ParsingException::ParsingException(const ParsingException& orig) : runtime_error("Parsing Exception") {
}

ParsingException::~ParsingException() throw() {}

ParsingException::ParsingException(Token* token) : runtime_error("Failure!\n\t"+token->toString()){}

