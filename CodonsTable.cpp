#include "CodonsTable.h"

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

CodonsTable::CodonsTable()
{
    //ctor
}

CodonsTable::~CodonsTable()
{

}

void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
    //map <string, char> codon;
    ifstream infile;
    infile.open(codonsFileName.c_str(),ios::in);
    //string key[64];
    //char kvalue[64];
    int i=0;
    while (infile)
    {
        infile >> codons[i].value;
        infile >> codons[i].AminoAcid;
        //infile >> key[i] >> kvalue[i];
        //codon[key[i]] = kvalue[i];


        i++;
    }

infile.close();
    /*i=0;
    for (int c=0 ; c<64 ; c++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            key[c][j] = codons[c].value[j];
        }
        kvalue[c] = codons[c].AminoAcid;
    }*/
}

Codon CodonsTable::getAminoAcid(string value)
{
    for (int i=0 ; i<64 ; i++)
    {
        if (value == codons[i].value)
        {
              return codons[i];
        }
    }

}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{

}

