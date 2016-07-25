#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
//Declare file pointer to access diffrent files
     FILE *fp1,*fp2,*fp3,*mri,*nmri,*io,*output;
  	 int j=0,lc=0,start,k=1,binary,length;
	 char v1[10],v2[10],v3[10],a1[10],b1[10],a2[10],b2[10],a3[10],b3[10],a4[10],b4[10],ch[4],c;

	 fp1=fopen("input.txt","r"); //accessing input.txt
	 fp2=fopen("symbol.txt","r");//accessing symbol.txt
	 fp3=fopen("out.txt","w");//accessing out.txt (in out.txt file hexadecimal code of program is stored)

	 mri=fopen("mri.txt","r");//accessing MRI table
	 nmri=fopen("nmri.txt","r");// accessing non MRI table
	 io=fopen("io.txt","r");//Accessing input output table

	 fscanf(fp1,"%s%s",v1,v2);
	 if(strcmp(v1,"ORG")==0){
		   start=atoi(v2);
		   lc=start;
		   
	  }
	 else
		  lc=0;
	 fscanf(fp1,"%s",v1);
	 while(strcmp(v1,"HLT")!=0){k=1;
		fseek(mri,0,SEEK_SET);//Seek to start of file
		while(!feof(mri)){
			fscanf(mri,"%s%s",a2,b2);
			if(strcmp(v1,a2)==0){
				fscanf(fp1,"%s",v2);
				strcat(v2,",");k=0;//Writing hexadecimal code to out.txt
				break;
				}
		}

		fseek(nmri,0,SEEK_SET);//Seek to start of file
		while(!feof(nmri)){
			fscanf(nmri,"%s%s",a3,b3);
			if(strcmp(v1,a3)==0){
				fprintf(fp3,"%s\n",b3);k=0;//Writing hexadecimal code to out.txt
				break;
				}
		}

		fseek(io,0,SEEK_SET);//Seek to start of file
		while(!feof(io)){
			fscanf(io,"%s%s",a4,b4);
			if(strcmp(v1,a4)==0){
				fprintf(fp3,"%s\n",b4);k=0;//Writing hexadecimal code to out.txt
				break;
				}
		}

		fseek(fp2,0,SEEK_SET);//Seek to start of file
		while(!feof(fp2)){
			fscanf(fp2,"%s%s",a1,b1);
			if(strcmp(v2,a1)==0){
				fprintf(fp3,"%s%s\n",b2,b1);//Writing hexadecimal code to out.txt 
				v2[0]=' ';k=0;
				break;
				}
		}
    	if(k==1) 
	    	printf("\nError in code\n");

       lc++;
	   fscanf(fp1,"%s",v1);
	}
	length=lc-start;	
	fprintf(fp3,"%s\n","7001");
	fcloseall();

	printf("\nThe contents of Input Table :\n");

  fp1=fopen("input.txt","r");
  c=fgetc(fp1);

  while(c!=EOF){
    printf("%c",c);
    c=fgetc(fp1);
   }
	fp3=fopen("out.txt","r");

//Output Binary Code
	printf("\nBinary Code\n");
	while(!feof(fp3)){
		fscanf(fp3,"%s",ch);
		for(j=0;j<4;j++){
           switch(ch[j]){
			//converting hexadecimal to binary
             case '0': printf("0000 "); break;
             case '1': printf("0001 "); break;
             case '2': printf("0010 "); break;
             case '3': printf("0011 "); break;
             case '4': printf("0100 "); break;
             case '5': printf("0101 "); break;
             case '6': printf("0110 "); break;
             case '7': printf("0111 "); break;
             case '8': printf("1000 "); break;
             case '9': printf("1001 "); break;
             case 'A': printf("1010 "); break;
             case 'B': printf("1011 "); break;
             case 'C': printf("1100 "); break;
             case 'D': printf("1101 "); break;
             case 'E': printf("1110 "); break;
             case 'F': printf("1111 "); break;
		  }
       }
	   printf("\n");
    }
}

