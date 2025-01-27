#include<iostream>
#include<vector>
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

struct node* LCA(struct node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    struct node* left = LCA(root->left,n1,n2);
    struct node* right = LCA(root->right,n1,n2);
    if(left != NULL && right != NULL){
        return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left != NULL){
        return (LCA(root->left,n1,n2));
    }
    return(LCA(root->right,n1,n2));
}

bool getPath(struct node* root, int key, vector<int> &path){
    if(root == NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == key){
        return true;
    }
    
    if(getPath(root->left,key,path) || getPath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}

int LCA2(struct node* root, int n1, int n2){
    vector<int> path1, path2;

    if(!getPath(root,n1,path1) || !getPath(root,n2,path2)){
        return -1;
    }

    int pc;
    for(pc = 0; pc < path1.size() && pc < path2.size(); pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }

    /* int pc = 0;
    while (pc < path1.size() && pc < path2.size() && path1[pc] == path2[pc]) {
        pc++;
    } */

    return path1[pc-1];
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);

    root->right = new node(3);
    root->right->right = new node(6);
    root->right->left = new node(5);
    root->right->left->left = new node(7);

    cout<<LCA(root,4,6)->data<<endl;
    cout<<LCA(root,5,6)->data<<endl;
    cout<<LCA2(root,5,6)<<endl;
}