#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
	 char v1[10],v2[10],v3[10],a3[10],b3[10],a4[10],b4[10],ch;
	 int lc,start,length,i=0;
//Declare file pointer to access diffrent files
	 FILE *fp1,*fp2,*nmri,*io;
	 fp1=fopen("input.txt","r");//fp1 for input.txt file
	 fp2=fopen("symbol.txt","w");//fp2 for accessing symbol.txt file
	 nmri=fopen("nmri.txt","r");//nmri for accessing nmri.txt(for non MRI instruction) file
	 io=fopen("io.txt","r");	//Input-output instruction file

	 fscanf(fp1,"%s%s",v1,v2);
	 if(strcmp(v1,"ORG")==0){
		   start=atoi(v2);
		   lc=start;
		   fscanf(fp1,"%s",v1);
	  }

	 while(strcmp(v1,"END")!=0){i=0;
		if(v1[3]==','){
			  fprintf(fp2,"%s\t%d\n",v1,lc);
			  fscanf(fp1,"%s%s",v2,v3);
		}
	    else if(v1[3]!=','){

			fseek(nmri,0,SEEK_SET);//Seek to start of file
			while(!feof(nmri)){
				fscanf(nmri,"%s%s",a3,b3);
				if(strcmp(v1,a3)==0){i++;
					break;
				}
			}

			fseek(io,0,SEEK_SET);//Seek to start of file
			while(!feof(io)){
				fscanf(io,"%s%s",a4,b4);
				if(strcmp(v1,a4)==0){i++;
					break;
					}
			}

			if(i==0)
				fscanf(fp1,"%s",v2);
	    }
       lc++;
	   fscanf(fp1,"%s",v1);
  }
	  fcloseall();
//output all the content
 	  length=lc-start;
	  printf("\nThe length of the program is %d.\n",length+2); //length+2 (including ORG and END instruction)
	  printf("\nThe contents of Input Table is stored in input.txt\n");
	  printf("The contents of Symbol Table is stored in symbol.txt\n\n");
	 
}
