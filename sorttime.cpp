//Sadie Jungers
//timer for sorts in sort.cpp
#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
#include"sort.h"
using namespace std;

//const int M=30;
const int M=10;
int data[M];
int sorter[M];

typedef struct{
	string name;
	void (*sort)(int[],int,int);
} TESTFIXTURE;

TESTFIXTURE tests[]= {
	{"Quick Sort",quick},
	{"Bubble Sort",bubble},
	//{"Shell Sort",shell},
	{"Selection Sort",selection},
	{"Heap Sort",heap},
};

int main(int arg,char* argv[]){
	fstream read(argv[1],ios_base::in);
	if(read.fail()){
		cout << "There was an error opening the data file.\n";
		return 1;
	}
	int k;
	for(k=0;k<M;k++){
		read >> data[k];
	} 
	int i,m=M;
	for(i=0;i<sizeof(tests)/sizeof(TESTFIXTURE);i++){
		int j;
		for(j=0;j<M;j++){
			sorter[j]=data[j];
		}
		clock_t t=clock();
		tests[i].sort(sorter,0,m-1);
		t=clock()-t;
		float time=t/CLOCKS_PER_SEC;
		cout << tests[i].name << " sort took " << time << " seconds (" << t << " ticks) to sort;\n";
		cout << "The first ten elements are: ";
		for(j=0;j<10;j++){
			cout << sorter[j] << " ";
		} 
		cout << endl;
	}
	read.close();
	return 0;
}
