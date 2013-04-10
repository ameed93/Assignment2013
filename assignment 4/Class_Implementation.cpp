
binarySearchTree::~binarySearchTree(){}

binarySearchTree::binarySearchTree(){
		T=NULL;

	
}

//*******************************************
int binarySearchTree::depth(){
	return depth_aux(T); 
}


int binarySearchTree::depth_aux(node *T){
	
	if(T==NULL) return 0;
	
	return max(depth_aux(T->left),depth_aux(T->right))+1;
}


int binarySearchTree::max(int  T1,int T2){
	if(T1 > T2) return T1;
	else
		return T2;
	
	
}

//*******************************************


int binarySearchTree::numberOfTerminals(){
return numberOfTerminals_aux(T);
}


int binarySearchTree::numberOfTerminals_aux(node *T){
	if(T==NULL) return 0;
	if(T->left==NULL && T->right==NULL) 
		return numberOfTerminals_aux(T->left)+numberOfTerminals_aux(T->right)+1;
	else
		return numberOfTerminals_aux(T->left)+numberOfTerminals_aux(T->right);
}

//********************************************************************************
void binarySearchTree::printInorder(){
printInorder_aux(T);
}

void binarySearchTree::printInorder_aux(node *T){
	if(T==NULL) return ;
	printInorder_aux(T->left);
	cout<<T->ID<<"      "<<T->Name<<"      "<<T->Avg<<"      "<<endl;
	printInorder_aux(T->right);
}

//*************************************************************************************
void binarySearchTree::printPreorder(){
	
printPreorder_aux(T);

}

void binarySearchTree::printPreorder_aux(node *T){
	if(T==NULL) return ;
	cout<<T->ID<<"      "<<T->Name<<"      "<<T->Avg<<"      "<<endl;
	printPreorder_aux(T->left);
	printPreorder_aux(T->right);
}
//********************************************************
void binarySearchTree::printPostorder(){
	printPostorder_aux(T);
}
void binarySearchTree::printPostorder_aux(node *T){
	if(T==NULL) return ;
	
	printPostorder_aux(T->left);
	printPostorder_aux(T->right);
	cout<<T->ID<<"      "<<T->Name<<"      "<<T->Avg<<"      "<<endl;
}

//************************************************

void binarySearchTree::insertStudent(Data *D){
insertStudent_aux(T,D);
}
void binarySearchTree::insertStudent_aux(node *&T,Data *D){
	node *R=T;
	node *p=NULL;
	
	
	if(T!=NULL){
	
	while(R && R->ID!=D->ID){
		if(D->ID < R->ID){
			p=R;
			R=R->left;
		}
		
		else{
			p=R;
			R=R->right;
		}
	}
	
	if(R==NULL){
		node *temp=new node;
		temp->ID=D->ID;
		temp->Name=D->Name;
		temp->Avg=D->Avg;
		
		temp->left=temp->right=NULL;
		
		if(D->ID  < p->ID) 
			p->left=temp;
		else
			p->right=temp;
	}
	
	else{
		cerr<<"Key Is Exist";
	}}
	else if(T==NULL){
			T=new node;
		T->ID=D->ID;
		T->Name=D->Name;
		T->Avg=D->Avg;
		
		T->left=T->right=NULL;
	}
	
}
//***********************************************************


int binarySearchTree::IsBalanced(){
	return IsBalanced_aux(T);
}

int binarySearchTree::IsBalanced_aux(node *T){
	if(T==NULL) return 0;
	if(abs(depth_aux(T->left)-depth_aux(T->right))>1) return 0;
	else
		return 1 ;
	return IsBalanced_aux(T->left) && IsBalanced_aux(T->right); 
	
	
}

//********************************************************


int binarySearchTree::maxID(){
return maxID_aux(T);
}
int binarySearchTree::maxID_aux(node *T){
	
	if(T==NULL) return 0;
	
	if(T->right)
		maxID_aux(T->right);
	
	else
		return T->ID;
	
	
	
}
//****************************************************
int binarySearchTree::minID(){
return minID_aux(T);
}

int binarySearchTree::minID_aux(node *T){
	if(T==NULL) return 0;
	
	if(T->left)
		minID_aux(T->left);
	
	else
		return T->ID;
}
///*********************************

int binarySearchTree::size(){
return size_aux(T);
}

int binarySearchTree::size_aux(node *T){
	if(T==NULL) return 0;
	return size_aux(T->left)+size_aux(T->right)+1;

}



//*****************************************************************

Data* binarySearchTree::searchID(int I){
Data * H=new Data;
	return searchID_aux(T,H,I);

}


Data* binarySearchTree::searchID_aux(node *T,Data *H,int I){
	
	if(T==NULL) return 0;
	if(T->ID==I) {H->ID=T->ID ; H->Avg=T->Avg ; H->Name=T->Name; return H;}
 
	
	if(I < T->ID) searchID_aux(T->left,H,I);
	if(I > T->ID) searchID_aux(T->right,H,I);
}

//********************************************************************************************************

node* binarySearchTree::search(int I){
return search_aux(T,I);
}


node* binarySearchTree::search_aux(node *T,int I){

	if(T==NULL) return 0;
if(T->ID==I)return T;
 
	
	if(I < T->ID) search_aux(T->left,I);
	if(I > T->ID) search_aux(T->right,I);
}


//*********************Delete******************************


void binarySearchTree::deleteStudent(int I){
deleteStudent_aux(T,I);
}
void binarySearchTree::deleteStudent_aux(node *T,int I){
	node *F=search(I);
	if(F->left==NULL && F->right==NULL) deleteTerminal(F);
	else 
	deleteNonTerminal(F);
}

//*************************************************************************************
node *binarySearchTree::parent(node *p){	
	return parent_aux(T,p);
}


node *binarySearchTree::parent_aux(node *T,node *p){
	
	if(T==NULL) return 0;
	if(T==p) return 0;

	//****************anchor*******************
	if(T->left==p )  return T;
	if(T->right==p )  return T;
	//*****************************************
	
	if(p->ID < T->ID ){
		return parent_aux(T->left,p);
	}
		else if(p->ID > T->ID){
		return parent_aux(T->right,p);
	}
	
}

//*************************************************************************************
void binarySearchTree::deleteTerminal(node *p){
	
	if(p->left || p->right) return ;
	if(T==NULL) return ;
	
	if(p==T){
		T=NULL;
		delete p;
		return  ;
	}
	
		node *q=parent(p);
	if(p==q->left) q->left=NULL;
	else q->right=NULL;
	delete p;
}
//********************************************************************************************************

node* binarySearchTree::nearest(node *p)
	{
	
	node *L;
	if(p->left){
		L=p->left;

	while(L->right) L=L->right;

	return L;
	}
	
	else
	{
	
		node *R;
	R=p->right;
while(R->left)R=R->left;

return R;
	}
}

void binarySearchTree::deleteNonTerminal(node *p){

	if(p->right==NULL &&  p->left==NULL){
		deleteTerminal(p); 
	}
	else{
		node *n=nearest(p);
	p->ID=n->ID;
	p->Avg=n->Avg;
	p->Name=n->Name;
	deleteNonTerminal(n);
	}


}