#include<iostream>
using namespace std;

template<class T>
class stack{
public:
	stack();
	stack(int s);
	~stack(){delete[]Arr;}
	T pop();
	T push(T x);
	bool IsFull();
	bool IsEmpty();
	T TopElement();
	
private:
	int size;
	int top;
	T *Arr;
	
	
};

template<class T>
stack<T>::stack(){top=-1; size=10 ; Arr=new T[size];}
template<class T>
stack<T>::stack(int s){top=-1; size=s ; Arr=new T[size];}
template<class T>
T stack<T>::pop(){T temp; temp = Arr[top]; top-- ; return temp;}
template<class T>
T stack<T>::push(T x){ top++; Arr[top]=x; return Arr[top];	}
template<class T>
bool stack<T>::IsFull(){return top==size-1;}
template<class T>
bool stack<T>::IsEmpty(){return top==-1;}
template<class T>
T stack<T>::TopElement(){
return Arr[top];

}