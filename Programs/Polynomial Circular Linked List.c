#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y) ((x==y)?0:(x>y)?1:-1)
struct node {
	float coeff;
	int exp;
	struct node* link;
};
typedef struct node* polypointer;
void attach(float coefficient,int exponent,polypointer *ptr) {
	polypointer temp;
	temp=(polypointer)malloc(sizeof(struct node));
	temp->coeff=coefficient;
	temp->exp=exponent;
	(*ptr)->link=temp;
	*ptr=temp;
	(*ptr)->link=NULL;
}
polypointer readpoly() {
	int n,i,expon;
	float coef;
	polypointer k,endK;
	k=(polypointer)malloc(sizeof(struct node));
	k->exp=-1;
	printf("enter the number of terms for polynomial\n");
	scanf("%d",&n);
	endK=k;
	for(i=0;i<n;i++) {
		printf("enter the coefficient\n");
		scanf("%f",&coef);
		printf("enter the exponenet\n");
		scanf("%d",&expon);
		attach(coef,expon,&endK);
	}
	endK->link=k;
	return k;
}
polypointer cadd(polypointer a,polypointer b) {
	polypointer c,lastC,startA;
	int sum,done=0;
	startA=a;
	a=a->link;
	b=b->link;
	c=(polypointer)malloc(sizeof(struct node));
	c->exp=-1;
	lastC=c;
	do {
		switch(COMPARE(a->exp,b->exp)) {
			case 1: 	attach(a->coeff,a->exp,&lastC);
								a=a->link;
								break;
			case 0: 	if(startA==a)
									done=1;
								else {
									sum=a->coeff+b->coeff;
									if(sum)
										attach(sum,a->exp,&lastC);
									a=a->link;
									b=b->link;
								}
								break;
			case -1:	attach(b->coeff,b->exp,&lastC);
								b=b->link;
								break;
		}
	}while(!done);
	lastC->link=c;
	return c;
}
void printPoly(polypointer k) {
	k=k->link;
	while(((k->link)->exp)!=-1) {
		printf("%fx^%d + ",k->coeff,k->exp);
		k=k->link;
	}
	printf("%fx^%d",k->coeff,k->exp);
	printf("\n");
}
int main() {
	polypointer a,b,c,endA,endB;
	a=readpoly();
	b=readpoly();
	c=cadd(a,b);
	printf("First Polynomial is\n");
	printPoly(a);
	printf("Second Polynomial is\n");
	printPoly(b);
	printf("Addition of two polynomials is\n");
	printPoly(c);
	return 0;
}