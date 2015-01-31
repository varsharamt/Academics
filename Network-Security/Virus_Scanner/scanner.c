#include<stdio.h>
#include<string.h>
#include<openssl/md5.h>
#include<stdlib.h>
#include <openssl/hmac.h>

void hash_compute(char file_name[30]) {


     int i,bytes;
     FILE *fname,*hash;
     char *out = (char*)malloc(33);
     unsigned char c[MD5_DIGEST_LENGTH];
     unsigned char data[1024];

     fname=fopen(file_name,"rb");
     hash=fopen("hash_infect.txt","a+");
     MD5_CTX mdc;
     MD5_Init(&mdc);

     while((bytes = fread(data,1,1024,fname))!=0)
        MD5_Update(&mdc,data,bytes);
     MD5_Final(c,&mdc);

     for(i=0;i<MD5_DIGEST_LENGTH;i++) {
        snprintf(&(out[i*2]), 16*2, "%02x", (unsigned int)c[i]);
     }
     //printf("\n%s",out);
     fprintf(hash,"%s\n",out);
     fclose(fname);
     fclose(hash);
}

int main() {

	char file1[100],a[20],b[20];
	int j=0,check,k;
	FILE *hash1, *infected,*infected1;
//	   hash1 = fopen("hash.txt","r");
  //     infected = fopen("hash_infect.txt","r");

	for(;;) {
		  infected1 = fopen("hash_infect.txt","w");
		  //fclose(infected1);
	   for(j = 0 ; j < 4 ; j++) {
	     sprintf(file1,"/home/vrt/Netsec_assnt2/file%d",j);
	     hash_compute(file1);
	     printf("\n");
	   }
	
	 
	hash1 = fopen("hash.txt","r");
	infected = fopen("hash_infect.txt","r");
	k=0;
	while ((fscanf(hash1,"%s",a)!=EOF)&&(fscanf(infected,"%s",b)!=EOF)) {
	  //printf("%s\n",a);
	
	  if(strncmp(a,b,32)!=0) 
		printf("File%d is infected\n",k);
	  else 
	        printf("File%d is not Infected\n",k);
	  k++;
		
	}
	printf("\n");
	sleep(1);
	fclose(infected);
	 fclose(hash1);
	 fclose(infected1);
		
}
// fclose(infected);
  //        fclose(hash1);

}






