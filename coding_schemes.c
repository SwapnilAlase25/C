#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
char bits[100];
int i,n;
char s='L';
printf("Enter the bit stream: ");
gets(bits);
n=strlen(bits);
printf("\n\t NRZ : \t\t");
for(i=0;i<n;i++){
	if(bits[i]=='0'){
		printf("L ");
	}else{
		printf("H ");
	}
   }

printf("\n\n\t NRZL : \t");
for(i=0;i<n;i++){
	if(bits[i]=='0'){
		printf("H ");
	}else{
		printf("L ");
	}
   }

printf("\n\n\t NRZI : \t");
printf("L ");
for(i=1;i<n;i++){
	if(bits[i]=='1'){
		if(s=='H'){
		s='L';
		}
		else		
		s='H';
	}
	printf("%c ",s);
   }


printf("\n\n\t Polar Manchester : \t");
for(i=0;i<n;i++){
	if(bits[i]=='0'){
		printf("HL");
	}else{
		printf("LH");
	}
   }

printf("\n\n");
return 0;
}
