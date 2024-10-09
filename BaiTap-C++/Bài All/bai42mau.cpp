/*
Bài 42(lthdtbai42.cpp): Tính diện tích các hình: Hình chữ nhật biết 2 cạnh a,b;
hình tam giác biết 3 cạnh a,b,c; hình tròn biết bán kính r, hình trụ biết bán kính r và chiều cao h.
Biết rằng hình trụ là một loại hình tròn có bán kính r được kéo dài với chiều cao h.
Nhập vào một số hình, trong đó có cả hình chữ nhật, hình tam giác, hình tròn và hình trụ.
Đưa ra diện tích các hình đã nhập. Y/c cài đặt đa hình động và lớp trừu tượng; viết 1 hàm
lựa chọn hình, nhập kích thước cho hình và trả về hình đã nhập; viết 1 hàm đưa ra
diện tích của một hình truyền vào qua đối số.
*/
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

class Hinh
{
    private:

    public:
        virtual void nhap()=0;
        virtual float tinhDT()=0;
};

class HinhTG:public Hinh
{
    private:
        float a,b,c;

    public:
        void nhap();
        float tinhDT();
};

class HinhCN:public Hinh
{
    private:
        float a,b;

    public:
        void nhap();
        float tinhDT();
};

class HinhTron:public Hinh
{
    private:
        float r;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};
class HinhTru:public HinhTron
{
    private:
        float h;

    public:
        void nhap();
        float tinhDT();
};

//Khai bao ham thong thuong
Hinh* nhapKT();
void hienDT(Hinh *h);

//===chuong trinh chinh===
int main()
{
    //Khai bao mang con tro lop co so Hinh
    Hinh *a[100];
    char traLoi;
    int n=0;

    //Nhap kich thuoc cac hinh
    do
    {
        //Nhap kich thuoc
        a[n++] = nhapKT();

        //Hoi co nhap tiep ko
        cout<<"\nCo nhap tiep khong(c/k)? ";
        cin>>traLoi;
    }
    while(traLoi=='c' || traLoi=='C');

    //Dua ra dien tich cac hinh da nhap
    cout<<"\nDien tich cac hinh da nhap la:";
    for(int i=0;i<n;i++)
    {
        printf("\nHinh thu %d co ",i+1);
        hienDT(a[i]);
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void HinhTG::nhap()
{
    do
    {
        cout<<"Nhap vao 3 canh tam giac: ";
        cin>>a>>b>>c;

        if(a+b<=c || a+c<=b || b+c<=a)
            cout<<"3 so da nhap khong phai 3 canh tam gaic. Nhap lai.\n";
    }
    while(a+b<=c || a+c<=b || b+c<=a);
}


float HinhTG::tinhDT()
{
    if(a+b>c && a+c>b & b+c>a)
    {
        float p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    return 0;
}

void HinhCN::nhap()
{
    cout<<"Nhap vao 2 canh hinh chu nhat: ";
    cin>>a>>b;
}

float HinhCN::tinhDT()
{
    return a*b;
}

void HinhTron::nhap()
{
    cout<<"Nhap vao ban kinh: ";
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
    //Nhap vao ban kinh ke thua tu lop hinh tron
    HinhTron::nhap();

    cout<<"Nhap vao chieu cao: ";
    cin>>h;
}

float HinhTru::tinhDT()
{
    return 2*HinhTron::tinhDT() + HinhTron::tinhCV()*h;
}

//Ham thong thuong


//Ham thong thuong
Hinh* nhapKT()
{
    Hinh *h;
    char chon;

    cout<<"Lua chon hinh nhap kich thuoc (1-TG,2-CN,3-Tron,4-Tru): ";
    cin>>chon;

    //Tao doi tuong hinh da chon
    switch(chon)
    {
        case '1':
            h = new HinhTG;
            break;
        case '2':
            h = new HinhCN;
            break;
        case '3':
            h = new HinhTron;
            break;
        case '4':
            h = new HinhTru;
            break;
        default:
            h = new HinhTG;
    }

    //Dung da hinh dong de nhap kich thuoc cho doi tuong hinh da tao
    h->nhap();

    //Tra ve hinh da nhap kich thuoc
    return h;
}

void hienDT(Hinh *h)
{
    //Dung da hinh dong de dua ra dien tich cua bat ky hinh nao truyen vao qua con tro h
    printf("dien tich la: %0.1f",h->tinhDT());
}

