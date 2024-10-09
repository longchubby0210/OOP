/*
Bài tập (lthdt-bienhamtinh.cpp): Viết chương trình nhập vào danh sách sinh viên cho tới khi
không muốn nhập thì thôi, mỗi sinh viên có thông tin về mã sinh viên, tên và điểm tbc.
Mã SV là các số nguyên được lấy tự động có giá trị từ 11 trở đi. Đưa ra màn hình số lượng
và danh sách sinh viên đã nhập. Yêu cầu trong chương trình có sử dụng
biến chung và hàm chung, sử dụng đối tượng động.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop sinh vien
class SinhVien
{
    private:
        int maSV;
        char ten[8];
        float diemTBC;

        //Bien tinh
        static int stt;

    public:
        void nhap();
        void hien();

        //Ham tinh
        static int laySL();
};

//Dinh nghia bien tinh
int SinhVien::stt=10;

//===chuong trinh chinh===
int main()
{
    SinhVien *ds[100];
    char traLoi;
    int i=0;

    do
    {
        //Tao doi tuong dong
        ds[i] = new SinhVien;

        //Nhap thong tin
        cout<<"\nNhap thong tin sinh vien:\n";
        ds[i++]->nhap();

        //Hoi nhap tiep ko
        cout<<"\nCo nhap tiep khong(c/k)? ";
        cin>>traLoi;
    }
    while(traLoi=='c' || traLoi=='C');

    //Dua ra
    int n = SinhVien::laySL();
