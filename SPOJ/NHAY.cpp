#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

// Based on Finite Automation.
// http://algs4.cs.princeton.edu/53substring/KMP.java.html
// http://stackoverflow.com/questions/30080153/pattern-matching-with-finite-automata
// This solution times out.
// Try this http://algs4.cs.princeton.edu/53substring/KMPplus.java.html


class KMP{
char *pattern;
int** dfa;
int R;
int temp;

public:
    KMP(char *pat):R(150){
        //printf("hala");
        //printf("%s\n",pat);
        //printf("%d\n",R);

        pattern = pat;

        int M = strlen(pattern);
        //printf("%d\n",M);

        dfa = new int*[R];
        for(int i = 0; i < R; ++i) {
            dfa[i] = new int[M];
        }
        //dfa = new int[R][M];

        dfa[pattern[0]][0] = 1;  // Initialize 1st column
        int X = 0;
        for (int j=1;j<M;j++){
            for(int c=0;c<R;c++){
                //printf("---%d\n",X);
                //printf("%d - %d\n",c,dfa[c][X]);
                dfa[c][j] = dfa[c][X];

            }
            dfa[pattern[j]][j] = j+1;
            //printf("----mid%d\n",X);
            X = dfa[pattern[j]][X];
        }
        //printf("----end%d\n",2);
        temp = X;
        //dfa[][] = X;
        //printf("%d\n",123456789);
    }

    ~KMP(){
        //printf("%s\n",pattern);
        //delete [] pattern;
        for(int i = 0; i < R; ++i) {
            delete [] dfa[i];
        }
        delete [] dfa;
        //delete [][] dfa;
    }

    int search(){
        int M = strlen(pattern);
        //int N = strlen(text);

        int i,j;
        char ch;
        j=0;
        i=0;
        while((ch=getchar())!='\n')
        int X=0;
        while((ch=getchar())!='\n'){
            j = dfa[ch][j];
            i++;
            if(j==M){
                printf("%d\n",i-M);
                //j=X;
                j=temp;

            }

            //printf("### %d-%d\n",i,j);
            //X = dfa[ch][X];
        }
        printf("\n");
        /*
        for(i=0,j=0;i<N&&j<M;i++){
            j = dfa[text[i]][j];
        }
        if (j==M) return i-M;
        return N;
        */
    }

};



int main(){
    //printf("%d\n",'z');
    int tc,n;
    scanf("%d", &tc);
    KMP* kmp;
    while(scanf("%d", &n) != EOF){

        char pat[n];
        scanf("%s", &pat);
        //printf("%s\n",pattern);
        kmp = new KMP(pat);
        kmp->search();
        //printf("%d\n",1234567890);
    }
    return 0;
}
