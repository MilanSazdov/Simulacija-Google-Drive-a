#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GoogleDrive.h"

int main()
{
    int n;

    int x = 1;
    printf("Meni koji korisnig moze da koristi: ");
    printf("\n\n");




    do{
        x = provera();
        if(x){
            Meni1();
        }else{
        Meni2();
        }
        printf("Unesite broj za opciju koje su navedene u meniju: ");
        fflush(stdin);
        scanf("%d",&n);
        printf("\n\n");
        if(n <= 0 || n > 6){
            printf("Niste uneli odgovarajuci broj iz menija. Pokusajte ponovo.\n");
        }

        if(n == 6){
            printf("Kraj programa ...");
            break;
        }
        switch(n){

            case 1:


                if(x){
                    DodavanjeNaloga();
                }else{
                printf("uneli ste neodgovarajuci broj!!\n\n");
                }
                break;
            case 2:
                if(x){
                Login();

                }else{
                printf("uneli ste neodgovarajuci broj!!\n\n");
                }
                break;
            case 3:
                if(!x){
                Logout();

                }else{
                printf("uneli ste neodgovarajuci broj!!\n\n");
                }
                break;
            case 4:
                if(!x){
                IzmenaNaloga();
                }else{
                printf("uneli ste neodgovarajuci broj!!\n\n");
                }
                break;
            case 5:
                if(!x){
                BrisanjeAcc();

                }else{
                printf("uneli ste neodgovarajuci broj!!\n\n");
                }
                break;
        }

    }while(n != 6);





    return 0;
}
