#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<crypt.h>
#include<unistd.h>
int main() {
	 int i,j=0;
	 FILE *f1,*f2,*f3,*f4,*f5;
	 ssize_t read,read1;  
	 char *l1 = NULL, *l2=NULL, *passwd;
	 char* salt = "$1$GC";
	 size_t len1 = 0,len2 = 0;  
	 char b[20],a[20],c[20],d[20],e[20];


	 f1 = fopen("top250.txt","r"); 
	 f2 = fopen("extracted.txt","w");

	 if (f1 == NULL)
		exit(EXIT_FAILURE);
	 if(f2 == NULL)
		exit(EXIT_FAILURE);
	 while ((read = getline(&l1, &len1, f1) != -1) ) {
	        sscanf(l1,"%s%s%s%s",a,b,c,d);
        	fputs(d,f2);
	        fputc('\n',f2);
	
	}
	
	free(l1);
	fclose(f1);
	fclose(f2);

	f3 = fopen("passwordfile.txt","r");
	f4 = fopen("extracted.txt","r");
	f5 = fopen("output.txt","w");
	
	while(fscanf(f4,"%s",e) != -1) {
	    passwd = crypt(e,salt);
	    fputs(passwd,f5);
	    fputc('\n',f5);
	} 

	free(l2);
	fclose(f3);
	fclose(f4);
	fclose(f5);

	exit(EXIT_SUCCESS);
	return 0;
}	
