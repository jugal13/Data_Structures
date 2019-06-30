#include <stdio.h>
#include <string.h>
int nfind(char *string,char *pat) {
	int i,j,start=0;
	int lasts=strlen(string)-1;
	int lastp=strlen(pat)-1;
	int endmatch=lastp;
	for(i=0;endmatch<=lasts;endmatch++,start++) {
		if(string[endmatch]==pat[lastp])
				for(j=0,i=start;j<lastp && string[i]==pat[j];i++,j++);
		if(j==lastp)
			return start;
	}
	return -1;
}
int main() {
	char string[50],pat[50];
	printf("enter the string\n");
	scanf("%s",string);
	printf("enter pattern\n");
	scanf("%s",pat);
	printf("pos of match is %d\n",nfind(string,pat)+1);
	return 0;
}