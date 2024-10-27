#include<bits/stdc++.h>
using namespace std;

class mathang {
	private: 
		string mahang, tenhang;
		long gia;
		
	public:
		mathang(){}
		mathang(string mh, string th, long cost){
			this->mahang = mh;
			this->tenhang = th;
			this->gia = cost;
		}
		void input(){
			cout<<setw(15)<<left<<"Nhap Ma Hang: ";cin>>this->mahang;
			cin.ignore();
			cout<<setw(15)<<left<<"Nhap Ten Hang: ";getline(cin, this->tenhang);
			cout<<setw(15)<<left<<"Gia Hang: ";cin>>this->gia;cout<<endl;
		}
		void output() {
			cout<<setw(10)<<left<<this->mahang<<setw(30)<<this->tenhang<<setw(15)<<this->gia<<endl;
		}
		void update(long newCost) {
			this->gia = newCost;
		}
		
		friend class donhang;
		friend bool isSort(mathang a, mathang b);
		
};

bool isSort( mathang a,  mathang b) {
	return a.tenhang < b.tenhang;
}

class donhang {
	private:
		vector<mathang> dh;
		
	public: 
		void add (){
			mathang v;
			v.input();
			dh.push_back(v);
		}
		void xoa(string tenhang){
			for(int i = 0; i<dh.size(); i++)
				if(dh[i].tenhang == tenhang){
					dh.erase(dh.begin()+i);
					break;
				}
		}
		void sortt(){
			sort(dh.begin(), dh.end(), isSort);
		}
		void sortt2(){
			for(int i = 0; i< dh.size()-1; i++)
				for(int j = i+1; j< dh.size(); i++ )
					if(	dh[i].tenhang < dh[i].tenhang)
						swap(dh[i], dh[j]);
		}
		long totalMoney(){
			long ttmoney = 0;
			for(auto x : dh)
				ttmoney += x.gia;
			return ttmoney;
		}
		void update(string tenhang, long newCost){
			for(int i = 0; i< dh.size(); i++)
				if(dh[i].tenhang == tenhang){
					dh[i].update(newCost);
					break;
				}
		}
		void Bill(long a){
			cout<<"                  YOUR BILL                      "<< endl<<endl;
			cout<<setw(10)<<left<<"Ma Hang"<<setw(30)<<"Ten Hang"<<setw(15)<<"Gia"<<endl<<endl;
			for(auto x: dh)
				x.output();
			cout<<endl<<setw(40)<<right<<"Tong Tien: "<<a<<endl<<endl;
		}
};

int main(){
	donhang dh;
	cout<<setw(40)<<"Menu"<<endl;
	cout<<"ADD: Them    DELETE: Xoa   SORT: Xap xep  UPDATE: Thay doi gia  MONEY: Tong tien  BILL: in hoa don"<<endl;
	cout<<"THOAT: de thoat CT !!!"<<endl<<endl;
	string option;
	while(true){
		cout<<"Nhap lua chon:: "; cin>>option;
		if(option == "ADD")
			dh.add();
		else if(option == "DELETE"){
			cout<<"Nhap ten hang can xoa: ";string mh; cin>>mh;	
			dh.xoa(mh);
			cout<<endl;
		}
		else if(option == "SORT"){
			dh.sortt();
			cout<<endl;
		}
		else if(option == "MONEY"){
			cout<<dh.totalMoney()<<endl;
		}
		else if(option == "BILL"){
			dh.Bill(dh.totalMoney());
			cout<<endl;
		}
		else if(option == "UPDATE"){
			cout<<"Nhap ten hang can thay gia: ";string mh; cin>>mh;
			cout<<"Nhap gia moi: "; long newCost; cin>>newCost;
			dh.update(mh, newCost);
			cout<<endl;
		}
		else if(option == "THOAT")
			break;
	}
}












