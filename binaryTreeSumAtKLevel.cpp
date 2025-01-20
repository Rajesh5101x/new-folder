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

int displaySum(struct node* root, int k){
    queue<struct node*> qe;
    qe.push(root);
    qe.push(NULL);
    int level = 0, sum = 0;

    while(!qe.empty()){
        struct node* temp = qe.front();
        qe.pop();
        if(temp != NULL){
            if(level == k){
                sum += temp->data;
            }
            if(temp->left){
                qe.push(temp->left);
            }
            if(temp->right){
                qe.push(temp->right);
            }
        }else{
            level++;
            if(!qe.empty()){
                qe.push(NULL);
            }
        }
    }

    /* while(!qe.empty()){
        struct node* temp = qe.front();
        qe.pop();
        if(temp != NULL){
            if(temp->left){
                qe.push(temp->left);
            }
            if(temp->right){
                qe.push(temp->right);
            }
        }else{
            level++;
            if(!qe.empty()){
                qe.push(NULL);
            }
        }

        if (level == k && temp != NULL) {
            sum += temp->data;
        }
    } */

    return sum;
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
    
    cout<<displaySum(root,2)<<endl;

    return 0;
}
