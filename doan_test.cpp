#include<iostream>
#include<string>
#define maxm 300
using namespace std;
struct monhoc
{
	char MAMH[6];
	char TENMH[50];
	float SCTLT;
	float STCTH;
}; typedef struct monhoc MH;
typedef struct list{
	MH *node [maxm];
	int n;
};
void dienTTMH(MH &x)
{
	fflush (stdin);
	cout<<"\nnhap ma mon hoc:";
	gets(x.MAMH);
	cout<<"\nnhap ten mon hoc:";
	gets(x.TENMH);
	cout<<"\nnhap so tin chi ly thuyet:";
	cin>>x.SCTLT;
	cout<<"\nnhap so tin chi thuc hanh:";
	cin>>x.STCTH;
}
void xuatMH(MH x)
{
	cout<<"\nma mon hoc: "<<x.MAMH;
	cout<<"\nten mon hoc: "<<x.TENMH;
	cout<<"\nso tin chi ly thuyet: "<<x.SCTLT;
	cout<<"\nso tin chi thuhc hanh: "<<x.STCTH;
}
void gpvungnho(list &ds)
{
	int j=0;
	while( j<=ds.n)
	{
		
		delete(ds.node[j]);
		j++;
	}
}
void nhapdsMH(list &ds, MH &mh)
{
	ds.n=0;
	while(1)
	{
		int temb;
		cout<<"\nmon hoc thu:"<<(ds.n+1);
		dienTTMH(mh);
		ds.node[ds.n]= new MH;
		if(ds.node[ds.n] == NULL)
	{
		cout<<"cap phat vung nho khong thanh cong!";
		break;
	}
    	*ds.node [ds.n]=mh;
		system("cls");
		chonlai:
		cout<<"ban co muon nhap them mon hoc:"<<endl;
		cout<<"1.yes"<<endl;
		cout<<"2.no"<<endl;
		cin>>temb;
		if(temb ==1 )
		{
    		ds.n++;
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
void xuatdsMH(list &ds)
{
	cout<<"\n================danh sach mon hoc=========="<<endl;
	int j=0;
	while(j<=ds.n)
	{
		cout<<"\nmon hoc thu: "<<j+1;
		xuatMH(*(ds.node[j]));
		j++;
	}
	cout<<"\n====================end===================="<<endl;
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
		cout<<"an 0 de thoat"<<endl;
		cout<<"--------------end-----------"<<endl;
	
		cout<<"\nnhap lua cho cua ban.";
		cin>>n;
		switch(n)
		{
			case 0:break;
			case 1:{
				nhapdsMH(ds,mh);
				break;
			}
			case 2:{
				xuatdsMH(ds);
				system("pause");
				break;
			}
			default:cout<<"co loi xay ra vui long nhap lai lua chon!";
					system("pause");
					continue;
		}
	}
	while(n!=0);
}
int main()
{
	list ds;
	MH mh;
	ds.n=0;
	menu(ds,mh);
	gpvungnho(ds);
}
