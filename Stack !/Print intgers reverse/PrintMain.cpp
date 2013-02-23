#include"Stack.h"
#include"IMPStack.cpp"

int split(int k){
	int counter=0;
	while(k){
		k=k/10;
		counter++;
	}
	
	return counter;
}

void pushtoSpilt(StackOfIntger &st,int k){
	
	while(k && !st.IsFull()){
		st.push(k%10);
		k=k/10;
	}
}
void PopNumber(StackOfIntger &st,int k){
	 int size=split(k);
	int *Arr=new int[size];
	int i=0;
	while(!st.IsEmpty()){
Arr[i++]=st.pop();
	}
	for( i=size-1;i>=0;--i){
	cout<<Arr[i];
	}
	
}


void main(){
	int k;
	while(k!=0){
	cout<<"\n\n\n\nEnter number you want... !"<<endl;
	cin>>k;
	stack <int> st(split(k));
	pushtoSpilt(st,k);
	PopNumber(st,k);
	
	}	
}