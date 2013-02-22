#include<string>
using namespace std;
struct node{
	string name;
	int ID;
	double score;
	node *next;
};


class listOfStudents{
	
	friend ostream& operator<<(ostream &out,const listOfStudents& L){
		node *p;
		out<<"Name"<<"		"<<"ID"<<"		"<<"Score"<<endl;
		for(p=(L.first);p;p=p->next){
			out<<p->name<<"	"<<p->ID<<"		"<<p->score<<endl;
		}
		return out;
	}
	
public :
	
	
	
	
	listOfStudents();//constructer
	node* Build (int NumberOfNode);//to build List 
	void AddNewNode(int n); // to add new node 
	void DeleteNode(int n);// to delete Node 
	node *CopyList();// to copy list 
	int SizeofList();// To find Size of list 
	void print(); // Print List 
	void MiddleOfList(); // To find Middle Of list
	void RecursionDeleteAll(int x); // Delete All Nodes
	double average(); // to find Average
	double maxScore(); // to find Max score 
	node *BuildFromFile(string fileName);//constructor creates a linked list form a text file
	~listOfStudents ();//destructor

private:
	node *first;
	int Current_Size;
};


