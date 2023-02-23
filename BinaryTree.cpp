#include <stdio.h>

typedef int ItemType;
struct TNode
{
    //Cấu trúc của 1 nút
    ItemType Info;      //Chứa thông tin của nút
    TNode* Left;        //Trỏ đến nút con trái
    TNode* Right;       //Trỏ đến nút con phải
};

struct BTree
{
    //Cấu trúc của 1 cây
    TNode* Root;   //Trỏ đến nút gốc của cây
};

void initBTree(BTree &bt)
{
    bt.Root=NULL;
}

TNode* createTNode(ItemType x)
{
    TNode *p = new TNode;       //Tạo, cấp phát vùng nhớ cho Node p
    if(p == NULL) return NULL;    //p không tồn tại -> trả về NULL
    p->Info = x;                //Gán giá trị x cho Info của p
    p->Left = NULL;      
    p->Right = NULL;
    return p;           //Trả về Node p mới được tạo xong
}

int insertTNodeLeft(TNode* T, ItemType x)
{
    if(T == NULL)   
        return 0;   //Node T không tồn tại 
    if(T->Left != NULL)
        return 0;   //Đã tồn tại Node con bên trái
    TNode* p = createTNode(x);      
    T->Left = p;    //Thêm Node con p vào bên trái Node T
    return 1;
}

int insertTNodeRight(TNode* T, ItemType x)
{
    if(T == NULL)   
        return 0;   //Node T không tồn tại 
    if(T->Right != NULL)
        return 0;   //Đã tồn tại Node con bên phải
    TNode* p = createTNode(x);      
    T->Right = p;    //Thêm Node con p vào bên phải Node T
    return 1;
}

void traverseNLR(TNode* root)
{ 
    if(root == NULL) return;    //Kiểm tra Node rỗng
    printf_s("%d ",root->Info); //Xuất giá trị ra màn hình
    traverseNLR(root->Left);    //Đệ quy -> Duyệt qua Trái
    traverseNLR(root->Right);   //Đệ quy -> Duyệt qua Phải
}

void traverseLNR(TNode* root)
{ 
    if(root == NULL) return;    //Kiểm tra Node rỗng
    traverseNLR(root->Left);    //Đệ quy -> Duyệt qua Trái
    printf_s("%d ",root->Info); //Xuất giá trị ra màn hình
    traverseNLR(root->Right);   //Đệ quy -> Duyệt qua Phải
}

void traverseLRN(TNode* root)
{ 
    if(root == NULL) return;    //Kiểm tra Node rỗng
    traverseNLR(root->Left);    //Đệ quy -> Duyệt qua Trái
    traverseNLR(root->Right);   //Đệ quy -> Duyệt qua Phải
    printf_s("%d ",root->Info); //Xuất giá trị ra màn hình
}

int deleteTNodeLeft(TNode* T)
{
    if(T == NULL) return 0;    //Kiểm tra Node T có tồn tại
    TNode* p = T->Left;        //Tạo Node p là Node trái của Node T
    if(p == NULL) return 0;    //Kiểm tra Node p có tồn tại (khác NULL)
    if(p->Left != NULL || p->Right != NULL)
        return 0;              //Kiểm tra Node p là Node lá
    delete p;                  //Thực hiện xóa Node p
    T->Left = NULL;            //Gán NULL là Node con trái của Node T
    return 1;
}

int deleteTNodeRight(TNode* T)
{
    if(T == NULL) return 0;     //Kiểm tra Node T có tồn tại
    TNode* p = T->Right;        //Tạo Node p là Node phải của Node T
    if(p == NULL) return 0;
    if(p->Left != NULL || p->Right != NULL)
        return 0;               //Kiểm tra Node p có tồn tại (khác NULL)
    delete p;                   //Kiểm tra Node p là Node lá
    T->Right = NULL;            //Gán NULL là Node con phải của Node T
    return 1;                   //Thực hiện xóa Node p
}

int main()
{
    BTree bt;
    initBTree(bt);
    bt.Root=createTNode(5);
    insertTNodeLeft(bt.Root,2);
    insertTNodeLeft(bt.Root->Left,1);
    insertTNodeRight(bt.Root->Left,3);
    insertTNodeRight(bt.Root,8);
    insertTNodeRight(bt.Root->Right,9);
    insertTNodeLeft(bt.Root->Right,7);
    traverseNLR(bt.Root); printf_s(" \n");
    traverseLNR(bt.Root); printf_s(" \n");
    traverseLRN(bt.Root); printf_s(" \n");
    deleteTNodeLeft(bt.Root->Left);
    deleteTNodeRight(bt.Root->Left);
    traverseLRN(bt.Root); printf_s(" \n");
    return 0;
}