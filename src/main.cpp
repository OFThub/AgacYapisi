/**
* @file AgacIslemleri.exe
* @description Txt dosyasından alınan ağaçları çizdirip işlem yapmamızı sağlayan program.
* @course 2.Öğretim B Grubu
* @assignment Ödev-2
* @date 13.12.2024
* @author Ömer Faruk TÜRKDOĞDU omer.turkdogdu@ogr.sakarya.edu.tr G231210002
*/

#include "Agac.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#define boslukMiktari 11

const int satir = 15;

void CizgiCiz(int miktar)
{
    for(int i = 0; i < miktar; i++)
    {
        for(int j = 0; j < boslukMiktari; j++)  
        {
            cout << "*";
        }
        cout << "    ";
    }
    cout<<endl;
}

void AdresYaz(Node* current)
{
    while (current)
    {
        cout<<"*"<<setw(9)<<current<<"*";
        cout<<"    ";
        current=current->next;
    }
    cout<<endl;
}

void SonrakiAdresYaz(Node* current)
{
    current=current->next;
    while (current)
    {
        cout<<"*"<<setw(9)<<current<<"*";
        cout<<"    ";
        current=current->next;
    }
    cout<<endl;
}

void ListeCiz(int miktar,Node* current,Agac agac,Node*head,bool aynala)
{
    CizgiCiz(miktar);
    AdresYaz(current);
    CizgiCiz(miktar);
    while(head)
    {
        agac.DegerYaz(head,aynala);
        head=head->next;
    }
    cout<<endl;
    CizgiCiz(miktar);
    SonrakiAdresYaz(current);
    CizgiCiz(miktar);
}


void IsaretYaz(int index)
{
    if(index != 0)
    {
        for(int i = 0; i < index; i++)
        {
            for(int i = 0; i < boslukMiktari; i++)
            {
                cout << " ";
            }
            cout << "    ";
        }
    }
    cout << "^^^^^^^^^^^" << endl;

    if(index != 0)
    {
        for(int i = 0; i < index; i++)
        {
            for(int i = 0; i < boslukMiktari; i++)
            {
                cout << " ";
            }
            cout << "    ";
        }
    }
    cout << "!!!!!!!!!!!" << endl;
}

void NodeSil(Node*& head, int index)
{
    if (head == nullptr) return;

    Node* current = head;
    Node* previous = nullptr;

    if (index == 0) {
        head = current->next;
        delete current;
        return;
    }

    for (int i = 0; current != nullptr && i < index; i++) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) return;

    previous->next = current->next;
    delete current;
}

int DosyaOku(const std::string& dosyaAdi, std::string satirlar[], int Satir)
{
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cerr << "Dosya açılamadı: " << dosyaAdi << endl;
        return 0;
    }

    int satirSayisi = 0;
    while (getline(dosya, satirlar[satirSayisi]) && satirSayisi < Satir) {
        satirSayisi++;
    }

    dosya.close();
    return satirSayisi;
}

int main()
{
    Agac agac;

    string satirlar[satir];
    const string dosyaAdi = "agaclar.txt";

    int okunanSatirSayisi = DosyaOku(dosyaAdi, satirlar, satir);

    Node* current = nullptr;

    
    for (int i = 0; i < okunanSatirSayisi; i++) 
    {
        Node* newNode = new Node;
        newNode->data = satirlar[i];
        newNode->next = nullptr;

        if (agac.head == nullptr) 
        {
            agac.head = newNode;
        } 
        else 
        {
            current->next = newNode;
        }
        current = newNode; 
    }

    current = agac.head; 
    Node* nodeHead=agac.head;
    int index=0;
    string secim;
    bool aynala = false;
    while(true)
    {
        system("cls");
        
        
        ListeCiz(agac.Count(),agac.head,agac,nodeHead,aynala);
        IsaretYaz(index);
        cout<<endl;
        agac.AgacCiz(current,aynala);
        
        getline(cin, secim);

        

        if(secim == "x")
        {
            break;
        }
        else if(secim=="w")
        {
            if(aynala==false)
            {
                aynala=true;
            }
            else if(aynala==true)
            {
                aynala=false;
            }
        }
        else if (secim=="a")
        {
            index--;
            current = agac.head;
            for(int i=0;i<index;i++)
            {
                current=current->next;
            }
        }
        else if (secim=="s")
        {
            if(index==0)
            {
                nodeHead=agac.head->next;
            }
            NodeSil(agac.head, index);
            index--;

            

            current = agac.head;
            
            if(index==agac.Count())
            {
                index==agac.Count()-1;
            }

            for(int i = 0;i<index-1;i++)
            {
                current=current->next;
            }
        }
        else if (secim=="d")
        {
            index++;
            if(current->next)
            {
                current=current->next;
            }
            
        }
        if(index>agac.Count()-1)
        {
            index=agac.Count()-1;
        }
        else if(index<0)
        {
            index=0;
        }
        if(!current)
        {
            system("cls");
            cout<<"Ilsem yapilacak agac kalmamistir."<<endl;
            break;
        }
    }
    system("cls");
    return 0;
}
