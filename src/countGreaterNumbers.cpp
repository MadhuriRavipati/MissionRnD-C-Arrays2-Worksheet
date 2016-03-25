/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare(char *str1, char *str2)
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
	if (y1 > y2)
		return 1;
	if (y1 == y2)
	{
		if (m1 > m2)
			return 1;
		if (d1 > d1)
			return 1;
	}
	if (y1 < y2)
		return 0;


}


int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
  
	int i = 0, x, c = 0;
	if (len == 0)
		return -1;
	if (Arr == nullptr)
		return -1;
	for (i = 0; i<len; i++)
	{
		x = compare(Arr[i].date, date);
		if (x == 1)
			c++;
	}
	return c;
}
