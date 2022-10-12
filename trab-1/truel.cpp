// Computação Experimental
// Alunos: Erick Figueiredo e Carlos Sabino

// AVISO: O código permite inserção por linhas de comando ou arquivo

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

void simulate1(long long n, int den, int prob[], long long wins[]) {
    for (int i = 0; i < n; i++) {
        int deaths[] = { 0, 0, 0 };

        map<long long, int> mostImportant = { {prob[0], 0}, {prob[1], 1}, {prob[2], 2} };

        while (mostImportant.size() > 1) {
            for (int j = 0; j < 3; j++) {
                if (!deaths[j] && (rand() % den < prob[j])) {
                    map<long long, int>::iterator it = mostImportant.end();
                    it--;

                    if (it->second == j)
                        it--;

                    deaths[it->second] = true;
                    mostImportant.erase(it);
                }
            }
        }

        wins[mostImportant.begin()->second]++;
    }

    printf("Simulacao estrategia 1 finalizada: %lld de duelos!\n - Vitorias de A: %.3f%%\n - Vitorias de B: %.3f%%\n - Vitorias de C: %.3f%%\n\n", n, (wins[0] * 100.0) / n, (wins[1] * 100.0) / n, (wins[2] * 100.0) / n);
}

void simulate2(long long n, int den, int prob[], long long wins[]) {
    bool nextBattle;
    int roundWin = 0;

    for (int i = 0; i < n; i++) {
        while (true) {
            nextBattle = false;
            for (int j = 0; j < 2; j++) {
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

    printf("Simulacao estrategia 2 finalizada: %lld de duelos!\n - Vitorias de A: %.3f%%\n - Vitorias de B: %.3f%%\n - Vitorias de C: %.3f%%\n\n", n, (wins[0] * 100.0) / n, (wins[1] * 100.0) / n, (wins[2] * 100.0) / n);
}

int main(int argc, char** argv) {
    srand(time(nullptr));

    int den, prob[3];

    if (argc == 1) {
        long long wins[] = { 0,0,0 };
        long long wins1[] = { 0,0,0 };
        long long nSimulations;

        cout << "Informe o numero de rodadas que deseja simular: ";
        cin >> nSimulations;
        cout << "Informe a precisao total e a precisao de cada jogador: ";
        cin >> den >> prob[0] >> prob[1] >> prob[2];

        simulate1(nSimulations, den, prob, wins);
        simulate2(nSimulations, den, prob, wins1);
    }
    else {
        den = stoi(argv[1]);
        prob[0] = stoi(argv[2]);
        prob[1] = stoi(argv[3]);
        prob[2] = stoi(argv[4]);

        for (int i = 5; i < argc; i++) {
            long long wins[] = { 0,0,0 };
            long long wins1[] = { 0,0,0 };

            simulate1(stoll(argv[i]), den, prob, wins);
            simulate2(stoll(argv[i]), den, prob, wins1);
        }
    }
    return 0;
}