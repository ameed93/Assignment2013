
template<class T>

Heap<T>::Heap(int n){
Element=new T[n];
Current_Size=0;
Max_Size=99;
}

template<class T>
void Heap<T>::insertEmployee(T N){
	if(isFull()){return ;}

	Current_Size++;
	int flag=0;
	int i=Current_Size;
	while(!flag){
		if(i==1){flag=1;}
		if(N.ID >=Element[i/2].ID){flag=1;}
		else{
			Element[i]=Element[i/2];
			
			i/=2;
		}
	}
	Element[i]=N;
}
template<class T>
T Heap<T>::deleteEmployee(){

	T result=Element[1];
	int done=0;
	T temp=Element[Current_Size];
	int i=1;
	int j=2;
Current_Size--;
while(j<Current_Size && !done){
	if(Element[j].ID > Element[j+1].ID){j++;}
	if(temp.ID<=Element[j].ID){done=1;}
	else{
		Element[i]=Element[j];
		i=j;
		j=i*2;

	}
}
Element[i]=temp;
return result;
}
template<class T>
int Heap<T>::isFull(){ return Current_Size==Max_Size;}
template<class T>
int Heap<T>::isEmpty(){return Current_Size==0;}
template<class T>
int Heap<T>::size(){return Current_Size;}
