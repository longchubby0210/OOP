#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop mat hang
class MatHang
{
    private:
        char tenHang[31];
        int soLuong;
        float donGia;

    public:
        void nhap();
        void hien();
        float tinhTien();
};

//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    int n;
    float tongTien=0;

    //Nhap n
    cout<<"So luong mat hang can nhap? ";cin>>n;

    //Tao mang dong n doi tuong mat hang de chua n mat hang
    MatHang *ds = new MatHang[n];

    //Nhap thong tin n mat hang va tinh tong tien cua n mat hang
    cout<<"Nhap vao cac mat hang:";
    for(int i=0;i<n;i++)
    {
        printf("\nNhap mat hang thu %d:\n",i+1);
        ds[i].nhap();

        //Tinh tong tien
        tongTien += ds[i].tinhTien();
    }

    cout<<"\nDanh sach cac mat hang da nhap la:";
    for(int i=0;i<n;i++)
    {
        printf("\nMat hang %d:",i+1);
        ds[i].hien();
        cout<<endl;
    }

    printf("\nTong tien cua %d mat hang la: %0.1f",n,tongTien);

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void MatHang::nhap()
{
    cout<<"Nhap ten hang: ";
    scanf(" ");cin.get(tenHang,sizeof(tenHang));
    cout<<"Nhap so luong: ";
    cin>>soLuong;
    cout<<"Nhap don gia: ";
    cin>>donGia;
}

void MatHang::hien()
{
    cout<<"\nTen hang: "<<tenHang;
    cout<<"\nSo luong: "<<soLuong;
    printf("\nDon gia: %0.1f",donGia);
    printf("\nThanh tien: %0.1f",soLuong*donGia);
}

float MatHang::tinhTien()
{
    return soLuong*donGia;
}
