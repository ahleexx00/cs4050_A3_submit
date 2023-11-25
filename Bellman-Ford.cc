#include "cs4050.h"
#include "Bellman-Ford.h"
#include "Util.h"

#include <float.h>
#include <stdio.h>

void ShortestPaths(
	Vertex * V, int countV, 
	Edge * E, int countE, 
	int t,
	float d[],
	int successor[])
{
    int prev[countV];
    int update[countV];
    for(int v=0; v<countV; v++){
        d[v]=FLT_MAX;
        successor[v]=-1;

        prev[v]=0;
        update[v]=0;

    }

    d[t]=0;
    prev[t]=1;
    //update[t]=1;

    for(int i=1; i<countV; i++){
        for(int w =0; w<countV; w++){
            if(prev[w]==1){
                for(int e=0; e<countE; e++){    //FOREACH edge (v, w) ∈ E :
                    if(E[e].to-1 == w){           //FOREACH edge (v, w) ∈ E :
                        if(d[E[e].from-1] > d[w] + E[e].weight){  //IF (d[v] > d[w] + ℓvw)
                            d[E[e].from-1] = d[w] + E[e].weight;  //d[v] ← d[w] + ℓvw
                            successor[E[e].from-1] = w;           //successor[v] ← w
                            update[E[e].from-1]=1;   //update
                        }
                        
                    }
                    
                }
                
                
            }

        }
        for(int k=0; k<countV; k++){
            prev[k]=update[k];
            update[k]=0;
        }
        
        /*
        printf("loop %d\n", i);
        printf("d[]=");
        for(int p=0; p<countV; p++){
            printf("|%.1f|", d[p]);
        }
        printf("\n");
        printf("successor[]=");
        for(int q=0; q<countV; q++){
            printf("|%d|", successor[q]);
        }
        printf("\n");
        */
    }

}
