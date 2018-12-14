#include "RNA.h"
#include "DNA.h"
#include "Protein.h"
#include "Sequence.h"

#include <iostream>

using namespace std;
class invalidOpertator : exception
{
public:
    void print() {
        cout << "Enter a valid operator\n";
    }
};
RNA::RNA()
{
    //ctor
}

RNA::~RNA()
{
    //ctor
}

void RNA::Print()
{
    DNA D;
    cout<<D.ConvertToRNA().seq;
}

DNA RNA::ConvertToDNA()
{   loop5:
    try
    {
    cin>>seq;
int i=0;
   for (int i=0; i<seq.length(); i++){
    if(seq[i] != 'A' && seq[i]  != 'C' && seq[i]  != 'G' && seq[i]  != 'U')
    throw  invalidOpertator();
    }
    }
      catch (invalidOpertator e)
    {
        e.print();
        cout << "Enter the sequence you want to enter : ";
        goto loop5;
    }
    DNA D;
    for (int i=0 ; i<seq.length() ; i++)
    {
        if (seq[i] == 'U')
        {
            D.seq += 'T';
        }
        else
        {
            D.seq +=seq[i];
        }
    }
    cout << D.seq;
    return D;
}

Protein RNA::ConvertToProtein(CodonsTable & table)
{Codon C;
loop6:
    try
    {
    cin>>seq;
int i=0;
   for (int i=0; i<seq.length(); i++){
    if(seq[i] != 'A' && seq[i]  != 'C' && seq[i]  != 'G' && seq[i]  != 'U')
    throw  invalidOpertator();
    }
    }
      catch (invalidOpertator e)
    {
        e.print();
        cout << "Enter the sequence you want to enter : ";
        goto loop6;
    }
        Protein P;
    //cout << P.seq[0];
    string value="";
    int len = seq.length();
    int l = 0 ;
    for (int i=0 ; i<len/3 ; i++)
    {
        for (int j=0 ; j<3 ; j++)
        {
            value = value + seq[l];
            l+=1;
        }
        C = table.getAminoAcid(value);
        P.seq = P.seq + C.AminoAcid;
        value="";

    }
    cout << P.seq;
    return P;
}
