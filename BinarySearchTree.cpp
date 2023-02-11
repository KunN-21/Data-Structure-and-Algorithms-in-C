#include <iostream>

using namespace std;

template <class T>
class SNode
{
public:
    //PROPERTIES
    T data;
    SNode<T> *left;
    SNode<T> *right;
    
    //CONSTRUCTOR
    SNode(): data(NULL), left(NULL), right(NULL){};
    SNode(T x): data(x), left(NULL), right(NULL){};

    //CLASS FUNCTIONS
    void setData(T data)            { this->data=data; }
    void setLeft(SNode<T> *left)    { this->left=left; }
    void setRight(SNode<T> *right)  { this->right=right; }
    T getData()                     { return this->data; }
    SNode<T> *getLeft()             { return this->left; }
    SNode<T> *getRight()            { return this->right; }
};

template <class T>
class BinarySearchTree
{
public:
    //PROPERTIES
    SNode<T> *root;
    int size;

    //CONSTRUCTOR
    BinarySearchTree(): size(0), root(NULL){};

    //CLASS FUNCTIONS
    bool isEmpty()
    {
        if(this->size==0) return true;
        return false;
    }
    int height()
    {
        return this->height(this->root);
    }
    int addNode(SNode<T> *node)
    {
        return this->addNode(this->root, node);
    }
    
    //PRIVATE
private:
    int height(SNode<T> *node)
    {
        if(node == NULL) {return 0;}
        return 1 + max(this->height(node->getLeft()), this->height(node->getRight()));
    }
    int addNode(SNode<T> *&currentNode, SNode<T> *node)
    {
        if(currentNode == NULL)
        { 
            currentNode = node;
            this->size++;
            return 1; 
        }
        if(currentNode->data == node->data)
        {
            cout << "ERROR: Root'data is same as Node'data ";
            return 0;
        }
        if(node->data < currentNode->data)
        {
            this->addNode(currentNode->left, node);
        }
        else
        {
            this->addNode(currentNode->right, node);
        }
        return 1;
    }
};

int main()
{
    SNode<int> *a= new SNode(5);
    SNode<int> *b= new SNode(3);
    SNode<int> *c= new SNode(8);
    BinarySearchTree<int> tree;
    tree.addNode(a);
    tree.addNode(b);
    tree.addNode(c);
    return 0;
};