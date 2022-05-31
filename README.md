## NasAlturas
  tive muita dificuldade para estruturar o programa e saber de fato as funções necessárias para o funcionamento dele. ainda estão com alguns erros, pois foi basicamente a primeira vez que "implementei" uma arvore, e pela metade uma vez que ~~peguei~~ foi disponibilizado o template pelo professor.
	
  particularmente, acredito que a função principal, não para execução e bom funcionamento do programa, mas sim para atingir a meta que este Exercicio Programa propoe, é calculo das Alturas, tanto de BST simples (_bstCalculaAltura()_), quanto da AVL (_avlCalculaAltura()_). Já que a proposta do exercicio é ver como as alturas de cada uma se comporta com a inserção de N elementos.
  
## árvore de elementos aleatórios
  talvez uma das partes que mais quebrei a cabeça, desisti e fui buscar algum video que poderia me ajudar, e encontrei! adaptei-o para meu codigo. a logica utilizada é um pouco estranha, mas compreensivel. uma vez que não sei quantos sorteios serão realizados para que nenhum numero se repita, é feito um ```do...while```, que sorteia N numeros (N é a quantidade de numeros que terá em cada arvore, sendo este _inputado_ pelo usuário), ou seja, enquanto não for sorteado N numeros, continue executando o codigo. 
	Nesta execução, ele vai fazer uma comparação de numeros sorteados e numeros inseridos no vetor, percorrendo-o. Se o numero sorteado for igual, sorteará um novo numero, senão, será inserido no vetor. Por algum motivo, acho que essa não é a melhor forma de fazer, acredito que os numeros sorteados ficam limitados até N-1, mas também não queria colocar um valor fixo ~~cheira a gambiarra, mas no replit coloquei 6K~~.
  
## comentários e conclusão Final

  não sei se é o replit que está tendo problemas em relação as funções de free, mas caso as chamadas não sejam comentadas elas davam problemas de ```segmentation fault (core dumped)```, comentei todas elas com exceção da //free(numerosAleatorios). Também atribui ```NULL``` a ```BST * rBST``` e ```AVL * rAVL```, não sei por qual motivo mas também corrigiu os erros de ```segmentation fault (core dumped)```.
	
  Nos 45 do segundo tempo, descobri um novo erro: ```double free or corruption (out)```, ele foi solucionado somente no replit (não sei como é o funcionamento em outros IDE) comentando a chamada da função ```free(numerosAleatorios)```. esse erro aparecia toda vez que Amostra(A) > 3, então não dava para chegar numa boa conclusão sobre o comportamento das arvores, muito menos elaborar este relatório ~por isso que ele está sendo elaborado tão tarde~.
	
![os benditos](https://user-images.githubusercontent.com/84683597/171119651-6a0efe07-ad78-4f3f-987b-bd211b6a6c8f.png)
  
	erros e versão corrigida, yeah! :D
  
  após este reparo, foi testado alguns valores para amostras e nós, e o resultado segue abaixo conforme imagens:
  
![impressoes](https://user-images.githubusercontent.com/84683597/171131879-ab3c0c0f-27c4-45f0-b425-e6b4aba73b1f.png)
  

   Por fim, de inicio, ao solicitar uma árvore com poucos elementos, ambas as árvores levam tempos aproximados de execução e suas alturas, quando não eram iguais, eram valores muito próximos. Então, usar o algoritmo de BST ou AVL com quantidade de inserções pequenas, pode ser a principio indiferente. No entanto, conforme o usuário solicita uma quantidade de inserção grande, ou seja, o número de nós(N) na árvore cresce, podemos ver que a BST perde sua eficiência por conta de sua altura, que possui tem uma diferença notável em comparação ao tamanho ideal. Por sua vez, a AVL, garante que a altura esteja sempre no tamanho ideal (log <sub> 2 </sub> n) ou muito proximo dele, possuindo sempre os menores valores de altura.
	 
  gostaria de ter implementado a função de tempo também, deve ser interessantíssimo ver o tempo de execução de cada árvore. acredito que por conta das diversas rotações que são feitas na arvore AVL, pode fazer com que o tempo de execução dela seja mais demorado, diferente da BST, uma vez que ela se preocupa só em adicionar o novo nó no lugar correspondente com sua lógica, independente do fator de balanceamento ou a altura final da arvore.
  
  
  O replit do exercicio pode ser visto neste acessando [Link - Replit](https://replit.com/@jyuurin/EasygoingClientsideTranslations#main.c)
