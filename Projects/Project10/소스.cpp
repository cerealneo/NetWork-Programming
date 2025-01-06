#include <stdio.h>
#include <iostream>

int main() {

	char str1[] = "HelloWorld";
	char str2[20] = "HelloWorld"; 
	const char* str3 = "HelloWorld";

	printf("sizeof(str1) : % d\n", (int)sizeof(str1));
	printf("sizeof(str2) : % d\n", (int)sizeof(str2));
	printf("sizeof(str3) : % d\n", (int)sizeof(str3));

	printf("strlen(str1) : % d\n", (int)strlen(str1));
	printf("strlen(str2) : % d\n", (int)strlen(str2));
	printf("strlen(str3) : % d\n", (int)strlen(str3));

	printf("printf(str1): %s\n", str1);
	printf("printf(str2): %s\n", str2);
	printf("printf(str3): %s\n", str3);
}