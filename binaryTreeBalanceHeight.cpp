#include<iostream>
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

int height(struct node* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left),height(root->right)) + 1;
}

bool isBalance(struct node* root){
    if(root == NULL){
        return true;
    }

    if(isBalance(root->left) == false) return false;
    if(isBalance(root->right) == false) return false;

    int temp = height(root->left) - height(root->right);
    if(temp <= 1){
        return true;
    }else{
        return false;
    }
}

bool isBalance2(struct node* root, int &height){
    if(root == NULL){
        height = 0;
        return true;
    }

    int lh = 0, rh = 0;

    if(isBalance2(root->left, lh) == false) return false;
    if(isBalance2(root->right, rh) == false) return false;

    if(abs(lh - rh) > 1){
        return false;
    }

    height = (max(lh, rh)) + 1;

    return true;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);

    cout<<isBalance(root)<<endl;
    int height = 0;
    cout<<isBalance2(root,height)<<endl;
}