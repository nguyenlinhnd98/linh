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
void themdsMH(MH *mh, int &n)
{
	while(n < maxm)
	{
		int temb;
		cout<<"\nmon hoc thu:"<<(n+1);
		dienTTMH(*(mh+n));
		system("cls");
		chonlai:
		cout<<"ban co muon nhap them mon hoc:"<<endl;
		cout<<"1.yes"<<endl;
		cout<<"2.no"<<endl;
		cin>>temb;
		if(temb ==1 )
		{
			n++;
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
void xuatdsMH(MH *mh,int n)
{
	cout<<"\n================danh sach mon hoc=========="<<endl;
	int j=0;
	while(j<=n)
	{
		cout<<"\nmon hoc thu: "<<j+1;
		xuatMH(*(mh+j));
		j++;
	}
	cout<<"\n====================end===================="<<endl;
}
void menu(MH *mh,int arr[])
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
				themdsMH(mh,a);
				break;
			}
			case 2:{
				xuatdsMH(mh,a);
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
	int  arr[maxm];

	
	
	

	MH *mh;
	mh=new MH [maxm];
	if(mh == NULL)
	{
		cout<<"cap phat vung nho khong thanh cong!";
		return 0;
	}
	menu(mh,arr);
	delete mh;
}
