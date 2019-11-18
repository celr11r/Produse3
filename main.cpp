
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    struct data
    {
        int z,l,a;
    };


    struct produs
    {
        int pret,greutate;
        char denumire[30],categorie[30];
        data termen;
    };

    {produs v[100];
        int n,i;
        int opt;
        cout<<"MENIU"<<endl;
        cout<<"0. Inchidere meniu"<<endl;
        cout<<"1. Citirea produselor"<<endl;
        cout<<"2. Afisarea celui mai scump produs"<<endl;
        cout<<"3. Afisarea produselor expirate"<<endl;
        cout<<"4. Adaugarea unui produs in lista"<<endl;
        cout<<"5. Eliminarea unui produs din lista"<<endl;
        cout<<"6. Afisarea valorii stocului"<<endl;
        cout<<"Alegeti optiunea din meniu"<<endl;
        while(cin>>opt && opt!=0)
        {
            if(opt==1)
            {
                cout<<"Numarul de produse: ";
                cin>>n;
                for (i=0; i<n; i++)
                {
                    cout<<"Pretul produsului: ";
                    cin>>v[i].pret;
                    cout<<"Greutatea produslui: ";
                    cin>>v[i].greutate;
                    cout<<"Denumirea produsului: ";
                    cin.ignore();
                    cin.getline(v[i].denumire,30);
                    cout<<"Categoria produsului: ";
                    cin.getline(v[i].categorie,30);
                    cout<<"Ziua termenului: ";
                    cin>>v[i].termen.z;
                    cout<<"Luna termenului: ";
                    cin>>v[i].termen.l;
                    cout<<"Anul termenului: ";
                    cin>>v[i].termen.a;
                }
                cout<<"MENIU"<<endl;
                cout<<"0. Inchidere meniu"<<endl;
                cout<<"1. Citirea produselor"<<endl;
                cout<<"2. Afisarea celui mai scump produs"<<endl;
                cout<<"3. Afisarea produselor expirate"<<endl;
                cout<<"4. Adaugarea unui produs in lista"<<endl;
                cout<<"5. Eliminarea unui produs din lista"<<endl;
                cout<<"6. Afisarea valorii stocului"<<endl;
                cout<<"Alegeti optiunea din meniu"<<endl;
            }
            if(opt==2)
            {
                int maxi=-1,maxipoz;
                for (i=0; i<n; i++)
                {
                    if (v[i].pret>maxi)
                    {
                        maxi=v[i].pret;
                        maxipoz=i;
                    }
                }
                cout<<v[maxipoz].denumire<<endl;
                cout<<"MENIU"<<endl;
                cout<<"0. Inchidere meniu"<<endl;
                cout<<"1. Citirea produselor"<<endl;
                cout<<"2. Afisarea celui mai scump produs"<<endl;
                cout<<"3. Afisarea produselor expirate"<<endl;
                cout<<"4. Adaugarea unui produs in lista"<<endl;
                cout<<"5. Eliminarea unui produs din lista"<<endl;
                cout<<"6. Afisarea valorii stocului"<<endl;
                cout<<"Alegeti optiunea din meniu"<<endl;

            }
            if(opt==3)
            {
                data azi;
                cout<<"Ziua curenta este: ";
                cin>>azi.z;
                cout<<"Luna curenta este: ";
                cin>>azi.l;
                cout<<"Anul curent este: ";
                cin>>azi.a;

                for (i=0; i<n; i++)
                {
                    if (azi.a>v[i].termen.a)
                        cout<<v[i].denumire<<endl;
                    else if (azi.a==v[i].termen.a)
                    {
                        if (azi.l>v[i].termen.l)
                            cout<<v[i].denumire<<endl;
                        else if (azi.l==v[i].termen.l)
                        {
                            if (azi.z>v[i].termen.z)
                                cout<<v[i].denumire<<endl;
                        }
                    }
                }
                cout<<"MENIU"<<endl;
                cout<<"0. Inchidere meniu"<<endl;
                cout<<"1. Citirea produselor"<<endl;
                cout<<"2. Afisarea celui mai scump produs"<<endl;
                cout<<"3. Afisarea produselor expirate"<<endl;
                cout<<"4. Adaugarea unui produs in lista"<<endl;
                cout<<"5. Eliminarea unui produs din lista"<<endl;
                cout<<"6. Afisarea valorii stocului"<<endl;
                cout<<"Alegeti optiunea din meniu"<<endl;
            }
            if(opt==4)
            {
                n=n+1;   //Actualizarea numarului de produse
                cout<<"Informatiile despre produsul pe care vrem sa il adaugam: "<<endl;
                cout<<"Pretul produsului: ";
                cin>>v[n-1].pret;
                cout<<"Greutatea produslui: ";
                cin>>v[n-1].greutate;
                cout<<"Denumirea produsului: ";
                cin.ignore();
                cin.getline(v[n-1].denumire,30);
                cout<<"Categoria produsului: ";
                cin.getline(v[n-1].categorie,30);
                cout<<"Ziua termenului: ";
                cin>>v[n-1].termen.z;
                cout<<"Luna termenului: ";
                cin>>v[n-1].termen.l;
                cout<<"Anul termenului: ";
                cin>>v[n-1].termen.a;
                cout<<"MENIU"<<endl;
                cout<<"0. Inchidere meniu"<<endl;
                cout<<"1. Citirea produselor"<<endl;
                cout<<"2. Afisarea celui mai scump produs"<<endl;
                cout<<"3. Afisarea produselor expirate"<<endl;
                cout<<"4. Adaugarea unui produs in lista"<<endl;
                cout<<"5. Eliminarea unui produs din lista"<<endl;
                cout<<"6. Afisarea valorii stocului"<<endl;
                cout<<"Alegeti optiunea din meniu"<<endl;

            }

            if(opt==5)
            {
                cout<<"Numele produsului pe care vrem sa-l eliminam: ";
                char eliminat[30];
                int pozelim;
                cin.ignore();
                cin.getline(eliminat,30);
                for (i=0; i<n; i++)
                {
                    if(strcmp(eliminat,v[i].denumire)==0)
                        pozelim=i;
                }
                for (i=pozelim; i<n-1; i++)
                    v[i]=v[i+1];
                n=n-1;
                for(i=0; i<n; i++)
                {
                    cout<<"--------------- Produsul "<<i+1<<" ------------"<<endl;
                    cout<<"Pretul produsului este: "<<v[i].pret<<endl;
                    cout<<"Greutatea prodsului este: "<<v[i].greutate<<endl;
                    cout<<"Denumirea produslui este: "<<v[i].denumire<<endl;
                    cout<<"Categoria produsului este: "<<v[i].categorie<<endl;
                    cout<<"Termenul de valabilitate este: "<<v[i].termen.z<<"."<<v[i].termen.l<<"."<<v[i].termen.a<<endl;
                }
                cout<<"MENIU"<<endl;
                cout<<"0. Inchidere meniu"<<endl;
                cout<<"1. Citirea produselor"<<endl;
                cout<<"2. Afisarea celui mai scump produs"<<endl;
                cout<<"3. Afisarea produselor expirate"<<endl;
                cout<<"4. Adaugarea unui produs in lista"<<endl;
                cout<<"5. Eliminarea unui produs din lista"<<endl;
                cout<<"6. Afisarea valorii stocului"<<endl;
                cout<<"Alegeti optiunea din meniu"<<endl;

            }
            if(opt==6)
            {
                cout<<"Numarul de produse din sistem este: "<<n<<endl;
                for(i=0; i<n; i++)
                {
                    cout<<"--------------- Produsul "<<i+1<<" ------------"<<endl;
                    cout<<"Pretul produsului este: "<<v[i].pret<<endl;
                    cout<<"Greutatea prodsului este: "<<v[i].greutate<<endl;
                    cout<<"Denumirea produslui este: "<<v[i].denumire<<endl;
                    cout<<"Categoria produsului este: "<<v[i].categorie<<endl;
                    cout<<"Termenul de valabilitate este: "<<v[i].termen.z<<"."<<v[i].termen.l<<"."<<v[i].termen.a<<endl;
                }
                cout<<"MENIU"<<endl;
                cout<<"0. Inchidere meniu"<<endl;
                cout<<"1. Citirea produselor"<<endl;
                cout<<"2. Afisarea celui mai scump produs"<<endl;
                cout<<"3. Afisarea produselor expirate"<<endl;
                cout<<"4. Adaugarea unui produs in lista"<<endl;
                cout<<"5. Eliminarea unui produs din lista"<<endl;
                cout<<"6. Afisarea valorii stocului"<<endl;
                cout<<"Alegeti optiunea din meniu"<<endl;
            }
        }
        if(opt==0)
            cout<<"Meniul a fost inchis cu succes!";

        return 0;
    }
 
