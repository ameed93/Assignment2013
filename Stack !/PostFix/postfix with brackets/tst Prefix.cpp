#include<iostream>
#include"TemplateStack.cpp"
using namespace std;

int operation(char eq){
	if(eq=='*' || eq=='/' ||eq=='+'||eq=='-'  )
		return 1;
	else
		return 0;
	
}

int Priority(char eq){
	if(eq=='*' || eq=='/'){ return 5;}
	if(eq=='+' || eq=='-'){ return  4;}
		else 
		return 3;
}


void main(){


	int row=50;
	char *Equation=new char[row];
	char x;
	cout<<"Enter Equation ... "<<endl;
	int i=0;
	int counter=0;
	char t;
		stack <char >st(5);

	while(x!=';'){
		cin>>x;
		x=toupper(x);//to make Capital Letter
		Equation[i]=x;
		i++;
		counter++; // to detected array size;
	}
	
	
	
	
	
	 for( i=0;i<counter-1;i++){
		
		//1 if element ( push it on stack 
		 if(Equation[i]=='('){st.push(Equation[i]);} 
		

		//2 if element ')' pop stack until first '(' appear 
		if(Equation[i]==')'){
					t=st.pop();
					while(t!='('){
						cout<<t;
						t=st.pop();
					}
		 }
		
		// if element Operator  : Do
		else if(operation(Equation[i]) )
		{		
				//if stack empty Or it have "(" push the operator 
				if(st.IsEmpty() || st.TopElement()=='('){
				st.push(Equation[i]);
						}
				// else if Not empty and New operator < = Old operator : 
				else if(!st.IsEmpty() && Priority(st.TopElement())>=Priority(Equation[i]) ){
				while(!st.IsEmpty() && Priority(st.TopElement())>=Priority(Equation[i]))
				cout<<st.pop();
				st.push(Equation[i]);
			}	
				
				else if(!st.IsEmpty() && Priority(st.TopElement())<Priority(Equation[i]) || st.TopElement()!='(' ){
				st.push(Equation[i]);
				}
		}
			
			
 
				if(!operation(Equation[i]) && Equation[i]!='(' && Equation[i]!=')') {
				cout<<Equation[i];
				}
		}

while(!st.IsEmpty())
		cout<<st.pop();
		cout<<endl;
	delete[]Equation;

  }
//((a+b)*(c-d))/e;