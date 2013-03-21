#include"Queqe.cpp"
#include<iostream>
using namespace std;

void main(){

Queqe<int> t(5);
int i=0;
while(!t.IsFull()){
t.InsertElement(i);
i++;
}
cout<<"Size : "<<t.FindSize()<<endl;

while(!t.IsEmpty()){
cout<<t.DeleteElement()<<endl;
 
}

}