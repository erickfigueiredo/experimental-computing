#include <iostream>
#include <vector>
#include <time.h>
#include <set>
#include <algorithm>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock



using namespace std;

// const int RAND_MAX = 1000000;
#define high 100000
#define low 1


void shuffle(vector<double> &v){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle (v.begin(), v.end(), std::default_random_engine(seed));
}

void generate_balanced_array(vector<double> &v, int n){
    for(int i = 0;i<n/3;i++){
        double r =  low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;
        v.push_back(r);
    }

    for(int i = 0;i<n/3;i++){
        double r =  low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;

        v.push_back(-r);
    }


    for(int i = 0;i<=n/3;i++){
        v.push_back(0);
    }

    shuffle(v);
}

void generate_less_zeros(vector<double> &v, int n){
    int k = rand() % ((n/10)); k++;

    n-=k;
    for(int i = 0;i<n/2;i++){
        double r =  low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;
        v.push_back(r);
    }

    for(int i = 0;i<n/2;i++){
        double r =  low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;

        v.push_back(-r);
    }

     for(int i = 0;i<k;i++){
        v.push_back(0);
    }

    shuffle(v);

}

void generate_sorted_array(vector<double> &v, int n){
     for(int i = 0;i<n/3;i++){
        double r =  low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;
        v.push_back(-r);
    }

    for(int i = 0;i<=n/3;i++){
        v.push_back(0);
    }

    for(int i = 0;i<=n/3;i++){
        double r =  low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;

        v.push_back(r);
    }

    int changes = (int) (0.1 * n);

    for(int i = 0; i < changes; i++) {
        int a = rand() % n;
        int b = rand() % n;

        double aux = v[a];
        v[a] = v[b];
        v[b] = aux;
    }
    
}   

int main(int argc, char ** argv){

    if(argc <5){
        cout << "Insira todos os 4 parametros\n";
        return 1;
    }

    int method = atoi(argv[1]);
    int n = atoi(argv[2]);
    int initial_state = atoi(argv[3]);
    int amount_values = atoi(argv[4]);
    vector<double> v;
    if(amount_values== 1){
        generate_balanced_array(v,n);
    }else{
        generate_less_zeros(v,n);
    }

    for(auto i:v) cout << i <<  " ";
    cout << "\n";

}