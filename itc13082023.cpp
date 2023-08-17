#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct Date{
    int ngay , thang , nam ;
};
class BN {
    int loai;
    public:
        virtual void nhap(){
            cout<<"Nhap loai ho so benh nhan: ";
            cin>>loai;
    }   
        virtual void xuat(){
            cout<<"Thong tin: "<<loai<<endl;
    }
};

class NoiTru : public BN{
    long mahs ;
    char ht[30], cd[30] , tk[30];
    Date ns;
    Date nv;
    Date rv;
    int sg;
    public:
        void nhap(){
            BN::nhap();
            cout<<"Nhap ma ho so :";
            cin>>mahs;
            fflush(stdin);
            cout<<"Nhap ho ten :";
            cin.getline(ht,30);
            fflush(stdin);
            cout<<"Nhap ngay sinh :"<<endl;
            cout<<"Nhap ngay :";
            cin>>ns.ngay;
            cout<<"Nhap thang :";
            cin>>ns.thang;
            cout<<"Nhap nam :";
            cin>>ns.nam;
            cout<<"Nhap ngay nhap vien :"<<endl;
            cout<<"Nhap ngay :";
            cin>>nv.ngay;
            cout<<"Nhap thang :";
            cin>>nv.thang;
            cout<<"Nhap nam :";
            cin>>nv.nam;
            cout<<"Nhap ngay ra vien :"<<endl;
            cout<<"Nhap ngay :";
            cin>>rv.ngay;
            cout<<"Nhap thang :";
            cin>>rv.thang;
            cout<<"Nhap nam :";
            cin>>rv.nam;
            fflush(stdin);
            cout<<"Nhap chuan doan benh :";
            cin.getline(cd,30);
            cout<<"Nhap ten khoa :";
            cin.getline(tk,30);
            fflush(stdin);
            cout<<"Nhap so giuong :";
            cin>>sg;
        }
        void xuat(){
            BN::xuat();
            cout<<"Ma ho so :"<<mahs<<endl
                <<"Ho ten :"<<ht<<endl
                <<"Ngay sinh :"<<ns.ngay<<"/"<<ns.thang<<"/"<<ns.nam<<endl
                <<"Ngay nhap vien :"<<nv.ngay<<"/"<<nv.thang<<"/"<<nv.nam<<endl
                <<"Ngay ra vien :"<<rv.ngay<<"/"<<rv.thang<<"/"<<rv.nam<<endl
                <<"Chuan doan benh :"<<cd<<endl
                <<"Ten khoa :"<<tk<<endl
                <<"So giuong :"<<sg<<endl;
        }
};

class NgoaiTru : public BN{
    long mahs ;
    char ht[30], cd[30] , noichuyen[30];
    Date ns;
    Date nc;
    public:
        void nhap(){
            BN::nhap();
            cout<<"Nhap ma ho so :";
            cin>>mahs;
            fflush(stdin);
            cout<<"Nhap ho ten :";
            cin.getline(ht,30);
            fflush(stdin);
            cout<<"Nhap ngay sinh :"<<endl;
            cout<<"Nhap ngay :";
            cin>>ns.ngay;
            cout<<"Nhap thang :";
            cin>>ns.thang;
            cout<<"Nhap nam :";
            cin>>ns.nam;
            fflush(stdin);
            cout<<"Nhap chuan doan benh :";
            cin.getline(cd,30);
            fflush(stdin);
            cout<<"Nhap ngay chuyen :"<<endl;
            cout<<"Nhap ngay :";
            cin>>nc.ngay;
            cout<<"Nhap thang :";
            cin>>nc.thang;
            cout<<"Nhap nam :";
            cin>>nc.nam;
            fflush(stdin);
            cout<<"Nhap noi chuyen :";
            cin.getline(noichuyen,30);
        }
        void xuat(){
            BN::xuat();
            cout<<"Ma ho so :"<<mahs<<endl
                <<"Ho ten :"<<ht<<endl
                <<"Ngay sinh :"<<ns.ngay<<"/"<<ns.thang<<"/"<<ns.nam<<endl
                <<"Chuan doan benh :"<<cd<<endl
                <<"Ngay chuyen :"<<nc.ngay<<"/"<<nc.thang<<"/"<<nc.nam<<endl
                <<"Noi chuyen :"<<noichuyen<<endl;
        }
};

void Nhap_DS(int &n, int &m)
{
    cout<<"\t\tNhap thong tin cho danh sach "<<n<<" benh nhan noi tru :\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\tNhap thong tin cho benh nhan thu "<<i+1<<endl; 
        BN *noitru  = new NoiTru();
				noitru->nhap();
    }   

    cout<<"\t\tNhap thong tin cho danh sach "<<m<<" benh nhan noi tru :\n";
    for(int i=0;i<m;i++)
    {
        cout<<"\tNhap thong tin cho benh nhan thu "<<i+1<<endl; 
        BN *ngoaitru  = new NgoaiTru();
				ngoaitru->nhap();
    }   
}
void Xuat_DS(int n, int m)
{
    BN *noitru  = new NoiTru();
    BN *ngoaitru  = new NgoaiTru();
    cout<<"\t\tXuat thong tin danh sach benh nhan :\n";
    for(int i=0;i<n+m;i++)
    {
        cout<<"\tXuat thong tin cho benh nhan thu "<<i+1<<endl; 
			noitru->xuat();
			ngoaitru->xuat();
    }   
} 
int main(){
    int n , m ;
    cout<<"\nNhap so benh nhan noi tru :";
    cin>>n;
    cout<<"\nNhap so benh nhan ngoai tru :";
    cin>>m;
    Nhap_DS(n,m);
    Xuat_DS(n,m);
    return 0;
}