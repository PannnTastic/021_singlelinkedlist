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
    
}