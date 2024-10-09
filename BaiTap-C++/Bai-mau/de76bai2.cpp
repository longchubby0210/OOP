//Ho va ten : Hoang Dieu Linh
//MSV: 671615
//Lop : K67CNPMA
//De bai : De 76 bai 2

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;
//Tao doi tuong la danh sach lien ket don
class DSLKD
{
private:
    struct node {
        int infor;
        node*link;
    }*F;
public:
    //Ham tao va ham huy
    DSLKD();
    ~DSLKD();
    //Ham nhap , ham dua ra phan tu ,ham tim kiem
    void push(int x);
    void display();
    bool sreach(int x);

};
//==Chuong trinh chinh
int main()
{
//Tao doi tuong
    DSLKD ds;
    //Tuong tac voi doi tuong
    //Nhap vao du lieu tu file
    int x,x1;
    ifstream file("daysonguyen-thi.txt");
    while(file>>x) {
        ds.push(x);
    }
    //Nhap vao so can tim roi dua ra ket qua tim kiem
    cout<<"Nhap vao so can tim kiem : ";
    cout<<"Nhap vao so can tim kiem : ";
    cin>>x1;
    if(ds.sreach(x1)==true) {
        cout<<"Co trong danh sach ! "<<endl;
    } else {
        cout<<"Khong co trong danh sach ! "<<
            endl;
    }
    //Dua ra danh sach
    cout<<"Danh sach nhap tu file la : ";
    ds.display();
    cout<<endl;
    return 0;
}
//===Dinh nghia ham ==//
//Ham tao va ham huy
DSLKD::DSLKD():F(NULL)
{

}

DSLKD:: ~DSLKD()
{
    while(F) {
        node*p=F;
        F=F->link;
        delete p;
    }

}
//Ham nhap , ham dua ra phan tu ,ham tim kiem,ham ktra rong
void  DSLKD::push(int x)
{
    //Tao 1 nut moi
    node*N=new node;
    N->infor=x;
    N->link=NULL;
    //Th danh sach rong
    if(F==NULL) {
        F=N;
        return;
    }
    //Tim nut cuoi cung
    node*p=F;
    while(p->link != NULL) {
        p=p->link;
    }

    //noi nut
    p->link=N;
}

void  DSLKD::display()
{
    //Cho  chạy tơi nút cuối , mỗi lần chạy đưa ra giá trị của nút đó
    while(F) {
        cout<<F->infor<<" ";
        F=F->link;
    }
}

bool  DSLKD::sreach(int x)
{
    //Đặt p = F rồi cho p chạy đến  nút cuối cùng ,nếu có giá trị nút =x thì trả về true không có trả về false
    node*p=F;
    while(p->link != NULL) {
        if(p->infor == x) {
            return true;
        }
        p=p->link;
    }
    return false;
}
