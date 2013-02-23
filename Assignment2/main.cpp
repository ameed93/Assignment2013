#include<iostream>
#include"TemplateStack.cpp"
#include<string>
#include<math.h>
using namespace std;
//you can't use intger Numbers ,<just like this  Example : >>1.0 2.0 + ; > To exit enter  >>e 
#define HELP "Example >>1.0 2.0 + ;. To exit enter >>e " 
//******************************************************************************+

int Operator(string eq){
	if(eq=="*" || eq=="/"  ||eq=="+" ||eq=="-")
		return 1;
	else
		return 0;
	
}

//*******************************************************************************//
int FindSize(string x){
	int counter=0;
	int i=0;
	
	while(x[i]!='.'){
		counter++;
		i++;
	}
	--counter;
	return counter;
	
}
//*********************************************************************************
double convert(string x){

	int i=0;
	int y;// converted string . -> (double )
	int counter=FindSize(x);// count digit until (.)
	int C=1;//count digit after (.)
	double result=0;


	while(x[i]!='\0'){
		
		if(x[i]!='.'){
			
			y=x[i]-'0';
			result+=y*pow(10,counter);
			--counter;
			i++;
		}

		if(x[i]=='.'){
			i++;
			while(x[i]!='\0'){
				y=x[i]-'0';
				result+= y * pow(10,(-C));
				C++;
				i++; 
			}//while 2
		}// if x[i]=='.';
	}//While 
	return result;	
}

//************************************************************************************************
double Evaluate(double x, double y, string E);//prototype 


int  main(){

	cout<<HELP<<endl<<endl;
	
	stack<double> st;		
	
	double N,x,y,temp;
	string E;
	
	cout<<">>";
	while(1){
		
		cin>>E;

	if(E[0]=='e'){
			cout<<"\n\n\n\n Thanks for using :)"<<endl;
			return 0;}

	else if(E!=";"){
				if(!Operator(E)){
					N=convert(E);
					st.push(N); }
								
				else if(Operator(E)){
					x=st.pop();
					y=st.pop();
					temp=Evaluate(x,y,E);
					st.push(temp);	}
					}

	else{
				
					while(!st.IsEmpty()){
					cout<<st.pop()<<endl;
					cout<<">>";}	
			}
			}
		
	
	
}


///////////*************************************************************************
double Evaluate(double x, double y, string E){
	double answer;
	if(E=="+"){answer=x+y;}
	if(E=="-"){answer=y-x;}
	if(E=="*"){answer=x*y;}
	if(E=="/"){answer=y/x;}

	return answer ;
	
	
}
