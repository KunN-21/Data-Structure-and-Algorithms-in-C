#include <iostream>

using namespace std;

template <class T>
class TNode
{
public:
    //PROPERTIES
    T data;
    TNode<T> *left;
    TNode<T> *right;
    
    //CONSTRUCTOR
    TNode(): data(NULL), left(NULL), right(NULL){};
    TNode(T x): data(x), left(NULL), right(NULL){};

    //CLASS FUNCTIONS
    void setData(T data)            { this->data=data; }
    void setLeft(TNode<T> *left)    { this->left=left; }
    void setRight(TNode<T> *right)  { this->right=right; }
    T getData()                     { return this->data; }
    TNode<T> *getLeft()             { return this->left; }
    TNode<T> *getRight()            { return this->right; }
};

template <class T>
class BinarySearchTree
{
public:
    //PROPERTIES
    TNode<T> *root;
    int size;

    //CONSTRUCTOR
    BinarySearchTree(): size(0), root(NULL){};

    //CLASS FUNCTIONS
    bool isEmpty()
    {
        if(this->size==0) return true;
        return false;
    }
    int height()                    { return this->height(this->root); }
    int addNode(TNode<T> *node)     { return this->addNode(this->root, node); }
    void NLR()                      { this->NLR(this->root); }
    void LNR()                      { this->LNR(this->root); }
    void LRN()                      { this->LRN(this->root); }
    TNode<T> *findNode(T x)         { this->findNode(this->root, x); }

    //PRIVATE
private:
    int height(TNode<T> *node)
    {
        if(node == NULL) {return 0;}
        return 1 + max(this->height(node->getLeft()), this->height(node->getRight()));
    }
    int addNode(TNode<T> *&currentNode, TNode<T> *node)
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
    void NLR(TNode<T> *node)
    {
        if(node==NULL) {return;}
        cout << node->getData() << ' ';
        this->NLR(node->left);
        this->NLR(node->right);
    }
    void LNR(TNode<T> *node)
    {
        if(node==NULL) {return;}
        this->LNR(node->left);
        cout << node->getData() << ' ';
        this->LNR(node->right);
    }
    void LRN(TNode<T> *node)
    {
        if(node==NULL) {return;}
        this->LRN(node->left);
        this->LRN(node->right);
        cout << node->getData() << ' ';
    }
    TNode<T> *findNode(TNode<T> *root, T x)
    {
        TNode<T> *node = root;
        while(node != NULL)
        {
            if(node->getData() == x)
                return node;
            if (x < node->getData())
                node = node->left;
            else
                node = node->right;
        }
        return NULL;
    }
};

int main()
{
    TNode<int> *a= new TNode(5);
    TNode<int> *b= new TNode(3);
    TNode<int> *c= new TNode(8);
    BinarySearchTree<int> tree;
    tree.addNode(a);
    tree.addNode(b);
    tree.addNode(c);
    tree.NLR(); cout << endl;
    tree.LNR(); cout << endl;
    tree.LRN(); cout << endl;
    TNode<int> *find=tree.findNode(5);
    return 0;
};