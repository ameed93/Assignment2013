template<class T>
class Queqe{
	
	
public:
	Queqe(int n);
	T DeleteElement();
	void InsertElement(T x);
	int IsEmpty();
	int IsFull();
	int FindSize();
	
	
private:
	int first;
	int last;
	T *Q;
	int size;
};

template<class T>
Queqe<T>::Queqe(int n){
	size=n;
	 Q=new T[size];
	
	first=1;
	last=0;
}

template<class T>
T Queqe<T>::DeleteElement(){

	if(IsEmpty()){cerr<<"Queqe is Empty !"; return -9999;}
	else {
		T temp=Q[first];
		first=(first+1)%size;
	
	return temp;
	}
}

template<class T>
void Queqe<T>::InsertElement(T x){
	
	if(IsFull()){cerr<<"Queqe Is Full ! "; }
	else {
	last=(last+1)%size;
	Q[last]=x;

	}
	
  }

template<class T>
int Queqe<T>::IsEmpty(){
return first==(last+1)%size;
}

template<class T>
int Queqe<T>::IsFull(){
return first==(last+2)%size;
}

template<class T>
int Queqe<T>::FindSize(){
int counter=0;
	for(int i=last;i>=first;i--){
	counter++;
	}
return counter;
}


