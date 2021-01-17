#include<stdio.h>
int a[100000+100];
void quicksort(int l,int r){
	int i=l,j=r,t;
	int mid=a[(r+l)/2];
	while(i<=j){
		while(a[i]<mid){
			i++;
		}
		while(a[j]>mid){
			j--; 
		}
		if(i<=j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;
			j--;
		}
	}
	if(i<r) quicksort(i,r);
	if(l<j) quicksort(l,j);
}
int main(){
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]); 
	}
	quicksort(0,n-1);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
