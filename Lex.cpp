#include "Lex.h"

#include "Input.h"
#include "TokenType.h"
#include "Utils.h"
#include <iostream>

using namespace std;

Lex::Lex() {
    input = new Input();
    generateTokens(input);
}

Lex::Lex(const char* filename) {
    input = new Input(filename);
    generateTokens(input);
}

Lex::Lex(istream& istream) {
    input = new Input(istream);
    generateTokens(input);
}

Lex::Lex(const Lex& lex) {
    input = new Input(*lex.input);
    tokens = new vector<Token*>();

    vector<Token*>::iterator iter;
    for(iter=lex.tokens->begin(); iter != lex.tokens->end(); iter++) {
        Token* newToken = new Token(**iter);
        tokens->push_back(newToken);
    }

    index = lex.index;
    state = lex.state;
}

Lex::~Lex(){
    for (int i = 0; i < tokens->size(); i++) {
        delete (*tokens)[i];
    }
    delete tokens;
    delete input;
}

bool Lex::operator==(const Lex& lex) {
    bool result = (tokens->size() == lex.tokens->size()) && (index == lex.index);
    if(result) {
        vector<Token*>::iterator iter1;
        vector<Token*>::iterator iter2;
        iter1 = tokens->begin();
        iter2 = lex.tokens->begin();
        while(result && iter1 != tokens->end() && iter2 != lex.tokens->end()) {
            result = **iter1 == **iter2;
            iter1++;
            iter2++;
        }
        result = result && iter1 == tokens->end() && iter2 == lex.tokens->end();
    }
    return result;
}

string Lex::toString() const {
    int count = 0;
    string result;
    while(count < tokens->size()) {
        Token* token = (*tokens)[count];
        result += token->toString();
        count++;
    }
    result += "Total Tokens = ";
    string countToString;
    result += itoa(countToString, count);
    result += "\n";
    return result;
}

void Lex::generateTokens(Input* input) {
    tokens = new vector<Token*>();
    index = 0;

    state = Start;
    while(state != End) {
        state = nextState();
    }
    emit(EOF);
    
}

Token* Lex::getCurrentToken() {
    return (*tokens)[index];
}

void Lex::advance() {
    index++;
}

bool Lex::hasNext() {
    return index < tokens->size();
}

State Lex::nextState() {
    State result;
    char character;
    switch(state) {
        case Start:               result = getNextState(); break;
        case Comma:               emit(COMMA); result = getNextState(); break;
        case Period:              emit(PERIOD); result = getNextState(); break;
        case SawColon:
            character = input->getCurrentCharacter();
            if(character == '-') {
                result = Colon_Dash;
                input->advance();
            } else { //Every other character
//                throw "ERROR:: in case SawColon:, Expecting  '-' but found " + character + '.';
                emit(COLON); result = getNextState(); break;
            }
            break;
        case Colon_Dash:          emit(COLON_DASH); result = getNextState(); break;
        case SawAQuote:  
            character = input->getCurrentCharacter();
            if(character == '\'') {
                result = PossibleEndOfString;
            } else if(character == -1) {
                throw "ERROR:: in Saw_A_Quote::nextState, reached EOF before end of string.";
            } else { //Every other character
                result = ProcessingString;
            }
            input->advance();
            break;
        case ProcessingString:  
            character = input->getCurrentCharacter();
            if(character == '\'') {
                result = PossibleEndOfString;
            } else if(character == -1) {
                emit(UNDEFINED);
                result = getNextState();
            } else { //Every other character
                result = ProcessingString;
            }
            input->advance();
            break;
        case PossibleEndOfString:
            if(input->getCurrentCharacter() == '\'') {
                input->advance();
                result = ProcessingString;
            } else { //Every other character
                emit(STRING);
                result = getNextState();
            }
            break;
        case QMark: emit(Q_MARK); result = getNextState(); break;
        case LeftParen: emit(LEFT_PAREN); result = getNextState(); break;
        case RightParen: emit(RIGHT_PAREN); result = getNextState(); break;
        case Multiply: emit(MULTIPLY); result = getNextState(); break;
        case Add: emit(ADD); result = getNextState(); break;
        case WhiteSpace:
            input->mark();
            result = getNextState();
            break;
        case Id: 
            character = input->getCurrentCharacter();
            if(isalnum(character)){
                input->advance();                
                result = Id;
            }else{
                if(input->getTokensValue() == "Schemes"){
                    emit(SCHEMES);
                }else if(input->getTokensValue() == "Facts"){
                    emit(FACTS);
                }else if(input->getTokensValue() == "Queries"){
                    emit(QUERIES);
                }else if(input->getTokensValue() == "Rules"){
                    emit(RULES);
                }else{
                    emit(ID);
                }                
                result = getNextState();
            }
            break;
        case SawPoundSign:
            character = input->getCurrentCharacter();
            if(character == '|'){
                result = BlockComment;
            }else{
                result = Comment;
            }
            break;
        case Comment:
            character = input->getCurrentCharacter();
            if(character == -1 || character == '\n'){
                emit(COMMENT);
                result = getNextState();
            }else{
                input->advance();
                result = Comment;
            }
            break;
        case BlockComment:
            input->advance();
            character = input->getCurrentCharacter();
            if(character == -1) {
                emit(UNDEFINED);
                result = getNextState();
            }
            else if(character != '|'){
                result = BlockComment;
            }else{
                input->advance();
                character = input->getCurrentCharacter();
                if(character == -1) {
                    emit(UNDEFINED);
                    result = getNextState();
                }
                if(character == '#'){
                    input->advance();
                    emit(COMMENT);                    
                    result = getNextState();
                }
            }
            
            break;
        case Undefined:
            emit(UNDEFINED);
            result = getNextState();
            break;
    };
    return result;
}

State Lex::getNextState() {
    State result;
    char currentCharacter = input->getCurrentCharacter();
    //The handling of checking for whitespace and setting the result to Whilespace and
    //checking for letters and setting the result to Id will probably best be handled by
    //if statements rather then the switch statement.
    switch(currentCharacter) {
        case ','  : result = Comma; break;
        case '.'  : result = Period; break;
        case ':'  : result = SawColon; break;
        case '\'' : result = ProcessingString; break;
        case '?'  : result = QMark; break;
        case '('  : result = LeftParen; break;
        case ')'  : result = RightParen; break;
        case '*'  : result = Multiply; break;
        case '+'  : result = Add; break;
        case '#'  : result = SawPoundSign; break;
        case ' '  :
        case '\n' :
        case '\t' :
            result = WhiteSpace; break;
        case -1   : result = End; break;
        default: 
            if(isalpha(currentCharacter)){
                result = Id; break;
            }
            result = Undefined;
    }
    input->advance();
    return result;
}

void Lex::emit(TokenType tokenType) {
    Token* token = new Token(tokenType, input->getTokensValue(), input->getCurrentTokensLineNumber());
    storeToken(token);
    input->mark();
}

void Lex::storeToken(Token* token) {
    //This section shoud ignore whitespace and comments and change the token type to the appropriate value
    //if the value of the token is "Schemes", "Facts", "Rules", or "Queries".
    tokens->push_back(token);
}

int main(int argc, char* argv[]) {
    Lex lex(argv[1]);
    TokensReader reader = lex.getTokens();
    DatalogProgram * program = new DatalogProgram(reader);
    try {
        cout << "Success!" << endl;
        cout << program->toString() << endl;
    } catch(ParsingException * e) {
        cout << e->what() << endl;
    }
    return 0;
}
