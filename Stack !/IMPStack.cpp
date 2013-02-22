#include<iostream>
using namespace std;

StackOfIntger::StackOfIntger(int n){
	top=-1;
	size=n;
	element=new int[size];
	
}
StackOfIntger::~StackOfIntger(){
	delete []element;
}
int StackOfIntger::IsFull(){
	return top==size-1;
}
int StackOfIntger::IsEmpty(){
	return top==-1;
}
void StackOfIntger::push(int n){
	if(!IsFull())
		element[++top]=n;
	else
		cerr<<"Stack is Full !"<<endl;
	return;
}
int	 StackOfIntger::pop(){
	if(!IsEmpty()){
int temp=element[top--];
return temp;
	}
	else{
cerr<<"Stack Is Empty ! ,Press any Key ..."<<endl;
return false;
	}
}
int StackOfIntger::TopElement(){
if(!IsEmpty())
return  element[top];
else
cerr<<"Stack Is Empty !"<<endl;
return -1;
	

}
