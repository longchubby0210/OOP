//De: Tinh dien tich va chu vi hinh chu nhat co 2 canh a,b.
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong hinh chu nhat
class HinhCN
{
    private:
        float a,b;
        
    public:
        void nhap();
        float tinhCV();
        float tinhDT();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong hinh chu nhat
    HinhCN h;
    
    //Tuong tac
    cout<<"Chuong trinh tinh dien tich va chu vi hinh chu nhat co 2 canh a,b\n\n";
    h.nhap();   
    printf("Dien tich hinh chu nhat la: %0.1f",h.tinhDT());
    printf("\nChu vi hinh chu nhat la: %0.1f",h.tinhCV());
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void HinhCN::nhap()
{
    cout<<"Nhap vao 2 canh hinh chu nhat: ";
    cin>>a>>b;
}

float HinhCN::tinhCV()
{
    return (a+b)*2;
}

float HinhCN::tinhDT()
{
    return a*b;
}