#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1024

typedef struct node *pnode;
typedef struct node
{
 char ch;
 int freq;
 pnode left;
 pnode right;
}node;

void push( pnode* heap, const int n);
pnode pop( pnode* heap, const int n);
int* encode( pnode current, int pre, int* top, char c );

int main(){
    int i=0, qSize=0;
    char str[MAX];             
    pnode pq[MAX];  
    pnode heap[MAX];           
    pnode entryOfHeap=NULL;     
    FILE *fp;                    
    char filename[16];

    printf("> Filename : ");
    scanf("%s", filename);
    if( ( fp=fopen(filename, "r+" ))==NULL ){
        printf("Input open error!\n" );
        exit(0);
    }

    char tmpc;
    int stridx = 0;
    while((tmpc = fgetc(fp)) != EOF){
        str[stridx++] = tmpc;
    }
    str[stridx] = '\0';
    fclose(fp);

    // calculate freq
    for( int j=0; j<strlen(str); j++ ){
        // overlap
        for( i=1; i<=qSize && i<MAX ;i++ ){
            if( pq[i]->ch==str[j] ){
                pq[i]->freq++;
                break;
            }
        }
        //else
        if( i==qSize+1 )
        {
            pq[qSize+1]=(pnode)malloc( sizeof(node) );
            pq[qSize+1]->ch=str[j];
            pq[qSize+1]->freq=1;
            pq[qSize+1]->left=NULL;
            pq[qSize+1]->right=NULL;
            qSize++;
        }
    }
    printf("> %s\n", str);
    printf("> leffers: %ld, bits: %ld\n", strlen(str), strlen(str)*8);

    // pq -> heap
    memcpy( &heap, &pq, sizeof(pq) );
    for( i=1; i<=qSize && i<MAX ;i++ )
        push( heap, i );

    for( i=qSize; i>1; i-- ){
        pnode tmp1 = pop( heap, i );
        pnode tmp2 = pop( heap, i-1 );
        
        heap[i-1] = (pnode)malloc( sizeof(node) );
        heap[i-1]->ch = -1;
        heap[i-1]->freq = tmp1->freq + tmp2->freq;

        if( tmp1->freq > tmp2->freq ){
            heap[i-1]->left=tmp2;
            heap[i-1]->right=tmp1;
        }
        else{
            heap[i-1]->left=tmp1;
            heap[i-1]->right=tmp2;
        }
        
        push( heap, i-1 );
    }

    entryOfHeap = heap[1];

    printf("> ---------------\n");
    printf("> Huffman code table\n");
    printf("> Char.\tFreq.\tCode\n");
    
    for( i=1; i<=qSize && i<MAX ;i++ ){
        printf("> %c\t%d\t", pq[i]->ch, pq[i]->freq );
        int top=0, *a=NULL;
        a = encode( entryOfHeap, -1, &top, pq[i]->ch );
            for( int j=0; j<top; j++ ){
                printf("%d", a[j] );
            }
            printf("\n" );
    }

    int wordCount=0;
    char total[MAX] = "";
    int totalindex = 0;
    for( i=0; i<strlen(str); i++ ){
        int top=0, *a=NULL;
        a = encode( entryOfHeap, -1, &top, str[i] );
        for( int j=0; j<top; j++ )
            total[totalindex++] = a[j] + '0';
        total[totalindex++] = ' ';
        wordCount+=top;
        free(a);
    }

    // Print result
    printf("----------------------------\n");
    printf("> Encodig results : %d bits\n", wordCount);
    
    printf("> %s", total);
    printf("\n");

    return 0;
}

//heap function
void push( pnode* heap, const int n){
    int i=n;
    pnode tmp = heap[n];
    while ( (i>1) && ( tmp->freq < heap[i/2]->freq) ){
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = tmp;
}

pnode pop( pnode* heap, const int n){
    int parent, child;
    pnode item, temp;
    item = heap[1];
    temp = heap[n];
    parent = 1;
    child = 2;
    while (child <= n){
        if ( (child < n) && ( heap[child]->freq > heap[child+1]->freq) )
            child++;
        if ( temp->freq <= heap[child]->freq )
            break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}

int* encode( pnode current, int pre, int* top, char c ){
    int* tmp;
    if( current->ch==c ){
        tmp=malloc( sizeof(int) );
        *tmp=pre;
        (*top)=1;
        return tmp;
    }
    if( current->ch!=-1 )
        return NULL;
    tmp=encode( current->left, 0, top, c );
    if( pre==-1 ){
        if( tmp!=NULL )
            return tmp;
        return encode( current->right, 1, top, c );
    }
    if( tmp==NULL ){
        tmp=encode( current->right, 1, top, c );
        if( tmp==NULL )
            return NULL;
    }
    ++(*top);
    tmp=realloc( tmp, *top );
    for( int i=(*top)-1; i>0; i-- )
        tmp[i]=tmp[i-1];
    tmp[0]=pre;
    return tmp;
}
