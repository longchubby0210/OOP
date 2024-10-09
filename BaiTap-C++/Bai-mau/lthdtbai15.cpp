//Ho ten :
//Lop :
//Ma SV :
//De :

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>

using namespace std;

class HinhTG{

    private:
        float a,b,c;
    public:
        void nhap();
        void docTep(const char*tenTep);
        float tinhCV();
        float tinhDT();
};

// ===Chuong trinh chinh===
int main(){

    HinhTG htg;
    int chon;
    cout<<">>> TÍNH DIỆN TÍCH VÀ CHU VI CỦA TAM GIÁC <<<\n"<<endl;
    cout<<"=== Vui Lòng chọn phương thức nhập vào tam giác ===\n>>> Nhập 1 để nhập vào 3 cạnh của tam giác từ bàn phím <<<\n>>> Nhập 2 để nhập vào 3 cạnh của tam giác từ tệp <<<"<<endl;
    cin >> chon;
    switch(chon)
    {
        case 1:
            htg.nhap();
            break;
        case 2:
            htg.docTep("tamgiac.txt");
           break;
        default:
            cout<<"Không hợp lệ! \n Mời bạn nhập lại.";
    } 
        
        cout<<"Chu vi của hình tam giác là : "<<htg.tinhCV()<<endl;
        cout<<"Diện tích của hình tam giác: "<<htg.tinhDT()<<endl;
        
    //cout<<chon;
    cout<<endl;
    return 0;
}
//Dinh nghia ham

void HinhTG::nhap()
{
    do {
        cout<<"Nhap vao 3 canh cua tam giac: ";
            cin>>a>>b>>c;
        if(a+b<=c ||a+c<=b || b+c<=a)
        cout<<"3 so vua nhap khong phai la 3 canh cua 1 tam giac. Nhap lai! "<<endl;  
    }while(a+b<=c ||a+c<=b || b+c<=a);
}
void HinhTG::docTep(const char*tenTep)
{
    ifstream fin(tenTep);
    fin>>a>>b>>c;
    cout<<"3 canh cua 1 tam giac la: "<<a<<" "<<b<<" "<<c<<endl;
    fin.close();
}
float HinhTG::tinhCV()
{
    return a + b + c;
}
float HinhTG::tinhDT()
{
    float s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
