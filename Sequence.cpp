#include "Sequence.h"
#include "RNA.h"
#include "DNA.h"
class invalidOpertator : exception
{
public:
    void print() {
        cout << "Enter a valid operator\n";
    }
};
Sequence::Sequence()
{
    //ctor
}

Sequence::~Sequence()
{

}

void Sequence::print2()
{   Protein P ;
    RNA R;
    DNA D;
    Codon C;
    CodonsTable CT;
    Sequence *s ,*s1;
    int choose = 0 ,choose2 = 0 ,choose3= 0;
    cout << "|||||||||||||| WELCOME TO OUR BIOLOGICAL SYTEM ||||||||||||||" << endl << endl;
   /* cout << "Which Type ?";
    cout << "DNA , RNA , Protein";
    cin >> choose2;
    switch (choose2)
    {
    case 1:
        cout <<"which Type ? "<<endl;
         cout<< "promoter, motif, tail, noncoding";
        cin >> choose3;
        cout << "Enter the sequence you want to enter : ";
        switch (choose3)
        {
            case 1 :
                cout << " promoter ";
                break ;
            case 2 :
                cout << " motif ";
                break ;
            case 3 :
                cout << " tail ";
                break ;
            case 4 :
                cout << " noncoding ";
                break ;

        }
        break;
    case 2:
         cout <<"which Type ? "<<endl;
         cout<< "mRNA, pre_mRNA, mRNA_exon, mRNA_intron";
        cin >> choose3;
        cout << "Enter the sequence you want to enter : ";
        cin >>seq;
        cout << seq << " TYPE -> ";
        switch (choose3)
        {
            case 1 :
                cout << " mRNA ";
                break ;
            case 2 :
                cout << " pre_mRNA ";
                break ;
            case 3 :
                cout << " mRNA_exon ";
                break ;
            case 4 :
                cout << " mRNA_intron ";
                break ;

        }
        break;
    case 3:
         cout <<"which Type ? "<<endl;
         cout <<"Hormon, Enzyme, TF, Cellular_Function";
        cin >> choose3;
        cout << "Enter the sequence you want to enter : ";
        switch (choose3)
        {
            case 1 :
                cout << " Hormon ";
                break ;
            case 2 :
                cout << " Enzyme ";
                break ;
            case 3 :
                cout << " TF ";
                break ;
            case 4 :
                cout << " Cellular_Function ";
                break ;

        }
        break;
    }*/
    loop:
    cout << endl << "Enter the conversion you want to make : "<<endl;
    cout << "1-Convert from DNA to RNA" << endl;
    cout << "2-Convert from RNA to DNA" << endl;
    cout << "3-Convert from RNA to Protein" << endl;
    cout << "4-Convert DNA to complement" << endl;
    cout << "5-Convert Protein to DNA" << endl;
    cout << "6-LCS" << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:
        cout << "Enter the sequence you want to enter : ";
        R.Print();
        break;
    case 2:
        cout << "Enter the sequence you want to enter : ";
        R.ConvertToDNA();
        break;

    case 3:
        cout << "Enter the sequence you want to enter : ";
        CT.LoadCodonsFromFile("RNA_codon_table.txt");
        R.ConvertToProtein(CT);
        break;
    case 4:
        cout << "Enter the sequence you want to enter : ";
        D.BuildComplementaryStrand();
        break;

    case 5 :
        P.GetDNAStrandsEncodingMe(D);
    break;
    case 6 :
        cout << "Enter the two sequence you want to enter : ";
        Align(s,s1);
    }
    goto loop;
}

void Sequence::setseq()
{
    cin >> seq;
}

string Align(Sequence * s1, Sequence * s2){
    string seq ;
    string seq2 ;
    cout << "S1 = ";
    cin >>seq;
    cout << endl << "S2 = ";
    cin >>seq2;
   int index=0;
    int j ;
    string LCS ;
    for (int i=0 ; i< seq2.length() ; i++){

        for ( j=index ; j<seq.length() ; j++){
            if (seq2[i]==seq[j]){
                LCS=LCS+seq2[i];
                index = j;
                break;
            }
        }
    }
    cout <<LCS;
return LCS;
}

istream& operator>> (istream& in ,Sequence & s){
in >> s.seq;
return in;
}


