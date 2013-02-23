#include<iostream>
using namespace std;

struct node {
	char element;
	node *next;
};



class List{
	public :
		List();
		char pop( );
		void push(int);
		
	private :
		node *top;
		int Current_Size;
		
};



List::List(){	 top=NULL; Current_Size=0; }

char List::pop( ){
char temp=top->element;
node *D=top;
top=top->next;
delete D;



		Current_Size--;
return temp;	
}

void List::push(int n){
node *temp=new node;
temp->element=n;
temp->next=top;
top=temp;	
		Current_Size++;
	
	
	

}



void main(){
	
}