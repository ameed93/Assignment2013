 #include<iostream.h>

void h(int n,char s,char i,char d){
int counter=0;
	if(n!=0){
	
		if(n==1){
						cout<<"move disk from"<<s<<"to"<<d<<endl;
			

		}
		else{
		
		h((n-1),s,d,i);
					cout<<"move disk from"<<s<<"to"<<d<<endl;//make sure
					
		h((n-1),i,s,d);
		
}
		
	}





}

void main(){


h(4,'A','B','C');
}