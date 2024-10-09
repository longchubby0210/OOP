/*
Bài 43(lthdtbai43.cpp): Viết chương trình quản lý nhân sự của một trường học;
nhân sự gồm có giảng viên và sinh viên; giảng viên có mã gv, họ tên và số bài báo;
sinh viên có mã sv, họ tên và điểm tbc. Nhập vào một số nhân sự trong đó có cả giảng viên
và sinh viên. Đưa ra thông tin của các nhân sự đã nhập kèm theo đánh giá:
giảng viên đánh giá là giỏi nếu số bài báo >=5, sinh viên đánh giá là giỏi
nếu điểm TBC>=8.0. Y/c cài đặt đa hình động.
Yêu cầu thêm:
1) Viết một hàm lựa chọn loại nhân sự cần nhập thông tin, nhập thông tin cho nhân sự
    và trả về nhân sự đã nhập thông tin;
2) Viết một hàm đưa ra thông tin của nhân sự truyền vào qua đối số.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop nhan su
class NhanSu
{
    private:
        char hoTen[36];

    public:
        virtual void nhap();
        virtual void hien();
};

//Khai bao lop giang vien
class GiangVien:public NhanSu
{
    private:
        char maGV[11];
        int soBB;

    public:
        void nhap();
        void hien();
};

//Khai bao lop sinh vien
class SinhVien:public NhanSu
{
    private:
        char maSV[11];
        float diemTBC;

    public:
        void nhap();
        void hien();
};

//Khai bao ham thong thuong
NhanSu* nhapTT();
void hienTT(NhanSu *x);

