/**
* @file AgacIslemleri.exe
* @description Txt dosyasından alınan ağaçları çizdirip işlem yapmamızı sağlayan program.
* @course 2.Öğretim B Grubu
* @assignment Ödev-2
* @date 13.12.2024
* @author Ömer Faruk TÜRKDOĞDU omer.turkdogdu@ogr.sakarya.edu.tr G231210002
*/

#ifndef AGAC_HPP
#define AGAC_HPP

#include <string>
using namespace std;

#define AgacSize 30

struct Node
{
    string data;
    Node*next;
};

struct Yaprak
{
    char data;
    Yaprak* root;
    Yaprak* right;
    Yaprak* left;
};

class Agac
{
private:
    
public:
    Node* head;
    char items[AgacSize];
    

    Agac();
    ~Agac();

    void AgacCiz(Node* current,bool aynala);
    void DegerYaz(Node* current,bool aynala);
    int Count();
};




#endif