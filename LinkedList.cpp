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
    void setData(T data)
    {
        this->data=data;
    }
    void setNext(SNode<T> *next)
    {
        this->next=next;
    }
    T getData()
    {
        return this->data;
    }
    SNode<T> *getNext()
    {
        return this->next;
    }

};

template <class T>
class SLinkedList
{
public:
    SNode<T> *head;
    SNode<T> *tail;
    int size;

    SLinkedList(): head(NULL), tail(NULL), size(0){};
    
    void Prt()
    {
        SNode<T> *node=this->head;
        while(node!=NULL)
        {
            cout << node->data << " ";
            node=node->next;
        }
    }

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
        if(NullList(newNode)==1)
        {
            newNode->next=head;
            this->head=newNode;
            this->size++;
        }

    }
    void addTail(SNode<T> *newNode)
    {
        if(NullList(newNode)==1)
        {
            this->tail->next=newNode;
            this->tail=newNode;
            this->size++;
        }
    }
    void addAfter(SNode<T> *nodeAfter, SNode<T> *newNode)
    {
        newNode->next=nodeAfter->next;
        nodeAfter->next=newNode;
    }

    void deleteHead()
    {
        SNode<T> *secNode = this->head->next;
        //this->head->next=NULL;
        delete this->head;
        this->head=NULL;
        this->head=secNode;
        this->size--;
        
    }
    void deleteTail()
    {
        SNode<T> *befTail=this->head;
        while(befTail->next!=this->tail)
        {
            befTail=befTail->next;
        }
        //befTail->next=NULL;
        delete this->tail;
        this->tail=befTail;
        this->size--;
    }
    void deleteMid(SNode<T> *node)
    {
        SNode<T> *nodeAfter=this->head;
        while(nodeAfter->next!=node)
        {
            nodeAfter=nodeAfter->next;
        }
        nodeAfter->next=node->next;
        //node->next=NULL;
        delete node;
        this->size--;
    }

};

int main()
{
    SNode<int> *a= new SNode(12);
    SNode<int> *b= new SNode(11);
    SNode<int> *c= new SNode(13);
    SLinkedList<int> lst;
    lst.addHead(a);
    lst.addHead(b);
    lst.addTail(c);
    lst.deleteHead();
    //lst.deleteTail();
    //lst.deleteMid(&a);
    cout << a->getNext();
    //lst.Prt();
    return 0;
}