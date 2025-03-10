---

# Rede Neural Simples em C++

Este repositório contém um código em C++ que implementa um **algoritmo simples de aprendizado de máquina** para treinar uma rede neural básica. O objetivo é ajustar os pesos da rede para que ela aprenda a mapear entradas para saídas desejadas, utilizando **iterações** e **verificação de erro**.

---

## Funcionalidades do Código

### 1. **Entradas e Pesos**
- As entradas são representadas por uma matriz `padroes_entrada`, onde cada linha corresponde a um padrão de entrada (incluindo o bias).
- Os pesos iniciais são definidos em uma matriz `pesos`, que é ajustada durante o treinamento.

### 2. **Saídas Desejadas**
- As saídas desejadas são armazenadas no vetor `saidas_desejadas`.

### 3. **Treinamento**
- O algoritmo calcula a **soma ponderada** das entradas e pesos.
- O **erro** é calculado como a diferença entre a saída desejada e a soma ponderada.
- Se o erro absoluto for maior que o **limiar de erro aceitável**, os pesos são ajustados usando a fórmula:
  ```cpp
  pesos[i][j] = pesos[i][j] + (((taxa_aprendizado * erro) / norma_entrada) * padroes_entrada[i][j]);
  ```

### 4. **Iterações**
- O treinamento continua até que o erro de todas as amostras esteja dentro do limiar aceitável.

### 5. **Função de Ativação**
- A função de ativação é uma função degrau, onde a saída é `1` se a soma ponderada for maior ou igual a zero, e `-1` caso contrário.

### 6. **Saída**
- O código exibe o erro e a saída calculada para cada padrão de entrada em cada iteração.
- Após o treinamento, os pesos finais são exibidos.

---

## Como Executar

### Compilação
1. Certifique-se de ter um compilador C++ instalado (ex.: `g++`).
2. Compile o código usando o seguinte comando:
   ```bash
   g++ -o rede_neural rede_neural.cpp
   ```

### Execução
Execute o programa gerado:
```bash
./rede_neural
```
---

## Variáveis do Código

- **`padroes_entrada[4][3]`**: Matriz que armazena os padrões de entrada (incluindo o bias).
- **`pesos[4][3]`**: Matriz que armazena os pesos da rede neural.
- **`saidas_desejadas[4]`**: Vetor que armazena as saídas desejadas para cada padrão de entrada.
- **`taxa_aprendizado`**: Taxa de aprendizado usada para ajustar os pesos.
- **`erro_aceitavel`**: Limiar de erro aceitável para parar o treinamento.
- **`soma_ponderada[4]`**: Vetor que armazena a soma ponderada das entradas e pesos.
- **`erro`**: Erro calculado para cada padrão de entrada.
- **`norma_entrada`**: Norma (magnitude) da entrada, usada para normalizar o ajuste dos pesos.
- **`saida_calculada[4]`**: Vetor que armazena a saída calculada pela função de ativação.
- **`erro_dentro_aceitavel`**: Flag que indica se o erro está dentro do limiar aceitável.
- **`iteracao`**: Contador de iterações do treinamento.

---

## Objetivo

Este código foi desenvolvido como parte do meu **primeiro contato com Inteligência Artificial**, com o objetivo de entender como as **iterações** e o **ajuste de pesos** funcionam em um algoritmo de aprendizado simples.

---
