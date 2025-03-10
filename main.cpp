#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int padroes_entrada[4][3] = { {1, 1, 1}, {1, -1, 1}, {-1, -1, 1}, {-1, 1, 1} };
    float pesos[4][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
    float saidas_desejadas[4] = {0.5, -0.5, -0.5, -0.5};
    float taxa_aprendizado = 1.5;

    float erro_aceitavel = 0.01;
    float soma_ponderada[4] = {0, 0, 0, 0}; // Soma ponderada das entradas
    float erro, norma_entrada;
    int saida_calculada[4]; // Saida calculada pela função de ativação
    bool erro_dentro_aceitavel;
    int iteracao = 0;
    
	while (!erro_dentro_aceitavel){
        erro_dentro_aceitavel = true;
        iteracao++;

        for (int i = 0; i < 4; i++) {
        	//Reinicializações
            soma_ponderada[i] = 0;
            norma_entrada = 0;

            // Calcula a soma ponderada e a norma da entrada
            for (int j = 0; j < 3; j++) {
                soma_ponderada[i] += padroes_entrada[i][j] * pesos[i][j];
                norma_entrada += pow(padroes_entrada[i][j], 2);
            }
            // Calcula o erro
            erro = saidas_desejadas[i] - soma_ponderada[i];

            // Verifica se o erro ABSOLUTO é aceitavel
            if (abs(erro) <= erro_aceitavel) {
        		continue;
            }
            erro_dentro_aceitavel = false;
            
            //Atualiza os pesos
            for (int j = 0; j < 3; j++) {
    			pesos[i][j] = pesos[i][j] + (((taxa_aprendizado * erro) / norma_entrada) * padroes_entrada[i][j]);
			}
			
            // Aplica a função de ativação
            saida_calculada[i] = (soma_ponderada[i] >= 0) ? 1 : -1;
            cout << "Entrada: (" << padroes_entrada[i][0] << ", " << padroes_entrada[i][1] << ") | Erro: " << erro << " | Saída: " << saida_calculada[i] << "\n";
        }
        cout << "----------------------------------------------\n";
    }

    cout << "Treinamento concluído após " << iteracao << " iterações.\n";
    cout << "Pesos finais:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Pesos[" << i << "]: ";
        for (int j = 0; j < 3; j++) {
            cout << pesos[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
