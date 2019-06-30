#include <stdio.h>
void Sort(int A[],int n) {
	int i,j,min,temp;
	for(i=0;i<n;i++) {
		min=i;
		for(j=i+1;j<n;j++) {
			if(A[j]<A[min])
				min=j;
		}
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
	}
}
int Search(int A[],int low,int high,int key) {
	int mid,i,j;
	mid=(low+high)/2;
	if(A[mid]==key)
		return mid+1;
	else if(A[mid]>key)
		return Search(A,low,mid-1,key);
	else if(A[mid]<key)
		return Search(A,mid+1,high,key);
	else
		return -1;
}
int main() {
	int A[100],i,j,n,pos,key;
	printf("Enter number of elements:\n");
	scanf("%d",&n);
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("\nEnter the element to be searched for:\n");
	scanf("%d",&key);
	Sort(A,n);
	printf("\nSorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);
	printf("\n");
	pos=Search(A,0,n-1,key);
	if (pos==-1)
		printf("Element not found\n");
	else
		printf("Element found at %d\n",pos);
	return 0;
}