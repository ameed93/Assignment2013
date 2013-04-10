#include"Class.h"
#include"Class_Implementation.cpp" 
#include<iostream>
#include<string>
using namespace std;

int Whatyouwant(binarySearchTree &T){
	int Do;
	int ID;
	Data *D=new Data;
	Data *F;
	int x;
	float avg;
	string n;
	do{
		cout<<endl<<"Enter "<<endl
			<<"1 to printInorder :"<<endl
			<<"2 to printPreorder :"<<endl
			<<"3 to printPostorder :"<<endl
			<<"4 to find SizeOfTree"<<endl
			<<"5 to insertStudent  "<<endl
			<<"6 isBalanced "<<endl
			<<"7 to find Depth"<<endl
			<<"8 to number of Terminals"<<endl
			<<"9 to find MaxID"<<endl
			<<"10 to find MinID"<<endl
			<<"11 to find ElementById"<<endl
			<<"12 to Delete element"<<endl
			<<"13 to Exit"<<endl
			;
		cout<<"Your Do ?";
		cin>>Do;
		system("cls");
		switch(Do){
			
		case 1:
			T.printInorder();
			break;
			
		case 2:
			T.printPreorder();
			
			break;
		case 3 :
			T.printPostorder();
			break;
		case 4:
			cout<<T.size();
			break;
			
		case 5:
			
			cout<<"enter ID , Name , AVG of student "<<endl;
			cin>>x>>n>>avg;
			D->ID=x;
			D->Name=n;
			D->Avg=avg;
			
			T.insertStudent(D);
			break;
		case 6:
			if(T.IsBalanced()) cout<<"IsBalanced"<<endl;
			else 
			cout<<"Not";
			break;
			
		case 7:
			cout<<T.depth();
			break;
			
		case 8:
			cout<<T.numberOfTerminals();
			break;
			
		case 9:
			cout<<T.maxID();
			break;
			
		case 10:
			cout<<T.minID();

			break;
			
		case 11:
			cout<<"enter ID which you want ..."<<endl;
			cin>>ID;
			F=T.searchID(ID);
			cout<<F->ID<<"	"<<F->Name<<F->Avg<<endl;

			break;
			
		case 12:
			cout<<"Enter ID for Student which you want to delete it Terminal\nonTerminal"<<endl;
			cin>>ID;
			T.deleteStudent(ID);
			break;
			
		case 13:
			cout<<"\n\n==================================================";
			cout<<"\n\n==================================================";
			cout<<"\n\n\n\n Thanks for using the System !"<<endl<<endl;
			cout<<"\n\n==================================================\n\n\n";
			cout<<"\n\n==================================================\n\n\n";
			return 0;
			break;
			
		}
	}while(Do!=13);
	
	return 0;
	
}


void main(){
	binarySearchTree T;
Whatyouwant(T);
	
} 