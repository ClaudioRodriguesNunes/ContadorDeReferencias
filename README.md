# ContadorDeReferencias
  Implementação de um coletor de lixo por contagem de referências para a linguagem C, usando uma biblioteca estática.
  
  O arquivo contref.c é o código fonte usado para gerar a biblioteca, nele constam:
  
   As funções necessárias para o coletor (malloc2 / atrib2).
    
   Algumas variações dessas funções que buscam melhorar o funcionamento das mesmas, porém mudam a passagem de parâmetros e retorno (malloc3 / atrib3).
    
   Uma lista global que armazena um endereço genérico e um contador, para simular o funcionamento do heap (listareferencias).
    
   Funções auxiliares para trabalhar com listas de forma recursiva (arrumacontador / removelixo).
    
   Uma função para exibir a lista global (dump).
    
   Uma função para liberar todos os endereços alocados dinamicamente (encerra).
   
  O arquivo contref.h é o cabeçalho da biblioteca, que deve ser incluido em códigos que façam uso da biblioteca, e contem apenas: 

   Os nomes das funções e seus respectivos parametros.
   
   Criação do tipo de dado usado para lista global ( uma struct ).
  
