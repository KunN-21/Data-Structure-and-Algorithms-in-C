#include <iostream>

using namespace std;

template <class T>
class StackNode
{
public:
    //PROPERTIES
    T data;
    StackNode<T> *next;

    //CONSTRUCTOR
    StackNode(): data(NULL), next(NULL){};
    StackNode(T x): data(x), next(NULL){};

    //CLASS FUNCTIONS
    void setData(T x)
    {
        this->data=x;
    }
    void setNext(StackNode<T> *nextNode)
    {
        this->next=nextNode;
    }

    T getData()
    {
        return this->data;
    }
    StackNode<T>* getNext()
    {
        return this->next;
    }
};

template <class T>
class STACK
{
public:
    //PROPERTIES
    StackNode<T> *Top;
    int index;
    int size;

    //CONSTRUCTOR
    STACK(): Top(NULL), index(-1), size(0){};

    //CLASS FUNCTIONS
    bool isEmpty()
    {
        if(this->size==0)
        {
            return true;
        }
        return false;
    }

    void Push(StackNode<T> *node)
    {
        if(isEmpty()==true)
        {
            this->Top=node;
            this->index++;
            this->size++;
            return;
        }
        node->next=this->Top; 
        this->Top=node;
        this->index++;
        this->size++;
    }

    void Pop()
    {
        if(isEmpty()==true)
        {
            cout << "ERROR: Stacks is Empty";
            return;
        }
        StackNode<T> *secNode=this->Top->next;
        delete this->Top;
        this->Top=secNode;
        this->index--;
        this->size--;

    }

    StackNode<T>* getTop()
    {
        return this->Top;
    }

};

int main()
{
    //Create Node
    StackNode<int> *nodeA = new StackNode(11);
    StackNode<int> *nodeB = new StackNode(12);

    //Create Stack
    STACK<int> sta;
    sta.Push(nodeA);
    sta.Push(nodeB);
    sta.Pop();
    cout << sta.getTop() << endl;
    cout << nodeA->getData() << endl;
    cout << nodeA->getNext();
    return 0;
};