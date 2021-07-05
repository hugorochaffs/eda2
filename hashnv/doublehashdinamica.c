#define hash(v,M) (v%M)
#define hashtwo(v,M) (v%97+1)
#define key int
#define key(x) (x.chave)
#define less(a,b) (key(a) < key(b))
#define null(A) (key(ht[A])== key(NULLitem))
#define eq(a,b) (a == b)
static int N,M;
static Item *ht;

void HTinsert(Item item){
    key v = key(item);
    int i = hash(v,M);
    int k = hashtwo(v,M);
    while(!null(i)) i=(i+k)%M;
    ht[i] = item;
    N++;
    if(N>=M/2)
    expand();

}

Item HTsearch(key v){
    int i = hash(v,M);
    int k = hashtwo(v,M);
    while(!null(i))
    if(eq(v,key(ht[i])))return ht[i];
    else i = (i+k)%M;
    return NULLitem;
}

void expand(){
    int i;
    Item *t = ht;
    ht = malloc(sizeof(Item)*M*2);
    M = M*2;
    for(i=0;i<M/2;i++){
        if(key(t[i])!=key(NULLitem))
        HTinsert(t[i]);
    free(t);
    }
}