#include <iostream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <ctime>

using namespace std;

void simulate1(long long n, int den, int prob[], long long wins[]) {
    bool nextBattle;
    int roundWin = 0;

    for (int i = 0; i < n; i++) {
        while (true) {
            nextBattle = false;
            for (int j = 0; j < 2; j++) {
                // incrementa e finaliza
                if (rand() % den < prob[j]) {
                    nextBattle = true;
                    roundWin = j;
                    break;
                }
            }
            if (nextBattle) break;
        }

        while (true) {
            if (rand() % den < prob[2]) {
                wins[2]++;
                break;
            }

            if (rand() % den < prob[roundWin]) {
                wins[roundWin]++;
                break;
            }
        }
    }

    printf("Simulacao estrategia 1 finalizada: %lld de duelos!\n - Vitorias de A: %.3f%%\n - Vitorias de B: %.3f%%\n - Vitorias de C: %.3f%%\n\n", n, (wins[0] * 100.0) / n, (wins[1] * 100.0) / n, (wins[2] * 100.0) / n);
}

void simulate2(long long n, int den, int prob[], long long wins[]) {
    int alive = 3;

    map<long long, int> mostImportant = { {prob[0], 0}, {prob[1], 1}, {prob[2], 2} };

    for (int i = 0; i < n; i++) {
        bool deaths[3] = { 0, 0, 0 };
        while (alive > 1) {
            for (int j = 0; j < 3; j++) {
                cout << "netrou\n";
                if (!deaths[j] && (rand() % den < prob[j])) {
                    wins[j]++;
                    auto it = --mostImportant.end();

                    if (it->second == j)
                        it--;
                    
                    cout << it->second << ' ' << it->first << endl;

                    deaths[it->second] = true;
                    mostImportant.erase(it);
                    alive--;

                }
            }
        }
    }
    cout << wins[0]+wins[1]+wins[2] << "\n";
    printf("Simulacao estrategia 2 finalizada: %lld de duelos!\n - Vitorias de A: %.3f%%\n - Vitorias de B: %.3f%%\n - Vitorias de C: %.3f%%\n\n", n, (wins[0] * 100.0) / n, (wins[1] * 100.0) / n, (wins[2] * 100.0) / n);
}


int main() {
    long long wins[] = { 0,0,0 };
    int den, prob[3];
    int nSimulations;

    cin >> den >> prob[0] >> prob[1] >> prob[2];
    while (true) {
        cin >> nSimulations;

        if (!nSimulations) break;
        long long wins[] = { 0,0,0 };
        simulate1(nSimulations, den, prob, wins);
        long long wins1[] = { 0,0,0 };
        simulate2(nSimulations, den, prob, wins1);
    }


    return 0;
}