#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
using namespace std;



//constructer 
listOfStudents::listOfStudents(){
		Current_Size=0;
	first=NULL;
	}

// great List
node* listOfStudents::Build (int NumberOfNode){
	node *last;
	node *temp;
	cout<<"Enter Name,ID,score Of student :"<<endl<<endl;
	cout<<"Name	 ID	 Score "<<endl;
	first=new node;
	cin>>first->name;
	cin>>first->ID ;
	cin>>first->score;
	last=first;
	Current_Size++;
	
	
	for(int i=1;i<NumberOfNode;i++){
		temp=new node;
		cin>>temp->name>>temp->ID>>temp->score;
		last->next=temp;
		last=temp;
		Current_Size++;
	}
	temp->next=NULL;
	
	return temp;
}


//Build from File 
node *listOfStudents::BuildFromFile(string fileName){
	
	ifstream Get(&fileName[0]);
	if(!Get){cerr<<"Invalid name Of file ! try again !\n\n\n"; return 0; }

	first=new node;	
	node *temp;
	node *last ;

                Get>>first->name;
		Get>>first->ID;
		Get>>first->score;
		last=first;
Current_Size++;
		while(!Get.eof()){
		temp=new node;
	
		
		Get>>temp->name;
		Get>>temp->ID;
		Get>>temp->score;
		
		last->next=temp;
		last=temp;
		Current_Size++;
	}
	temp->next=NULL;

	
	return temp;
	
	
	
}

// ~Free 
listOfStudents::~listOfStudents (){
	
	RecursionDeleteAll(1);
	
}//destructor




// print
void listOfStudents::print(){
	
	node *p;
	cout<<"Name"<<"		"<<"ID"<<"		"<<"Score"<<endl;
	for(p=first;p;p=p->next){
		cout<<p->name<<"	"<<p->ID<<"		"<<p->score<<endl;
}}

// Size Of list 
int listOfStudents::SizeofList(){
				return Current_Size ;
				
}

// Delete node;

void listOfStudents::DeleteNode(int n){
	if(n<1 || n>SizeofList()){cerr<<"Invalid node ";}
	
	if(n==1){
		node *r=first;
		first=r->next;
		delete r;
		Current_Size--;
	}
	else {
		node *p,*r;
		int Counter=1;
		
		for(p=first;Counter!=n-1;p=p->next,Counter++);
		r=p->next;
		p->next=r->next;
		delete r;
		Current_Size--;
	}
}


// Add new Node 
void listOfStudents::AddNewNode(int n){
	if(n<1 || n>(SizeofList()+1)){cerr<<"Invalid node ";}
	node *p=new node;
	cout<<"Enter New element node Name , ID , score "<<endl;
	cin>>p->name>>p->ID>>p->score;
	if(n==1){
		p->next=first;
		first=p;
		Current_Size++;
	}
	else {
		int Counter=1;
		node *r;
		for(r=first;Counter!=n-1;r=r->next,Counter++);
		p->next=r->next;
		r->next=p;
		Current_Size++;
	}
}


node* listOfStudents::CopyList(){
	if(first==NULL){return NULL;}
	else{
		node *Copy=new node;
		
		Copy->name=first->name;
		Copy->ID=first->ID;
		Copy->score=first->score;
		
		node *last=Copy;
		node *p=first;
		while(p){
			node *temp=new node;
			
			temp->name=p->name;
			temp->ID=p->ID;
			temp->score=p->score;
			
			last->next=temp;
			last=temp;
			p=p->next;	
		}last->next=NULL;
		return Copy;	
}}



// Middle
void listOfStudents::MiddleOfList(){
	node *p;
	node *r;
	int Counter=1;
	
	if(Current_Size % 2 != 0){
		for(p=first;Counter !=(Current_Size/2);p=p->next,Counter++);
		r=p->next;
		cout<<r->name<<"	"<<r->ID<<"		"<<r->score;
	}
	else {
		
		for(p=first;Counter !=((Current_Size/2)-1);p=p->next,Counter++);
		r=p->next;
		cout<<r->name<<"	"<<r->ID<<"		"<<r->score;
}}


// AVG

double listOfStudents::average(){
	double sum=0;
	double avg=0;
	node *p;
	for(p=first;p;p=p->next){
		sum+=p->score;
		avg=sum/Current_Size;
	}
	return avg;
}


//Max Score 
double listOfStudents::maxScore(){
	
	node *p=first;
	double Max=p->score;
	int max=p->score;
	while(p){
		
		if(p->score > Max ){
			Max=p->score;
			
		}
		p=p->next;
	}
	
	return Max;
	
}


// Delete All 
void listOfStudents::RecursionDeleteAll(int x){
	node *p=first;
	if(p==NULL) return ;
	DeleteNode(x);
	RecursionDeleteAll(x);
	
	
	
}

