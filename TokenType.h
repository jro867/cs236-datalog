#ifndef TokenType_h
#define TokenType_h

#include <string>

/**
 * The token types declared as an enumerated type.
 */
enum TokenType{
    COMMA, 
    PERIOD, 
    COLON_DASH, 
    STRING, 
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN, 
    COLON, 
    MULTIPLY,
    ADD,
    ID, 
    SCHEMES, 
    FACTS, 
    QUERIES, 
    RULES, 
    COMMENT, 
    UNDEFINED,
    NUL,
    END
};
    
/**
 * Converts a token type to a string.
 * 
 * Parameters: tokenType -- the token type to be converted to a string.
 * PreCondition: none
 * Postcondition: result = the string representation of the token type which
 *                         looks exactly like its TokenType name.
 */
std::string TokenTypeToString(TokenType tokenType);
#endif
