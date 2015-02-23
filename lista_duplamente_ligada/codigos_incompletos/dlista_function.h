/***************************\   

    dlista_function.h * 


\***************************/   
void inicialização (dl_Lista * lista){   
  lista->início = NULL;   
  lista->fim = NULL;   
  lista->tamanho = 0;   
}   

int inserção_em_uma_lista_vazia (dl_Lista * lista, char *dado){   
  dl_elemento *novo_elemento;   
  if ((novo_elemento = aloc (novo_elemento)) == NULL)   
    return -1;   
  strcpy (novo_elemento->dado, dado);   
  novo_elemento->anterior = NULL;   
  novo_elemento->seguinte = NULL;   
  lista->início = novo_elemento;   
  lista->fim = novo_elemento;   
  lista->tamanho++;   
  return 0;   
}   

int ins_início_lista (dl_Lista * lista, char *dado){   
  dl_elemento *novo_elemento;   
  if ((novo_elemento = aloc (novo_elemento)) == NULL)   
    return -1;   
  strcpy (novo_elemento->dado, dado);   
  novo_elemento->anterior = NULL;   
  novo_elemento->seguinte = liste->início;   
  lista->início->anterior = novo_elemento;   
  lista->início = novo_elemento;   
  lista->tamanho++;   
  return 0;   
}   

int ins_fim_lista (dl_Lista * lista, char *dado){   
  dl_elemento *novo_elemento;   
  if ((novo_elemento = aloc (novo_elemento)) == NULL)   
    return -1;   
  strcpy (novo_elemento->dado, dado);   
  novo_elemento->seguinte = NULL;   
  novo_elemento->anterior = lista->fim;   
  lista->fim->seguinte = novo_elemento;   
  lista->fim = novo_elemento;   
  lista->tamanho++;   
  return 0;   
}   

int ins_depois (dl_Lista * lista, char *dado, int pos){   
  int i;   
  dl_elemento *novo_elemento, *em curso;   
  if ((novo_elemento = aloc (novo_elemento)) == NULL)   
    return -1;   
  strcpy (novo_elemento->dado, dado);   
  em curso = lista->início;   
  for (i = 1; i < pos; ++i)   
    em curso = em curso->seguinte;   
  novo_elemento->seguinte = em curso->seguinte;   
  novo_elemento->anterior = em curso;   
  if(em curso->seguinte == NULL)   
    lista->fim = novo_elemento;   
  else   
    em curso->seguinte->anterior = novo_elemento;   
  em curso->seguinte = novo_elemento;   
  lista->tamanho++;   
  return 0;   
}   

int ins_antes (dl_Lista * lista, char *dado, int pos){   
  int i;   
  dl_elemento *novo_elemento, *em curso;   
  if ((novo_elemento = aloc (novo_elemento)) == NULL)   
    return -1;   
  strcpy (novo_elemento->dado, dado);   
  em curso = lista->início;   
  for (i = 1; i < pos; ++i)   
    em curso = em curso->seguinte;   
  novo_elemento->seguinte = em curso;   
  novo_elemento-> anterior = em curso->anterior;   
  if(em curso->anterior == NULL)   
    lista->início = novo_elemento;   
  else   
    em curso->anterior->seguinte = novo_elemento;   
  em curso->anterior = novo_elemento;   
  lista->tamanho++;   
  return 0;   
}   

int remov(dl_Lista *lista, int pos){   
  int i;   
  dl_elemento *remov_elemento,*em curso;   
     
  if(liste->tamanho == 0)   
    return -1;   

  if(pos == 1){ /* remoção do 1° elemento */   
    remov_elemento = lista->início;   
    lista->início = lista->início->seguinte;   
    if(lista->início == NULL)   
      lista->fim = NULL;   
    else   
      lista->início->anterior == NULL;   
  }else if(pos == lista->tamanho){ /* remoção do último elemento */   
    remov_elemento = lista->fim;   
    lista->fim->anterior->seguinte = NULL;   
    lista->fim = lista->fim->anterior;   
  }else { /* remoção em outro lugar */   
    em curso = lista->início;   
    for(i=1;i<pos;++i)   
     em curso = em curso->seguinte;   
    remov_elemento = em curso;   
    em curso->anterior->seguinte = em curso->seguinte;   
    em curso->seguinte->anterior = em curso->anterior;   
  }   
  free(remov_elemento->dado);   
  free(remov_elemento);   
  lista->tamanho--;   
  return 0;   
}   

void destruir(dl_Lista *lista){   
  while(lista->tamanho > 0)   
    remov(lista,1);   
}   

dl_elemento *aloc (dl_elemento * novo_elemento){   
  if ((novo_elemento = (dl_elemento *) malloc (sizeof (dl_elemento))) == NULL)   
    return NULL;   
  if ((novo_elemento->dado = (char *) malloc (50 * sizeof (char)))   
      == NULL)   
    return NULL;   
  return novo_elemento;   
}   

int menu (dl_Lista *lista){   
  int escolha;   
  if (lista->tamanho == 0){   
    printf ("1. Adição do 1° elemento\n");   
    printf ("2. Fechar\n");   
  }  else{   
    printf ("1. Adição no início da lista\n");   
    printf ("2. Adição no final da lista\n");   
    printf ("3. Adição antes da posição especificada\n");   
    printf ("4. Adição depois da posição especificada\n");   
    printf ("5. Remoção da posição especificada\n");   
    printf ("6. Destruir a lista\n");   
    printf ("7. Fechar\n");   
  }   
  printf ("\n\nFaça sua escolha: ");   
  scanf ("%d", &escolha);   
  getchar();   
  if(lista->tamanho == 0 && escolha == 2)   
    escolha = 7;   
  return escolha;   
}   
int exibe(dl_Lista *lista, int pos);   
void exibe(dl_Lista *lista){   
 dl_elemento *em curso;   
 em curso = lista->início;   
 printf("[ ");   
 while(em curso != NULL){   
  printf("%s ",em curso->dado);   
  em curso = em curso->seguinte;   
 }   
 printf("]\n");   
}   
void exibe_inv(dl_Lista *lista){   
 dl_elemento *em curso;   
 em curso = lista->fim;   
 while(em curso != NULL){   
  printf("%s : ",em curso->dado);   
  em curso = em curso->anterior;   
 }   
 printf("\n");   
}   
/* -------- FIM dlista_function.h --------- */  
