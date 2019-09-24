/* tokens.hpp
   This header includes an emumerator for values returned from the lexer. */

enum token{
    COMMA = 1,  // A single comma.
    DOT,        // A single period
    RPAREN,     // A right parenthesis
    LPAREN,     // A left parenthesis
    LBRACK,
    RBRACK,
    LBRACE,
    RBRACE,
    NEQ,
    EQ,
    LT,
    GT,
    LEQ,
    GEQ,
    AND,
    OR,
    NOT,
    PLUS,
    MINUS,
    TIMES,
    DIV,
    MOD,
    SEMI,
    ASSIGN,
    COMMENT,
    INT,
    VOID,
    CLASS,
    NEW,
    PRINT,
    READ,
    RETURN,
    ELSE,
    NULLT,
    THIS,       // The "this" command
    IF,         // The if command
    WHILE,      // The while command
    IDENT,
    NUMBER,
    ER_CH,      // A single unknown character surrounded by white space.
    ER_WD,      // An error character followed by an identifier.
    ERRORS,     // Passed on the 21st error.
    IGNORE,     // Means "ignore this lexeme it is useless".
};

char* tokenToString(token t);
