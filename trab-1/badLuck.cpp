#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void simulate(long long n, int mA, int mB) {
    long long wins[] = { 0, 0 };
    for (long long i = 0; i < n; i++) {
        int moneyA = mA;
        int moneyB = mB;
        do {
            int ran = rand();
            if (ran % 2) {
                moneyA--;
                moneyB++;
            }
            else {
                moneyA++;
                moneyB--;
            }

        } while (moneyA && moneyB);

        if (!moneyA) wins[1]++;
        else wins[0]++;
    }

    printf("Simulacao finalizada: %lld rodadas!\n - Vitorias de A: %.3f%%\n - Vitorias de B: %.3f%%\n\n", n, (wins[0] * 100.0) / n, (wins[1] * 100.0) / n);
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