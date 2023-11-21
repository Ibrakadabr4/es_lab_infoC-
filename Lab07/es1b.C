#include <iostream>
#include <fstream>

#define NMAX 150

using namespace std;


int pos_min(float v[], int ind_min, int ind_max);
void selsort(float v[], int used);
void scambia(float*,float*);

int main(){

    int ndati;
    float vdati[NMAX];

    ifstream file_in;
    ofstream file_out;

    file_in.open("dati_header.dat");

    //Leggo numero di dati da file, come da specifiche formato
    file_in >> ndati;

    //Adesso so quanti dati devo caricare
    for(int i=0; i<ndati; i++)
        file_in >> vdati[i];
    
    file_in.close();
    
    cout << endl << endl << " Prima ordinamento:" << endl;
    for(int i=0; i<10; i++)
        cout << endl << vdati[i] << endl;

    //Supponiamo di avere i dati correttamente caricati
    selsort(vdati,ndati);
    
    //verifico solo i primi dieci dati ordinati
    cout << endl << endl << " Dopo ordinamento:" << endl;
    for(int i=0; i<10; i++)
        cout << endl << vdati[i] << endl;

    return 0;
}

void scambia(float*p1, float*p2){
    float appo = *p1;
    *p1 = *p2;
    *p2 = appo;
}


int pos_min(float v[], int ind_min, int ind_max){
    
    int pos_min = ind_min;
    float min = v[ind_min];
    //Determino minimo in array v[ind_min],...v[ind_max]
    for(int i = ind_min+1; i<=ind_max; i++){
        //Se incontro elemento piu`  piccolo del minimo
        //attuale aggiorno minimo e posizione minimo
        if (v[i]<min){
            pos_min = i;
            min = v[i];
        }
    }
    return pos_min;
}


void selsort(float v[], int used){
    int pmin;
    float* p1;
    float* p2;

    for(int i=0; i<used; i++){
        pmin = pos_min(v,i,used-1);
        p1 = &v[i];
        p2 = &v[pmin];
        scambia(p1, p2);
    }
}
