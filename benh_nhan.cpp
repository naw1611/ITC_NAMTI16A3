#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct Date{
    int ngay , thang , nam ;
};
class BN {
    Date ns;
    long mahs ;
    char ht[30] , cd[30] ;
    public:
        virtual void nhap(){
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
    }   
        virtual void xuat(){
            cout<<"Ma ho so :"<<mahs<<endl
                <<"Ho ten :"<<ht<<endl
                <<"Ngay sinh :"<<ns.ngay<<"/"<<ns.thang<<"/"<<ns.nam<<endl
                <<"Chuan doan benh :"<<cd<<endl;
    }
    virtual bool kieu_benh_nhan()=0;
            
        int get_nam_sinh(){
            return this->ns.nam; 
        }
};

class NoiTru : public BN{
    char tk[30];
    Date nv;
    Date rv;
    int sg;
    public:
        void nhap(){
            BN::nhap();
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
            cout<<"Nhap ten khoa :";
            cin.getline(tk,30);
            fflush(stdin);
            cout<<"Nhap so giuong :";
            cin>>sg;
        }
        void xuat(){
            BN::xuat();
            cout<<"Ngay nhap vien :"<<nv.ngay<<"/"<<nv.thang<<"/"<<nv.nam<<endl
                <<"Ngay ra vien :"<<rv.ngay<<"/"<<rv.thang<<"/"<<rv.nam<<endl
                <<"Ten khoa :"<<tk<<endl
                <<"So giuong :"<<sg<<endl;
        }
         bool kieu_benh_nhan(){
            return true; 
        }
};

class NgoaiTru : public BN{
    char noichuyen[30];
    Date nc;
    public:
        void nhap(){
            BN::nhap();
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
            cout<<"Ngay chuyen :"<<nc.ngay<<"/"<<nc.thang<<"/"<<nc.nam<<endl
                <<"Noi chuyen :"<<noichuyen<<endl;
        }
        bool kieu_benh_nhan(){
            return false; 
        }
};
class quan_ly_ho_so{
    private:
        BN *ql[100];
        int n;
    public: 
        void nhap_danh_sach(){
            cout<<"Nhap so luong benh nhan co trong danh sach: ";
            cin>>n; 
            //while... 
            
            cout<<"Nhap danh sach "<<n<<" benh nhanh\n";
            for(int i=0;i<n;i++){
                cout<<"\t[+]Bang lua chon:\n"
                    <<"\t\t1. Benh nhan noi tru\n"
                    <<"\t\t2. Benh nhan ngoai tru\n"
                    <<"\t\t  >>Nhap lua chon cua ban: ";
                int lc;cin>>lc;
                while(lc<1 || lc >2){
                    cout<<"\t\t\t> Lua con nay khong ton tai, hay chon lai: ";
                    cin>>lc; 
                }
                     
                if(lc==1){
                    ql[i] = new NoiTru();
                } 
                else
                {
                    ql[i] = new NgoaiTru();
                }
                
                ql[i]->nhap();  
            } 
        }
        
        void xuat_danh_sach(){
            cout<<"Xuat danh sach "<<n<<" ho so\n";
            for(int i=0;i<n;i++){
                cout<<"\t[+]Xuat thong tin cua ho so benh nhan "
                    <<(ql[i]->kieu_benh_nhan() ? "noi tru" : "ngoai tru")
                    <<" thu "<<i+1<<endl; 
                ql[i]->xuat(); 
            } 
        }
        
        void dem_ho_so(){
            int x;
            cout<<"Dem cac ho so co nam sinh lon hon x,nhap x: ";
            cin>>x;
            //while
            
            int cnt_true=0,cnt_false=0;
            
            for(int i=0;i<n;i++)
            {
                if(ql[i]->get_nam_sinh() > x){
                    ql[i]->kieu_benh_nhan() ? cnt_true++ : cnt_false++; 
                } 
            } 
            cout<<"[-]So luong benh nhan theo loai co nam sinh lon hon "<<x<<endl
                <<"\t[+]Benh nhan noi tru: "<<cnt_true<<endl
                <<"\t[+]Benh nhan noi tru: "<<cnt_false<<endl;
             
        }    
}; 

int main()
{
    quan_ly_ho_so *ql = new quan_ly_ho_so();
    
    ql->nhap_danh_sach();
    ql->xuat_danh_sach();
    ql->dem_ho_so(); 
    return 0;
}
