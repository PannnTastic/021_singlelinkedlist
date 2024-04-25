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

    
}