class StackOfIntger{

public:
	static int top;
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



};
