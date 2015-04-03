#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;
namespace cop4530{

template <typename T>
class BST
{
public:
    BST(int th=1);
    BST(const string input, int th=1);
    BST(const BST& v);
    BST(BST&& v);
    ~BST();
    void buildFromInputString(const string input);
    const BST& operator=(const BST& n);
    const BST& operator=(BST&& n);
    bool empty();
    void printInOrder() const;
    void printLevelOrder() const;
    int numOfNodes() const;
    int height() const;
    void makeEmpty();
    void insert(const T& v);
    void insert(T&& v);
    void remove(const T& v);
    bool contains(const T&v);
private:
    struct BSTNode{
        T element;
        int counter;
        BSTNode* left;
        BSTNode* right;
        BSTNode(const T& theelement, BSTNode* lp, BSTNode* rp,int ct=0)
        :element(theelement),left(lp),right(rp),counter(ct)
                {}
        BSTNode(const T&&theelement, BSTNode* lp, BSTNode*rp,int ct=0)
        :element(std::move(theelement)),left(lp),right(rp),counter(ct)
                {}
        };

    BSTNode* root;
    int threshold;
    typename BST<T>::BSTNode* clone(BSTNode* t)const;
    void printInOrder(BSTNode* t)const;
    void printLevelOrder(BSTNode*t) const;
    void makeEmpty(BSTNode* &t);
    void insert(const T& v, BSTNode* &t);
    void insert(T&& v, BSTNode*& t);
    void remove(const T& v, BSTNode* &t);
    void rotation(BSTNode* & t, BSTNode* & p);
    bool contains(const T&v, BSTNode*&t, BSTNode*& p);
    int numOfNodes(BSTNode*t,int &num=0) const;
    int height(BSTNode*t)const;
    BSTNode* findmin(BSTNode* rt);
     };
  }
#include "bst.hpp"

#endif

