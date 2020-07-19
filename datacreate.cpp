#include<stdio.h>
int main()
{
	FILE *f;
	f=fopen("database.csv","w");
	fprintf(f,"%s,\n","0");
	fclose(f);
}
