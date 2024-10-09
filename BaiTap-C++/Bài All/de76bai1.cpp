//Ho va ten : Hoang Dieu Linh
//MSV: 671615
//Lop : K67CNPMA
//De bai : De 76 bai 1

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

class Diem
{
    private:
        float x,y;

    public:
        //Ham tao
        Diem();
        Diem(float x, float y);
        //Ham tinh khoang cach bang  toan tu -
        float operator-(Diem& d2);
        //Ham ban
        friend istream& operator>>(istream& cin,Diem& d);
        friend ostream& operator<<(ostream& cout,Diem& d);


};
//==Chuong trinh chinh==//
int main()
{
    //Tao doi tuong
    Diem d1,d2;
    //Nhap vao 2 diem
    cout<<"Nhap vao diem so 1 : "<<endl;
    cin>>d1;
    cout<<"Nhap vao diem so 2 : "<<endl;;
    cin>>d2;
    //Tinh khoang cach va tra ve ket qua
    float kc=d2-d1;
    cout<<"Khoang cach cua 2 diem la : "<<kc;
    cout<<endl;
    return 0;
}
//===Dinh nghia ham ==//
//Ham tao
Diem::Diem():x(0),y(0)
{

}

Diem::Diem(float x, float y):x(x),y(y)
{

}
//Ham tinh khoang cach bang  toan tu -
float  Diem::operator-(Diem& d2)
{
    return sqrt(pow((d2.x-x),2)+pow((d2.y-y),2));
}

