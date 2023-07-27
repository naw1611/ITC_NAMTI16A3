#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;
class GiaoVien{
	private :
        char ten[30] , bc[15] ;
	    int tuoi ;
	    float bl ;
    public :
        char cn[20];
        void nhap()
        {
        	fflush(stdin);
        	cout<<"\nNhap ho ten :"; cin.getline(this->ten,30);
        	fflush(stdin);
        	cout<<"\nNhap tuoi :"; cin>>this->tuoi;
        	fflush(stdin);
        	cout<<"\nNhap bang cap :"; cin.getline(this->bc,15);
        	cout<<"\nNhap chuyen nganh :"; cin.getline(this->cn,20);
        	fflush(stdin);
        	cout<<"\nNhap bac luong :"; cin>>this->bl;
        }
        float lcb(){
        	return this->bl*610;
		}
        void xuat();
    
};
void GiaoVien::xuat(){
	cout<<left<<setw(31)<<this->ten
        	    <<left<<setw(10)<<this->tuoi
        	    <<left<<setw(16)<<this->bc
        	    <<left<<setw(21)<<this->cn
        	    <<left<<setw(10)<<this->bl
                <<left<<setw(20)<<lcb()<<endl;
}
void NhapDS(GiaoVien a[], int &n)
{
	for(int i=0 ; i<n ; i++)
	{
		cout<<"\nNhap thong tin giao vien thu "<<i+1<<endl;
		a[i].nhap();
	}
}

void TD()
{
	cout<<"============================DANH SACH THONG TIN GIAO VIEN========================"<<endl;
	cout<<left<<setw(31)<<"HO TEN"
        <<left<<setw(10)<<"TUOI"
        <<left<<setw(16)<<"BANG CAP"
   	    <<left<<setw(21)<<"CHUYEN NGANH"
   	    <<left<<setw(10)<<"BAC LUONG"
   	    <<left<<setw(20)<<"LUONG CO BAN"<<endl;
}

void XuatDS(GiaoVien a[], int n)
{
	for(int i=0 ; i<n ; i++)
	{
		a[i].xuat();
	}
}

void TLduoi2000(GiaoVien a[], int &n)
{
	cout<<"\nDanh sach giao vien co tien luong duoi 2000 :"<<endl;
	TD();
	for(int i=0 ; i<n ; i++)
	{
		if(a[i].lcb() < 2000 )
		a[i].xuat();
	}
}

void Sapxep(GiaoVien a[], int n)
{
	cout<<"\n-Danh sach sau khi sap xep theo nganh :"<<endl;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
           if(strcmp(a[i].cn,a[j].cn)>0)
          {
            GiaoVien k=a[i];
            a[i]=a[j];
            a[j]=k;
          }
        }
    } 
}

int main()
{
	int n;
	cout<<"\nNhap so luong giao vien :"; cin>>n;
	GiaoVien a[n];
	NhapDS(a,n);
	cout<<"\nDanh sach giao vien :"<<endl;
	TD();
	XuatDS(a,n);
	TLduoi2000(a,n);
    Sapxep(a,n);
	XuatDS(a,n);
	return 0;
}