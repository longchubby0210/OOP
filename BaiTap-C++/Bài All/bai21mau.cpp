/*
Bài 21(lthdtbai21.cpp): Tính tổng 2 ma trận nguyên: Cmxn = Amxn + Bmxn. Ma trận Amxn để trong
tệp văn bản "matran-A.txt", ma trận Bmxn để trong tệp văn bản "matran-B.txt".
Đưa các ma trận ra màn hình theo định dạng hàng, cột.
Yêu cầu thêm:
1) Sử dụng toán tử nhập >> để đọc vào ma trận từ tệp;
2) Sử dụng toán tử xuất << để đưa ma trận ra màn hình theo định dạng hàng, cột;
3) Sử dụng toán tử cộng + để cộng 2 ma trận và trả về ma trận tổng;
4) Tự động khởi tạo kích thước ma trận bằng 0.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong ma tran nguyen
class MaTran
{
    private:
        enum {size=10};
        int a[size][size];
        int m,n;

    public:
        MaTran();
        MaTran operator+(MaTran &mt2);

        //Ham ban
        friend ifstream& operator>>(ifstream &fin,MaTran &mt);
        friend ostream& operator<<(ostream &cout,MaTran &mt);
};

//===chuong trinh chinh===
int main()
{
    //Tao 3 doi tuong ma tran
    MaTran A,B,C;

    //Tao doi tuong tep doc vao
    ifstream finA("matran-A.txt");
    ifstream finB("matran-B.txt");

    //Doc ma tran A va B vao doi tuong A, B tuong ung
    finA>>A;
    finB>>B;

    //Dua ma tran A,B ra man hinh
    cout<<"Ma tran A:\n"<<A;
    cout<<"\nMa tran B:\n"<<B;

    //Cong ma tran
    C = A + B;

    //Dua ra ma tran tong
    cout<<"\nMa tran C = A + B:\n"<<C;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
MaTran::MaTran():m(0),n(0)
{

}

MaTran MaTran::operator+(MaTran &mt2)
{
    //Tao doi tuong de chua ma tran tong
    MaTran tong;

    //Kiem tra dieu kien, neu thoa man thi cong ma tran
    if(m==mt2.m && n==mt2.n)
    {
        tong.m = m;
        tong.n = n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                tong.a[i][j] = a[i][j] + mt2.a[i][j];
    }
    else cout<<"\nHai ma tran khong cung kich thuoc, khong cong duoc.\n";

    //Tra ve ma tran tong
    return tong;
}

//Ham ban, ham thong thuong
ifstream& operator>>(ifstream &fin,MaTran &mt)
{
    //Doc kich thuoc ma tran tu tep
    fin>>mt.m>>mt.n;

    //Doc cac phan tu cua ma tran tu tep
    for(int i=0;i<mt.m;i++)
        for(int j=0;j<mt.n;j++)
            fin>>mt.a[i][j];

    return fin;
}

ostream& operator<<(ostream &cout,MaTran &mt)
{
    for(int i=0;i<mt.m;i++)
    {
        //Dua ra hang i
        for(int j=0;j<mt.n;j++)
            printf("%6d",mt.a[i][j]);

        //Xuong dong
        cout<<endl;
    }

    return cout;
}
