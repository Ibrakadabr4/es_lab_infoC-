#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
void ordina(float[],int);
float mediana(float[],int);
float calcoloMedia(float[], int);
float devstandard(float[], int);
void calcolaStats(float v[], int ndata, float* pmin, float* pmax, float* pmediana, float* pmedia, float* pstddev){

    *pmin = v[0];
    *pmax = v[ndata-1];
    *pmediana = mediana(v, ndata);
    *pmedia = calcoloMedia(v, ndata);
    *pstddev = devstandard(v, ndata);

}

int main(){
    float* v =NULL;
    float min, max, mediana, media, stddev;

    int ndati;
    ifstream file_in("dati_header.dat");
    if(file_in.fail()){
        return -1;
    }
    file_in>> ndati;
    v = new float[ndati];
    if(v == NULL){
        cout<< endl << "Problema allocazione dinamica vdati, esco"<<endl;
        return -2;
    }

    for(int i=0; i<(ndati); i++){ 

        file_in>>v[i];

        //file_in >> *v;
        //v++;
    }
    file_in.close();
 

    ordina(v,ndati);
    calcolaStats(v, ndati, &min, &max, &mediana, &media, &stddev);

    cout<<endl<<"min = "<<min;
    cout<<endl<<"max = "<<max;
    cout<<endl<<"mediana = "<<mediana;
    cout<<endl<<"media = "<<media;
    cout<<endl<<"scarto quadratico medio = "<<stddev;


    delete [] v;
    v = NULL;
    ofstream file_out("risultati.dat");
    file_out<<endl<<"min = "<<min;
    file_out<<endl<<"max = "<<max;
    file_out<<endl<<"mediana = "<<mediana;
    file_out<<endl<<"media = "<<media;
    file_out<<endl<<"scarto quadratico medio = "<<stddev;
    
    file_out.close();
    return 0;
}

float mediana(float v[],int size){
    
    if(size%2==0){
        return (float)(v[size/2 -1 ]+v[size/2 ])/2;
    } else {
        return (float)v[(size+1)/2 -1]; 
    }
    
}

float calcoloMedia(float v[], int size){
    float a,m;
     
    for(int i =0; i<size; i++){
        a += v[i];
    }
    m = a/size;
    return m;

}

float devstandard (float v[], int ndt) {

    float scarto = 0;
    float x = calcoloMedia(v, ndt); 

     for( int c= 0; c < ndt; c++){
        scarto = scarto + pow((x - v[c]), 2); 
    }


    float devstd = sqrt(scarto/ (ndt -1)); 

    return devstd; 
}

void ordina(float a[],int size){
    int p_min = 0;
    float temp;
    for(int i=0;i<size-1;i++)
    {
	p_min=i;
        for(int j=i+1;j<size;j++)
        	if (a[j]<a[p_min])
        	     p_min= j;

        temp=a[p_min];
        a[p_min]=a[i];
        a[i]=temp;
    }
}