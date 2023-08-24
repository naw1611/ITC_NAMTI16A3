#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
struct Date{
    int ngay , thang , nam ;
};
class Doc_gia {
    Date ngaythue;
    Date ngaytra;
    long masach ;
    char ts[30] , tg[30] , ten[30];
    int tuoi;
    public:
        virtual void nhap(){
            cout<<"Nhap ma sach :";
            cin>>masach;
            fflush(stdin);
            cout<<"Nhap ten sach :";
            cin.getline(ts,30);
            cout<<"Nhap tac gia :";
            cin.getline(tg,30);
            cout<<"Nhap ten nguoi thue :";
            cin.getline(ten,30);
            fflush(stdin);
            cout<<"Nhap tuoi :";
            cin>>tuoi;
            cout<<"Nhap ngay thue :"<<endl;
            cout<<"Nhap ngay :";
            cin>>ngaythue.ngay;
            cout<<"Nhap thang :";
            cin>>ngaythue.thang;
            cout<<"Nhap nam :";
            cin>>ngaythue.nam;
            cout<<"Nhap ngay tra :"<<endl;
            cout<<"Nhap ngay :";
            cin>>ngaytra.ngay;
            cout<<"Nhap thang :";
            cin>>ngaytra.thang;
            cout<<"Nhap nam :";
            cin>>ngaytra.nam;
    }   
        virtual void xuat(){
            cout<<"Ma sach :"<<masach<<endl
                <<"Ten sach :"<<ts<<endl
                <<"Tac gia :"<<tg<<endl
                <<"Ten nguoi thue :"<<ten<<endl
                <<"Tuoi :"<<tuoi<<endl
                <<"Ngay thue :"<<ngaythue.ngay<<"/"<<ngaythue.thang<<"/"<<ngaythue.nam<<endl
                <<"Ngay tra :"<<ngaytra.ngay<<"/"<<ngaytra.thang<<"/"<<ngaytra.nam<<endl;
    }
        virtual bool kieu_doc_gia()=0;
    int get_ngay_thue(){
        return this->ngaythue.ngay;
    }
    int get_thang_thue(){
        return this->ngaythue.thang;
    }  
    int get_nam_thue(){
        return this->ngaythue.nam;
    }  
    int get_ngay_tra(){
        return this->ngaytra.ngay;
    }  
    int get_thang_tra(){
        return this->ngaytra.thang;
    }  
    int get_nam_tra(){
        return this->ngaytra.nam;
    } 
    bool laNamNhuan(int y){
	if((y%4==0 && y%100!=0) || y%400==0)
	   return true;
	return false;

}
int tinh_so_ngay_trong_thang(int m , int y){
	if(m==2)
	   if(laNamNhuan(y))
	        return 29;
		else
		    return 28;
	else
	    if(m==4 || m ==6 || m==9 || m==11)
		    return 30;
		else
		    return 31;
}
int tinh_so_ngay_tu_dau_nam(int d , int m , int y){
	int songay = d;
	for(int i =1 ; i<m ; i++){
		songay = songay + tinh_so_ngay_trong_thang(i,y);
	}
	return songay;
}
int tinh_so_ngay(int d , int m , int y){
	int kc=0;
	for(int i=1 ; i<y ; i++){
		if(laNamNhuan(i)==true)
		   kc = kc+366;
		else
		   kc = kc+365;
	}
	kc = kc + tinh_so_ngay_tu_dau_nam(d,m,y);
	return kc;
}
int tinh_khoang_cach(int d1, int m1, int y1, int d2,int m2,int y2){
	int kc1 =tinh_so_ngay(d1,m1,y1);
	int kc2 =tinh_so_ngay(d2,m2,y2);
	int songay = abs(kc2-kc1);
	return songay;
}
char* get_tg(){
    return this->tg;
}
};

class Tre_em : public Doc_gia{
    char tennguoigiamho[30];
    public:
        void nhap(){
            Doc_gia::nhap();
            fflush(stdin);
            cout<<"Nhap ten nguoi giam ho :";
            cin.getline(tennguoigiamho,30);
        }
        void xuat(){
            Doc_gia::xuat();
            cout<<"Ten nguoi giam ho :"<<tennguoigiamho<<endl
                <<"Thanh tien :"<<tinh_tien()<<endl;
        }
        float tinh_tien(){
            int songay= tinh_khoang_cach(get_ngay_thue(),get_thang_thue(),get_nam_thue(),get_ngay_tra(),get_thang_tra(),get_nam_tra());
            return songay*2000;
        }
         bool kieu_doc_gia(){
            return true; 
        }
};

class Nguoi_lon : public Doc_gia{
    char cmt[30];
    Date nc;
    public:
        void nhap(){
            Doc_gia::nhap();
            fflush(stdin);
            cout<<"Nhap chung minh thu :";
            cin.getline(cmt,30);
        }
        void xuat(){
            Doc_gia::xuat();
            cout<<"So chung minh thu :"<<cmt<<endl
                <<"Thanh tien :"<<tinh_tien()<<endl;
        }
        float tinh_tien(){
            int songay= tinh_khoang_cach(get_ngay_thue(),get_thang_thue(),get_nam_thue(),get_ngay_tra(),get_thang_tra(),get_nam_tra());
            return songay*3000;
        }
        bool kieu_doc_gia(){
            return false; 
        }
};
class quan_ly_ho_so{
    private:
        Doc_gia *ql[100];
        int n;
    public: 
        void nhap_ds(){
            cout<<"Nhap so luong doc gia co trong danh sach: ";
            cin>>n; 
            cout<<"Nhap danh sach "<<n<<" doc gia\n";
            for(int i=0;i<n;i++){
                cout<<"\nBang lua chon:\n"
                    <<"\n1. Doc gia tre em\n"
                    <<"\n2. Doc gia nguoi lon\n"
                    <<"\n>>Nhap lua chon cua ban: ";
                int lc;
                cin>>lc;
                while(lc<1 || lc >2){
                    cout<<"\nLua con nay khong ton tai, hay chon lai: ";
                    cin>>lc; 
                }
                     
                if(lc==1){
                    ql[i] = new Tre_em();
                } 
                else
                {
                    ql[i] = new Nguoi_lon();
                }
                
                ql[i]->nhap();  
            } 
        }
        
        void xuat_ds(){
            cout<<"Xuat danh sach "<<n<<" ho so\n";
            for(int i=0;i<n;i++){
                cout<<"\n\t\t\tXUAT THONG TIN DOC GIA  "
                    <<(ql[i]->kieu_doc_gia() ? "tre em" : "nguoi lon")
                    <<" thu "<<i+1<<endl; 
                ql[i]->xuat(); 
            } 
        } 
        bool cmp(Doc_gia *a, Doc_gia *b){
            return a->get_tg() < b->get_tg();
        }
        void sapxep(){
            cout << "\n\t\t\tDANH SACH DOC GIA SAU KHI SAP XEP\n";
			sort(ql,ql + n,cmp);
			for(int i = 0; i < n;i++){
				cout << "Thong tin doc gia thu " << i + 1 << endl;
				ql[i]->xuat();
			}
        }
}; 

int main()
{
    quan_ly_ho_so *ql = new quan_ly_ho_so();
    ql->nhap_ds();
    ql->xuat_ds();
    ql->sapxep();
    return 0;
}
