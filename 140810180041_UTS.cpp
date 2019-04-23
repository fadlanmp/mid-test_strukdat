/*
Nama Program		: case 1
Nama				: Fadlan Mulya Priatna
NPM					: 140810180041
Tanggal Pembuatan	: 23 April 2019
Deskripsi Program	: program ini berisikan kodingan case 1
*/

#include <iostream>
using namespace std;

struct  lomba{
	int noDaftar;
	char tim[30];
	char daerah[30];
	int gol;
	lomba* next;
};

typedef lomba* pointer;
typedef pointer List;

void createList (List& First){
	First = NULL;
}

void createElemt (pointer& pBaru){
	pBaru = new lomba;
	cout<<"Masukkan data tim!"<<endl;
	cout<<"No daftar : ";cin>>pBaru->noDaftar;
	cout<<"TIM : ";cin>>pBaru->tim;
	cout<<"Daerah : ";cin>>pBaru->daerah;
	pBaru->gol = NULL;
	pBaru->next = NULL;
}

void insertLast(List& First, pointer pBaru){	
	pointer last;
	if (First==NULL){
		First=pBaru;
	}
	else {
		last=First;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void traversal(List First){
	pointer pBantu;
	if (First==NULL){
		cout<<"Tidak ada tim yang daftar"<<endl;
	}
	else {
		pBantu=First;
		do{
			cout<<"No daftar : "<<pBantu->noDaftar<<endl;
			cout<<"TIM : "<<pBantu->tim<<endl;
			cout<<"Daerah : "<<pBantu->daerah<<endl;
			cout<<"GOL : "<<pBantu->gol<<endl;
			pBantu = pBantu ->next;
		}	
		while (pBantu != NULL);
	}
}

void cariTim(List First, string key, int& found, pointer& pCari){
	found = 0;
	pCari = First;
	while (found==0&&pCari!=NULL){
		if (pCari->tim==key)
			found=1;
		else
			pCari=pCari->next;
	}
}

int main(){
	pointer go;
	List lomba;
	int pilih;
	string tim;
	do{
		cout<<"Menu"<<endl;
		cout<<"1.Input data awal TIM"<<endl;
		cout<<"2.Update gol TIM"<<endl;
		cout<<"3.Tampilkan data TIM"<<endl;
		cout<<"Masukan pilihan :"; cin>>pilih;
		switch(pilih){
			case 1 :
				cout<<endl;
				createElemt (go);
				insertLast (lomba,go);
				cout<<endl;
				break;
			case 2 :
				cout<<endl;
				cout<<"Silakan masukkan nama TIM yang akan diupdate : ";cin>>tim;
				int ketemu;
				cariTim(lomba,tim,ketemu,go);
				if (ketemu){
					cout<<"TIM ditemukan, silakan update gol"<<endl;
					//cout<<"Gol : ";cin>>pBaru->gol;
				}
				else{
				cout<<"Tidak ditemukan"<<endl;
				}
				cout<<endl;
				break;
			case 3 :
				cout<<"Data TIM"<<endl;
				traversal(lomba);
				cout<<endl;
				break;
			default : exit(0);
		}
	}
	while(pilih!=4);
}
