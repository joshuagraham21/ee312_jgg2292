/*
 * assignment5.c
 * SpellCheck
 */


/*
Student: Joshua Graham
UT EID: jgg2292
Section: Mengshi 1-2pm
Assignment: Assignment 5

*/

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
#include <stdlib.h>



/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I strongly encourage you to avoid big functions
 * (while there are always exceptions, a good rule of thumb is about 15 lines in a function).
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */

//TODO:
char int2LowerCase(int);


void spellCheck(char article[], char dictionary[])
{
	int word[200];
	char words[200];
	int flag, j, k,l, match = 0, i = 0;
	while (article[i] != '\0')
	{
		for (j = 0; j < 200; j++)
		{
			word[j] = -1;
		}
		for (l = 0; l < 200; l++)
		{
			words[l] = '\0';
		}
		if (letter_check(article[i]) == 1)
		{
			i = find_word(article, word, i);
			match = check_dictionary(word, dictionary);
			if (match == 0 && length(word) >= 2)
			{
				k = 0;
				while (word[k] != -1)
				{
					words[k] = int2LowerCase(word[k]);
					k++;
				}
				puts(words);
			}
		}
		else
		{
			i++;
		}
	}
}

int find_word(char article[], int word[], int i)
{
	int j = 0;
	while (letter_check(article[i]) != '\0')
	{
		word[j] = ASCII2Int(article[i]);
		j++;
		i++;
	}
	return i;
}

int letter_check(char c)
{
	int letter = 0;
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		letter++;
	}
	return letter;
}

int check_dictionary(int word[], char dictionary[])
{
	int dictionary_word[200];
	char dictionary_string[200];
	int match, j, k, i = 0, check = 0;
	while (dictionary[i] != '\0')
	{
		k = 0;
		for (j = 0; j < 200; j++)
		{
			dictionary_string[j] = '\0';
			dictionary_word[j] = -1;
		}
		if (letter_check(dictionary[i]) == 1 || dictionary[i] == 39)
		{
			while (dictionary[i] != '\n' && dictionary[i] != '\0')
			{
				dictionary_string[k] = dictionary[i];
				dictionary_word[k] = ASCII2Int(dictionary[i]);
				k++;
				i++;
			}
			match = compare(dictionary_word, word);
			if (match == 1)
			{
				return 1;
			}
		}
		else
		{
			i++;
		}
	}
	return 0;
}

int compare(int string1[], int string2[])
{
	int length1, length2, check = 1, i = 0;
	while (string1[i] != -1 && string2[i] != -1)
	{
		if (string1[i] != string2[i])
		{
			check = 0;
		}
		i++;
	}
	length1 = length(string1);
	length2 = length(string2);
	if (length1 != length2)
	{
		check = 0;
	}
	return check;
}

int length(int string[])
{
	int i = 0;
	while (string[i] != -1)
	{
		i++;
	}
	return i;
}

int ASCII2Int(char c)
{
	if (isUpperCase(c))
	{
		return c - 'A';
	}
	else if (isLowerCase(c))
	{
		return c - 'a';
	}
	else if (c == '\'')
	{
		return 9;
	}
	else
	{
		return -6;
	}
}

char int2LowerCase(int i)
{
	char c = 'a' + i;
	return c;
}

int isUpperCase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isLowerCase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}