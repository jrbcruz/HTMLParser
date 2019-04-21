# Listing of complete set of files included in the submission
1) **lexer.l** - lexical analyzer file that will be paired with the bison generated parser to process html input
2) **lex.yy.c** - C accompanying file generated upon compiling lexer.l file with flex
3) **parser.y** - y file containing grammar rules for parsing input
4) **parser.tab.c/parser.tab.h** - accompanying files generated upon compiling parser.y file with bison
5) **parser.exe** - executable file of flex and bison generated parser
6) **sed.exe** - GNU library used for cleaning up output of generated parser
7) **tester.c** - C file which serves as the driver of the Unity testing library that was used for this project
8) **tester.exe** - executable file of Unity driver C file
