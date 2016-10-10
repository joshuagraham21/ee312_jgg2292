// ConsoleApplication5.c : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#define BEGIN_FCN {
#define END_FCN }

#include "stdafx.h"
#include "stdio.h"
#include <string.h>

void read_process(FILE *, char *, int *);
void get_fcn_name(char *, char *, int);
void name_fcn(char *, char *, int);

int main(void)
{
	FILE * fp;
	char file_name[200];
	char str_in[200];
	int counter[4]; // counter[0] refers to the number of functions in the program
					// counter[1] refers to the number of C instructions in the program
	int i;
	counter[0] = 0;
	counter[1] = 0;

	printf("File Counting Summary Table\n\n");
	printf("Filename: ");
	gets(file_name);
	while (strcmp(file_name, "STOP") != 0)
	{
		fp = fopen(file_name, "r");
		if (fp == NULL)
		{
			printf("File cannot be opened.\n");
		}
		else
		{
			printf("Function Name			# of Lines of Code\n");
			read_process(fp, str_in, counter);
			if (counter[0] == 0)
			{
				printf("There are no functions in this program.\n");
				fclose(fp);
			}
			else if (counter[2] != counter[3])
			{
				printf("\nThere is a mismatch error.\n");
				fclose(fp);
			}
			else
			{
				printf("Total number of functions: %d\n", counter[0]);
				printf("Total lines of code: %d\n\n", counter[1]);
				for (i = 0; i < 4; i++)
				{
					counter[i] = 0;
				}
				fclose(fp);
			}
		}
		printf("Enter Filename: ");
		gets(file_name);
	}
	return 0;
}

void read_process(FILE *fp, char str[200], int my_array[4])
{
	int i, size, old_size, current, j, bfcn_flag = 0, cmnt_flag = 0, qflag = 0, last = 0;
	char name[200];
	char copy[200];
	char string[5];
	while (fgets(str, 200, fp) != NULL)
	{
		size = 0;
		while (str[size] != NULL)
		{
			size++;
		}
		if (strcmp(str, "BEGIN_FCN\n") == 0)
		{
			my_array[0]++;
			my_array[2]++;
			last = my_array[1];
			get_fcn_name(name, copy, old_size);
			bfcn_flag = 1;
		}
		else if (strcmp(str, "END_FCN\n") == 0)
		{
			current = my_array[1] - last;
			my_array[3]++;
			printf("				%d\n", current);
			bfcn_flag = 0;
		}
		else
		{
			for (i = 0; i < size; i++)
			{
				if (str[i] == ';' && bfcn_flag == 1 && cmnt_flag == 0 && qflag == 0)
				{
					my_array[1] = my_array[1] + 1;
				}
				else if (str[i] == '\"' && qflag == 0)
				{
					qflag = 1;
				}
				else if (str[i] == '\"' && qflag == 1)
				{
					qflag = 0;
				}
				else if ('/' == str[i] && '/' == str[i - 1])
				{
					i = size;
				}
				else if ('*' == str[i] && '/' == str[i - 1])
				{
					cmnt_flag = 1;
				}
				else if ('/' == str[i] && '*' == str[i - 1])
				{
					cmnt_flag = 0;
				}
			}
		}
		strcpy(name, str);
		old_size = size;
	}
}

void get_fcn_name(char original[200], char copy[200], int size)
{
	int i, k, j, l;
	for (i = 0; i <= size; i++)
	{
		if (original[i] == ' ')
		{
			j = i + 1;
		}
		if(original[i] == '(' )
		{
			k = i;
			i = size;
		}
	}
	for (l = j; l < k; l++)
	{
		printf("%c", original[l]);
	}
}

/*
void name_fcn(char name[200], char copy[200], int i)
{
	int j, k = 0;
	char x;
	while (name[k] != ' ')
	{
		copy[k] = name[i - k];
	}
	for (j = 0; j <= k; j++)
	{
		x = copy[j];
		copy[j] = copy[k - j];
		copy[k - j] = x;
	}
}
*/