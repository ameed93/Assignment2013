#include<iostream>
#include"TemplateStack.cpp"
using namespace std;

int operation(char eq){
	if(eq=='*' || eq=='/' ||eq=='+'||eq=='-' || eq=='(' || eq==')')
		return 1;
	else
		return 0;
	
}

int Priority(char eq){
	if(eq=='*' || eq=='/'){ return 5;}
	if(eq=='+' || eq=='-'){ return 4;}
		else 
		return 0;
}


void main(){


	int row=50;
	char *Equation=new char[row];
	char x;
	cout<<"Enter Equation ... "<<endl;
	int i=0;
	int counter=0;

		stack <char >st(5);

	while(x!=';'){
		cin>>x;
		x=toupper(x);//to make Capital Letter
		Equation[i]=x;
		i++;
		counter++; // to detected array size;
	}
	
	
	
	
	
	for( i=0;i<counter-1;i++){

		if(operation(Equation[i]) )
		{
			if(st.IsEmpty()){
				st.push(Equation[i]);
			}
			else if(!st.IsEmpty() && Priority(st.TopElement())>=Priority(Equation[i] )){
				while(!st.IsEmpty() && Priority(st.TopElement())>=Priority(Equation[i]) )
				cout<<st.pop();
				st.push(Equation[i]);
			}	
		
				else if(!st.IsEmpty() && Priority(st.TopElement())<Priority(Equation[i]) )
			{
				st.push(Equation[i]);
				}	
	}
				else{
				cout<<Equation[i];
			}
		}

	while(!st.IsEmpty())
		cout<<st.pop();
	cout<<endl;
	delete[]Equation;

  }
