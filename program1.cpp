#include<FlexLexer.h>
#include "tokens.hpp"

/* This is a small program so I just made these globals */
extern int row;
extern int column;
int rtn;
yyFlexLexer myScanner;

int main()
{
	/* ----- Print Header ----- */
	printf("Line\tColumn\tType\tValue\n");
	
	/* ----- Loop through the input file ----- */
	while((rtn = myScanner.yylex()) > 0) {
        /* --------- White Space --------- */
        if (rtn == IGNORE) {
            /* The lexer told us to ignore this. I added this block to be very certain
               we do nothing. */

		/* ----- Over 20 errors ----- */
		} else if(rtn == ERRORS) {
            // I know, breaks are kind of lazy, but I like them.
            break;
            
        /* ----- All other recognized symbols ----- */
        } else {
            if(rtn == NUMBER){
                printf("%d\t%d\t%s\t%s\n", row, column, tokenToString((token) rtn), myScanner.YYText());
            } else {
			    printf("%d\t%d\t%s\t%s\n", row, column, tokenToString((token) rtn));
            }
		}
	}

}
