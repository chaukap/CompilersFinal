#include<FlexLexer.h>

/* This is a small program so I just made these globals */
int row;
int column;
int rtn;
yyFlexLexer myScanner;

int main()
{
	/* ---- Initialization ---- */
	row = 1;
	column = 1;

	/* ----- Print Header ----- */
	printf("Line\tColumn\tType\tLength\tValue\n");
	
	/* ----- Loop through the input file ----- */
	while((rtn = myScanner.yylex()) != 0) {
		/* ------- Newline -------- */
		if(rtn == 11){
			printf("%d\t%d\t%d\t%d\n", row - 1, column, rtn, myScanner.YYLeng());
			column = 1;

		/* ---- A single space ---- */
		} else if(rtn == 12) {
			column++;

		/* ----- A single tab ----- */
		} else if(rtn == 13) {
			column += 8 - (column % 8);

		} else if(rtn == 10){
			printf("%d\t%d\t%d\t%d\t%s\n", row, column, rtn, myScanner.YYLeng(), myScanner.YYText());
			column += myScanner.YYLeng();
			
		/* ----- All other recognized symbols ----- */
		} else {
			printf("%d\t%d\t%d\t%d\t%s\n", row, column, rtn, myScanner.YYLeng(), myScanner.YYText());
			column += myScanner.YYLeng();
		}
	}

}
