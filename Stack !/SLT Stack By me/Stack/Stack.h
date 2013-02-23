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
	bool operator==(const StackOfIntger &st);
private:
	int size;
	int *element;



};
