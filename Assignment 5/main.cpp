#include"class.h"
#include"implementation.cpp"
void main(){
	int n;

	Heap<Employee> H(10);
	cout<<"how many Employee you want to Add ???"<<endl;
	cin>>n;
	Employee *x=new Employee[n];
	
	int i=0;
	cout<<"Enter ID Name Salary Of Employee : "<<endl;
	
	while(i!=n){
		cin>>x[i].ID>>x[i].Name>>x[i].Salary;
		i++;
	}

	for(i=0;i<n;i++){
	H.insertEmployee(x[i]);
	}
	cout<<"Size"<<H.size()<<endl<<endl; 
	
	while(!H.isEmpty()){
		Employee D=H.deleteEmployee();
		cout<<D.ID<<" "<<D.Name<<""<<D.Salary<<endl;
	}
	
}
