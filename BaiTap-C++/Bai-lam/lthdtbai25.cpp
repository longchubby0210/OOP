

//De:
/*
Bài 25(lthdtbai25.cpp): Viết chương trình nhập vào một thời gian có giờ và phút.
Tính và đưa ra màn hình thời gian sau n phút nhập vào từ bàn phím.
Yêu cầu thêm:
1) Sử dụng toán tử nhập >> để nhập vào thời gian ở dạng h:mm
2) Sử dụng toán tử xuất << để đưa ra vào thời gian ở dạng h:mm
3) Sử dụng toán tử cộng để cộng thời gian với số phút n và trả về thời gian.
4) Tự động tạo thời gian có giờ, phút bằng 0;
*/

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
class ThoiGian
{
    private:
        int gio,phut;
    public:
        ThoiGian();
        ThoiGian operator+(int n);
        //Ham ban
        friend istream& operator>>(istream &cin,ThoiGian &tg);
        friend ostream& operator<<(ostream &cout,ThoiGian &tg);

};

int main(){
    ThoiGian time,time1;
    int n;
    cout<<" "<<endl;
    cin>>time;
    cout<<"Nhập số phút cần thêm: ";
    cin>>n;
    
    time1 = time + n;

    cout<<time1<<endl;
    return 0;
}

ThoiGian::ThoiGian():gio(0),phut(0)
{

}

ThoiGian ThoiGian::operator+(int n)
{
    ThoiGian result= *this; // Tạo bản sao của đối tượng hiện tại
        result.phut += n;        // Cộng thêm n phút vào phút
        result.gio += result.phut / 60; // Cộng số giờ từ phút
        result.phut %= 60;       // Giữ lại số phút
        result.gio %= 24;        // Đảm bảo giờ không vượt quá 24
        return result;   
}
istream& operator>>(istream &cin,ThoiGian &tg)
{
    char cham;
    cout<<"Nhập vào thời gian dạng h:mm : ";
    cin>>tg.gio>>cham>>tg.phut;
    return cin;
}
ostream& operator<<(ostream &cout,ThoiGian &tg)
{
    cout<<"Thời gian dạng h:mm là: "<<tg.gio<<":"<<tg.phut;
    return cout;
}
