/*
Bài 30(lthdtbai30.cpp): Đọc vào một dãy số nguyên từ tệp văn bản, trong đó có cả số dương và số âm.
Sử dụng hàng đợi lưu trữ kế tiếp theo kiểu quay vòng để tách, đưa ra màn hình đồng thời
ghi ra tệp văn bản dãy các số dương và dãy các số âm.*/
#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;



int main(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	cout<<q.front()<<endl;
	q.pop();
	q.pop();
	cout<<q.front()<<endl;
	cout<<endl;
	cout<<q.size()<<endl;
	q.pop();
	cout<<q.empty()<<endl;
	return 0;
}
