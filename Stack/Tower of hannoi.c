#include<stdio.h>
void Hannoi(int, char, char, char);

void main(){
	int disk;
	printf("Enter Number of Disk: ");
	scanf("%d", &disk);
	int i;
 i = (pow(2,disk)-1);
 printf("No of Steps= %d\n", i);
	Hannoi(disk, 'A', 'C', 'B');
}
void Hannoi(int disk,char s,char d,char a){
	if (disk ==1){
	printf("move from %c to %c\n", s, d);}
	else{
		Hannoi(disk-1, s, a, d);
		printf("move from %c to %c\n", s, d);
		Hannoi(disk-1, a, d, s);
}
}
