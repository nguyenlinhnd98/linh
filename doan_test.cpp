#include<iostream>
#include<string>
#include "mylib.h"
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include<fstream>
#define maxm 300
using namespace std;
struct monhoc
{
	char MAMH[10];
	char TENMH[50];
	float SCTLT;
	float STCTH;
}; typedef struct monhoc MH;
typedef struct list{
	MH *node [maxm];
	int n;
};
int search(list &ds, char *s) {
  for (int i =0; i < ds.n ; i++)
	if (strcmp((ds.node[i]->MAMH),s) == 0) return i;
  return -1;
}
void thongbao (char *S){
  int x=wherex() , y=wherey();
  gotoxy (10,24);
  cout <<S;
  Sleep(2000);
  gotoxy(10,24);
  clreol();
  gotoxy(x,y);
}
char *nhapchuoi(int k)
{
char *kq=new char[k+1]; // tao mang
int n,index=0;
do
{
loop:;
n=getch(); // lay ma ASCII
if ( ( (n>='0' && n<='9') || (n>='A' && n<='Z') || (n>='a' && n<='z') || n==' ' || n=='.' ) && index<k) // Neu thuoc 0-9, A-Z, a-z hoac du . hoac khoang trang&&chuoi dang co it hon k ki tu thi cho phep
{
cout <<char(n); // xuat ky tu do ra màn hình
kq[index++]=n; // Luu vào mang
}
else if (n=='\b' && index>0) // Neu nhan dau BackSpace mà chuoi khong rong
{
cout <<"\b \b"; // Xóa 1 ký tu trên màn hình
kq[--index]=0; // Xóa 1 ký tu trong chuoi kq
}
if (n==13 && index==0) goto loop; // Neu nhan Enter mà chua nhap gì thì k cho phép
}
while (n!=13); // Cu lap lai trong khi chua nhap Enter

kq[index]=0; // Ket thúc chuoi
return kq;

}
void dienTTMH(list ds, MH &x)
{
	int n;
	nhaplai:
	cout<<"\nnhap ma mon hoc:";
	strcpy(x.MAMH, nhapchuoi(9));
	n = search(ds,x.MAMH);
	if(n>=0)
	{
		thongbao("ma mon hoc bi trung!");
		goto nhaplai;	
	}
	fflush (stdin);
	cout<<"\nnhap ten mon hoc:";
	gets(x.TENMH);
	cout<<"\nnhap so tin chi ly thuyet(kieu so float):";
	scanf("%f", &x.SCTLT);
	fflush (stdin);
	cout<<"\nnhap so tin chi thuc hanh(kieu so float):";
	scanf("%f", &x.STCTH);
	fflush (stdin);
}
void xuatMH(MH x)
{
	cout<<"\nma mon hoc: "<<x.MAMH;
	cout<<"\nten mon hoc: "<<x.TENMH;
	cout<<"\nso tin chi ly thuyet: "<<x.SCTLT;
	cout<<"\nso tin chi thuc hanh: "<<x.STCTH;
}
void nhapdsMH(list &ds, MH &mh)
{
	ds.n=0;
	while(1)
	{
		int temb;
		cout<<"\nmon hoc thu:"<<(ds.n+1);
		dienTTMH(ds, mh);
		ds.node[ds.n]= new MH;
		if(ds.node[ds.n] == NULL)
	{
		cout<<"cap phat vung nho khong thanh cong!";
		break;
	}
    	*ds.node [ds.n]=mh;
    	ds.n++;
		system("cls");
		chonlai:
		cout<<"ban co muon nhap them mon hoc:"<<endl;
		cout<<"1.yes"<<endl;
		cout<<"2.no"<<endl;
		cin>>temb;
		if(temb ==1 )
		{
			system("cls");
			continue;
		}
		else if(temb == 2)
		break;
		else
		{
		system("cls");
		goto chonlai;
		}
		
	}
}
void themMH(list &ds,MH &mh)
{
	if (ds.n == maxm ){
		thongbao("mon hoc day!");
		return;
	}
	ds.node[ds.n]= new MH;
	if(ds.node[ds.n] == NULL)
	{
		thongbao("cap phat vung nho khong thanh cong!");
		return;
	}
    	*ds.node [ds.n]=mh;
    	ds.n++;
}
//void hieuchinh ( list ds, char *mamh ) {
//	cout<<"\nma mon hoc muon hieu chinh:";
//	gets(mamh)
//  int i = search (ds, mamh) ;
//  if (i==-1) BaoLoi("Ma so sinh vien khong co trong danh sach");
//  else { printf( " Ho ten sv : %30s%10s", ds.nodes[i]->ho, ds.nodes[i]->ten); 
//         getch () ; }
void xoaMH(list &ds){
	char mamh[10];
	fflush (stdin);
	cout<<"\nnhap ma mon hoc muon xoa:";
	gets(mamh);
   int i = search (ds, mamh) ;
   if (i<0) thongbao("Ma mon hoc khong co trong danh sach");
   else  
   { delete  ds.node[i];
     for (int j=i+1; j <= ds.n; j++)
       ds.node[j-1]=ds.node[j];
       
     ds.n--;  
	}
}
void sapxepA_Z(list &ds){
	MH *tmp;
	tmp= new MH;
	for (int i = 0; i<ds.n-1; i++){
        for (int j = i+1; j<ds.n; j++){
		   if(strcmp(ds.node[i]->TENMH , ds.node[j]->TENMH) > 0 )
		  {
			*tmp = *ds.node[i];
            *ds.node[i] = *ds.node[j];
            *ds.node[j] = *tmp;
		  }
		}
	}
	delete tmp; 
}
void xuatdsMH(list &ds)
{
	sapxepA_Z(ds);
	cout<<"\n================danh sach mon hoc=========="<<endl;
	int j=0;
	while(j<ds.n)
	{
		cout<<"\nmon hoc thu: "<<j+1;
		xuatMH(*(ds.node[j]));
		j++;
	}
	cout<<"\n====================end===================="<<endl;
}
void luufile(list &ds, char file[100])
{
	fstream f;
	f.open(file, ios::out);
	for(int j=0; j<ds.n ; j++)
	{
		f<<ds.node[j]->MAMH<<endl;
		f<<ds.node[j]->TENMH<<endl;
		f<<ds.node[j]->SCTLT<<endl;
		f<<ds.node[j]->STCTH<<endl;
	}
	thongbao("luu file thanh cong!");
	f.close();
}
void doctt(MH &mh, char file[100], fstream &f){
	string temp;
	getline(f,temp);
	strcpy(mh.MAMH,temp.c_str());
	string tempa;
	getline(f,tempa);
	strcpy(mh.TENMH,tempa.c_str());
	f>>mh.SCTLT;
	f>>mh.STCTH;
}
void openfile(list &ds, MH&mh, char file[100],fstream &f){
	if(!f.is_open())
	thongbao("khong the mo file!");
	else{
		ds.n=0;
		while(!f.eof()){
		monhoc mh;
		doctt(mh, "dsmonhoc.txt",f);
		ds.node[ds.n]= new MH;
		if(ds.node[ds.n] == NULL)
	{
		cout<<"cap phat vung nho khong thanh cong!";
		break;
	}
    	*ds.node [ds.n]=mh;
    	ds.n++;
		}
	}
	
}
void gpvungnho(list &ds)
{
	int j=0;
	while( j<ds.n)
	{
		
		delete (ds.node[j]);
		j++;
	}
}
void menu(	list &ds,MH &mh)
{

	int n;
	int a=0;
	do
	{
		system("cls");
		cout<<"--------------menu----------"<<endl;
		cout<<"an 1 them mon hoc vao dsmh"<<endl;
		cout<<"an 2 xuat danh sach mon hoc"<<endl;
		cout<<"an 3 xoa mon hoc"<<endl;
		cout<<"an 4 luu file:"<<endl;
		cout<<"an 0 de thoat"<<endl;
		cout<<"--------------end-----------"<<endl;
	
		cout<<"\nnhap lua cho cua ban.";
		cin>>n;
		switch(n)
		{
			case 0:break;
			case 1:{
				dienTTMH(ds,mh);
				themMH(ds,mh);
				break;
			}
			case 2:{
				xuatdsMH(ds);
				system("pause");
				break;
			}
			case 3:{
				xoaMH(ds);
				cout<<"xoa thanh cong:";
				system("pause");
				break;
			}
			case 4: luufile(ds,"dsmonhoc.txt"); break;
			default:cout<<"co loi xay ra vui long nhap lai lua chon!";
					system("pause");
					continue;
		}
	}
	while(n!=0);
}
int main()
{
	MH mh;
	fstream f;
	f.open("dsmonhoc.txt", ios ::in);
	list ds;
//	doctt(mh, "dsmonhoc.txt");
//	xuatdsMH();
//	nhapdsMH(ds,mh);
	openfile(ds, mh, "dsmonhoc.txt", f);
	menu(ds,mh);
	gpvungnho(ds);
}
