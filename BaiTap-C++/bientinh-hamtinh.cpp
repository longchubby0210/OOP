//De: Lop co bien chung va ham chung (tinh)
/*
Viết chương trình nhập vào danh sách sinh viên cho tới khi
không muốn nhập thì thôi, mỗi sinh viên có thông tin về
mã sinh viên, tên và điểm tbc. Mã SV là các số nguyên được
lấy tự động có giá trị từ 11 trở đi. 
Đưa ra màn hình số lượng và danh sách sinh viên đã nhập.
Yêu cầu trong chương trình có sử dụng biến chung
và hàm chung, sử dụng đối tượng động.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong sinh vien
class SinhVien
{
    private:
        int maSV;
        char ten[8];
        float diemTBC;
        
        //Bien chung cua lop
        static int stt;
        
    public:
        void nhap();
        void hien();
        
        //Ham chung cua lop
        static int laySL();
};

//Dinh nghia bien chung cua lop SinhVien
int SinhVien::stt=10;

//===chuong trinh chinh===
int main()
{
    SinhVien *ds[50];
    int n,i=0;
    char traLoi;
    
    do
    {
        //Tao doi duong sinh vien, tao dong
        ds[i] = new SinhVien;
        
        //Nhap thong tin sinh vien
        ds[i++]->nhap();
        
        cout<<"\n\nCo nhap tiep khong(c/k)? ";
        cin>>traLoi;
    }
    while(traLoi=='c' || traLoi=='C');

    //Dua ra
    //Lay so luong sinh vien da nhap
    n = SinhVien::laySL(); //Goi ham cua lop
    cout<<"\n\nDanh sach sinh vien da nhap la:\n";
    for(i=0;i<n;i++)
    {
        cout<<"Sinh vien thu "<<i+1<<":\n";
        ds[i]->hien();
        cout<<"\n\n";
    }
    
    cout<<"\nSo luong sinh vien da nhap la: "<<n;
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void SinhVien::nhap()
{
    //Tinh ma sinh vien tu dong va dua ra
    maSV = ++stt;
    cout<<"Sinh vien co ma la: "<<maSV;
    
    //Nhap cac thong tin con lai
    cout<<"\nNhap ten sinh vien: ";cin>>ten;
    cout<<"Nhap diem TBC: ";cin>>diemTBC;
}

void SinhVien::hien()
{
    cout<<"Ma sinh vien: "<<maSV;
    cout<<"\nTen sinh vien: "<<ten;
    cout<<"\nDiem TBC: "<<diemTBC;
}
//Ham cua lop SinhVien
int SinhVien::laySL()
{
    return stt-10;
}