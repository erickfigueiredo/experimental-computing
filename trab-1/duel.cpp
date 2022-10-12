// Computação Experimental
// Alunos: Erick Figueiredo e Carlos Sabino

// AVISO: O código permite inserção por linhas de comando ou arquivo

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void simulate(long long n, long long wins[]){
  bool died;

  while(n--) {
    while(true){
      died = false;
      for(int i = 0; i < 2; i++){
        // incrementa e finaliza
        if(rand()%2) {
          wins[i]++;
          died = true;
          break;
        }
      }
      if (died) break;
    }
  }
  printf("Simulacao finalizada!\n - Vitorias de A: %lld\n - Vitorias de B: %lld\n", wins[0], wins[1]);
}

int main(int argc, char** argv) {
  srand(time(nullptr));

  if(argc == 1){
    long long wins[] = {0, 0};
    long long nSimulations;
    cout << "Informe o numero de rodadas que deseja simular: ";
    cin >> nSimulations;
    simulate(nSimulations, wins);
  } else {
    for(int i = 1; i < argc; i++){
      long long wins[] = {0, 0};
      simulate(stoll(argv[i]), wins);
    }
  }
  return 0;
}