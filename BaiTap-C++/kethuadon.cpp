#include<iostream>
#include<stdio.h>
/*
 Bài tập(lthdt-kethua-1): Viết chương trình tính thể tích và diện tích bề mặt của hình trụ có bán kính r và chiều cao h. Biết rằng hình trụ là một loại hình tròn có bán kính r được kéo daif với chiều cao h.
 */
using namespace std;

class HinhTron
{
    private :
        float r;
    public :
        void nhap();
        float tinhDT();
        float tinhCV();
};

class HinhTru:public HinhTron
{
    private :
        float h;
    public: 
        void nhap();
        float tinhTT();
        float tinhDT();
};
int main()
{
    HinhTru htru;
    htru.nhap();
    cout<<"The tich: "<<htru.tinhTT()<<endl;
    cout<<"Dien tich: "<<htru.tinhDT();
    cout<<endl;
    return 0;
}

 void HinhTron::nhap()
 {
    cout<<"Nhap vao r: ";
    cin>>r;
 }

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

float HinhTron::tinhCV()
{
    return 2*3.14*r;
}

void HinhTru::nhap()
{
    HinhTron::nhap();
    cout<<"Nhap vao h : ";
    cin>>h;
}

float HinhTru::tinhDT()
{
    return HinhTron::tinhCV()*h+HinhTron::tinhDT()*2;
}

float HinhTru::tinhTT()
{
    return HinhTron::tinhDT()*h;
}
    
