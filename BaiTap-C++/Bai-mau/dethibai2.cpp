//Tinh tong cac chu so cua 1 so nguyen duong
#include<iostream>
#include<stdio.h>

using namespace std;
template<class Type>
class DSLKD
{
    private:
        struct node
        {
            int infor;
            node*link;
        }*F;
    public:
        DSLKD();
        ~DSLKD();
        void push(int x);
        Type pop();
        bool isEmpty();
};
int main()
{
    DSLKD<int> ds;
    int x,count=0;
    cout<<"Nhap vao so can tinh : ";
    cin>>x;
    while(x!=0)
    {
        int tg=x%10;
        x=x/10;
        ds.push(tg);
    }
    cout<<endl;
    while(!ds.isEmpty())
    {
        int temp=ds.pop();
        cout<<temp;
        count+=temp;
    }
    cout<<endl;
    cout<<count;
    cout<<endl;
    return 0;

}

template<class Type>
DSLKD<Type>::DSLKD():F(NULL)
{
    
}

template<class Type>
DSLKD<Type>::~DSLKD()
{
    while(F)
    {
        node*p=F;
        F=F->link;
        delete p;
    }
}

template<class Type>
void DSLKD<Type>::push(int x)
{
    //vao 3 ra 4
    //Tao nut moi 
    node*N=new node;
    N->link=NULL;
    N->infor = x;
    //noi nut
    if(F==NULL)
    {
        F=N;
    }else
    {
        //Chen vao truoc nut F 
        N->link=F;
        F=N;
    }

}

template<class Type>
Type DSLKD< Type >::pop()
{
    //truong hop ds rong
    if(F==NULL)
    {
        cout<<" Danh sach rong ! ";
        Type temp;
        return temp;
    }
    //Giu lai nut noi truoc
    Type tg=F->infor;
    node*p=F;
    //Th chi co 1 phan tu
    if(F->link==NULL)
    {
        F=NULL;
    }else{

        while(F->link !=NULL){
            F=F->link;
        }
    }
    delete p;
    return tg;
}

template<class Type>
bool DSLKD<Type>::isEmpty()
{
    return F==NULL;
}
