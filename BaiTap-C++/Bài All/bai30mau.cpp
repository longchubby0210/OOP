/*
Bài 30(lthdtbai30.cpp): Cho tệp văn bản "daysonguyen-bai30.txt" chứa dãy số nguyên,
trong đó có cả số dương và số âm, trên tệp không có thông tin về số lượng số.
Sử dụng hàng đợi lưu trữ kế tiếp để tách, đưa ra màn hình dãy các số dương và dãy các số âm,
mỗi dãy số trên một dòng.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tương hang doi luu tru ke tiep
class Queue
{
    private:
        enum {size=100};
        int Q[size];
        int F,R;

    public:
        Queue();
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
Queue::Queue():F(-1),R(-1)
{

}

void Queue::insert(int x)
{
    //1.Kiem tra hang doi day
    if(F==0 && R==size-1 || R+1==F)
    {
        cout<<"Hang doi da day.";
        return;
    }

    //2.Tang R len 1
    if(R==-1) F=R=0;
    else if(R==size-1) R=0;
    else R++;

    //3.Bo sung x vao hang doi tai vi tri R
    Q[R] = x;
}

int Queue::remove()
{
    //1.Kiem tra rong
    if(F==-1)
    {
        cout<<"Hang doi da rong.";
        return 1;
    }

    //2.Giu lai phan tu loi truoc (dau hang doi)
    int tg = Q[F];

    //3.Tang F len 1
    if(F==R) F=R=-1;
    else if(F==size-1) F=0;
    else F++;

    //4.Tra ve phan tu da loai bo
    return tg;
}

bool Queue::isEmpty()
{
    return F==-1;
}
