#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
int isKeyword(char buffer[]){ //check if keyword return 1 else 0
    char keywords[33][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int i, flag = 0;
    
    for(i = 0; i < 32; ++i){ //loop for keywords
        if(strcmp(keywords[i], buffer) == 0){  // compare keyword with buffer 
            flag = 1;//flag =1 if keyword
            break;
        }
    }
    
    return flag;
}

int isoperator(char ch){
int flag ,i;
char operators[] = "+-*/%=^><";
	for(i=0;i<9;i++){
		if(ch==operators[i]){
			flag=1;
			}
}
	return flag;
}
 
 int isnum(char buffer[]){
  int length,i;
  int flag=0; 
	
    length = strlen (buffer);
    if (isdigit(buffer[0])) {
    	for (i=0;i<length; i++){
		
        	if (isdigit(buffer[i]))
        	{
            flag=1;
        		}
   
	}
     	return flag ;
}}
int isSeparator(char ch){
	int flag ,i;
char Separator[] = ",;(){}";
	for(i=0;i<6;i++){
		if(ch==Separator[i]){
			flag=1;
			}
}
	return flag;
	
}
int main(){
    char ch, buffer[15];
    FILE *fp; //pointer to file 
    int i,j=0;
    char disaalawed[11]="_1234567890";
    
    fp = fopen("New Text Document.txt","r"); //read from file 
    
    if(fp == NULL){ //if file is empty 
        printf("error while opening the file\n");
        exit(0);
    }
    
    while((ch = fgetc(fp)) != EOF){ //checck not end of file & scan it 
            if(isoperator(ch)==1){//check for oerator
            	printf("%c ----> operator\n", ch);
        }
         if(isSeparator(ch)==1){//check for oerator
            	printf("%c ----> Separator\n", ch);
        }
           
           if((isalnum(ch)) || (ch =='_')||(ch =='.')){ // check if it is alpha numeric
               buffer[j++] = ch;
           }
           else if((ch == ' ' || ch == '\n') && (j != 0)){ //not detected
                   buffer[j] = '\0';
                   j = 0;
                                      
                   if(isKeyword(buffer) == 1) //check keywords
                       printf("%s ---> keyword\n", buffer);
                   else if (isnum(buffer)==1 )
                   	printf("%s ---> number\n", buffer);
				   else if (buffer[0]=='_'||'0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9')
				   		
					 printf("%s ---> indentifier\n", buffer);
          }
           
}
    
    fclose(fp);
    return 0;
}
