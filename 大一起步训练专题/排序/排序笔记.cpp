//几种排序算法 真的烦 

#include<iostream>
using namespace std;

const int MANX=100000;

int a[MANX];
int tmp[MANX];
int n;

void Bubblesort(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n-1;j++){
			if(a[j]<a[i]){
				swap(a[j],a[i]);
			}
		}
	}
} 

void Selectsort(){
	int i,j;
	int m,now;
	for(i=0;i<n-1;i++){
		int m=a[i],now=i;
		for(j=i+1;j<n;j++){
			if(m>a[j]){
				now=j; m=a[j];
			}
		}
		swap(a[i],a[now]);
	}
} 

void Parallel(int u,int mid,int v){   
    int pb=0; int pu=u, pm=mid+1, pv=v;
    while( pu<pm && pm<pv ){
    	if( a[pu] > a[pm] ) tmp[pb++] = a[pm++];
    	else tmp[pb++] = a[pu++];
    }
    while(pu<=mid) tmp[pb++] = a[pu++];
    while(pm<=v) tmp[pb++] = a[pm++];
    for(int i=0;i<v-u+1;i++){
    	a[u+i]=tmp[i];
    }
}

void Mergesort(int u,int v){
	if(v>u){
		int mid=u+(v-u)/2; 
	    Mergesort(u,mid);
	    Mergesort(mid+1,v);
	    Parallel(u,mid,v);
	}
}

void Quicksort(int u,int v){
	if(u>=v)  return;
	int k=a[u];
	int i=u,j=v;
	while(i!=j){
		while(i<j && a[j]>=k) j--;
		swap(a[i],a[j]);
		while(i<j && a[i]<=k) i++;
		swap(a[i],a[j]);
	}
	Quicksort(u,i-1);
	Quicksort(i+1,v);
}

void input(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}
void output(){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(){
	input();
	
	//Bubblesort();  
	//Selectsort();        
	//Mergesort(0,n-1);   
	Quicksort(0,n-1);
	output();
	return 0;
} 