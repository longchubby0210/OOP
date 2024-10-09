//De: Tinh tong 2 so phuc
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong so phuc
class SoPhuc
{
    private:
        float a,b;
    
    public:
        void nhap();
        void hien();
        SoPhuc cong(SoPhuc &p2);
};

//===chuong trinh chinh===
int main()
{
    //Tao 3 doi tuong so phuc
    SoPhuc p1,p2,tong;
    
    //Tuong tac
    cout<<"Chuong trinh tinh tong 2 so phuc: p1 + p2";
    
    cout<<"\n\nNhap vao so phuc p1:\n";
    p1.nhap();
    cout<<"\nNhap vao so phuc p2:\n";
    p2.nhap();
    
    //Cong 2 so phuc
    tong = p1.cong(p2);
    
    //Dua ra cac so phuc
    cout<<"\nSo phuc p1 = "; p1.hien();
    cout<<"\nSo phuc p2 = "; p2.hien();
    cout<<"\nSo phuc p1 + p2 = "; tong.hien();
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void SoPhuc::nhap()
{
    cout<<"Nhap vao phan thuc: ";
    cin>>a;
    cout<<"Nhap vao phan ao: ";
    cin>>b;
}

void SoPhuc::hien()
{
    if(b>=0) cout<<a<<" + j"<<b;
    else cout<<a<<" - j"<<-b;
}

SoPhuc SoPhuc::cong(SoPhuc &p2)
{
    SoPhuc tong;
    
    tong.a = a + p2.a;
    tong.b = b + p2.b;
    
    return tong;
}