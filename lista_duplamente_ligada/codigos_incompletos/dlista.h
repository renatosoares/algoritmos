/* ---------- dlista.h ----------- */   
typedef struct dl_elementoLista{   
  char *dado;   
  struct dl_elementoLista *anterior;   
  struct dl_elementoLista*seguinte;   
} dl_elemento;   

typedef struct dl_ListaDetectada{   
  dl_elemento *início;   
  dl_elemento *fim;   
  int tamanho;   
} dl_Lista;   

/* inicialização da lista */   
void inicialização (dl_Lista * lista);   
dl_elemento *aloc (dl_elemento * novo_elemento);   

/* INSERÇÃO */   
int ins_em_uma_lista_vazia (dl_Lista * lista, char *dado);   
int ins_início_lista (dl_Lista * lista, char *dado);   
int ins_fim_lista (dl_Lista * lista, char *dado);   
int ins_depois (dl_Lista * lista, char *dado, int pos);   
int ins_antes (dl_Lista * lista, char *dado, int pos);   


/* REMOÇÃO */   
int REMOV(dl_Lista *lista, int pos);   
void exibe (dl_Lista * lista);   

/**************************/   
void exibe_inv (dl_Lista * lista);   
void destruir (dl_Lista * lista);   
/* -------- FIM lista.h --------- */   