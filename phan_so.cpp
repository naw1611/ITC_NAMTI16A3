#include <stdio.h>
#include <iostream>
using namespace std;

class Phanso
{
private:
    int tuso, mauso;

public:
    Phanso()
    {
        tuso = 0;
        mauso = 1;
    }

    ~Phanso()
    {
        tuso = 0;
        mauso = 1;
    }

    void nhap()
    {
        cout << "Nhap Tu So: "; 
		cin >> this->tuso;
        cout << "Nhap Mau So: "; 
		cin >> this-> mauso;
        do
        {
        	if(mauso == 0)
        	{
			cout<<"\nNhap sai , nhap lai!"<<endl;
        	cin>>this-> mauso;
        	}
		}while(mauso == 0);
    }

    void xuat()
    {
        cout << this->tuso << "/" << this->mauso << endl;
    }
};
int main()
{
    Phanso a;
    a.nhap();
    a.xuat();
    return 0;
}