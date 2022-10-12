// Computação Experimental
// Alunos: Erick Figueiredo e Carlos Sabino

// AVISO: O código permite inserção por linhas de comando ou arquivo

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void simulate(long long n, int den, int prob[], long long wins[]) {
  bool died;

  for (int i = 0; i < n; i++) {
    while (true) {
      died = false;
      for (int j = 0; j < 2; j++) {
        // incrementa e finaliza
        if (rand() % den < prob[j]) {
          wins[j]++;
          died = true;
          break;
        }
      }
      if (died) break;
    }
  }
  printf("Simulacao finalizada: %lld de duelos!\n - Vitorias de A: %.3f%%\n - Vitorias de B: %.3f%%\n\n", n, (wins[0] * 100.0) / n, (wins[1] * 100.0) / n);
}

int main(int argc, char** argv) {
  srand(time(nullptr));

  if (argc == 1) {
    long long wins[] = { 0, 0 };
    long long nSimulations;
    int den, prob[2];

    cout << "Informe o numero de rodadas que deseja simular: ";
    cin >> nSimulations;
    cout << "Informe a precisao total e a precisao de cada jogador: ";
    cin >> den >> prob[0] >> prob[1];

    simulate(nSimulations, den, prob, wins);
  }
  else {
    int prob[2];
    int den = stoi(argv[1]);
    prob[0] = stoi(argv[2]);
    prob[1] = stoi(argv[3]);

    for (int i = 4; i < argc; i++) {
      long long wins[] = { 0, 0 };
      simulate(stoll(argv[i]), den, prob, wins);
    }
  }
  return 0;
}
