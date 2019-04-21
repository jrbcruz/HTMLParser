#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "src/unity.h"

char* getFileContents(char* target){
	char * buffer = 0;
	long length;
	FILE * f = fopen (target, "rb");

	if (f)
	{
	  fseek (f, 0, SEEK_END);
	  length = ftell (f) ;
	  fseek (f, 0, SEEK_SET);
	  buffer = calloc (length, 1);
	  if (buffer)
	  {
		fread (buffer, 1, length, f);
	  }
	  fclose (f);
	}

	if (buffer)
	{
		return buffer;
	}
	else{
		return NULL;
	}
}

void test_MC(void){
	char* str = getFileContents("ExpectedOutputs/mcoutputexp.txt");
	char* str2 = getFileContents("ParserOutputs/mcoutput.txt");	
	char* strV2 = malloc(strlen(str) + 2);
	strcpy(strV2, str);
	strcat(strV2, "\n");	
	TEST_ASSERT_EQUAL_STRING(strV2, str2);
}

void test_Tab0(void){
	char* str = getFileContents("ExpectedOutputs/tab0outputexp.csv");
	char* str2 = getFileContents("ParserOutputs/tab0output.csv");
	char* strV2 = malloc(strlen(str) + 2);
	strcpy(strV2, str);
	strcat(strV2, "\n");	
	TEST_ASSERT_EQUAL_STRING(strV2, str2);  //if expected output does not have extra endline
	//TEST_ASSERT_EQUAL_STRING(str, str2); //if expected output has extra line
}

void test_Tab1(void){
	char* str = getFileContents("ExpectedOutputs/tab1outputexp.csv");
	char* str2 = getFileContents("ParserOutputs/tab1output.csv");
	char* strV2 = malloc(strlen(str) + 2);
	strcpy(strV2, str);
	strcat(strV2, "\n");
	// printf("==========TAB1================\n");
	// printf("%s\n", str);
	// printf("====================================\n");
	// printf("%s\n", str2);
	TEST_ASSERT_EQUAL_STRING(strV2, str2);  //if expected output does not have extra endline
	//TEST_ASSERT_EQUAL_STRING(str, str2); //if expected output has extra line
}

void test_Tab2(void){
	char* str = getFileContents("ExpectedOutputs/tab2outputexp.csv");
	char* str2 = getFileContents("ParserOutputs/tab2output.csv");
	char* strV2 = malloc(strlen(str) + 2);
	strcpy(strV2, str);
	strcat(strV2, "\n");
	
	// char* str2V2 = malloc(strlen(str2) + 2);
	// strcpy(str2V2, str2);
	// strcat(str2V2, "\n");
	// str[strlen(str)] = '\0';
	// str2[strlen(str2)] = '\0';
	// printf("==========TAB2================\n");
	// printf("%s\n", str);
	// printf("====================================\n");
	// printf("%s\n", str2);
	// TEST_ASSERT_EQUAL_STRING(str, str2V2); 
	
	TEST_ASSERT_EQUAL_STRING(strV2, str2); //if expected output does not have extra endline
	//TEST_ASSERT_EQUAL_STRING(str, str2); //if expected output has extra line
}

void test_Tab3(void){
	char* str = getFileContents("ExpectedOutputs/tab3outputexp.csv");
	char* str2 = getFileContents("ParserOutputs/tab3output.csv");
	char* strV2 = malloc(strlen(str) + 2);
	strcpy(strV2, str);
	strcat(strV2, "\n");	
	TEST_ASSERT_EQUAL_STRING(strV2, str2);	
}

void test_Tab4(void){
	char* str = getFileContents("ExpectedOutputs/tab4outputexp.csv");
	char* str2 = getFileContents("ParserOutputs/tab4output.csv");
	char* strV2 = malloc(strlen(str) + 2);
	strcpy(strV2, str);
	strcat(strV2, "\n");	
	TEST_ASSERT_EQUAL_STRING(strV2, str2);		
}

void test_Tab5(void){
	char* str = getFileContents("ExpectedOutputs/tab5outputexp.csv");
	char* str2 = getFileContents("ParserOutputs/tab5output.csv");
	char* strV2 = malloc(strlen(str) + 2);
	strcpy(strV2, str);
	strcat(strV2, "\n");	
	TEST_ASSERT_EQUAL_STRING(strV2, str2);			
}

/* TEST CASE METHOD TEMPLATE BELOW
void test_<testCaseName>(void){
	char* str = getFileContents("ExpectedOutputs/<expectedoutput.csv>");
	char* str2 = getFileContents("ParserOutputs/<parseroutput.csv>");
	char* strV2 = malloc(strlen(str) + 2);
	strcpy(strV2, str);
	strcat(strV2, "\n");	
	TEST_ASSERT_EQUAL_STRING(strV2, str2);			
}
*/

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_MC);
	RUN_TEST(test_Tab0);
	RUN_TEST(test_Tab1);
	RUN_TEST(test_Tab2);
	RUN_TEST(test_Tab3);
	RUN_TEST(test_Tab4);
	RUN_TEST(test_Tab5);
	//RUN_TEST(test_<testCaseName>);
	return UNITY_END();
}