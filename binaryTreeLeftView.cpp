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

void displayLeftView(struct node* root){
    queue<struct node*> qe;
    qe.push(root);

    while(!qe.empty()){
        int n = qe.size();
        for(int i = 0; i < n; i++){
            struct node* temp = qe.front();
            qe.pop();

            if(i == 0){
                cout<<temp->data<<", ";
            }

            if(temp->left){
                qe.push(temp->left);
            }

            if(temp->right){
                qe.push(temp->right);
            }
        }
    }
    cout<<endl;
}

void display(struct node* root){
    queue<struct node*> qe;
    qe.push(root);

    while(!qe.empty()){
        int n = qe.size();
        for(int i = 0; i < n; i++){
            struct node* temp = qe.front();
            qe.pop();

            cout<<temp->data<<", ";

            if(temp->left){
                qe.push(temp->left);
            }

            if(temp->right){
                qe.push(temp->right);
            }
        }
    }
    cout<<endl;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);

    root->right->left = new node(5);
    root->right->right = new node(6);

    root->right->left->left = new node(7);

    displayLeftView(root);
    display(root);

    return 0;
}