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

2) **No int-double modulo** - the group researched that in the case of the C programming language, there are no/very few cases
where int % double occurs. The group has decided that the program will not handle this case as this is rare.

3) **Unclosed html statements** - the group perceived/assumed that there was a typo in the tab2.html given test case. If an html statement is not enclosed by an ending tag, then the program will see classify that as a syntax error, but an output will still be printed out.

# Instructions on how to recompile/rebuild programs from source codes
1) Download/clone master branch of this repo and extract files
2) Open command prompt
3) Compile lexical analyzer with Flex with the following command: **flex lexer.l**
4) Compile parser with Bison with the following command: **bison -d parser.y**
5) Compile lexical analyzer and parser together to produce executable file with the following command: **gcc lex.yy.c parser.tab.c -o parser.exe**

# Instructions on how to test programs using the Unity testing library
1) Trim output CSVs of the generated parser and the expected output CSVs
  - Remove excess commas from parser output CSVs using sed with the following command: **sed -i s/,$// file.csv**
  - Remove excess whitespaces from parser output CSVs using sed with the following command: **sed -i s/[[:space:]]*$// file.csv**
  - Remove carriage return characters from both parser output CSVs and expected output CSVs with the following command: **sed -i s/\r// file.csv**
2) Edit **tester.c** driver file and add test case
  - Add method to account for new test case
  - Call added method in main method
3) Compile tester file using the following command: **gcc tester.c src/unity.c -o tester.exe**
4) Run **tester.exe**

# Instructions on how to run lexical analyzer program and parser program
1) **To run JUST/ONLY the lexical analyzer on its own**, please follow the instructions below this item
- Navigate to the StandAloneLexer folder
- Compile the lexical analyzer via command prompt with the following command: **flex standalonelexer.l**
- Compile the lex driver file with the lexical analyzer generated file with the following command: **gcc lexdriver.c lex.yy.c -o standalonelexer.exe**
- Run the generated executable lexical analyzer with the following command: **standalonelexer.exe<file.html**
2) **NOTE:** The reason why the group decided to make a "stand alone" version of the lexical analyzer is because there were some changes the group had to make concerning the Bison generated parser which required some modifications to the original lexical analyzer. One of these changes is **to address operator precedence on the end of the Bison generated parser**, since operator precedence in Bison only works with non-terminals, hence the operator tokens (e.g. PLUS, MINUS, etc.) had to be reduced to terminals to address this. Another reason is to address the project specifications regarding the feature where **a punctuation token will be appended to the token previous to it**. However, the stand alone lexical analyzer and the lexical analyzer used along with the actual generated parser do not have any other differences aside from these two points.
3) **To run the parser program**, please follow the instructions below this item:
- Compile lexical analyzer with Flex with the following command: **flex lexer.l**
- Compile parser with Bison with the following command: **bison -d parser.y**
- Compile lexical analyzer and parser together to produce executable file with the following command: **gcc lex.yy.c parser.tab.c -o parser.exe**
- Run executable file with the following command: **parser.exe<Inputs/input.html>ParserOutput/output.csv**

# Additional notes for input and expected output files
- Please be careful with input html files. If the parser outputs "syntax error" then please make sure that the html input file in question has **either one newline character at the end of the file or none at all. If an html table entry is NOT preceded by an html comment, then please make sure that there are no excess newlines at the end of the file. Otherwise, excess newlines are fine**.
- Please make sure that the **expected output files DO NOT contain any extra newline/endline characters**
- Please also take note regarding the testing library (Unity). **In cases where an html table is succeeded by a token or a series of tokens, please be aware that the Unity testing library will react differently**. To address this case, **please make sure to erase the last endline/newline character of the CSV outputted by the Bison generated parser (using the sed program automatically appends an extra newline to the file for some reason). Also, please make sure to modify the test case code in the tester.c file to instead use the commented out test assert equal statement (which is TEST_ASSERT_EQUAL_STRING(str, str2)) INSTEAD OF THE DEFAULT ONE**. The same must be done if the input html/txt file **ends with tokens and NOT html statements**. So for both cases, the excess newline character of the Bison generated parser output must be erased (1), and the test assert statement in the tester.c file must be switched (2)
- If the tester file outputs a FAILED test case value, please check the output of the command prompt. If the only/main difference is the
presence of garbage characters, please do the steps mentioned in the bullet point right above this current one.
