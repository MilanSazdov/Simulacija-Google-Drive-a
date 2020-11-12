#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GoogleDrive.h"
/*
fscanf(dat,"%[^\n]s",niz);

*/
int provera(){
    int i;
    FILE* dat = fopen("Dodavanje naloga.txt","r+");
    if (dat == NULL){
        printf("Memory failed!!!");
        return;
    }
    char s1[40];
for(i=0;;i++){

        fscanf(dat,"%[^\n]s",s1);



        if(feof(dat)){
            break;
        }
        fgetc(dat);
        if(strcmp("Online",s1) == 0 && i%6 == 5){
                fclose(dat);
            return 0;
            break;
        }
    }
    fclose(dat);
return 1;
}
void Meni1()
{


    printf("\n  *-----------------------------------------------------*\n");
    printf("  | Unesite 1. za Register:                             |\n");
    printf("  | Unesite 2. za Login:                                |\n");
    printf("  | Unesite 6. za Exit:                                 |\n");
    printf("  *-----------------------------------------------------*\n\n");

    return;
}
void Meni2(){
    printf("\n  *-----------------------------------------------------*\n");
    printf("  | Unesite 3. za Logout:                               |\n");
    printf("  | Unesite 4. za Izmenu naloga:                        |\n");
    printf("  | Unesite 5. za Brisanje naloga:                      |\n");
    printf("  | Unesite 6. za Exit:                                 |\n");
    printf("  *-----------------------------------------------------*\n\n");


return;
}
int Mail(char* niz){

    int i;
    int a = 0;
    for(i=0;i<strlen(niz);i++){
        if(niz[i]=='@'){
            a= 1;
        }
        if (niz[i] == '.' && a == 1){
            a = 2;

        }
    }
    if(a!=2){

        return 1;
    }
    FILE* dat = fopen("Mejlovi.txt","r+");
    if(dat == NULL){
        printf("Memory failed!");
        return 1;
    }
    fseek(dat,0,SEEK_SET);
    char s[40];

    for(i=0;;i++){
     //   fscanf(dat,"%s",s);
        fscanf(dat,"%[^\n]s",s);

        fgetc(dat);
        if (feof(dat)){
            break;
        }
        if(strcmp(s,niz)==0){
                fclose(dat);
            return 1;
        }

    }

fclose(dat);
return 0;
}

int DodavanjeNaloga()
{
    Nalog acc;
    FILE* dat;
    dat = fopen("Dodavanje naloga.txt","a+");
    if(dat == NULL)
    {
        printf("Dodavanje naloga nije moguce !");
    }
    FILE* dat1 = fopen("Mejlovi.txt","a+");
     if(dat1 == NULL){
        printf("Memory failed !");
    }
    char pom[20];
    int rezultat;

    printf("Unesite ime: ");
    fflush(stdin);
    gets(acc.ime);
    fflush(stdin);


    printf("Unesite prezime: ");
    fflush(stdin);
    gets(acc.prezime);
    fflush(stdin);

   // do{
    ponovo:
    printf("Unesite email: ");
    fflush(stdin);
    gets(acc.email);
    if(Mail(acc.email)){
        printf("Uneli ste neodgovarajucu email adresu!!!\n\n");
        goto ponovo;
    }

    int i,n;
    char privremeni[40];
    /*for(i=0;;i++){
        fscanf(dat1,"%s",privremeni);
        if(feof(dat1)){
            break;
        }
        if (!strcmp(acc.email,privremeni)){
            printf("Uneli ste isti email!!!\n\n");
            goto ponovo;
        }
    }
*/
    fflush(stdin);
  //  }while(ValidEmail(acc.email,dat));

    printf("Unesite nickname: ");
    fflush(stdin);
    gets(acc.nickname);
    fflush(stdin);



    do
    {
        printf("Unesite password: ");
        fflush(stdin);
        gets(acc.password);
        fflush(stdin);

        printf("Unesite password jos jednom za potvrdu: ");
        fflush(stdin);
        gets(pom);
        fflush(stdin);

        rezultat = strcmp(acc.password,pom);

        if(rezultat != 0)
        {
            printf("Sifre se ne podudaraju. Pokusajte ponovo !\n\n");
        }
    }
    while(rezultat != 0);


    fprintf(dat,"%s",acc.ime);
    fputc('\n',dat);
    fprintf(dat,"%s",acc.prezime);
    fputc('\n',dat);
    fprintf(dat,"%s",acc.email);
    fprintf(dat1,"%s",acc.email);
    fputc('\n',dat);
    fputc('\n',dat1);
    fprintf(dat,"%s",acc.nickname);
    fputc('\n',dat);
    fprintf(dat,"%s",acc.password);
    fputc('\n',dat);
    fprintf(dat,"%s","Offline");
    fputc('\n',dat);
    fclose(dat);
    fclose(dat1);

    return;

}
void Overflow(int n,FILE* dat){

    n=n+1;
    int counter = 0;
    char status[] = "Online\n";
    fseek(dat,0,SEEK_SET);
    char c;
    int linija;
    linija = n * 6 - 1;

    FILE* datCopy;
    datCopy = fopen("Kopiranje.txt","w+");
    if(datCopy == NULL){
        printf("Memory failed !!!");
    }
    char kopiranje[40];

    for(;;counter++){
    fgets(kopiranje,40,dat);
    if (feof(dat)){
                break;
            }
        if(counter == linija){
            fputs(status,datCopy);

        }
        else{



            fflush(stdin);
            fputs(kopiranje,datCopy);
        }

    }

    fclose(datCopy);
    fclose(dat);

    rename("Dodavanje naloga.txt","Zamena.txt");
    rename("Kopiranje.txt","Dodavanje naloga.txt");
    remove("Zamena.txt");

    return;

}
void OverflowV2(int n,FILE* dat){

    int counter = 0;
    char status[] = "Offline\n";
    fseek(dat,0,SEEK_SET);
    char c;
    FILE* datCopy;
    datCopy = fopen("Kopija.txt","w+");
    if(datCopy == NULL){
        printf("Memory failed!");
        return;
    }
    char kopiranje[40];
    for(;;counter++){
      //  fscanf(dat,"%s",kopiranje);
        fscanf(dat,"%[^\n]s",kopiranje);

        if(feof(dat)){
            break;
        }
        fgetc(dat);
        if(counter == n){
            fflush(stdin);
            fprintf(datCopy,"%s",status);
        }
        else{
            fflush(stdin);
            fprintf(datCopy,"%s",kopiranje);
            fprintf(datCopy,"\n");
            fflush(stdin);
        }
    }
    fclose(datCopy);
    fclose(dat);

    remove("Dodavanje naloga.txt");

    rename("Kopija.txt","Dodavanje naloga.txt");

    return;

}

int Login()
{

    Nalog niz[100];

    int pom2,i;
    char nickV[20];
    char emailV[40];
    char passwordV[20];
    int rezultat;
    int n;
    char status[10];
    FILE* dat = fopen("Dodavanje naloga.txt", "r+");
    if(dat == NULL){
        printf("Memory failed !");
    }
    for (n=0;; n++)
    {
       // fscanf(dat,"%s",niz[n].ime);
        fscanf(dat,"%[^\n]s",niz[n].ime);

        if (feof(dat))
        {   if(n == 0){
            printf("Morate se prvo registrovati !");
            fclose(dat);
            return;
        }
            break;
        }
        fgetc(dat);
       // fscanf(dat,"%s",niz[n].prezime);
        fscanf(dat,"%[^\n]s",niz[n].prezime);

        fgetc(dat);
     //   fscanf(dat,"%s",niz[n].email);
        fscanf(dat,"%[^\n]s",niz[n].email);

        fgetc(dat);
      //  fscanf(dat,"%s",niz[n].nickname);
        fscanf(dat,"%[^\n]s",niz[n].nickname);

        fgetc(dat);
     //   fscanf(dat,"%s",niz[n].password);
        fscanf(dat,"%[^\n]s",niz[n].password);

        fgetc(dat);
       // fscanf(dat,"%s",status);
        fscanf(dat,"%[^\n]s",status);


        if (!strcmp("Online",status)){
            printf("Vec ste ulogovani !!!");
            fclose(dat);
            return;
        }
        fgetc(dat);






    }

    printf("Unesite Vas username: ");
    fflush(stdin);
    scanf("%[^\n]s",nickV);

    printf("Unesite Vas email: ");
    fflush(stdin);
    scanf("%[^\n]s",emailV);

    printf("Unesite Vasu sifru: ");
    fflush(stdin);
    scanf("%[^\n]s",passwordV);
    int flag = 0;
    for(i = 0; i < n; i++)
    {
        rezultat = strcmp(nickV,niz[i].nickname);
        if(rezultat == 0)
        {

            rezultat = strcmp(emailV,niz[i].email);
            if(rezultat == 0){

                rezultat = strcmp(passwordV,niz[i].password);
                if(rezultat == 0){

                    printf("Vas account je pronadjen !");
                    pom2 = i;
                    Overflow(pom2,dat);
                    flag = 1;
                    break;
                }

            }

    }

    }
    if (flag == 0){
        printf("vas nalog nije pronadjen!!!\n\n");
        fclose(dat);
        return;
    }
    int pozicija = pom2;
    fclose(dat);

    return pozicija;
    }


void Logout()
{
    FILE* dat;
    dat = fopen("Dodavanje naloga.txt","r");
    if(dat == NULL){
        printf("Memory failed!");
        return;
    }

    int i,flag = 0;
    char s1[40];
    for(i=0;;i++){
       // fscanf(dat,"%s",s1);
        fscanf(dat,"%[^\n]s",s1);


        //fscanf(dat,"\n");
        if(feof(dat)){
            break;
        }
        fgetc(dat);
        if(strcmp("Online",s1) == 0 && i%6 == 5){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Morate se prvo loginovati da bi se mogli logoutovali !!!");
        fclose(dat);
        return;
    }
    fseek(dat,0,SEEK_SET);
    if(flag == 1){
    for(i=0;;i++){
      //  fscanf(dat,"%s",s1);
        fscanf(dat,"%[^\n]s",s1);

        if(feof(dat)){
            break;
        }
        fgetc(dat);
        if(strcmp("Online",s1)==0){
            OverflowV2(i,dat);
            printf("Uspesno ste se logoutovali !\n\n");
            break;
            }
        }
    }
    fclose(dat);
    return;
}
void OverflowV3(int n,FILE* dat,char* a){

 /*   FILE* dat;
    dat = fopen("Dodavanje naloga.txt","r+");
    if(dat == NULL){
        printf("Memory failed!");
    }*/
    int counter = 0;
    fseek(dat,0,SEEK_SET);
    FILE* datCopy;
    datCopy = fopen("Napapiri.txt","w+");
    if(datCopy == NULL){
        printf("Memory failed!");
        return;
    }
    char kopiranje[40];
    for(;;counter++){
       // fscanf(dat,"%s",kopiranje);
        fscanf(dat,"%[^\n]s",kopiranje);
        fgetc(dat);
        if(feof(dat)){
            break;
        }
        if(counter == n){
            fflush(stdin);
            fputs(a,datCopy);
            fputc('\n',datCopy);
        }
        else{
            fflush(stdin);
            fputs(kopiranje,datCopy);
            fputc('\n',datCopy);
            fflush(stdin);
        }

    }

    fclose(datCopy);
    fclose(dat);

    remove("Dodavanje naloga.txt");
    rename("Napapiri.txt","Dodavanje naloga.txt");




}
void OverflowV4(int n,char* a){

    int i;
    FILE* dat;
    dat = fopen("Mejlovi.txt","r+");
    if(dat == NULL){
        printf("Memory failed!");
        return;
    }
    fseek(dat,0,SEEK_SET);
    FILE* datCopy;
    datCopy = fopen("Zmejlovi.txt","w+");
    if(datCopy == NULL){
        printf("Memory failed!");
        return;
    }
    char kopiranje[40];
    for(i=0;;i++){
       // fscanf(dat,"%s",kopiranje);
        fscanf(dat,"%[^\n]s",kopiranje);
        fgetc(dat);
        if(feof(dat)){
            break;
        }
        if(n == i){
            fflush(stdin);
            fprintf(datCopy,"%s",a);
            fprintf(datCopy,"\n");
        }
        else{
            fflush(stdin);
            fprintf(datCopy,"%s",kopiranje);
            fputc('\n',datCopy);
            fflush(stdin);
        }
    }

    fclose(dat);
    fclose(datCopy);

    remove("Mejlovi.txt");
    rename("Zmejlovi.txt","Mejlovi.txt");





}
void OverflowV5(int n,FILE* dat){
    fseek(dat,0,SEEK_SET);

    int i;
    FILE* datCpy;
    datCpy = fopen("Brisanje.txt","w+");
    if(datCpy == NULL){
        printf("Memory failed !");
        return;
    }
    char s[40];
    for(i=0;;i++){
      //  fscanf(dat,"%s",s);
        fscanf(dat,"%[^\n]s",s);
        fgetc(dat);


        if(feof(dat)){
            break;
        }
        if(i >= n && i <= n + 5){

            continue;
        }
        else{
            fflush(stdin);
            fprintf(datCpy,"%s",s);

            fputc('\n',datCpy);
            fflush(stdin);
        }
    }
    fclose(dat);
    fclose(datCpy);

    remove("Dodavanje naloga.txt");
    rename("Brisanje.txt","Dodavanje naloga.txt");





}
void OverflowV6(int n){

    FILE* dat;
    dat = fopen("Mejlovi.txt","r+");
    if(dat == NULL){
        printf("Memory failed!");
        return;
    }
    fseek(dat,0,SEEK_SET);
    FILE* datCopy;
    datCopy = fopen("Novi.txt","w+");
    if(datCopy == NULL){
        printf("Memory failed!");
        return;
    }
    int i;
    char s[40];

    for(i=0;;i++){
      //  fscanf(dat,"%s",s);
        fscanf(dat,"%[^\n]s",s);
        fgetc(dat);
        if(feof(dat)){
            break;
        }
        if(i == n){
            continue;
        }
        else{
            fflush(stdin);
            fprintf(datCopy,"%s",s);
            fputc('\n',datCopy);
            fflush(stdin);
        }
    }
    fclose(dat);
    fclose(datCopy);
    remove("Mejlovi.txt");
    rename("Novi.txt","Mejlovi.txt");


}
void IzmenaNaloga(){

    FILE* dat;
    dat = fopen("Dodavanje naloga.txt","r+");
    if(dat == NULL){
        printf("Memory failed!");
        return;
    }
    fseek(dat,0,SEEK_SET);
    char s1[40];
    char email[40];
    char password[20];
    char username[20];
    char ime[20];
    char prezime[20];
    char ProveraSifre[20];
    char pom[40];
    char pom2[40];
    int i = 0;
    int j;
    int n;
    for(i=0;;i++){
       // fscanf(dat,"%s",s1);
        fscanf(dat,"%[^\n]s",s1);
        fgetc(dat);
        if( feof(dat)){
                printf("Morate se prvo loginovati !\n");
                fclose(dat);
            return;
        }

        if(strcmp("Online",s1)==0 && i % 6 == 5){
            break;
        }

        }
        fclose(dat);
            do{
            dat = fopen("Dodavanje naloga.txt","r+");
            printf("\nUnesite 1. za izmenu imena: \n");
            printf("Unesite 2. za izmenu prezimena: \n");
            printf("Unesite 3. za izmenu emaila: \n");
            printf("Unesite 4. za izmenu username: \n");
            printf("Unesite 5. za izmenu passworda: \n");
            printf("Unesite 6. za exit: \n");

            printf("Unesite sta zelite da izmenite: \n");
            scanf("%i",&n);
            fflush(stdin);

            if(n <= 0 || n > 6){
            printf("Niste uneli odgovarajuci broj iz menija. Pokusajte ponovo.\n");
            }
            if(n == 6){
                printf("Sve izemene koje ste uradili su zabelezene !");
                fclose(dat);
                break;
            }

            if(n == 1){
                printf("Unesite novo ime: ");
                gets(ime);
                fflush(stdin);
                OverflowV3(i-5,dat,ime);
            }
            if(n == 2){
                printf("Unesite novo prezime: ");
                gets(prezime);
                fflush(stdin);
                OverflowV3(i-4,dat,prezime);
            }
            if(n == 3){
                skok:
                printf("Unesite novi email: ");
                fflush(stdin);
                gets(email);

                if(Mail(email)){
                    printf("Uneli ste nevezeci ili isti email !");
                    goto skok;
                }
                OverflowV3(i-3,dat,email);
                OverflowV4(i/6,email);



            }
            if(n == 4){
                printf("Unesite novi username: ");
                fflush(stdin);
                gets(username);

                OverflowV3(i-2,dat,username);
            }
            if(n == 5){
                ponovo:
                printf("Unesite novi password: ");
                fflush(stdin);
                gets(password);
                printf("Ponovo unesite novi password: ");
                fflush(stdin);
                gets(ProveraSifre);
                if(strcmp(password,ProveraSifre) == 0){
                    OverflowV3(i-1,dat,password);
                }
                else{
                    printf("Uneli ste dve razlicite sifre !\n");
                    goto ponovo;
                }

               // OverflowV3(i-1,dat,password);
            }

            }while(n != 6);

}

void BrisanjeAcc(){

    FILE* dat;
    dat = fopen("Dodavanje naloga.txt","r+");
    if(dat == NULL){
        printf("Memory failed!");
        return;
    }
    int i;
    char s1[40];

    for(i=0;;i++){
      //  fscanf(dat,"%s",s1);
        fscanf(dat,"%[^\n]s",s1);
        fgetc(dat);
        if(feof(dat)){
            printf("Morate se prvo loginovati !\n");
            fclose(dat);
            return;
        }
        if(strcmp("Online",s1)==0 && i % 6 == 5){
            break;

        }
    }
        OverflowV5(i - 5,dat);
        OverflowV6(i/6);
        printf("Vas nalog je uspesno obrisan !\n");
}
