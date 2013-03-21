#include<iostream>
#include<string>
using namespace std;
#include<fstream>

struct car{
	string Manufacture;
	int ID;
	int Year;
	string Color;
	car *next;
};

class QueqeOfCars{
	
	
	friend ostream& operator<<(ostream &out,const QueqeOfCars &L){//Overload Print:
		cout<<"\n\n==================================================\n\n\n";
		car *p;
		out<<endl<<"Manu"<<"		"<<"ID"<<"		"<<"Color"<<"		"<<"Year"<<endl;
		
		for(p=(L.first);p;p=p->next){
			out<<p->Manufacture<<"	"<<p->ID<<"		"<<p->Color<<"		"<<p->Year<<endl;
		}
		cout<<"\n\n==================================================";
		return out;
	} 
public:
	QueqeOfCars(int n);//constructor 
	car DeleteCar(car *temp); // delete Cars;
	void InsertCar();//insert Car from KB
	int File_InsertCar(string &FileName); // insert car from File
	int IsEmpty();// check if Linked is Empty 
	int IsFull(); // check if Linked is Full
	int FindSize(); // find Size of Queqe 
	void print();// print Queqe 
	
private:
	int Current_Size;
	car *first;
	car *last;
	int limit;
};


void QueqeOfCars::print(){
	car   *p;
	cout<<"Manufacture"<<"		"<<"ID"<<"		"<<"Color"<<"		"<<"Year"<<endl;
	for(p=first;p;p=p->next){
		cout<<p->Manufacture<<"	"<<p->ID<<"		"<<p->Color<<"		"<<p->Year<<endl;
	}
	cout<<endl;
}




QueqeOfCars::QueqeOfCars(int n){
	first=0;
	last=0;
	Current_Size=0;
	limit=n;
}


car QueqeOfCars::DeleteCar(car *temp){
	//car *temp=new car;

	if(IsEmpty()){
		cout<<"\n\n==================================================\n\n\n";
		cerr<<"\t IsEmpty ... "; return *temp;
		cout<<"\n\n==================================================\n\n\n";
	}
	else {
		car *p=first;
		
		
		temp->Manufacture=first->Manufacture;
		temp->ID=first->ID;
		temp->Color=first->Color;
		temp->Year=first->Year;
		
		first=first->next;
		delete p;
		
		Current_Size--;
		if(Current_Size==0){last=0; first=0;}
		
		return *temp;
	}
	
}


int QueqeOfCars::File_InsertCar(string &FileName){
	
	
	ifstream Get(&FileName[0]);
	
	if(!Get){cerr<<"Can't Open File !!!" <<endl; return 0;}

	while(!Get.eof()){
	
		
	if(IsFull()){
		cout<<"\n\n==================================================\n\n\n";
		cerr<<"Caution, you are you have broken a Limit numbers..."<<endl; 
		cout<<"\n\n==================================================\n\n\n";
	}

		if(last!=0){
			car *n=new car;
			Get>>n->Manufacture;
			Get>>n->ID;
			Get>>n->Color;
			Get>>n->Year;
			
			last->next=n;
			last=n;
			n->next=0;
			Current_Size++;
		}
		else if(last==0){
			first=new car ;
			
			Get>>first->Manufacture;
			Get>>first->ID;
			Get>>first->Color;
			Get>>first->Year;
			
			first->next=0;
			last=first;
			Current_Size++;
			
		}
	}
	return 1;
}


int QueqeOfCars::IsEmpty(){
	return first==0;
}


void QueqeOfCars::InsertCar(){
	
	
	if(IsFull()){
		cout<<"\n\n==================================================\n\n\n";
		cerr<<"Caution, you are you have broken a Limit numbers..."<<endl;
		cout<<"\n\n==================================================\n\n\n";
	}
	cout<<endl;
	cout<<"Manufacture		ID		Color		Year"<<endl;
	
	if(last!=0){
		car *n=new car ;	
		cin>>n->Manufacture;
		cin>>n->ID;
		cin>>n->Color;
		cin>>n->Year;
		
		last->next=n;
		last=n;
		last->next=0;
		Current_Size++;
	}
	else if(last==0){
		first=new car ;		
		cin>>first->Manufacture;
		cin>>first->ID;
		cin>>first->Color;
		cin>>first->Year;
		
		first->next=0;
		last=first;
		Current_Size++;
		
	}
	
}


int QueqeOfCars::IsFull(){
	return Current_Size==limit ;
}



int QueqeOfCars::FindSize(){
	return Current_Size;
}

