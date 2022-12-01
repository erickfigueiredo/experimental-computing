#include <iostream>
#include <cstdlib>
#include <list>
#include <ctime>

using namespace std;

void simulate(long long n, int mA, int mB) {
    long long wins[] = { 0, 0 };
    int sempreFrente = 0;

    printf("Simulacao finalizada: %lld rodada(s)!\n", n);

    for (long long i = 0; i < n; i++) {
        long long flipCoin = 0;
        
        printf("=> Round %lld:\n", i+1);
        int moneyA = mA;
        int moneyB = mB;

        list<pair<int, int>> moneyPerRound;
        moneyPerRound.push_back({moneyA, moneyB});
        do {
            flipCoin++;
            int ran = rand();
            if (ran % 2) {
                moneyA--;
                moneyB++;
            }
            else {
                moneyA++;
                moneyB--;
            }

            moneyPerRound.push_back({moneyA, moneyB});
        } while (moneyA && moneyB);

        if (!moneyA) wins[1]++;
        else wins[0]++;

        //contar inversões em cada simulação
        int idx = mA > mB ? 0 : 1;
        int inversoes = 0;
        int vezes_frente[2] = {0,0};

        auto it = ++moneyPerRound.begin();
        while(it != moneyPerRound.end()){
            int aux[2] = {it->first,it->second};
            vezes_frente[idx]++;
            if(aux[idx] < aux[1-idx]){
                inversoes++;
                idx = 1 - idx; // se idx é 0 e teve inv idx = 1
            }
            it++;
        }


        // for(const auto &p:moneyPerRound){
        //     printf("%d,%d\n", p.first, p.second);
        // }

        // printf("-Numero de lancamentos: %lld\n\n", flipCoin);
        // cout << inversoes <<"\n";

        printf("-Numero de lancamentos: %lld\n\n", flipCoin);
    }

    printf("- Vitorias de A: %.3f%%\n- Vitorias de B: %.3f%%\n\n", (wins[0] * 100.0) / n, (wins[1] * 100.0) / n);

}

int main(int argc, char** argv) {
    int monA, monB;
    srand(time(nullptr));

    if (argc > 1) {
        monA = stoi(argv[1]);
        monB = stoi(argv[2]);

        for (int i = 3; i < argc; i++)
            simulate(stoll(argv[i]), monA, monB);
    }
    else {
        long long simulations;
        cout << "Informe a quantia inicial de A e B,  respectivamente: ";
        cin >> monA >> monB;
        cout << "Informe o número de simulações que deseja realizar: ";
        cin >> simulations;

        simulate(simulations, monA, monB);
    }

    return 0;
}