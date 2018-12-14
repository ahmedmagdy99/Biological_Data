#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include "Sequence.h"
#include <cstring>
#include <iostream>
using namespace std;


int main()
{
    /*
    cout << "|||||||||||||| WELCOME TO OUR BIOLOGICAL SYTEM ||||||||||||||" << endl;
    cout << "Enter the type you want to enter : ";
    cout << "1-DNA" << endl;
    cout << "1-RNA" << endl;
    cout << "1-Protein" << endl;
    int kind;
    cin >> kind;
    */
    //RNA R;
    //DNA D;
    //Protein P;
    Sequence *S;
    S->print2();
    //S->setseq();

//    Sequence *S2;
//    Sequence *S3;
//    cout << Align(S,S2);
   // P.GetDNAStrandsEncodingMe(D);
   // R.ConvertToDNA();

    //CodonsTable c;
    //c.LoadCodonsFromFile("RNA_codon_table.txt");
  //  c.getAminoAcid("AAA");
    //R.ConvertToProtein(c);

    return 0;
}


// Function SetCodon
