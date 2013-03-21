#include"Queqe.cpp"

int Whatyouwant(QueqeOfCars &Q,car *temp){
	int Do;
	
	do{
		cout<<endl<<"Enter "<<endl
			<<"1 to print Queqe :"<<endl
			<<"2 to find SizeOfList"<<endl
			<<"3 to Delete Car "<<endl
			<<"4 to Add new Car"<<endl
			<<"5 to Exit "<<endl;
		cout<<"Your Do ?";
		cin>>Do;
		system("cls");
		switch(Do){
			
		case 1:
			cout<<Q;
			break;
		case 2:
			cout<<Q;
			cout<<"\n\n==================================================\n\n\n";
			cout<<"Size Is :"<<Q.FindSize();
			cout<<"\n\n==================================================\n\n\n";
			break;
		case 3 :
			Q.DeleteCar(temp);
			cout<<Q;
			break;
		case 4:
			cout<<Q;
			Q.InsertCar();
			break;
		case 5:
			cout<<"\n\n==================================================";
			cout<<"\n\n==================================================";
			cout<<"\n\n\n\n Thanks for using the System !"<<endl<<endl;
			cout<<"\n\n==================================================\n\n\n";
			cout<<"\n\n==================================================\n\n\n";
			return 0;
			break;
			
		}
	}while(Do!=6);
	
	return 0;
	
}

void main(){
	car *temp=new car;	
	char choice;
	int n;
	
	string NameOfFile;
	
	
	
	cout<<"do you want to input from File or from User (F/U) ?"<<endl;
	cin>>choice;
	
	if(choice=='F' || choice=='f'){
		
		cout<<"Enter Name Of File :";
		cin>>NameOfFile;
		cout<<endl;
		
		QueqeOfCars Q(10);
		Q.File_InsertCar(NameOfFile);
		
		
		cout<<"What you Want to do ?";
		
		Whatyouwant(Q,temp);
	}
	
	
	else if(choice=='U' || choice=='u'){
		
		cout<<"Enter Number of Cars which you want to Add them :";
		cin>>n;
		QueqeOfCars Q(n);
		Q.InsertCar();
		
		
		cout<<"What you Want to do ?";
		Whatyouwant(Q,temp);
		
	}
	
	
	
	
	else {cerr<<"Invalid Choice :( ";}	
	
	
	
}