#include<iostream>
using namespace std;

struct  node
{
    int noMhs;
    string name;
    node* next;
};

node* START = NULL;

void addnode(){
    int nim;
    string nama;
    node* nodebaru = new node();

    cout << "Masukkan NIM : ";
    cin >> nim;
    cout << "Masukkan Nama : ";
    cin >> nama; 
    
    nodebaru -> noMhs = nim;
    nodebaru -> name = nama;

    if (START == NULL || nim <= START -> noMhs){
        if(START != NULL && nim == START -> noMhs){
            cout << "NIM sudah ada " << endl;
            return;
        }
         nodebaru ->next = START;
          START = nodebaru;
         return;
    }

    node* previous = START;
    node* current = START;

    while ((current != NULL) && (nim >= current -> noMhs))
    {
       if (nim == current -> noMhs)
       {
        cout << "NIM sudah ada" << endl;
        return;
       }
       previous = current;
       current = current->next;
       
    }
    nodebaru->next = current;
    previous->next = nodebaru;
    
}

bool searchnode(int nim, node* current,node* previous){
    previous = START;
    current = START;

    while (current != NULL && nim > current->noMhs)
    {
       previous = current;
       current = current->next;
    }

    if (current == NULL){
        return false;
    }
    else if (current->noMhs == nim){
        return true;
    }
    else{
        return false;
    }
    
}

bool deletenode (int nim){
    node* current = START;
    node* previous = START;

    if(searchnode(nim,previous,current)==false)
        return false;
    previous->next = current->next;
    if (current == START)
        START = current->next;
    return true;
}

bool listempty(){
    if( START == NULL)
        return true;
    else
        return false;
    
}

void traverse(){
    if (listempty()){
        cout<< "List Kosong" << endl;
        system ( "pause");
        system ("cls");
        return;
    }
    else {
        node* currentnode = START;
        while ( currentnode != NULL){
            cout << "NIM : " << currentnode->noMhs << ", Nama : " << currentnode->name << endl;
            currentnode = currentnode->next;
        }
    }
}

void searchdata(){
    if (listempty()){
        cout<< "List Kosong" << endl;
        system ( "pause");
        system ("cls");
        return;
    }
    else {
        int nim;
        cout<< "Masukkan NIM : ";
        cin >> nim;
        node* currentnode = START;
        while ( currentnode != NULL ){
            if( currentnode->noMhs == nim){
                cout << "NIM : " << currentnode->noMhs << ", Nama : " << currentnode->name << endl;
                return;
            }
            currentnode = currentnode->next;
        }
        cout << "Data tidak ditemukan "<< endl;
    }
}

int main (){
    int pil;
    do
    {
        try
        {
            cout << "1. Tambah Data " << endl;
            cout << "2. Hapus Data \n";
            cout << "3. Tampilkan Data \n";
            cout << "4. Cari Data \n";
            cout << "5. Keluar \n";
            cout << "Pilihan : ";
            cin >> pil;

            switch (pil){
                case 1: addnode();
                    cout << "data Berhasil Ditambahkan\n";
                    system ("pause");
                    system("cls");
                    break;
                case 2: 
                    if (listempty()){
                       cout <<"List Kosong\n";
                       system ("pause");
                       system ("cls");
                       break; 
                    }
                    int nim;

                    cout << "Masukkan Nim : ";
                    cin >> nim;
                    if (deletenode(nim)){
                        cout << "Nim : " << nim << "Berhasil Dihapus\n";
                        system ("Pause");
                        system ("cls");
                    }
                    else{
                        cout << "Data tidak ditemukan\n";
                    }
                    break;
                case 3 :
                    traverse();
                    break;
                case 4 : 
                    searchdata();
                    break;
                case 5 :
                    break;
                default:
                    cout<< "PILIHAN TIDAK ADA\n";
                    break;
            }
        }
        catch(exception e)
        {
            cout << "Terjadi Kesalahan\n";
        }
        
    } while (pil != 5);
    
}