 #include"Class.h"
#include"Implementation.cpp"
int Whatyouwant(listOfStudents &Linked){
	int Do;
	int NumberOfNode;
	do{
		cout<<endl<<"Enter "<<endl
			<<"1 to print List :"<<endl
			<<"2 to find SizeOfList"<<endl
			<<"3 to Delete Node "<<endl
			<<"4 to Add new Node"<<endl
			<<"5 to find Max Student score "<<endl
			<<"6 to find Average of the Scores "<<endl
			<<"7 to copy List "<<endl
			<<"8 to Find Middle of the List "<<endl
			<<"9 to Delete All Nodes "<<endl
			<<"10 to Exit "<<endl;
		cout<<"Your Do ?";
		cin>>Do;
		system("cls");
		switch(Do){
		case 1:
			cout<<Linked;
			break;
		case 2:
			cout<<Linked;
			cout<<"Size Is :"<<Linked.SizeofList();
			break;
		case 3 :
			cout<<Linked;
			cout<<"Which Node you want to Delete it  ?";
			cin >> NumberOfNode;
			Linked.DeleteNode(NumberOfNode);
			break;
		case 4:
			cout<<Linked;
			cout<<"where you want to Add Node ?";
			cin >> NumberOfNode;
			Linked.AddNewNode(NumberOfNode);
			break;
		case 5:
			cout<<Linked;
			cout<<Linked.maxScore();
			break;
		case 6:
			cout<<Linked;
			cout<<Linked.average();
			break;
		case 7:
			
			Linked.CopyList();
			
			break;
		case 8 :
			cout<<Linked;
			Linked.MiddleOfList();
			break;
		case 9 :
			cout<<Linked;
			Linked.RecursionDeleteAll(1);
			break;
			
		case 10:
			cout<<"\n\n\n\n Thanks for using the System !"<<endl<<endl;
			return 0;
			break;
			
		}
	}while(Do!=11);
	
	return 0;
	
}
void main(){
	char choice;
	int n;
	
	string NameOfFile;
	
	listOfStudents Linked;
	
	cout<<"do you want to input from File or from User (F/U) ?"<<endl;
	cin>>choice;
	
	if(choice=='F' || choice=='f'){
		
		cout<<"Enter Name Of File :";
		cin>>NameOfFile;
		cout<<endl;
		
		Linked.BuildFromFile(NameOfFile);
		
		
		cout<<"What you Want to do ?";
		Whatyouwant(Linked);
	}
	
	else if(choice=='U' || choice=='u'){
		
		cout<<"Enter Number of Node which you want to create it :";
		cin>>n;
		Linked.Build(n);
		
		
		cout<<"What you Want to do ?";
		Whatyouwant(Linked);
		
	}
	
	
	
		
	else {cerr<<"Invalid Choice :( ";}	
	
	
	
	
}
