#include<iostream>
using namespace std;

class parent{
    public :
        virtual void fun(){
            cout<<"This is called from parent"<<endl;
        }
};

class child : public  parent{
    public :
        void fun() override {
            cout<<"This is called from child by overriding"<<endl;
        }
};

int main(){
    parent p;
    child c;
    p.fun();
    c.fun();
    return 0;
}
