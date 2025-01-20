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

int countNode(struct node* root){
    queue<struct node*> qe;
    qe.push(root);
    qe.push(NULL);
    int count = 0;

    while(!qe.empty()){
        struct node* temp = qe.front();
        qe.pop();
        if(temp != NULL){
            count++;
            if(temp->left){
                qe.push(temp->left);
            }
            if(temp->right){
                qe.push(temp->right);
            }
        }else if(!qe.empty()){
            qe.push(NULL);
        }
    }
    return count;
}

void recCountNode(struct node* root, int &count){
    if(root == NULL){
        return;
    }
    count++;
    recCountNode(root->left,count);
    recCountNode(root->right,count);
}

int recCountnode(struct node* root){
    if(root == NULL){
        return 0;
    }
    return recCountnode(root->left) + recCountnode(root->right) + 1;
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
    
    cout<<countNode(root)<<endl;

    int count = 0;
    recCountNode(root,count);
    cout<<count<<endl;

    cout<<recCountnode(root)<<endl;

    return 0;
}