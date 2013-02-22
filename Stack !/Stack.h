class StackOfIntger{

public:
	
	StackOfIntger(int);
	~StackOfIntger();
	int IsFull();
	int IsEmpty();
	void push(int);
	int	 pop();
	int TopElement();

private:
	int size;
	int *element;
	int top;



};
