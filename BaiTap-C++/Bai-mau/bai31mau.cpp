/*
Bài 31(lthdtbai31.cpp): Cho tệp văn bản "daysonguyen-bai30.txt" chứa dãy số nguyên,
trong đó có cả số dương và số âm, trên tệp không có thông tin về số lượng số.
Sử dụng hàng đợi lưu trữ phân tán để tách, đưa ra màn hình dãy các số dương và dãy các số âm,
mỗi dãy số trên một dòng.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tương hang doi luu tru phan tan
class Queue
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *F,*R;

    public:
        Queue();
        ~Queue();
        void insert(int x);
        int remove();
        bool isEmpty();
};

//===Chuong trinh chinh===
int main()
{
    //Tao 2 doi tuong hang doi, Q1 chua so duong, Q2 chua so am
    Queue Q1,Q2;

    //Tao doi tuong tep vao
    ifstream fin("daysonguyen-bai30.txt");

    //Khai bao bien
    int x;

    //Doc day so tu tep
    cout<<"Day so nguyen doc duoc tu tep la:\n";
    while(fin>>x)
    {
        cout<<x<<"  ";
        if(x>=0) Q1.insert(x);
        else Q2.insert(x);
    }

    //Dua ra man hinh va tep
    cout<<"\n\nDay cac so duong la:\n";
    while(!Q1.isEmpty())
    {
        x = Q1.remove();
        cout<<x<<"  ";
    }

    cout<<"\n\nDay cac so am la:\n";
    while(!Q2.isEmpty())
    {
        x = Q2.remove();
        cout<<x<<"  ";
    }

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
Queue::Queue():F(NULL),R(NULL)
{

}

Queue::~Queue()
{
    while(F)
    {
        node *P = F;
        F = F->link;
        delete P;
    }
}

void Queue::insert(int x)
{
    //1.Tao nut nho moi chua x
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao sau nut R
    if(R==NULL) F = N;
    else R->link = N;

    //3.Cho R tro sang nut moi
    R = N;
}

int Queue::remove()
{
    //1.Kiem tra hang doi rong
    if(F==NULL)
    {
        cout<<"Hang doi da rong!";
        return 1;
    }

    //2.Giu lai nut dau hang doi (noi truoc)
    int tg = F->infor;
    node *P = F;

    //3.Cho F tro sang nut dung sau
    if(F==R) F = R = NULL;
    else F = F->link;

    //4.Huy nut va tra ve phan tu dau hang doi da loai bo
    delete P;
    return tg;
}

bool Queue::isEmpty()
{
    return F==NULL;
}
