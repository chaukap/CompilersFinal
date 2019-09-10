#include<FlexLexer.h>

int main()
{
	yyFlexLexer myScanner;
	int rtn;
	printf("running\n");
	
	while((rtn = myScanner.yylex()) != 0){
		printf("returned %d\n", rtn);
	}

}
