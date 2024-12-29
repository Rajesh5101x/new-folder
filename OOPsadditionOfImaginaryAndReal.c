#include<iostream>
using namespace std;

class complex{
    public :
        int real, imng;

        complex(int r = 0, int i = 0){
            real = r;
            imng = i;
        }

        complex operator +(const complex& obj){
            complex res;
            res.real = real + obj.real;
            res.imng = imng + obj.imng;
            return res;
        }
        
        void display(){
            cout<<real<<" + i"<<imng<<endl;
        }
        
};

int main(){
    complex s1(2,4), s2(4,2);
    complex s3 = s1 + s2;

    s3.display();
    return 0;
}




