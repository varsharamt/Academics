#include<stdio.h>
#include<string.h>
#include<openssl/md5.h>
#include<stdlib.h>
#include <openssl/hmac.h>

void get_hash(char file_name[30]) {
     

     int i,bytes;
     FILE *fname,*hash;
     char *out = (char*)malloc(33);
     unsigned char c[MD5_DIGEST_LENGTH];
     unsigned char data[1024];

     fname=fopen(file_name,"rb");
     hash=fopen("hash.txt","a+");
     MD5_CTX mdc;
     MD5_Init(&mdc);

     while((bytes = fread(data,1,1024,fname))!=0)
	MD5_Update(&mdc,data,bytes);
     MD5_Final(c,&mdc);
     
     for(i=0;i<MD5_DIGEST_LENGTH;i++) {
        snprintf(&(out[i*2]), 16*2, "%02x", (unsigned int)c[i]);
     }
    // printf("\n%s",out);
     fprintf(hash,"%s\n",out);
     fclose(fname);
     fclose(hash);
} 
int main()
{

	 char command[10],file1[100],file2[100];

	 int ch,i = 0,j=0;
	 for(i = 0; i < 4; i++){
	     sprintf(command,"head -c 10 /dev/random > file%d",i);
	     system(command);
	 }

	 for(j = 0 ; j < 4 ; j++) {
	     sprintf(file1,"/home/vrt/Netsec_assnt2/file%d",j);
	     //printf("%s",file);
	     get_hash(file1);

	     //printf("\n");
	 }
	
	 return 0;
}

