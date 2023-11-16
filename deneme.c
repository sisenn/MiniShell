#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *i;
	void *j;
	int f = 48;
	i = malloc(sizeof(char) * 10 + 1);
	for(int q = 0; q < 10; q++)
	{
		i[q] = f++; 
	}
	j = &i;
	int g = 'a';
	printf("%s\n%s\n", i, j);
	char *w = malloc(sizeof(char) * 10 + 1);
	for(int q = 0; q < 10; q++)
	{
		w[q] = g++; 
	}
	printf("%s\n", w);
	i = w;
	printf(" %p = %s\n %p = %s\n %p = %s\n", &i, i, &j, j, &w, w);

}