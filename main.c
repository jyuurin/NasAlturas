#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

 /* NÃO CONSEGUI IMPLEMENTAR :()
--------------------------------------------------------------------------------
 * Pra quem gosta mesmo:
 * Para calcularmos o tempo gasto numa operação, fazemos:
 
    clock_t t_inicio, t_final;
    double t_total;

    t_inicio = clock();
    fazTudoQueTemQueFazer(); // aqui podemos ter várias linhas, é onde vai o que queremos medir o tempo
    t_final = clock();

    t_total = (double) (t_final - t_inicio) / CLOCKS_PER_SEC;
    printf("Tempo total gasto pela CPU: %f\n", t_total);
 * 
 */

int MAX(int a, int b) {
    return a > b ? a : b;
}

typedef struct noBst {
    int chave;
    struct noBst * esq;
    struct noBst * dir;
} BST;

BST * bstNovoNo(int chaveParaCriacao) {
    BST * no = malloc(sizeof(struct noBst));
    no->chave = chaveParaCriacao;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

BST * bstInsert(BST * raiz, int chaveParaInsercao) {
    if (raiz == NULL) {
        return bstNovoNo(chaveParaInsercao);
    }

    if (chaveParaInsercao > raiz->chave) {
        raiz->dir = bstInsert(raiz->dir, chaveParaInsercao);
    }
    else {
  
        raiz->esq = bstInsert(raiz->esq, chaveParaInsercao);
    }
    return raiz;
}


int bstCalculaAltura(BST * raiz) {
// TODO: Essa função precisa retornar um inteiro que represente a altura do nó AVL recebido
  //adoraria explicar o que foi feito, mas infelizmente não consegui entender direito e vi num video como faz. Mas deu certo ):
  if(raiz == NULL)
    return 0;
  else
  {
    int esquerda = bstCalculaAltura(raiz->esq);
    int direita = bstCalculaAltura(raiz->dir);
    if(esquerda > direita)
      return esquerda + 1;
    else
      return direita + 1;

  }
}

void bstFree(BST * raiz) {
  if (raiz == NULL) return;

  if (raiz->esq != NULL)
    bstFree(raiz->esq);
  if (raiz->dir != NULL)
    bstFree(raiz->dir);
  
  free(raiz);
}

// _____________________________________________________________________________________________

typedef struct noAvl {
    int chave;
    int altura;
    struct noAvl * esq;
    struct noAvl * dir;
} AVL;

AVL * avlNovoNo(int chaveParaCriacao) {
    AVL * no = malloc(sizeof(struct noAvl));
    no->chave = chaveParaCriacao;
    no->altura = 1;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

int avlGetAltura(AVL * raiz) {
  if (raiz == NULL) return 0;
  return raiz->altura;
}

int avlCalculaAltura(AVL * raiz) {
// TODO: Essa função precisa retornar um inteiro que represente a altura do nó AVL recebido
  //adoraria explicar o que foi feito, mas infelizmente não consegui entender direito e vi num video como faz. Mas deu certo ):
  if(raiz == NULL)
    return 0;
  else
  {
    int esquerda = avlCalculaAltura(raiz->esq);
    int direita = avlCalculaAltura(raiz->dir);
    if(esquerda > direita)
      return esquerda + 1;
    else
      return direita + 1;
  }
}

int avlCalculaFb(AVL * no) {
  return avlGetAltura(no->esq) - avlGetAltura(no->dir);
}

AVL * avlRotL(AVL * raiz) {
  if (raiz == NULL) return raiz;
  
  AVL * novaRaiz = raiz->dir;
  raiz->dir = novaRaiz->esq;
  novaRaiz->esq = raiz;

  raiz->altura = avlCalculaAltura(raiz);
  novaRaiz->altura = avlCalculaAltura(novaRaiz);

  return novaRaiz;
}

AVL * avlRotR(AVL * raiz) {
  // TODO: Implementar o algoritmo de rotação à direita. Dica: é simétrico ao de RotL!
  // Fiz as substituições, o que era dir virou esq e o que era esq virou dir. hahah(y)
  //return NULL;Tá assim só pra vc ficar com vontade de implementar logo //e funcionou :D
  if (raiz == NULL) return raiz;
  
  AVL * novaRaiz = raiz->esq;
  raiz->esq = novaRaiz->dir;
  novaRaiz->dir = raiz;

  raiz->altura = avlCalculaAltura(raiz);
  novaRaiz->altura = avlCalculaAltura(novaRaiz);

  return novaRaiz;
}

AVL * avlInsert(AVL * raiz, int chave) {
  if (raiz == NULL)
    return avlNovoNo(chave);
  
  if (chave > raiz->chave)
    raiz->dir = avlInsert(raiz->dir, chave);
  else
    raiz->esq = avlInsert(raiz->esq, chave);

  raiz->altura = avlCalculaAltura(raiz);
  int fb = avlCalculaFb(raiz);

  if (fb == +2) { 
    if (avlCalculaFb(raiz->esq) < 0) {
      raiz->esq = avlRotL(raiz->esq); 
    }
    raiz = avlRotR(raiz);
  }
  else if (fb == -2) {
    if (avlCalculaFb(raiz->dir) > 0) {
      raiz->dir = avlRotR(raiz->dir);
    }
    raiz = avlRotL(raiz);
  }
  
  return raiz;
}

/*FUNÇAO FREE Comentada pois tava dando Segmentation Fault.
void avlFree(AVL * raiz) {
  if (raiz == NULL) return;

  if (raiz->esq != NULL)
    avlFree(raiz->esq);
  if (raiz->dir != NULL)
    avlFree(raiz->dir);
  
  free(raiz);
}*/

// _____________________________________________________________________________________________

int* geraNumerosAleatorios(int N) {
  // TODO: gerar N números aleatórios e inserir no array numerosAleatorios.Perguntas que você deve fazer.
  //Fiz um Do...While, que sorteia N numeros, e faz uma comparação de numeros sorteados, se for igual sorteia novamente, até sortear as N vezes.
  
  int* numerosAleatorios = malloc(sizeof(int) * N); // array de numeros aleatorios inteiros, de tamanho N
  int i = 0, j, compara;
  
  do
  {
    numerosAleatorios[i] = rand() % N;
    compara = 0;
    for(j = 0; i > j; j++)
    {
      if(numerosAleatorios[j] == numerosAleatorios[i])
        compara = 1;
    }
    if(compara == 0)
      i++;
  }while(i < N);
    return numerosAleatorios;
}

void print(char * msg) {
    printf("%s", msg);
    printf("\n");
}

int main() {
    srand(time(NULL));
  
    //Inputs do usuário
    int A, N;
    print("EP2 - Nas alturas - Template");
    print("--------------------------------");
    printf("Digite o número de amostras: ");
    scanf("%d", &A);
    printf("Digite o número de nós: ");
    scanf("%d", &N);

    //VARIAVEIS
    //Para guardar as alturas registradas em cada amostra.
    double* alturaBst = malloc(sizeof(int) * A);
    double* alturaAvl = malloc(sizeof(int) * A);
    //Para guardar a soma de todas as alturas e fazer o calculo da média.
    double bstAlturas = 0;
    double avlAlturas = 0;
    //Para exibir o valor final de cada media.
    double mediaBst = 0;
    double mediaAvl = 0;
    double mediaGeral = 0;
  
    for (int i = 0; i < A; i++) {
        int * numerosAleatorios = geraNumerosAleatorios(N);
        BST * rBst = NULL;
        AVL * rAvl = NULL;

        for (int k = 0; k < N; k++) {
            printf("%d ", numerosAleatorios[k]);
            rBst = bstInsert(rBst, numerosAleatorios[k]);
            rAvl = avlInsert(rAvl, numerosAleatorios[k]);
        }
        //Vetor que guarda as alturas de cada arvore, conforme o numero de amostras solicitadas.
        alturaBst[i] = bstCalculaAltura(rBst);
        alturaAvl[i] = avlCalculaAltura(rAvl);

        //Funções de Free comentadas pois tava dando problema de segmentation fault, não entendi porque. :(
        //avlFree(rAvl);
        //bstFree(rBst);
        free(numerosAleatorios);
    }
    printf("\n");
    //TODO: pensar em um jeito de guardar essas alturas para depois poder calcular a média geral:
    //Resposta: Array de alturas, soma os valores de alturas de cada posiçao do array e atribui a uma variavel.
    
    for (int i = 0; i < A; i++) 
    {
      bstAlturas += alturaBst[i];
      avlAlturas += alturaAvl[i];
    }
    //Calculo de médias. Divisão das Alturas por Amostras.
    mediaBst = bstAlturas / A;
    mediaAvl = avlAlturas / A;
    mediaGeral = (bstAlturas + avlAlturas)/(2*A);

    
    /*DADOS DO EXERCICIO:
      Retorno de dados solicitados no exercicio, os calculos de média. */
    printf("A altura média geral das arvores é: %f \n", mediaGeral);
    print("--------------------------------");
    printf("A altura média da BST é: %f\n", mediaBst);
    print("--------------------------------");
    printf("A altura média da AVL é: %f\n", mediaAvl);
    print("--------------------------------");

}
