//Sadie Jungers
//Sort implementations
#include<iostream>
#include"sort.h"
#include "stackclass.h"
#include "trees.h"
using namespace std;

void shell(int ar[],int b,int t){
	int check=b;
	bool s=false,done=false;
	while(!done) {
		s=false;
		while(ar[check]<=ar[check+1] && check<t){
			check++;
		} if(ar[check]>ar[check+1]){
			if(check==t){
				check=0;
				continue;
			}
			swap(ar[check],ar[check+1]);
			s=true;
		} 
		if(check>=t){
			check=0;
			if(!s) done=true;
			continue;
		}
	} 
}

void bubble(int ar[],int b,int t){ ////IT WORKS :)
	int check=t;
	bool s=false,done=false;
	while(!done){
		while(ar[check]>=ar[check-1] && check>=b){
			check--;
		} if(ar[check]<ar[check-1]){
			if(check==b){
				check=t;
				continue;
			}
			swap(ar[check],ar[check-1]);
			s=true;
		} if(check<=b){
			check=t;
			if(!s) done=true;
			s=false;
			continue;
		}
	}

}

void selection(int ar[],int b,int t){ ///SUCCESS :)
	int check=b;
	int c=b;
	bool s=false,done=false;
	while(!done){
		while(ar[check]<=ar[c+1] && c<t){
			c++;
		} if(ar[c+1]<ar[check] && c<t){
			swap(ar[c+1],ar[check]);
			s=true;
		}
		if(c>=t){
			b++;
			check=c=b;
			if(!s) done=true;
			s=false;
		}
	}
}

void quick(int ar[],int b,int t){ //TADAAAA
	if(b>=t) return;
	int pivot;
	partition(ar,b,t,pivot);
	quick(ar,pivot+1,t);
	quick(ar,b,pivot-1);
}

void partition(int x[],int b, int t, int& pv){
	pv=b;
	int up,dn;
	dn=b;
	up=t;
	while(up>dn){
		while(x[up]>x[pv] && up>dn){
			up--;
		} while(x[dn]<=x[pv] && dn<up){
			dn++;
		}
	 if(x[dn]>x[up]) swap(x[dn],x[up]);
	}
	if(x[b]>x[dn]) swap(x[b],x[dn]);
 	pv=up;
	b++;
}

struct subarray {
		int lb;
		int ub;
};
void quicki(int ar[],int b,int t){ //ignore this
	subarray a;
	sstack<subarray> s;
	int len=t-b;
	a.lb=0;
	a.ub=len;
	s.push(a);
	while(!s.empty()){
		a=s.pop();
		int temp=a.ub;
		int pivot=(a.ub-a.lb)/2;
		partition(ar,a.lb,a.ub,pivot);
		a.lb=a.lb;
		a.ub=pivot-1;
		if(pivot-a.lb<2){
			continue;
		}
		s.push(a);
		a.lb=pivot;
		a.ub=temp;
		if(pivot-a.lb<2){
			continue;
		}
		s.push(a);
	}
}

void heap(int ar[],int b,int t){
	int i,a,f,s,max;
	/*for(i=b;i<=t;i++){ //code from the book
		a=ar[i];
		f=(i-1)/2;
		while(i>0 && ar[f] < a) {
			ar[i]=ar[f];
			//s=f;
			f=(i-1)/2;
		} 
		//ar[s]=a;
	}*/
	for(i=0;i<=t;i++){
		cout << ar[i] << " ";
	}
	cout << endl;
	for(i=t-1;i>0;i--){ //sift it
		max=ar[i];
		swap(ar[i],ar[0]);
		f=0;
		//s=i;
		if(i==1){
			s=-1;
		} else s=1;
		if(i>2 && ar[2]>ar[1]){
			s=2;
		}
		while(s>=2 && max < ar[i]){
			ar[f]=ar[i];
			f=s;
			s=2*f+1;
			if(s+1 <= i-1 && ar[s] <ar[s-1]){
				s+=1;
			} if(s>i-1){
				s=-1;
			}
		}
		ar[f]=max;
	}
}

/*void swap(Node*& a,Node*& b){
	Node* tmp=a;
	a=b;
	b=tmp;
}*/
void swap(int& a,int& b){
	int temp=a;
	a=b;
	b=temp;
}
