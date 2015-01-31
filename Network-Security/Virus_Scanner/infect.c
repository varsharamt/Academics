#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main()
{

	int ch;	
	 char *path0="/home/vrt/Netsec_assnt2/file0";

	 FILE *infected,*original;
	 
	 infected = fopen(path0,"a+");
	 original = fopen("hello","r");

         while ((ch = fgetc(original)) != EOF) {  
	      fprintf(infected,"%c",ch);
	 }
	 
	 fclose(infected);
	 fclose(original);
	
	 return 0;
}

