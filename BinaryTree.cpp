// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* create(int item) {
    node* q = new node();
    q->data = item;
    q->left = NULL;
    q->right = NULL;
    return q;
}

int height(node* r) {
    if (r == NULL)return -1;
    if ((r->left == NULL) && (r->right == NULL))return 0;
    int hl = height(r->left);
    int hr = height(r->right);
    if (hl > hr)return(hl + 1);
    else return(hr + 1);
}

int leaf(node* r) {
    if (r == NULL)return 0;
    if (r->left == NULL && r->right == NULL)return 1;
    return(leaf(r->left) + leaf(r->right));
}

int countNode(node* r) {
    if (r == NULL)return 0;
    if ((r->left == NULL) && (r->right == NULL))return 1;
    return(1 + countNode(r->left) + countNode(r->right));
}

void deleteTree(node* r) {
    if (r == NULL)return;
    if (r->left == NULL && r->right == NULL) {
        cout << r->data<<"\t";
        delete r;
        return;
    }
    deleteTree(r->left);
    deleteTree(r->right);
    cout << r->data<<"\t";
    delete r;
}

int max(node* r) {
    if (r == NULL)return INT_MIN;
    int m = r->data;
    if (max(r->left) > m)m = max(r->left);
    if (max(r->right) > m)m = max(r->right);
    return m;
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

void postorder(node* r) {
    if (r == NULL)return;
    if (r->left == NULL && r->right == NULL) {
        cout << r->data << "  ";
        return;
    }
    postorder(r->left);
    postorder(r->right);
    cout << r->data << "  ";
}

int isIdentical(node* a, node* b) {
    if (a == NULL && b == NULL) {
        return 1;
    }
    if (a != NULL && b != NULL) {
        return (a->data == b->data && isIdentical(a->left, b->left) && isIdentical(a->right, b->right));
    }
    return 0;
}

//

struct Node {
    node* data;
    Node* next;
};

void insert(Node* &start, node* item,int &front,int &rear) {
    Node* a = new Node();
    a->data = item;
    a->next = NULL;
    if (start == NULL) {
        front = 1;
        rear = 1;
        start = a;
        return;
    }
    Node* t = start;
    while (t->next!=NULL)
    {
        t = t->next;
    }
    t->next = a;
    rear++;
}

void del(Node* &start, int& front, int& rear) {
    if (start == NULL) {
        front = 0;
        rear = 0;
        return;
    }
    Node* t = start;
    if (start->next == NULL) {
        start = NULL;
        delete t;
        front = 0;
        rear = 0;
        return;
    }
    start = start->next;
    delete t;
    front++;
}

void levelOrder(node* root) {
    Node* s = NULL;
    int front = 0;
    int rear = 0;
    //s->data = root;
    //s->next = NULL;
    insert(s, root, front, rear);
    while (s!=NULL)
    {
        if (s->data->left) 
        {
            insert(s, s->data->left, front, rear);
        }
        if (s->data->right)
        {
            insert(s, s->data->right, front, rear);
        }
        cout << (s->data->data) << "   ";
        del(s, front, rear);
    }
}

//



int main()
{
    node* r = NULL;
    r = create(1);
    r->left = create(2);
    r->left->right = create(5);
    r->left->left = create(4);
    r->left->left->left = create(23);
    r->left->left->right = create(8);
    r->left->left->right->left = create(13);
    r->right = create(3);
    r->right->right = create(6);
    r->right->right->left = create(9);
    r->right->right->right = create(10);
    //cout << height(r);
    //cout << leaf(r);
    //cout << countNode(r);
    //deleteTree(r);
    //cout << max(r);
    //levelOrder(r);;
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
