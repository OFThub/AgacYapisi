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

Agac::Agac()
{
    head=nullptr;
}

Agac::~Agac()
{
}

Yaprak* AddToTree(Yaprak* root, char data)
{
    if (root == nullptr)
    {
        root = new Yaprak();
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }

    if (data < root->data)
    {
        root->left = AddToTree(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = AddToTree(root->right, data);
    }

    return root;
}

Yaprak* Aynala(Yaprak* root)
{
    if (root == nullptr)
        return nullptr;

    Yaprak* temp = root->left;
    root->left = root->right;
    root->right = temp;

    if (root->left)
        Aynala(root->left);
    if (root->right)
        Aynala(root->right);

    return root;
}

void PrintTree(Yaprak* root, int space, int way)
{
    if (root == nullptr)
        return;
    
    space += 5;
    
    PrintTree(root->right, space, 1);

    
    
    cout << endl;
    if (way == 1) 
    {
        cout << setw(space - 1) << "/";
    }

    else if (way == 2) 
    {
        cout << setw(space - 1) << "\\";
    }
    cout << root->data << endl;
    PrintTree(root->left, space, 2);
}

int DegerHesapla(Yaprak* root, int way,int deger)
{
    if (root == nullptr)
        return deger;
    deger=DegerHesapla(root->right, 1,deger);
    if (way == 1) 
    {
        deger+=static_cast<int>(root->data);
    }

    else if (way == 2) 
    {
        deger+=2*static_cast<int>(root->data);
    }

    deger=DegerHesapla(root->left,2,deger);
    return deger;
}

void Agac::DegerYaz(Node* current,bool aynala)
{
    int deger=0;
    Yaprak* root = nullptr;

    for (char c : current->data)
    {
        if(deger==0)
        {
            deger+=static_cast<int>(c);
        }
        root = AddToTree(root, c);
    }
    if(aynala)
    {
        Aynala(root);
    }
    deger+=DegerHesapla(root,0,deger);
    cout << "*" << setw(9) << deger << "*";
    cout << "    ";
}


void Agac::AgacCiz(Node* current,bool aynala)
{
    
    if (current == nullptr)
        return;

    Yaprak* root = nullptr;

    for (char c : current->data)
    {
        root = AddToTree(root, c);
    }

    if(aynala)
    {
        Aynala(root);
    }

    PrintTree(root,0,0);
}

int Agac::Count()
{
    Node* current=head;
    int index = 0;
    while(current)
    {
        index++;
        current=current->next;
    }
    return index;
}