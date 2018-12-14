#include <iostream>
#include <string>
#include "DNA.h"
#include "Protein.h"
#include "Sequence.h"
#include "RNA.h"

using namespace std;
class invalidOpertator : exception
{
public:
    void print() {
        cout << "Enter a valid operator\n";
    }
};
Protein::Protein()
{
    //ctor
}

Protein::~Protein()
{
    //ctor
}

void Protein::Print()
{

}
DNA* Protein::GetDNAStrandsEncodingMe(DNA & bigDNA)
{   loop2:
    try
    {
    cout << "Enter the BigDNA sequence: ";
    cin>>bigDNA.seq;
int i=0;
   for (int i=0; i<bigDNA.seq.length(); i++){
    if(bigDNA.seq[i] != 'A' && bigDNA.seq[i]  != 'C' && bigDNA.seq[i]  != 'G' && bigDNA.seq[i]  != 'T')
    throw  invalidOpertator();
    }
    }
      catch (invalidOpertator e)
    {
        e.print();
        goto loop2;
    }

    Protein P, F;
    cout << endl << "Enter the AminoAcid sequence: ";
    cin >>F.seq;
    P.seq="";
    Codon C;
    string value,value2,amino;
    CodonsTable Ctable;
    RNA R2;
    CodonsTable table;
    string arr[20];
    string seq;
    for (int i=0; i<bigDNA.seq.length() ; i++)
    {
        if (bigDNA.seq[i] == 'T')
        {
            R2.seq += 'U';
        }
        else
        {
            R2.seq += bigDNA.seq[i];
        }
    }
    Ctable.LoadCodonsFromFile("RNA_codon_table.txt");
    int siz = R2.seq.length(),counter=0;
    int l=0,c=0;
    for (int i=0 ; i < siz-2 ; i++)                                         // Numbers of Tries of DNA Producing
    {
        for (int o=0 ; o<siz/3 ; o++)                                        // Loop to check every 3 letters
        {

            for (int j=0 ; j<3 ; j++)                                           // Loop to get every 3 chars
            {
                value = value + R2.seq[l];
                l+=1;
            }

            C = Ctable.getAminoAcid(value);
//            for(int f =0 ; f<F.seq.length() ; f++)
//            {
//                amino+=C.AminoAcid;
//            }

            P.seq = P.seq + C.AminoAcid;
            value2+=value;

            if(P.seq==F.seq)
            {
                arr[c]=value2;
                c++;
                P.seq="";
                value2="";
            }
            if(counter==F.seq.length())
            {
                P.seq="";
                value2="";
            }

            value="";
        }
    counter++;
    l=i;


    }


    for(int k=0 ; k<8 ; k++)
    {
        cout <<arr[k]<<" ";
    }
}

