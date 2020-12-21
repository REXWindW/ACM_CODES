#include<stdio.h>
#include<string.h>
#define N 7
void sort(char *language[N]){
	int i,j;
	char t[50];
	for(i=0;i<N-1;i++){ 
		for(j=0;j<N-1-i;j++){ 
			if(strcmp(language[i],language[j])>0){
				strcpy(t,language[i]);
				strcpy(language[i],language[j]);
				strcpy(language[j],t);
			}
		}
	} 
}
void output(char *language[N]){
	int i;
	for(i=0;i<N;i++){
		printf("%s\n",language[i]);
	}
}
int main(){
	char* language[]={"PASCAL","BASIC","C/C++","Fortran","Turbo C","JAVA"};
	sort(language);
	output(language);
	return 0;
}