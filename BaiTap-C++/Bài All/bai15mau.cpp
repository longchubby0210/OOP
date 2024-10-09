Bài 15(lthdtbai15.cpp): Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c.
Ba cạnh a,b,c có thể nhập vào từ bàn phím hoặc từ tệp văn bản.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop doi tuong tam giac
class HinhTG
{
    private:
        float a,b,c;

    public:
        void nhap();
        void docTep(const char *tenTep);
        float tinhDT();
        float tinhCV();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong tam giac
    HinhTG tg;

    tg.nhap();
    //tg.docTep("tamgiac.txt");

    printf("Dien tich tam giac la: %0.1f",tg.tinhDT());
    printf("\nChu vi tam giac la: %0.1f",tg.tinhCV());

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
            cout<<"3 so da nhap khong phai 3 canh tam giac. Nhap lai!\n";
    }
    while(a+b<=c || a+c<=b || b+c<=a);
}

void HinhTG::docTep(const char *tenTep)
{
    //Tao doi tuong tep doc vao
    ifstream fin(tenTep);

    //Doc 3 canh tam giac tu tep
    fin>>a>>b>>c;

    if(a+b<=c || a+c<=b || b+c<=a)
    {
        printf("3 so tren tep %s khong phai 3 canh tam giac. Kiem tra lai!\n",tenTep);
        a = b = c = 0;
    }
}

float HinhTG::tinhDT()
{
    if(a+b>c && a+c>b && b+c>a)
    {
        float p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    return 0;
}

float HinhTG::tinhCV()
{
    if(a+b>c && a+c>b && b+c>a) return a+b+c;

    return 0;
}
