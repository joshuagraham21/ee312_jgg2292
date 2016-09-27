#include <stdio.h>
#include <stdlib.h>

/*
* Student Name: Graham, Joshua
* UT EID: jgg2292
* Unique Course Number: 16290
* Assignment Number: EE312-Assignmnet-2
*/


/*
 * return 1 if the ASCII interpretation of 
 * c is an upper case letter.  
 * return 0 otherwise
 */
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

/*
 * return 1 if the ASCII interpretation of
 * c is a lower case letter.
 * return 0 otherwise
 */
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

/*
 * return 1 c is an Alphabet.  
 * return 0 otherwise
 */
int isAlphabet(char c)
{
	return isUpperCase(c) || isLowerCase(c);
}

/*
 * if the ASCII interpretation of c is a letter, then
 * return a number between 0 and 25 indicating which letter of 
 * the alphabet c represents.  For example, if c is the ASCII
 * encoding for 'A', then we should return 0.  If c is the
 * ASCII encoding for 'e', then we should return 4.
 * if the ASCII interpretation of c is not a letter, then
 * return -1.
 */
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
	else 
	{ 
		return -1;
	}
}

/*
* assumes i is between 0 and 25 inclusive
*/
char int2UpperCase(int i)
{
	char c = 'A'+i;
	return c;
}

/*
* assumes i is between 0 and 25 inclusive
*/
char int2LowerCase(int i)
{
	char c = 'a'+i;
	return c;
}

/*
* This function takes in a message and computes the frequencies of all the alphabets
*/
void buildHistogram(char message[], int messageLength, int histogram[], int histogramLength)
{
	int i, j, letter, debug;
	int zero = 0;
	for (i = 0; i < histogramLength; i++)
	{
		histogram[i] = zero;
	}
	for (j = 0; j < messageLength; j++)
	{
		if (isAlphabet(message[j]) == 1)
		{
			letter = ASCII2Int(message[j]);
			histogram[letter]++;
		}
	}
}

/*
* This function computes the maximum value in an array and returns the index location\
* for which the maximum value occured
*/

int maxIndex(int myArray[], int arrayLength)
{
	int max_value, index, i, j, plurality;
	max_value = myArray[0];
	plurality = 0;
	index = 0;
	for (i = 0; i < arrayLength; i++)
	{
		if (myArray[i] > max_value)
		{
			max_value = myArray[i];
			index = i;
		}
	}
	return index;
}

/*
 * Encrypt the string s using the rotation cypher
 * Each letter in s should be shifted "shift" letters to the 
 * right.  For example, if "shift" is 2, then "a zebra" should be
 * changed to "c bgdtc".  Note that when shifting past the end
 * of the alphabet, we wrap around again to a.
 *
 * Only change the letters in s.  Do not change spaces, punctuation
 * or numbers in s.  
 * For full credit, you should keep upper case letters as 
 * upper case, and leave lower case letters as lower case.  So, if
 * s had been the string "a ZeBra", you should change s to be
 * "c BgDtc".
 */
void encrypt(char message[], int messageLength, int shift) 
{
	int i, letter, upper, lower;
	char temp;
	for (i = 0; i < messageLength; i++)
	{
		lower = isLowerCase(message[i]);
		upper = isUpperCase(message[i]);
		letter = ASCII2Int(message[i]);
		letter += shift;
		if (letter > 25)
		{
			letter -= 26;
		}
		if (letter < 0)
		{
			letter += 26;
		}
		if (lower == 1)
		{
			temp = int2LowerCase(letter);
		}
		else if (upper == 1)
		{
			temp = int2UpperCase(letter);
		}
		else
		{
			temp = message[i];
		}
		message[i] = temp;
	}
}

/*
 * return a number between 0 and 25 indicating which letter
 * of the alphabet is most common in the string s
 */
int mostFrequentLetter(char message[], int messageLength) 
{
	int histogram[26];
	int histogramLength, letter, i, index, lower, upper;
	histogramLength = 26;
	buildHistogram(message, messageLength, histogram, histogramLength);
	letter = maxIndex(histogram, histogramLength);
	for (i = 0; i < messageLength; i++)
	{
		index = ASCII2Int(message[i]);
		if (histogram[index] == histogram[letter])
		{
			letter = index;
			break;
		}
	}
	return letter;
}

void decrypt(char cypher[],int cypherLength, int common)
{
	int letter, shift, i, lower, upper;
	char temp;
	letter = mostFrequentLetter(cypher, cypherLength);
	shift = common - letter;
	encrypt(cypher, cypherLength, shift);
}	
