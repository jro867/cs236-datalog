#include "TokenType.h"

using namespace std;

string TokenTypeToString(TokenType tokenType){
    string result = "";
    switch(tokenType){
        case COMMA:              result = "COMMA"; break;
        case PERIOD:             result = "PERIOD"; break;
        case COLON_DASH:         result = "COLON_DASH"; break;
        case STRING:             result = "STRING"; break;
        case Q_MARK:             result = "Q_MARK"; break;
        case LEFT_PAREN:         result = "LEFT_PAREN"; break;
        case RIGHT_PAREN:        result = "RIGHT_PAREN"; break;
        case COLON:              result = "COLON"; break;
        case MULTIPLY:           result = "MULTIPLY"; break;
        case ADD:                result = "ADD"; break;
        case ID:                 result = "ID"; break;
        case SCHEMES:            result = "SCHEMES"; break;
        case FACTS:              result = "FACTS"; break;
        case QUERIES:            result = "QUERIES"; break;
        case RULES:              result = "RULES"; break;
        case COMMENT:            result = "COMMENT"; break;
        case UNDEFINED:          result = "UNDEFINED"; break;
        case NUL:                result = "NUL"; break;
        case EOF:                result = "EOF"; break;
    }
    return result;
};
