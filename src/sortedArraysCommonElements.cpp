/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int common(char *str1, char *str2)
{
	int i = 0, j = 0, k, d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	while (str1[i] != '-' || str2[i] != '-')
	{
		d1 = (d1 * 10) + (str1[i] - '0');
		d2 = (d2 * 10) + (str2[i] - '0');
		i++;
	}
	j = i + 1;
	while (str1[j] != '-' || str2[j] != '-')
	{
		m1 = (m1 * 10) + (str1[j] - '0');
		m2 = (m2 * 10) + (str2[j] - '0');
		j++;
	}
	k = j + 1;
	while (str1[k] != '\0' && str2[k] != '\0')
	{
		y1 = (y1 * 10) + (str1[k] - '0');
		y2 = (y2 * 10) + (str2[k] - '0');
		k++;
	}
	if (y1 == y2 && m1 == m2 && d1 == d2)
		return 1;
	return 0;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL)
		return NULL;
	if (B == NULL)
		return NULL;
	if (A == B)
		return A;
	struct transaction *D=NULL;
	int i, j, x, k = 0;
	for (i = 0; i<ALen; i++)
	{
		for (j = 0; j<BLen; j++)
		{
			x = common(A[i].date, B[j].date);
			if (x == 1)
			{
				D = (struct transaction*)calloc(1, sizeof(struct transaction));
				D[k] = A[i];
				k++;
			}
		}
	}
	return D;

	
}