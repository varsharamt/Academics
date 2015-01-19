#include<string.h>
#include<crypt.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main() {

	int i=0,j;
	FILE *f1,*f2,*f3,*f4;
	size_t read1, read2;  
	char *l1 = NULL, *l2 = NULL,*str,*passwd;
	size_t len1 = 0,len2 = 0;  
	char username[10],hash[30],a[20];
	clock_t begin, end;
	double time_spent;

	f1 = fopen("extracted.txt","r"); 
	f3 = fopen("allcrackedpasswords.txt","a");

	if (f1 == NULL)
	   exit(EXIT_FAILURE);
	if (f3 == NULL)
	   exit(EXIT_FAILURE);

	begin = clock();

	while (fscanf(f1,"%s",a)!=EOF) {
	    
	    passwd = crypt(a,"$1$GC");
	    f2 = fopen("hashvalue.txt","r");
	    while(read2 = getline(&l2,&len2,f2)!=-1) {	        
		    
		str=strtok(l2,":");
		while((str != NULL)&&(i<2)) {
			 
		    if(i==0) {
			sscanf(str,"%s",username);
			str = strtok(NULL, ":");
		    }
		    else if(i==1) {
			sscanf(str,"%s",hash);
			str = strtok(NULL, ":");
		    }
		    i++;
		}
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

          	if(!strcmp(hash,passwd)) {
		    
		    //printf("%f : %s : %s\n",time_spent,username,a);
		    fprintf(f3,"%f : %s : %s\n",time_spent,username,a);
		    begin=end;	
		}
		i=0;
			
	    }	
	
	}
	
	free(l1);
	free(l2);
	fclose(f1);			 
	fclose(f3);
	fclose(f2);

}
