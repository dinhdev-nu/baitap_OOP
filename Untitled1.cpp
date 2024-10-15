#include<bits/stdc++.h>

using namespace std;

class vattu{
	public:
		string tenvt;
		int soluong, dongia;
		
		vattu(string tenvt, int sl , int dg) {
			this->tenvt = tenvt;
			this->soluong = sl;
			this->dongia = dg;
		}
		
};
bool isShort(vattu a, vattu b){
	return a.dongia > b.dongia;
}
class hoadon {
	private:
		string mahd, tenkh;
		vector<vattu> x;
	public:
		hoadon(string mhd, string tkh){
			cout<<"----------------------------- Your Bill ------------------------------"<<endl<<endl;

			this->mahd = mhd;
			this->tenkh = tkh;
			cout<<"Ma Hoa Don:      "<<mahd<<endl;
			cout<<"Ten Khach Hang:  "<<tkh<<endl<<endl;
			
			cout<<"Danh sach vat tu::"<< endl;
			int i = 0;
			while(true){
				
				cout<<"---------- Vat tu "<< i+1 <<":" << " ( Nhan ENTER de ket thuc )"<<endl;
				cout<<"Ten vat tu:_________ ";
				string tenvt; getline(cin, tenvt);
				
				if(tenvt == "")
				break;
				cout<<"So luong, done gia: ";
				int soluong;cin>>soluong;
				int dongia; cin>>dongia;
				cout<<endl<<endl;
				vattu vt(tenvt, soluong, dongia);
				
				i++;
				x.push_back(vt);
				cin.ignore();
			}
			
		}
		
		void sapsep (){
			sort(x.begin(), x.end(), isShort);
		}
		
		long long thanhtien (){
			long long money = 0;
			for(auto i : x)
				money+=(i.soluong * i.dongia);
				
			return money;
		}
		
		void in () {
			for(auto i : x)
				cout<<i.tenvt<<"  ";
		}
};

int main() {
	hoadon hoadon1("1", "dinh");
	cout<<endl<<endl<<"___________________________ Thanh tien: "<<hoadon1.thanhtien()<<" USD"<<endl<<endl;
	hoadon1.in();
	hoadon1.sapsep();
	
	cout<<endl<<"Xap xep:";
	hoadon1.in();
}
