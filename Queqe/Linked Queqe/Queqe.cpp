

template<class T>
class Queqe{
	
	struct node{
		T element;
		node *next;
	};
	
	public:
		Queqe(int n);
		T DeleteElement();
		void InsertElement(T x);
		int IsEmpty();
		int IsFull();
		int FindSize();
		void print();
		
	private:
		int Current_Size;
		node *first;
		node *last;
		int limit;
};



template<class T>
void Queqe<T>::print(){
	node *p;
	//cout<<first->element<<"	";
	for(p=first;p;p=p->next){
	cout<<p->element<<"	";}
	cout<<endl;
}



template<class T>
Queqe<T>::Queqe(int n){
	first=0;
	last=0;
	Current_Size=0;
	limit=n;
}

template<class T>
T Queqe<T>::DeleteElement(){
	node *p=first;
	T temp=first->element;
	first=first->next;
	delete p;
	Current_Size--;
	return temp;
}

template<class T>
void Queqe<T>::InsertElement(T x){

	if(IsFull()){cerr<<"Caution, you are you have broken a Limit numbers..."<<endl; }
	
if(last!=0){
	node *n=new node ;	
		n->element=x;
		last->next=n;
		last=n;
		last->next=0;
		Current_Size++;
}
else if(last==0){
first=new node;
	first->element=x;
last=first;
Current_Size++;

}

}

template<class T>
int Queqe<T>::IsEmpty(){
	return first==0;
}


template<class T>
int Queqe<T>::IsFull(){
	return Current_Size==limit ;
}


template<class T>
int Queqe<T>::FindSize(){
	return Current_size;
}

#include<iostream>
using namespace std;
void main(){
	
	
	Queqe<int> Q(10);
	/*cout<<Q.IsEmpty()<<endl;
	cout<<Q.IsFull()<<endl;*/
	
	int i=0;
	while(!Q.IsFull()){
	Q.InsertElement(i);
	i++;
	}

	Q.print();
	cout<<"Deleted :"<<Q.DeleteElement()<<endl;
	Q.print();
cout<<"Deleted :"<<Q.DeleteElement()<<endl;
cout<<"Deleted :"<<Q.DeleteElement()<<endl;
Q.print();
Q.InsertElement(100);
Q.InsertElement(200);
Q.InsertElement(300);
Q.InsertElement(300);
Q.print();

while(!Q.IsEmpty()){
	cout<<Q.DeleteElement()<<endl;
	}
}
