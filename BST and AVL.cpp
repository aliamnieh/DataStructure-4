// BST and AVL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
    int data;
    int height;
    node* left;
    node* right;
};

int height(node* r) {
    if (r == NULL)return -1;
    if ((r->left == NULL) && (r->right == NULL))return 0;
    int hl = height(r->left);
    int hr = height(r->right);
    if (hl > hr)return(hl + 1);
    else return(hr + 1);
}

node* create(int item) {
    node* q = new node();
    q->data = item;
    q->left = NULL;
    q->right = NULL;
    q->height = 0;
    return q;
}

node* insert(node* r, int item) {
    if (r == NULL) {
        return create(item);
    }
    else if (item < r->data) r->left = insert(r->left, item);
    else if (item > r->data)r->right = insert(r->right, item);
    return r;
}

node* search(node* r, int item) {
    if (r == NULL || r->data == item)return r;
    if (item < r->data) return search(r->left, item);
    return search(r->right, item);
}

node* Search(node* r, int item) {
    node* t = r;
    while (t!=NULL)
    {
        if (item < t->data)t = t->left;
        else if (item > t->data)t = t->right;
        else return t;
    }
    return t;
}


//finds minimum node in right subtree and returns the address
node* min(node* r) {
    while (r->left!=NULL)
    {
        r = r->left;
    }
    return r;
}



node* Delete(node* r, int item) {
    node* t = NULL;
    if (r == NULL)return r;
    if (item < r->data)Delete(r->left, item);
    else if (item > r->data)Delete(r->right, item);
    else {
        if (r->left == NULL) { t = r->right; delete r; return t; }
        else if (r->right == NULL) { t = r->left; delete r; return t; }
        else {
            t = min(r->right);
            r->data = t->data;
            Delete(r->right, r->data);
        }
    }
    return r;
}


//finds the bigger number
int max(int a, int b) {
    return (a >= b) ? a : b;
}



node* rightRotation(node* y) {
    node* x = y->left;
    node* t2 = x->right;
    x->right = y;
    y->left = t2;
    x->height = max(height(x->right), height(x->left)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return x;
}

node* leftRotation(node* y) {
    node* x = y->right;
    node* t2 = x->left;
    y->right = t2;
    x->left = y;
    x->height = max(height(x->right), height(x->left)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return x;
}

int balanceFactor(node* r) {
    if (r == NULL)return 0;
    int hl = height(r->left);
    int hr = height(r->right);
    return(hl - hr);
}

node* add(node* p, int item) {
    if (p == NULL)return(create(item));
    if (item < p->data)p->left = add(p->left, item);
    else if (item > p->data)p->right = add(p->right, item);
    else return p;
    p->height = max(height(p->left), height(p->right)) + 1;
    int b = balanceFactor(p);
    if (b >= 2 && item < p->left->data)return rightRotation(p);
    else if (b >= 2 && item > p->left->data) { p->left = leftRotation(p->left); return rightRotation(p); }
    else if (b <= -2 && item > p->right->data) return leftRotation(p);
    else if (b <= -2 && item < p->right->data) { p->right = rightRotation(p->right); return leftRotation(p); }
    return p;
}

void preorder(node* r) {
    if (r == NULL)return;
    if (r->left == NULL && r->right == NULL) {
        cout << r->data << "  ";
        return;
    }
    cout << r->data << "  ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(node* r) {
    if (r == NULL)return;
    if (r->left == NULL && r->right == NULL) {
        cout << r->data << "  ";
        return;
    }
    inorder(r->left);
    cout << r->data << "  ";
    inorder(r->right);
}

int main()
{
    node* r = NULL;
    /*r = create(13);
    r->right = create(15);
    r->right->right = create(16);
    r->left = create(6);
    r->left->left = create(5);
    r->left->right = create(10);
    r->left->right->left = create(7);
    r->left->right->right = create(11);
    r->left->left->left = create(4);*/
    //r->left->left->left->left = create(1);
    r=add(r, 13);
    r = add(r, 6);
    r = add(r, 15);
    r = add(r, 16);
    r = add(r, 5);
    r = add(r, 10);
    r = add(r, 4);
    r = add(r, 7);
    r = add(r, 11);
    r = add(r, 22);
    r = add(r, 23);
    r = add(r, 24);
    preorder(r);
    cout << endl;
    inorder(r);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
