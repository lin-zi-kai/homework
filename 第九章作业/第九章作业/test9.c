#define _CRT_SECURE_NO_WARNINGS
//6.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
void str_copy(char* ss, char* ds)
{
	ds = (char*)calloc(MAX, sizeof(char));//(char*)malloc(sizeof(char)*MAX)
	for (; *ss != '\0'; ss++, ds++) {
		*ds = *ss;
	}
	*ds = '\0';
}
void str_linky(char* ss, char* ds)
{
	int i = 0, j = 0;
	ds = (char*)calloc(MAX, sizeof(char));
	while (*ds != '\0')i++;
	while (*ds != '\0')*ds = *ss;

}
int str_comp(char* ss, char* ds)
{
	int i = 0, q;
	while (*ds != '\0' && *ds == *ss)
		i++;
	if (*ds == *ss)q = 0;
	else if (*ds > *ss)q = 1;
	else q = -1;
	return q;
}
//
int str_length(char* ss)
{
	int i = 0;
	while (*ss != 0)
	{
		i++;
	}
	return i;
}

