#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Nguoi {
protected:
    string ht ,ns;
public:
    friend istream& operator >> (istream& in, Nguoi &a){
        fflush(stdin);
        cout<<"\nNhap ten: ";
        getline(in,a.ht);
        fflush(stdin);
        cout<<"\nNhap nam sinh: ";
        in>>a.ns;
        return in;
    }
    friend ostream& operator << (ostream& out, Nguoi a){
        out<<"Ten: "<<a.ht<<endl
           <<"Nam Sinh: "<<a.ns<<endl;
        return out;
    }
};

class ThiSinh : public Nguoi {
private :
    char sbd[20];
    float toan , ly , hoa ; 
public :
    
    friend istream& operator >> (istream& in, ThiSinh &a){
        in>>(Nguoi&)a;
        fflush(stdin);
        cout<<"\nNhap so bao danh :";
        cin.getline(a.sbd,20);
        cout<<"\nNhap diem toan :";
        in>>a.toan;
        cout<<"\nNhap diem ly :";
        in>>a.ly;
        cout<<"\nNhap diem hoa :";
        in>>a.hoa;
        return in;
    }
    friend ostream& operator << (ostream& out, ThiSinh a){
        out<<(Nguoi)a;
        out<<"So bao danh :"<<a.sbd<<endl
           <<"Diem toan :"<<a.toan<<endl
           <<"Diem ly :"<<a.ly<<endl
           <<"Diem hoa :"<<a.hoa<<endl;
        return out;
    }
    char *set_sbd(){
            return this->sbd; 
        } 

    float S(){
        return this->toan + this->ly + this->hoa;
    }
    float get_toan(){
        return toan;
    }
        
    float get_ly(){
        return ly;
    }
        
    float get_hoa(){
        return hoa;
    }

};
void Nhap_DS(ThiSinh a[],int &n)
{
    cout<<"\t\tNhap thong tin cho danh sach "<<n<<" thi sinh :\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\tNhap thong tin cho thi sinh thu "<<i+1<<endl; 
        cin>>a[i];
    }   
} 

void Xuat_DS(ThiSinh a[],int n)
{
    cout<<"\t\tXuat thong tin cho danh sach "<<n<<" thi sinh\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\tXuat thong tin cho thi sinh thu "<<i+1<<endl; 
        cout<<a[i];
    }   
} 

void sort(ThiSinh a[], int &n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
        {
            if(a[i].S()>a[j].S()) 
            {
                swap(a[i],a[j]); 
            }
        } 
    } 
    cout<<"\t\t\tDa sap xep thanh cong!\n";
    Xuat_DS(a,n); 
} 

void found(ThiSinh a[],int &n){
    cout<<"tim kiem thi sinh qua so bao danh :\n" ;
    char SBD[20];
    cout<<"Nhap so bao danh thi sinh :";
    fflush(stdin);
    cin.getline(SBD,20);
    bool check=false; 
    for(int i=0;i<n;i++){
        if(strcmpi(a[i].set_sbd(),SBD)==0)
        {
            cout<<a[i];
            check=true;
        } 
    } 
    cout<<(check == false ? "Khong co nguoi ban can tim! \n" : ""); 
} 

void tinh_ti_le(ThiSinh a[],int n){
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].get_toan() >= 5 && a[i].get_ly() >= 5 && a[i].get_hoa() >= 5)
        {
            dem++;
        }
    }
    cout<<"\nXuat ti le thi sinh dat :\n"
        <<"\nTi le dat: "<<(float)dem/n*100<<endl
        <<"\nTi le khong dat: "<<100- ((float)dem/n*100)<<endl;
}

int main()
{
    int n;
    cout<<"Nhap so luong thi sinh co trong danh sach: ";
    cin>>n;
    ThiSinh a[n];
    Nhap_DS(a,n);
    Xuat_DS(a,n); 
    sort(a,n); 
    found(a,n);
    tinh_ti_le(a,n);
    return 0;
}