#include<FlexLexer.h>

/* This is a small program so I just made these globals */
extern int row;
extern int column;
int rtn;
yyFlexLexer myScanner;

int main()
{
	/* ----- Print Header ----- */
	printf("Line\tColumn\tType\tLength\tValue\n");
	
	/* ----- Loop through the input file ----- */
	while((rtn = myScanner.yylex()) != 0) {
		/* ------- Newline -------- */
		if(rtn == 11){
			printf("%d\t%d\t%d\t%d\n", row - 1, column, rtn, myScanner.YYLeng());
            // I tried to put all of the row/column stuff in the lexer but I couldn't think
            // of a better way to reset the column number.
			column = 1;

        /* --------- White Space --------- */
        } else if (rtn == 12) {
            /* For white space we do nothing. I added this block to be very certain
               we do nothing. */

		/* ----- All other recognized symbols ----- */
		} else {
			printf("%d\t%d\t%d\t%d\t%s\n", row, column, rtn, myScanner.YYLeng(), myScanner.YYText());
		}
	}

}
