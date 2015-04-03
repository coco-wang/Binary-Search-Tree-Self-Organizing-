#include <iostream>
#include <sstream>
#include <queue>

using namespace std;
using namespace cop4530;

template <typename T>
BST<T>::BST(int th):root(nullptr),threshold(th)
{
}

template <typename T>
BST<T>::BST(const string input, int th):root(nullptr),threshold(th)
{
         buildFromInputString(input);
}

template<typename T>
BST<T>::~BST()
{
        makeEmpty(root);
}

template <typename T>
void BST<T>::makeEmpty(BSTNode* & rt)
{
        if (rt!=nullptr){
            makeEmpty(rt->left);
            makeEmpty(rt->right);
            delete rt;
         }
        rt=nullptr;
}

template<typename T>
void BST<T>::buildFromInputString(const string input)
{
        makeEmpty(root);
        if (empty()){
            stringstream iss(input);
            T x;
            while (iss>>x){
                insert(x);}
       }
}

template <typename T>
const BST<T>& BST<T>::operator=(BST<T>&& n)
{
        swap(root,n.root);
        return *this;
}

template<typename T>
BST<T>::BST(const BST<T>& rhs):root(nullptr)
{
        root=clone(rhs.root);
}

template<typename T>
typename BST<T>::BSTNode* BST<T>::clone(BST<T>::BSTNode* t)const
{
        if (t==nullptr)
             return nullptr;
        else
            return new BSTNode(
                   t->element,clone(t->left),clone(t->right));
}

template<typename T>
BST<T>::BST(BST<T>&& rhs):root(nullptr)
{
        swap(rhs.root,root);
}

template <typename T>
int BST<T>::height() const
{
        return height(root);
}

template <typename T>
int BST<T>::height(BSTNode*t)const
{
        int height_left,height_right;
        if (t==nullptr)
            height_left=height_right=0;
        else
         {
            height_left=1+height(t->left);
            height_right=1+height(t->right);
         }
        if (height_left>height_right)
             return height_left;
        else
             return height_right;
}

template<typename T>
int BST<T>::numOfNodes() const
{
        int num=0;
        numOfNodes(root,num);
}

template <typename T>
int BST<T>::numOfNodes(BSTNode*t,int& num) const
{
        if (t!=nullptr)
         {
             num=num+1;
             numOfNodes(t->left,num);
             numOfNodes(t->right,num);
         }
        return num;
}

template <typename T>
void BST<T>::printLevelOrder() const
{
        printLevelOrder(root);
}

template <typename T>
void BST<T>::printLevelOrder(BSTNode*t) const
{
        if (t==nullptr)
             return;
        queue<BSTNode*> qq;
        qq.push(t);
        while(!qq.empty()){
                BSTNode* front=qq.front();
                cout <<front->element<<" ";
                if(front->left!=nullptr)
                         qq.push(front->left);
                if(front->right!=nullptr)
                          qq.push(front->right);
                qq.pop();
        }
        cout <<"\n";
}

template <typename T>
void BST<T>::rotation (BSTNode*& t, BSTNode*& p)
{
  if (t==p->left)
    {
        BSTNode*oldnode = p;
        p = t;
        oldnode->left = t->right;
        p->right=oldnode;
    }
  else if (t==p->right){
        BSTNode*oldnode = p;
        p = t;
        oldnode->right = t->left;
        p->left=oldnode;
    }
}

template<typename T>
bool BST<T>::contains(const T& v)
{
        if (v==root->element){
             root->counter=0;
             return true;}
        else if (v>root->element)
             return contains(v,root->right,root);
        else
             return contains(v,root->left,root);
}

template<typename T>
bool BST<T>::contains(const T& v, BSTNode* &t, BSTNode*& p)
{
        if (t==nullptr)
             return false;
        if (v>t->element)
             return contains(v,t->right,t);
        else if(v<t->element)
             return contains(v,t->left,t);
        else{
             ++ (t->counter);
             if(t->counter>threshold){
                 rotation(t,p);
                 t->counter=0;
                 return true;}
             }
}
template <typename T>
void BST<T>::insert(const T & x,BST<T>:: BSTNode* & rt)
{
        if (rt==nullptr)
           rt=new BSTNode(x,nullptr,nullptr);
        else if(x<rt->element)
           insert(x,rt->left);
        else if(x>rt->element)
           insert(x,rt->right);
        else
            return;
}

template<typename T>
void BST<T>::insert(T&& v)
{
        insert(std::move(v),root);
}

template<typename T>
void BST<T>::insert(T&& v, BST<T>::BSTNode*& rt)
{
        if (rt==nullptr)
            rt=new BSTNode(std::move(v),nullptr,nullptr);
        else if (v>rt->element)
            insert(std::move(v),rt->right);
        else if(v<rt->element)
            insert(std::move(v),rt->left);
        else
            return;
}

template<typename T>
void BST<T>::remove(const T& v)
{
        remove(v,root);
}


template<typename T>
void BST<T>::remove(const T& v, BSTNode* &t)
{
        if (t!=nullptr){
            if(v>t->element)
                remove(v,t->right);
            else if(v<t->element)
                remove(v,t->left);
            else{
                if(t->left!=nullptr&&t->right!=nullptr){
                     t->element=findmin(t->right)->element;
                     remove(t->element,t->right);}
               else {
                    BSTNode* oldnode=t;
                    t= (t->left!=nullptr)?t->left: t->right;
                    delete oldnode;}
               }
       }
}

template<typename T>
void BST<T>::printInOrder() const
{
      printInOrder(root);
      cout <<"\n";
}

template <typename T>
void BST<T>::printInOrder(BSTNode* t) const
{
        if(t!=nullptr)
        {
            printInOrder(t->left);
            cout << t->element<<" ";
            printInOrder(t->right);
        }
}

template <typename T> bool BST<T>::empty()
{
        return (root==nullptr);
}

template <typename T>
typename BST<T>::BSTNode* BST<T>::findmin(BSTNode* rt)
{
        if (rt==nullptr)
            return nullptr;
        else if (rt->left==nullptr)
            return rt;
        else
            findmin(rt->left);
}

