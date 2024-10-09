/*
Bài tập (lthdt-maulop.cpp): Ứng dụng ngăn xếp lưu trữ kế tiếp chuyển số
nguyên dương hệ 10 sang hệ 2 và 16. Yêu cầu sử dụng mẫu lớp trong cài đặt.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao mau lop ngan xep
template<class Type>
class Stack
{
    private:
        enum {size=32};
        Type S[size];
        int T;

    public:
        Stack();
        void push(Type x);
        Type pop();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
    //Tao 2 doi tuong ngan xep
    Stack<int> s1; //Doi tuong ngan xep chua phan tu la so nguyen, dung cho chuyen he 10 sang he 2
    Stack<char> s2; //Doi tuong ngan xep chua phan tu la ky tu, dung cho chuyen he 10 sang he 16

    //Khai bao bien
    int n,thuong,du;

    cout<<"Nhap vao 1 so nguyen duong: ";
    cin>>n;

    //Chuyen sang he 2
    thuong=n;
    while(thuong)
    {
        du = thuong%2;
        thuong /= 2;
        s1.push(du);
    }

    cout<<"So nhi phan cua "<<n<<" la: ";
    while(!s1.isEmpty()) cout<<s1.pop();

    //Chuyen sang he 16
    thuong=n;
    while(thuong)
    {
        du = thuong%16;
        thuong /= 16;

        //Chuyen so du thanh chu so he 16 roi day vao ngan xep
        if(du<10) s2.push(du+48);
        else s2.push(du+55);
    }
    cout<<"\nSo hex cua "<<n<<" la: ";
    while(!s2.isEmpty()) cout<<s2.pop();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
template<class Type>
Stack<Type>::Stack():T(-1)
{

}

template<class Type>
void Stack<Type>::push(Type x)
{
    //1.Kiem tra day
    if(T==size-1)
    {
        cout<<"Ngan xep day day.";
        return;
    }

    //2-3.Tang T len 1 roi dua x vao S tai vi tri T
    S[++T] = x;
}

template<class Type>
Type Stack<Type>::pop()
{
    //1.Kiem tra rong
    if(T==-1)
    {
        cout<<"Ngan xep da rong.";
        Type tg;
        return tg;
    }

    //2-3-4.Tra ve phan tu dinh roi giam T di 1
    return S[T--];
}

template<class Type>
bool Stack<Type>::isEmpty()
{
    return T == -1;
}
