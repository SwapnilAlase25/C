#include<stdio.h>
#include<string.h>
#define SIZE 100
///////////////////// bit stuffing //////////////////////////
char* BitStuffing(char *bit_stream){
int len=strlen(bit_stream),count=0,nl;
	for(int i=0;i<len;i++){
	count=0;
	// check if consecutive 6 1's are there
		for(int j=i;j<=i+5;j++){
			if(bit_stream[j]=='1'){
			count++;
			}
		}
	//add stuff bit
		if(count==6){
		nl=len+2;	// length of string + stuffed bit + null char
			for(;nl>=(i+5);nl--){
			bit_stream[nl]=bit_stream[nl-1];
			}
		bit_stream[i+5]='0';
		}

	}
	return bit_stream;
}

/////////////////// bit Destuffing /////////////////////////////////

char* BitDestuffing(char *bit_stuffed){
int len=strlen(bit_stuffed),count=0,nl,j;
	for(int i=0;i<len;i++){
	count=0;
	// check if consecutive 1111101 are there
			//11111
		for( j=i;j<=i+4;j++){
			if(bit_stuffed[j]=='1'){
			count++;
			}
		}
		if(count==5){		//01
			if(bit_stuffed[j]=='0' && bit_stuffed[j+1]=='1'){
				count=count+2;
			}
		}

	//remove stuff bit
		if(count==7){
		nl=strlen(bit_stuffed);			// length of string 
			for(int k=0;k<=nl;k++){
			if(k>=i+5){
				bit_stuffed[k]=bit_stuffed[k+1];
			    }
			}
		i++;
		}
	
	}
	return bit_stuffed;
}
/////////////////////////// main /////////////////////////////

void main(){
char *bit_stream=(char *)malloc(SIZE*sizeof(char)),*bit_stuffed,*bit_destuffed;
printf("Enter a Bit Stream of 1's and 0's : ");
gets(bit_stream);

printf("\nAfter Bit Stuffing : ");
bit_stuffed=BitStuffing(bit_stream);
printf("%s\n",bit_stuffed);

printf("\nAfter Bit Destuffing : ");
bit_destuffed=BitDestuffing(bit_stuffed);
printf("%s\n",bit_destuffed);
}
