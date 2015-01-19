#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 
void main() {
	
	int i;
	FILE *f1,*f2,*f3,*f4;
	ssize_t read1, read2;  
        char *l1 = NULL, *l2 = NULL;
        size_t len1 = 0,len2 = 0;     
		     
	f1 = fopen("shadow.txt","r"); 
	f2 = fopen("passwd.txt","r");
	f3 = fopen("passwordfile.txt","w");
	f4 = fopen("hashvalue.txt","w");
	
	if (f1 == NULL)
		exit(EXIT_FAILURE);
	if (f2 == NULL)
		exit(EXIT_FAILURE);
	if (f3 == NULL)
		exit(EXIT_FAILURE);
	if (f4 ==NULL)
		exit(EXIT_FAILURE);
			
	while ((read1 = getline(&l1, &len1, f1) != -1) && (read2 = getline(&l2, &len2, f2) != -1) ) {
	   for(i=0;i<36;i++) {
		fputc(l1[i],f3);
	   }
	   for(i=9;i<strlen(l2);i++) {
		fputc(l2[i],f3);
	   }
	   for(i=0;i<36;i++) {
	        fputc(l1[i],f4);
	   }
	   fputc('\n',f4);
	}
	
	free(l1);
	free(l2);
	fclose(f1);			 
	fclose(f3);
	fclose(f2);

	exit(EXIT_SUCCESS);
}
