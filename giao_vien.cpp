#include<iostream>
#include<string.h>
using namespace std;
class GiaoVien{
    private :
        char ht[30], bc[15], cn[20];
        int tuoi;
        float bl;
    public :
        friend istream& operator >> (istream& in , GiaoVien &a){
            fflush(stdin);
            cout<<"\nNhap ho ten :";
            in.getline(a.ht,30);
            cout<<"\nNhap tuoi :";
            in>>a.tuoi;
            fflush(stdin);
            cout<<"\nNhap bang cap :";
            in.getline(a.bc,15);
            cout<<"\nNhap chuyen nganh :";
            in.getline(a.cn,20);
            cout<<"\nNhap bac luong :";
            in>>a.bl;
            return in;
        }
        float lcb(){
        	return this->bl*610;
        }
        friend ostream& operator <<(ostream& out, GiaoVien a){
            out<<"\nHo va ten :"<<a.ht<<endl
               <<"\nTuoi :"<<a.tuoi<<endl
               <<"\nBang cap :"<<a.bc<<endl
               <<"\nChuyen nganh :"<<a.cn<<endl
               <<"\nBac luong :"<<a.bl<<endl
               <<"\nLuong co ban :"<<a.lcb()<<endl;
            return out;
        }
        bool operator == (GiaoVien a){
            return strcmpi(this->bc,a.bc) == 0;
        }
        char* get_bc()
        {
            return this->bc; 
        } 

};

void Nhap_DSGV(GiaoVien a[], int &n){
    for(int i = 0 ; i < n ; i++){
        cout<<"\nNhap thong tin giao vien thu "<<i+1<<endl;
        cin>>a[i];
    }
}

void Xuat_DSGV(GiaoVien a[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<"\nThong tin giao vien thu "<<i+1<<endl;
        cout<<a[i];
    }
}

void Sosanh2GV(GiaoVien a[], int &n){
    GiaoVien c,b;
    cin>>c>>b;
    if(c==b)
       cout<<"\nBang cap giong nhau"<<endl;
    else
       cout<<"\nBang cap khac nhau"<<endl;
}

void SapXep(GiaoVien a[],int &n){
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmpi(a[i].get_bc() , a[j].get_bc())==1) 
                swap(a[i],a[j]); 
        } 
    } 
}

int main()
{
    int n ;
    cout<<"\nNhap so giao vien :";
    cin>>n;
    GiaoVien a[n];
    cout<<"\n-Nhap thong tin giao vien :"<<endl;
    Nhap_DSGV(a,n);
    cout<<"\n-Xuat thong tin giao vien :"<<endl;
    Xuat_DSGV(a,n);
    cout<<"\n-Thong tin sau khi sap xep :"<<endl;
    SapXep(a,n);
    Xuat_DSGV(a,n);
    cout<<"\n-So sanh 2 giao vien ve bang cap :"<<endl;
    Sosanh2GV(a,n);
    return 0;
}