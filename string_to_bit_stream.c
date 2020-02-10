#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* StrToBitStream(char *str){
	if(str==NULL){
		return 0;
	}
	int len = strlen(str);
	char* binary=(char *)malloc(len*8+1);	//1byte*len + null char

	for(int i=0;i<len;++i){
	char ch = str[i];
		for(int j=7;j>=0;--j){
			if(ch & (1<<j)){
				strcat(binary,"1");
			}else{
				strcat(binary,"0");
			}
		}
	strcat(binary," ");
	}
	return binary;

}


int main(){
char str[100],*rx;
printf("Enter a String: ");
scanf("%s",&str);

printf("\nString into Bit Stream: \n");
rx=StrToBitStream(str);
printf("%s\n\n",rx);
return 0;
}

