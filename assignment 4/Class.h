#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
using namespace std;

struct node{
node *left;
node *right;

int ID;
string Name;
double Avg;

}; 

struct Data{

int ID;
string Name;
double Avg;


};


class binarySearchTree{

public :

~binarySearchTree();
binarySearchTree();
void insertStudent(Data *D);
void printInorder( );
void printPreorder( );
void printPostorder( );
int IsBalanced();
int depth( );
int numberOfTerminals();
int maxID( );
int minID( );
int size( );
int max(int T1,int T2);
node *search(int I);
Data *searchID(int I);

void deleteStudent( int I);
node *parent( node *p);
node *nearest( node *p);
void deleteTerminal(node *p);
void deleteNonTerminal( node *p);




private:
node *T;	

int depth_aux(node *T);
int numberOfTerminals_aux(node *T);
void printInorder_aux(node *T);
void printPreorder_aux(node *T);
void printPostorder_aux(node *T);	
void insertStudent_aux(node *&T,Data *D);
int IsBalanced_aux(node *T);
int maxID_aux(node *T );
int minID_aux( node *T);
int size_aux( node *T);
node *search_aux(node *T,int I);
Data *searchID_aux(node*T,Data *H,int I);
node *parent_aux(node *T,node *p);
void deleteStudent_aux(node *T,int I);
};