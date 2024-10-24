//Ho ten: Le Tuan Tu
//MaSV: 672231
//Lop: K67CNTTB
//De: Da hinh dong
/*
Tính diện tích các hình: Hình tam giác biết 3 cạnh a,b,c;
hình chữ nhật biết 2 cạnh a,b; hình tròn biết bán kính r;
hình trụ biết bán kính r và chiều cao h.
Biết rằng hình trụ là một loại hình tròn có bán kính r
được kéo dài với chiều cao h. Nhập vào một số hình
tùy theo yêu cầu, trong đó cả cả hình tam giác, chữ nhật,
tròn, trụ. Đưa ra diện tích các hình đã nhập.
Yêu cầu cài đặt đa hình động.
*/
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop doi tuong hinh
class Hinh
{
    private:
    
    public:
        virtual void nhap()=0;
        virtual float tinhDT()=0;
};

//Khai bao lop doi tuong hinh tam giac
class HinhTG:public Hinh
{
    private:
        float a,b,c;
    
    public:
        void nhap();
        float tinhDT();
};

//Khai bao lop doi tuong hinh chu nhat
class HinhCN:public Hinh
{
    private:
        float a,b;
    
    public:
        void nhap();
        float tinhDT();
};

//Khai bao lop doi tuong hinh tron
class HinhTron:public Hinh
{
    private:
        float r;
    
    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

//Khai bao lop doi tuong hinh tru
class HinhTru:public HinhTron
{
    private:
        float h;
    
    public:
        void nhap();
        float tinhDT();
};

//===chuong trinh chinh===
int main()
{
    //Khai bao mang con tro lop co so hinh
    Hinh *a[100];
    
    //Khai bao bien
    int n=0;
    char traLoi,chon;
    
    //Nhap kich thuoc cac hinh
    do
    {
        cout<<"Nhap kich thuoc cho hinh nao (1-TG,2-CN,3-Tron,4-Tru)? ";
        cin>>chon;
        
        //Tao doi tuong hinh theo lua chon
        switch(chon)
        {
            case '1':
                a[n] = new HinhTG;
                break;
            case '2':
                a[n] = new HinhCN;
                break;
            case '3':
                a[n] = new HinhTron;
                break;
            case '4':
                a[n] = new HinhTru;
                break;
            default:
                a[n] = new HinhTG;
        }
        
        //Dung da hinh dong de nhap kich thuoc cho doi tuong hinh da tao
        a[n++]->nhap();
        
        //Hoi co nhap nua ko
        cout<<"\nCo nhap tiep khong(c/k)? ";
        cin>>traLoi;
    }
    while(traLoi=='c' || traLoi=='C');
    
    //Dung da hinh dong de dua ra dien tich cac hinh da nhap
    cout<<"\nDien tich cac hinh da nhap la:";
    for(int i=0;i<n;i++)
        printf("\nDien tich hinh thu %d la: %0.1f",i+1,a[i]->tinhDT());
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop hinh tam giac
void HinhTG::nhap()
{
    do
    {
        cout<<"Nhap vao 3 canh cua tam giac: ";
        cin>>a>>b>>c;
        
        if(a+b<=c || a+c<=b || b+c<=a)
            cout<<"3 so vua nhap khong phai 3 canh tam giac. Nhap lai!\n";
    }
    while(a+b<=c || a+c<=b || b+c<=a);
}

float HinhTG::tinhDT()
{
    if(a+b>c || a+c>b || b+c>a)
    {
        float p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    
    return 0;
}

//Ham thanh vien lop hinh chu nhat
void HinhCN::nhap()
{
    cout<<"Nhap vao 2 canh hinh chu nhat: ";
    cin>>a>>b;
}

float HinhCN::tinhDT()
{
    return a*b;
}

//Ham thanh vien lop hinh tron
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

//Ham thanh vien lop hinh tru
void HinhTru::nhap()
{
    //Nhap ban kinh
    HinhTron::nhap();
    
    //Nhap chieu cao
    cout<<"Nhap vao chieu cao: ";
    cin>>h;
}

float HinhTru::tinhDT()
{
    return 2*HinhTron::tinhDT() + HinhTron::tinhCV()*h;
}