# Listing of complete set of files included in the submission
1) **lexer.l** - lexical analyzer file that will be paired with the bison generated parser to process html input
2) **lex.yy.c** - C accompanying file generated upon compiling lexer.l file with flex
3) **parser.y** - y file containing grammar rules for parsing input
4) **parser.tab.c/parser.tab.h** - accompanying files generated upon compiling parser.y file with bison
5) **parser.exe** - executable file of flex and bison generated parser
6) **sed.exe** - GNU library used for cleaning up output of generated parser
7) **tester.c** - C file which serves as the driver of the Unity testing library that was used for this project
8) **tester.exe** - executable file of Unity driver C file
9) **src folder** - folder that contains the Unity testing library files
10) **Inputs folder** - folder that contains the input files for the flex/bison generated parser
11) **ParserOutputs folder** - folder that contains the output files of the flex/bison generated parser
12) **ExpectedOutputs folder** - folder that contains the expected outputs of each test case from the flex/bison generated parser
13) **StandAloneLexer folder** - contains files for the **first part of the project only**, includes the "standalone" version of the lexical analyzer

# Description of minimum machine specs required
Machine OS must be Windows 7 and above. Machine must have GCC (C compiler), Flex, and Bison installed locally. Machine needs at least 1 GB 
of free memory. 

# Some special cases not mentioned in the project specs
1) **Negative numbers** - the given test cases did not contain any negative numbers. The parser program created by our group handles negative numbers by performing an operation called unary subtraction to handle negative numbers. Unary subtraction essentially means subtracting a given value from zero to yield a negative value. 

2) 
