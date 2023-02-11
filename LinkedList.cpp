#include <iostream>

using namespace std;

template <class T>
class SNode
{
public:
    //PROPERTIES
    T data;
    SNode<T> *next;
    
    //CONSTRUCTOR
    SNode(): data(), next(){};
    SNode(T x): data(x), next(){};

    //CLASS FUNCTIONS
    void setData(T data)            { this->data=data; }
    void setNext(SNode<T> *next)    { this->next=next; }
    T getData()                     { return this->data; }
    SNode<T> *getNext()             { return this->next; }
};

template <class T>
class SLinkedList
{
public:
    SNode<T> *head;
    SNode<T> *tail;
    int size;

    SLinkedList(): head(NULL), tail(NULL), size(0){};

    int NullList(SNode<T> *newNode)
    {
        if(size==0)
        {
            this->head=newNode;
            this->head->next=this->tail;
            this->tail=newNode;
            this->size=1;
            return 0;
        }
        else
        {
            return 1;
        }
    }

    void addHead(SNode<T> *newNode)
    {
        if(NullList(newNode)==0)
            return;
        newNode->next=head;
        this->head=newNode;
        this->size++;

    }
    void addTail(SNode<T> *newNode)
    {
        if(NullList(newNode)==0)
            return;
        this->tail->next=newNode;
        this->tail=newNode;
        this->size++;
    }
    void addAfter(SNode<T> *nodeBehind, SNode<T> *newNode)
    {
        if (NullList(newNode)==0)
            return;
        newNode->next=nodeBehind->next;
        nodeBehind->next=newNode;
        size++;
        if (nodeBehind == this->tail)
            this->tail=newNode;          
    }

    void deleteHead()
    {
        if (size==0)
        {
            cout << "ERROR: List is NULL";
            return;
        }
        SNode<T> *secNode = this->head->next;
        delete this->head;
        this->head=NULL;
        this->head=secNode;
        this->size--;
        
    }
    void deleteTail()
    {
        if (size==0)
        {
            cout << "ERROR: List is NULL";
            return;
        }
        SNode<T> *frontTail=this->head;       //Create a Node front tail
        while(frontTail->next!=this->tail)
        {
            frontTail=frontTail->next;       //Find frontTail' address
        }
        delete this->tail;
        this->tail=frontTail;
        this->size--;
    }
    void deleteMid(SNode<T> *node)
    {
        if (size==0)
        {
            cout << "ERROR: List is NULL";
            return;
        }
        if (node == this->head)
        {
            deleteHead();
            return;
        }
        if (node == this->head)
        {
            deleteTail();
            return;
        }
        SNode<T> *nodeBehind=this->head;         //Create a Node behind deleteNode
        while(nodeBehind->next!=node)            //Find nodeBehind' address
        {
            nodeBehind=nodeBehind->next;
        }
        nodeBehind->next=node->next;
        delete node;
        this->size--;
    }
    void Prt()
    {
        if (NullList == 0)
        {
            cout << "ERROR: List is NULL";
            return;
        }
        SNode<T> *node=this->head;
        while(node!=NULL)
        {
            cout << node->data << " ";
            node=node->next;
        }
    }
};

int main()
{
    //Create Node
    SNode<int> *a= new SNode(12);
    SNode<int> *b= new SNode(11);
    SNode<int> *c= new SNode(13);
    //Create List
    SLinkedList<int> lst;
    
    lst.addHead(a);
    lst.addHead(b);
    lst.addTail(c);
    // lst.deleteHead();
    //lst.deleteTail();
    //lst.deleteMid(&a);
    //lst.Prt();
    return 0;
}