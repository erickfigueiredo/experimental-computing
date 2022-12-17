#include <iostream>
#include <vector>
#include <time.h>
#include <set>
#include <algorithm>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock



using namespace std;

void three_way_partition(vector<double> &a){
    int lo = 0;
    int hi = a.size() - 1;
    int mid = 0;
    //Iterate till all the elements
    //are sorted
    while (mid <= hi){
        //If the element is 0
        if (a[mid] < 0){
            swap(a[lo], a[mid]);
            lo++;
            mid++;
        }
        //If the element is 1
        else if(a[mid] == 0)
            mid++;
        //If the element is 2
        else{
            swap(a[mid], a[hi]);
            hi--;
        }
    }
}

void default_sort(vector<double> &v){
    sort(v.begin(), v.end());
}



int main(int argc, char ** argv){
    srand(time(NULL));
    vector<double> v,v1;

    int n, mode, initial_state, qtdZeros;
    if(argc == 5){
        n = atoi(argv[1]);
        mode = atoi(argv[2]);
        initial_state = atoi(argv[3]);
        qtdZeros = atoi(argv[4]);

    }else{
        cout << "Insira todos os parametros\n";
        return 1;
    }
    double aux;
    for(int i = 0; i<n;i++){
        cin >> aux;
        v.push_back(aux);
        v1.push_back(aux);
    }

    auto inicio = std::chrono::high_resolution_clock::now();
    three_way_partition(v);
    auto resultado = std::chrono::high_resolution_clock::now() - inicio;

    long long three_way_time = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

    inicio = std::chrono::high_resolution_clock::now();
    default_sort(v1);
    resultado = std::chrono::high_resolution_clock::now() - inicio;

    long long default_sort_time = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
    cout << "3-way time\n";
    cout << three_way_time << "\n\n\n";

    cout << "Default sort time\n";

    cout << default_sort_time << "\n";

}