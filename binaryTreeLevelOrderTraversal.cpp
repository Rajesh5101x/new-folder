#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void displayLevel(struct node* root){
    queue<node*> qe;
    qe.push(root);
    qe.push(NULL);

    while(!qe.empty()){
        node* node = qe.front();
        qe.pop();
        if(node != NULL){
            cout<<node->data<<", ";
            if(node->left){
                qe.push(node->left);
            }
            if(node->right){
                qe.push(node->right);
            }
        }else if(!qe.empty()){
            qe.push(NULL);
        }
    }
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    root->left->left->left = new node(8);
    root->left->left->right = new node(9);

    root->left->right->left = new node(10);

    root->right->left->left = new node(11);
    root->right->left->right = new node(12);

    root->right->right->left = new node(13);
    root->right->right->right = new node(14);
    
    displayLevel(root);
    
    return 0;
}