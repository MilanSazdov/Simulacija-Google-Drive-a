#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "GoogleDrive.h"
/*
fscanf(dat,"%[^\n]s",niz);

*/
int provera(){
    int i;
    FILE* dat = fopen("Dodavanje naloga.txt","r+");
    if (dat == NULL){
        printf("Memory failed!!!");
        return 0;
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
    printf("  | Unesite 0. za Exit:                                 |\n");
    printf("  *-----------------------------------------------------*\n\n");

    return;
}
void Meni2(){
    printf("\n  *-----------------------------------------------------*\n");
    printf("  | Unesite 3. za Logout:                               |\n");
    printf("  | Unesite 4. za Izmenu naloga:                        |\n");
    printf("  | Unesite 5. za Brisanje naloga:                      |\n");
    printf("  | Unesite 6. za Kreiranje Foldera:                    |\n");
    printf("  | Unesite 7. za Deljenje Foldera:                     |\n");
    printf("  | Unesite 8. za Izmenu Foldera:                       |\n");
    printf("  | Unesite 9. za Brisanje Foldera:                     |\n");
    printf("  | Unesite 10. za Pretragu fajlova i foldera           |\n");
    printf("  | Unesite 11. za Prikazivanje svih foldera korisnika: |\n");
    printf("  | Unesite 12. za Akcije u folderu:                    |\n");
    printf("  | Unesite 0. za Exit:                                 |\n");
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

        return 2;
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
    /*
    char dest[47] = "mkdir ";
    strcat(dest,acc.email);
    system(dest);
    */
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


char* GenerateLink(char* link){

    srand(time(NULL));
    int i;
    for(i=0;i<5;i++){
        link[i] = (rand() % 26) + 65;
    }
    link[5] = '\0';

    return link;
}

void KreirajFolder()
    {
        int i;
        FILE* dat = fopen("Dodavanje naloga.txt","r");
        if (dat == NULL){
            fclose(dat);
            printf("Greska pri otvaranju datoteke!!\n");
            return;
        }
    char s1[40];
    char s2[40];

    for(i=0;;i++){
        fscanf(dat,"%[^\n]s",s1);
        if (feof(dat))
        {
            break;
        }
        fgetc(dat);
        fscanf(dat,"%[^\n]s",s1);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",s2);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",s1);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",s1);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",s1);
        if (strcmp(s1,"Online") == 0)
        {
            break;
        }
        fgetc(dat);
    }


        char g_naziv[30];
        char g_kod[20] = "Folderi\\";

        printf("Unesite naziv foldera: \n");
        fflush(stdin);
        gets(g_naziv);
        fflush(stdin);
       char kod[6];
       GenerateLink(kod);
       strcat(g_kod,kod);
       strcat(g_kod,".txt");

        FILE* dat1 = fopen("kodovi.txt", "a+");
        if (dat1 == NULL){
            printf("GRESKA!!\n");
            fclose(dat);
            fclose(dat1);
            return;
        }
        fprintf(dat1,"%s\n",g_kod);
        FILE* dat2 = fopen(g_kod, "w+");
        if (dat1 == NULL){
            printf("GRESKA!!\n");
            fclose(dat);
            fclose(dat1);
            fclose(dat2);
            return;
        }

        fputs(g_naziv,dat2);
        fputc('\n',dat2);
        fputs(s2,dat2);
        fputc('\n',dat2);
        fputc('#',dat2);
        fputc('\n',dat2);
        fputc('!',dat2);
        fputc('\n',dat2);
        fputc('$',dat2);
        fputc('\n',dat2);



    fclose(dat);
    fclose(dat1);
    fclose(dat2);
    }

void SerovanjeFoldera(){


  FILE* dat3 = fopen("kodovi.txt" , "r+");
    FILE* dat2;
    int i;
        FILE* dat = fopen("Dodavanje naloga.txt","r+");
        if (dat == NULL){
            fclose(dat);
            printf("Greska pri otvaranju datoteke!!\n");
            return;
        }
    char ppom[40];

    char email_ulogovanog[40];

    for(i=0;;i++){
        fscanf(dat,"%[^\n]s",ppom);
        if (i % 6 == 2){
            strcpy(email_ulogovanog,ppom);
        }
        fgetc(dat);
        if(feof(dat)){
            printf("Morate se prvo loginovati !\n\n");
            fclose(dat);
            return;
        }
        if(strcmp("Online",ppom) == 0 && (i % 6) == 5){
            break;
        }
    }
    fclose(dat);
    char s1[6];
    char s2[100];
    int pom[100];
    char emai[50];
    strcpy(emai,email_ulogovanog);
    i=0;
    int n;
    n=0;
    int j;

    while(5){

        fscanf(dat3,"%[^\n]s",s1);
        fgetc(dat3);
        if(feof(dat3)){
                break;
            }
        dat2 = fopen(s1,"r");
        j=0;
        char poms[40];
        while(5){

            fscanf(dat2,"%[^\n]s",s2);
            fgetc(dat2);
            if(feof(dat2)){
                    break;
                }
            if (j==0){
                strcpy(poms,s2);
            }

            if (strcmp(s2,"!") == 0){
                break;
            }
            if (strcmp(s2,"$") == 0){
                break;
            }
            if (strcmp(s2,emai) == 0){
                pom[n] = i;
                n++;
                puts(poms);
                break;
            }
            j++;
        }
        fclose(dat2);


        i++;
    }
    if (n==0){
        printf("Niste admin/kreator nijedne grupe!!\n\n");
    }else{
        printf("Unesite broj foldera koju zelite da izmenite: ");
    }
int broj;
pon:
    scanf("%i",&broj);
    if (broj > n || broj < 1){
        printf("uneli ste neodgovarajuc folder\n\n");
        goto pon;
    }
    broj--;
   /// pom[broj] /// koji je po redu u kodovi.txt

   fseek(dat3,0,SEEK_SET);
   int x;
   char s3[100];
   char StringKodovi[100];
   for(x=0;;x++){
    fscanf(dat3,"%[^\n]s",s3);
    if(feof(dat3)){
        break;
    }
    fgetc(dat3);

    if(x == pom[broj]){
        strcpy(StringKodovi,s3);
        break;
    }

   }
   char email[50];
   PonoviEmail:
   printf("Unesite email kome serujete: ");
   fflush(stdin);
   gets(email);

   ///Provera mejla

   FILE* dat6;
   dat6 = fopen("Mejlovi.txt","r");
   if(dat6 == NULL){
    printf("Memory failed !!!\n\n");
    fclose(dat6);
    return;
   }
   int k,flag=0;
   char sss[100];
   for(k=0;;k++){
    fscanf(dat6,"%[^\n]s",sss);
    if(strcmp(sss,email) == 0){
            flag = 1;
            break;
    }
    fgetc(dat6);
    if(feof(dat6)){
        break;
    }

   }
   fclose(dat6);

   if(flag == 0){
    printf("Uneti email nepostoji !!! \n\n");
    goto PonoviEmail;
   }
   if(flag == 1){


   fclose(dat3);
   FILE* dat4;
   dat4 = fopen(StringKodovi,"r+");
   int a = 0;
   while(5){
    fscanf(dat4,"%[^\n]s",s3);
    if(feof(dat4)){
        break;
    }
    fgetc(dat4);
    if (strcmp(s3,"$") == 0){
                break;
            }
    if (strcmp(s3,email) == 0 && a != 0){
        printf("Vec serujete toj osobi");
        ///CLOSE dat... - VALJDA SVE CLOSOVANO
        return;
    }
    a++;
   }
   fseek(dat4,0,SEEK_SET);
   fseek(dat4,0,SEEK_CUR);
   FILE* dat5 = fopen("Folderi\\pom.txt" , "w+");
   fseek(dat5,0,SEEK_CUR);
   while(5){
    fscanf(dat4,"%[^\n]s",s3);
    if(feof(dat4)){
        break;
    }
    fgetc(dat4);
    fputs(s3,dat5);
    fputc('\n',dat5);
    if(strcmp(s3,"!") == 0){
        fputs(email,dat5);
    fputc('\n',dat5);
    }
   }
    fclose(dat4);
    fclose(dat5);
    remove(StringKodovi);
    rename("Folderi\\pom.txt" , StringKodovi);

   }
}


void IzmenaFoldera(){

    FILE* dat3 = fopen("kodovi.txt" , "r+");
    FILE* dat2;
    int i;
        FILE* dat = fopen("Dodavanje naloga.txt","r+");
        if (dat == NULL){
            fclose(dat);
            printf("Greska pri otvaranju datoteke!!\n");
            return;
        }
    char ppom[40];

    char email_ulogovanog[40];

    for(i=0;;i++){
        fscanf(dat,"%[^\n]s",ppom);
        if (i % 6 == 2){
            strcpy(email_ulogovanog,ppom);
        }
        fgetc(dat);
        if(feof(dat)){
            printf("Morate se prvo loginovati !\n\n");
            fclose(dat);
            return;
        }
        if(strcmp("Online",ppom) == 0 && (i % 6) == 5){
            break;
        }
    }
    fclose(dat);
    char s1[6];
    char s2[100];
    int pom[100];
    char emai[50];
    strcpy(emai,email_ulogovanog);
    i=0;
    int n;
    n=0;
    int j;

    while(5){

        fscanf(dat3,"%[^\n]s",s1);
        fgetc(dat3);
        if(feof(dat3)){
                break;
            }
        dat2 = fopen(s1,"r");
        j=0;
        char poms[40];
        while(5){

            fscanf(dat2,"%[^\n]s",s2);
            fgetc(dat2);
            if(feof(dat2)){
                    break;
                }
            if (j==0){
                strcpy(poms,s2);
            }

            if (strcmp(s2,"!") == 0){
                break;
            }
            if (strcmp(s2,"$") == 0){
                break;
            }
            if (strcmp(s2,emai) == 0){
                pom[n] = i;
                n++;
                puts(poms);
                break;
            }
            j++;
        }
        fclose(dat2);


        i++;
    }
    if (n==0){
        printf("Niste admin/kreator nijedne grupe!!\n\n");
    }else{
        printf("Unesite broj foldera koju zelite da izmenite: ");
    }
int broj;
pon:
    scanf("%i",&broj);
    if (broj > n || broj < 1){
        printf("uneli ste neodgovarajuc folder\n\n");
        goto pon;
    }
    broj--;
   /// pom[broj] /// koji je po redu u kodovi.txt

   fseek(dat3,0,SEEK_SET);
   int a;
   char NovoIme[40];
   char ss1[100];
   char ss2[100];
   char kodprvog[100];

   do{

    printf("Unesite 1. Za promenu naziva foldera !\n");
    printf("Unesite 2. Za kikovanje sa shera !\n");
    printf("Unesite 3. Za postavljanje za admina !\n");
    printf("Unesite 4. Za postavljanje admina u obicne clanove !\n");
    printf("Unesite 0. Za izlaz iz menija !\n");
    printf("Unesite broj za opciju iz menija: ");
    scanf("%i",&a);

    if(a < 0 || a > 4){
        printf("Uneliste neodgovarajuci broj !!!\n");
    }
for(i=0;;i++){
                fscanf(dat3,"%[^\n]s",ss1);
                fgetc(dat3);
                if(feof(dat3)){
                    break;
                }if(i == pom[broj]){
                    strcpy(kodprvog,ss1);
                    break;
                }
            }
    switch(a){

        case 1:
            printf("Unesite novo ime foldera: ");
            fflush(stdin);
            gets(NovoIme);
            fflush(stdin);

            FILE* datt2;
            datt2 = fopen(kodprvog,"r+");

            FILE* datt3;
            datt3 = fopen("Folderi\\pom.txt","w+");
            if(datt3 == NULL){
                printf("Memory failed !!!\n\n");
                fclose(datt2);
                fclose(datt3);
                return;
            }
            for(i=0;;i++){
                fscanf(datt2,"%[^\n]s",ss2);
                fgetc(datt2);

                if(i == 0){
                        fputs(NovoIme,datt3);
                fputc('\n',datt3);
                    continue;
                }
                if(feof(datt2)){
                    break;
                }
                fputs(ss2,datt3);
                fputc('\n',datt3);

            }

            fclose(datt2);
            fclose(datt3);
            remove(kodprvog);
            rename("Folderi\\pom.txt",kodprvog);

            break;
        case 3:{


            FILE* dpom;
            dpom = fopen(kodprvog,"r+");

            fseek(dpom,0,SEEK_SET);
            fscanf(dpom,"%[^\n]s",ss2);
            fgetc(dpom);
            fscanf(dpom,"%[^\n]s",ss2);
            fgetc(dpom);


           if (strcmp(ss2,emai) != 0){
            printf("Samo kreator moze dodati admina!!\n\n");
            fclose(dpom);
            fclose(dat3);
            return;
           }
            printf("Unesite email koga zelite da dodate za admina:\n");
            int pom2 = 0;
            char admin[40];
            fflush(stdin);
            gets(admin);
          fseek(dpom,0,SEEK_SET);
          int j=0;
            while(6){
               fscanf(dpom,"%[^\n]s",ss2);
                fgetc(dpom);
                if (feof(dpom)){
                        printf("Ta osoba nije u serovanom folderu!!\n\n");
                        fclose(dpom);
            fclose(dat3);
                    return;
                }
                if(strcmp(ss2 , "!")==0){
                    pom2 = 1;
                }
                if(strcmp(ss2 , "$")==0){
                    printf("Ta osoba nije u grupi!!\n\n");
                    fclose(dpom);
            fclose(dat);
            fclose(dat3);
                    return;
                }
                if (strcmp(ss2,admin) == 0 && j != 0 && pom2  == 0){
                    printf("Ta osoba je vec admin");
                    fclose(dpom);
            fclose(dat);
            fclose(dat3);
                    return;
                }
                if(strcmp(ss2,admin) == 0 && pom2 == 1){
                    break;
                }
                j++;
            }

            fseek(dpom,0,SEEK_SET);
            FILE* datt = fopen("Folderi\\pom.txt", "w+");
            fscanf(dpom,"%[^\n]s",ss2);
            fgetc(dpom);
            fputs(ss2,datt);
            fputc('\n',datt);
            fscanf(dpom,"%[^\n]s",ss2);
            fgetc(dpom);
            fputs(ss2,datt);
            fputc('\n',datt);
            fscanf(dpom,"%[^\n]s",ss2);
            fgetc(dpom);
            fputs(ss2,datt);
            fputc('\n',datt);
            fputs(admin,datt);
            fputc('\n',datt);
            while(5){
                    fscanf(dpom,"%[^\n]s",ss2);
                    fgetc(dpom);
                if (feof(dpom)){
                    break;
                }
                if(strcmp(ss2,admin)){
                fputs(ss2,datt);
                fputc('\n',datt);
                }

            }
            fclose(datt);
            fclose(dpom);
            remove(kodprvog);
            rename("Folderi\\pom.txt" , kodprvog);
            fclose(dat3);
        }
            break;
        case 2:
            /// Viticaste zagrade, zbog zabrane deklarisanja promenljivih u case:
            {

            FILE* dpom = fopen(kodprvog,"r");
            int c = 0;
            fscanf(dpom,"%[^\n]s",ss2);
            fgetc(dpom);
            fscanf(dpom,"%[^\n]s",ss2);
            fgetc(dpom);
            if(strcmp(emai,ss2) != 0){
                c = 2;
            }
            else
                c = 1;

            fseek(dpom,0,SEEK_SET);

            printf("Unesite email osobe koju zelite da kickujete : ");
            char emailV[40];
            fflush(stdin);
            gets(emailV);
            fflush(stdin);

            if(strcmp(emai,emailV) == 0){
                printf("Ne mozete kikovati sebe !!!\n\n");
                fclose(dpom);
                fclose(dat3);
                return;
            }
            if(strcmp(ss2,emailV) == 0){
                printf("Ne mozete kickati kreatora foldera !!!\n\n");
                fclose(dpom);
                fclose(dat3);
                return;
            }
            int pomocV = 0;
            int d = 0;
            while(5){

                fscanf(dpom,"%[^\n]s",ss2);
                fgetc(dpom);
                if(feof(dpom)){
                    printf("Email nije pronadjen !!!\n");
                    fclose(dpom);
                    fclose(dat3);
                    return;
                }
                if(strcmp(ss2,"!") == 0){
                    pomocV = 1;
                }
                if(strcmp(ss2,"$") == 0){
                    printf("Email nije pronadjen !!!\n");
                    fclose(dpom);
                    fclose(dat3);
                    return;
                }

                if(strcmp(ss2,emailV) == 0 && pomocV == 0 && c == 1){
                    printf("Ne mozete da kikate drugog admina !!!\n");
                    fclose(dpom);
                    fclose(dat3);
                    return;
                }

                if(strcmp(ss2,emailV) == 0 && d > 2){
                    break;
                }

                d++;
                }

                fseek(dpom,0,SEEK_SET);
                FILE* datCopy;
                datCopy = fopen("Folderi\\pomoc.txt","w+");

                fscanf(dpom,"%[^\n]s",ss2);
                fgetc(dpom);
                fputs(ss2,datCopy);
                fputc('\n',datCopy);
                fscanf(dpom,"%[^\n]s",ss2);
                fgetc(dpom);
                fputs(ss2,datCopy);
                fputc('\n',datCopy);

                for(;;){

                    fscanf(dpom,"%[^\n]s",ss2);
                    fgetc(dpom);
                    if(feof(dpom)){
                        break;
                    }
                    if(strcmp(ss2, emailV) == 0){
                        continue;
                    }
                    fputs(ss2,datCopy);
                    fputc('\n',datCopy);
                }

                fclose(datCopy);
                fclose(dpom);
                remove(kodprvog);
                rename("Folderi\\pomoc.txt",kodprvog);
                break;




            }
        case 4:

            {

            FILE* DatZamena;
            DatZamena = fopen(kodprvog,"r");
            fseek(DatZamena,0,SEEK_SET);

            fscanf(DatZamena,"%[^\n]s",ss2);
            fgetc(DatZamena);
            fscanf(DatZamena,"%[^\n]s",ss2);
            fgetc(DatZamena);

            if(strcmp(emai,ss2) != 0){
                printf("Vi niste kreator. Samo kreator ima ovu mugucnost !!!\n");
                fclose(DatZamena);
                fclose(dat3);
                return;
            }

            printf("Unesite email admina koga hocete da postavite u clana (da ne bude vise admin) : \n");
            char emailAdmina[40];
            int temp = 0;
            fflush(stdin);
            gets(emailAdmina);
            fflush(stdin);

            fseek(DatZamena,0,SEEK_SET);

            int p;

            for(p=0;;p++){

                fscanf(DatZamena,"%[^\n]s",ss2);
                fgetc(DatZamena);
                if(feof(DatZamena)){
                    printf("Email koji ste uneli se ne nalazi na listi (serovanih) !!! \n\n");
                    fclose(DatZamena);
                    fclose(dat3);
                    return;
                }
                if(strcmp(emailAdmina, ss2) != 0 && p != 0){
                    break;
                }
                if(strcmp(ss2,"!") == 0){
                    printf("Uneti email ne pripada adminu !!! \n\n");
                    fclose(DatZamena);
                    fclose(dat3);
                    return;
                }
            }

            fseek(DatZamena,0,SEEK_SET);

            FILE *datCopyV;
            datCopyV = fopen("Folderi\\novi.txt","w+");

            fscanf(DatZamena,"%[^\n]s",ss2);
            fgetc(DatZamena);
            fputs(ss2,datCopyV);
            fputc('\n',datCopyV);
            fscanf(DatZamena,"%[^\n]s",ss2);
            fgetc(DatZamena);
            fputs(ss2,datCopyV);
            fputc('\n',datCopyV);
            fscanf(DatZamena,"%[^\n]s",ss2);
            fgetc(DatZamena);
            fputs(ss2,datCopyV);
            fputc('\n',datCopyV);

            for(;;){
                fscanf(DatZamena,"%[^\n]s",ss2);
                fgetc(DatZamena);

                if(feof(DatZamena)){
                    break;
                }
                if(strcmp(emailAdmina,ss2) == 0){
                    temp = 1;
                    continue;
                }
                fputs(ss2,datCopyV);
                fputc('\n',datCopyV);

                if(strcmp(ss2, "!") == 0){
                    fputs(emailAdmina,datCopyV);
                    fputc('\n',datCopyV);
                    continue;
                }

            }

            fclose(datCopyV);
            fclose(DatZamena);
            remove(kodprvog);
            rename("Folderi\\novi.txt",kodprvog);

            break;

            }

    }

   }while(a != 0);

}


void BrisanjeFoldera(){

    FILE* dat;
    dat = fopen("Dodavanje naloga.txt","r");
    if(dat == NULL){
        printf("Memory failed !!!\n\n");
        fclose(dat);
        return;
    }
    FILE* datKodovi;
    datKodovi = fopen("kodovi.txt","r");

    int i;
    char s1[40];
    char s2[40];
    char email_ulogovanog[40];
    int flag2 = 0;
    int niz[100];

    ///Trazenje emaila ulogovanog korisnika

    for(i=0;;i++){
        fscanf(dat,"%[^\n]s",s1);
        if (i % 6 == 2){
            strcpy(email_ulogovanog,s1);
        }
        fgetc(dat);
        if(feof(dat)){
            printf("Morate se prvo loginovati !\n\n");
            fclose(dat);
            return;
        }
        if(strcmp("Online",s1) == 0 && (i % 6) == 5){
            break;
        }
    }
    fclose(dat);

    FILE* Folder;

    char kopijaEmailaUlogovanog[40];
    strcpy(kopijaEmailaUlogovanog,email_ulogovanog);

    int flag = 0;

    fseek(datKodovi,0,SEEK_SET);

    for(i=0;;i++){
        fscanf(datKodovi,"%[^\n]s",s1);
        fgetc(datKodovi);
        if(feof(datKodovi)){
            break;
        }
        Folder = fopen(s1,"r");
        flag = 0;


        char ps[40];

        for(;;flag++){

            fscanf(Folder,"%[^\n]s",s2);
            fgetc(Folder);
            if(feof(Folder)){
                break;
            }
            if(flag == 0){
                strcpy(ps,s2);
            }
            if(strcmp(s2,"#") == 0){
                break;
            }
            if(strcmp(s2,"!") == 0){
                break;
            }
            if(strcmp(s2,"$") == 0){
                break;
            }
            if(strcmp(s2,kopijaEmailaUlogovanog) == 0){
                niz[flag2] = i;
                flag2 ++;
                puts(ps);
                break;
            }
        }
        fclose(Folder);
    }

    if(flag2 == 0){
        printf("Vi niste kreator ove grupe !!!\n\n");
    }
    else{
        printf("Unesite broj foldera koji zelite da izbrisete: ");
    }

    int opcija;
    ponovo:
    scanf("%i",&opcija);
    if (opcija > flag2 || opcija < 1){
        printf("Uneli ste neodgovarajuc folder\n\n");
        goto ponovo;
    }
    opcija--;

    fseek(datKodovi,0,SEEK_SET);
    int x;
    char s3[100];
    char StringKodovi[100];
    for(x=0;;x++){
        fscanf(datKodovi,"%[^\n]s",s3);
        if(feof(datKodovi)){
            break;
        }
        fgetc(datKodovi);

        if(x == niz[opcija]){
            strcpy(StringKodovi,s3);
            break;
        }
    }



    FILE* datKodoviCopy;
    datKodoviCopy = fopen("kopija.txt","w+");

    fseek(datKodovi,0,SEEK_SET);

    for(i=0;;i++){
        fscanf(datKodovi,"%[^\n]s",s3);
        if(feof(datKodovi)){
            break;
        }
        fgetc(datKodovi);

        if(i == niz[opcija]){
            continue;
        }
        else{
            fprintf(datKodoviCopy,"%s",s3);
            fputc('\n',datKodoviCopy);
        }
    }

    remove(StringKodovi);

    fclose(datKodoviCopy);
    fclose(datKodovi);

    remove("kodovi.txt");
    rename("kopija.txt","kodovi.txt");

}

void PretragaPrikazFoldera(){

    FILE* dat;
    dat = fopen("Dodavanje naloga.txt","r");
    if(dat == NULL){
        printf("Memory failed !!!\n\n");
        fclose(dat);
        return;
    }
    FILE* datKodovi;
    datKodovi = fopen("kodovi.txt","r");

    int i;
    char s1[100];
    char s2[100];
    char email_ulogovanog[40];
    int flag2 = 0;
    int niz[100];
    int flag = 0;

    for(i=0;;i++){
        fscanf(dat,"%[^\n]s",s1);
        if (i % 6 == 2){
            strcpy(email_ulogovanog,s1);
        }
        fgetc(dat);
        if(feof(dat)){
            printf("Morate se prvo loginovati !\n\n");
            fclose(dat);
            return;
        }
        if(strcmp("Online",s1) == 0 && (i % 6) == 5){
            break;
        }
    }
    fclose(dat);

    FILE* Folder;

    char kopijaEmailaUlogovanog[40];
    strcpy(kopijaEmailaUlogovanog,email_ulogovanog);

    char ImeFoldera[40];

        printf("Unesite ime foldera: ");
        fflush(stdin);
        gets(ImeFoldera);
        fflush(stdin);
int pom =0;

    printf("Rezultat pretrage je : \n\n");

    for(i=0;;i++){
        fscanf(datKodovi,"%[^\n]s",s1);
        fgetc(datKodovi);
        if(feof(datKodovi)){
            break;
        }
        pom = 0;
        Folder = fopen(s1,"r+");

        flag = 0;

        char ps[40];

        for(;;flag++){

            fscanf(Folder,"%[^\n]s",s2);
            fgetc(Folder);
            if(feof(Folder)){
                break;
            }
            if(flag == 0){
                strcpy(ps,s2);
            }
            if(pom == 1 && strstr(s2,ImeFoldera) != NULL){

                puts(s2);


            }
            if(strcmp(s2,"$") == 0 && flag!= 0){
                pom = 1;
            }
            if(pom ==1 && flag2 == 0){
                break;
            }

            if(strcmp(s2,kopijaEmailaUlogovanog) == 0 && flag != 0){
                flag2 ++;
                if (strstr(ps,ImeFoldera) != NULL){
                puts(ps);
                }}
        }
        fclose(Folder);
    }
    printf("\n********\n");
    fclose(datKodovi);
}

void PrikaziSveFoldereKorisnika(){


    FILE* dat;
    dat = fopen("Dodavanje naloga.txt","r");
    if(dat == NULL){
        printf("Memory failed !!!\n\n");
        fclose(dat);
        return;
    }
    FILE* datKodovi;
    datKodovi = fopen("kodovi.txt","r");

    int i;
    char s1[100];
    char s2[100];
    char email_ulogovanog[40];
    int flag2 = 0;
    int niz[100];
    int flag = 0;

    for(i=0;;i++){
        fscanf(dat,"%[^\n]s",s1);
        if (i % 6 == 2){
            strcpy(email_ulogovanog,s1);
        }
        fgetc(dat);
        if(feof(dat)){
            printf("Morate se prvo loginovati !\n\n");
            fclose(dat);
            return;
        }
        if(strcmp("Online",s1) == 0 && (i % 6) == 5){
            break;
        }
    }
    fclose(dat);


    FILE* Folder;

    char kopijaEmailaUlogovanog[40];
    strcpy(kopijaEmailaUlogovanog,email_ulogovanog);

    printf("Folderi kojima imate pristup: \n");

    for(i=0;;i++){

        fscanf(datKodovi,"%[^\n]s",s1);
        fgetc(datKodovi);
        if(feof(datKodovi)){
            break;
        }
        Folder = fopen(s1,"r+");

        flag = 0;

        char ps[40];

        for(;;flag++){

            fscanf(Folder,"%[^\n]s",s2);
            fgetc(Folder);

            if(feof(Folder)){
                break;
            }
            if(flag == 0){
                strcpy(ps,s2);
            }
            if(strcmp(kopijaEmailaUlogovanog,s2) == 0 && flag != 0){
                puts(ps);
                printf("\n");
                break;
            }
        }
        fclose(Folder);
    }
    printf("****************\n");

    fclose(datKodovi);
}

void AkcijeFolderi(){

    FILE* dat;
    dat = fopen("Dodavanje naloga.txt","r");
    if(dat == NULL){
        printf("Memory failed !!!\n\n");
        fclose(dat);
        return;
    }
    FILE* datKodovi;
    datKodovi = fopen("kodovi.txt","r");

    int i = 0;
    char s1[100];
    char s2[100];
    char email_ulogovanog[40];
    int niz[100];

    for(i=0;;i++){
        fscanf(dat,"%[^\n]s",s1);
        if (i % 6 == 2){
            strcpy(email_ulogovanog,s1);
        }
        fgetc(dat);
        if(feof(dat)){
            printf("Morate se prvo loginovati !\n\n");
            fclose(dat);
            return;
        }
        if(strcmp("Online",s1) == 0 && (i % 6) == 5){
            break;
        }
    }
    fclose(dat);


    FILE* Folder;

    char kopijaEmailaUlogovanog[40];
    strcpy(kopijaEmailaUlogovanog,email_ulogovanog);

    char NazivPodFoldera[40];
    char Putanja[40];

    fseek(datKodovi,0,SEEK_SET);

         int n;
    n=0;
    int j;
    int pok[100];
    i=0;
    while(5){

        fscanf(datKodovi,"%[^\n]s",s1);
        fgetc(datKodovi);
        if(feof(datKodovi)){
                break;
            }
        Folder = fopen(s1,"r");
        j=0;
        char ps[40];
        while(5){

            fscanf(Folder,"%[^\n]s",s2);
            fgetc(Folder);
            if(feof(Folder)){
                    break;
                }
            if (j==0){
                strcpy(ps,s2);
            }

            if (strcmp(s2,"!") == 0){
                break;
            }
            if (strcmp(s2,"$") == 0){
                break;
            }
            if (strcmp(s2,kopijaEmailaUlogovanog) == 0){
                pok[n] = i;
                n++;
                puts(ps);
                break;
            }
            j++;
        }
        fclose(Folder);


        i++;
    }
    if (n==0){
        printf("Niste admin/kreator nijedne grupe!!\n\n");
    }else{
        printf("Unesite broj foldera za koji hocete da radite akcije: ");
    }
    int broj;
    pon:
    scanf("%i",&broj);
    if (broj > n || broj < 1){
        printf("Uneli ste neodgovarajuci folder\n\n");
        goto pon;
    }
    broj--;


    fseek(datKodovi,0,SEEK_SET);
//broj
    int slucaj;
    char kodpravog[100];
    char kod1[20] = "Folderi\\";

    for(i=0;;i++){
            fscanf(datKodovi,"%[^\n]s",s1);
            fgetc(datKodovi);
            if(feof(datKodovi)){
                break;
            }
            if(i == pok[broj]){
                strcpy(kodpravog,s1);
                break;
            }
        }

    fseek(datKodovi,0,SEEK_SET);
    fclose(datKodovi);

    printf("Unesite 1. za dodavanje podfoldera: \n");
    printf("Unesite 2. za dodavanje fajla: \n");
    printf("Unesite broj za opciju iz menija: ");
    fflush(stdin);
    scanf("%d",&slucaj);
    fflush(stdin);

    if(slucaj < 0 || slucaj > 2){
        printf("Uneli ste neodgovarajuci broj !!!\n\n");
    }

    switch(slucaj){

        case 1:

        printf("Unesite naziv podfoldera koji hocete da kreirate: ");
        fflush(stdin);
        gets(NazivPodFoldera);
        fflush(stdin);

        char kod2[6];
        GenerateLink(kod2);
        strcat(kod1,kod2);
        strcat(kod1,".txt");

        FILE* datt = fopen(kodpravog , "r");
        FILE* datt1 = fopen(kod1 , "w+");
        int pom = 0;
        while(5){
            fscanf(datt,"%[^\n]s",s1);
            fgetc(datt);
            if(feof(datt)){

                break;
            }

            if(pom == 0){
                    strcat(s1,"\\");
                    strcat(s1,NazivPodFoldera);
                fputs(s1,datt1);
                fputc('\n',datt1);
                pom++;
            continue;
            }
            fputs(s1,datt1);
            fputc('\n',datt1);
            if(strcmp(s1,"$") == 0){
                break;
            }



        }
         fclose(datt);
         fclose(datt1);
         datKodovi = fopen("kodovi.txt" , "a+");
         fputs(kod1,datKodovi);
         fputc('\n',datKodovi);
         fclose(datKodovi);
        break;

        case 2:{
            char fajl[50];
            printf("Unesite ime fajla: ");
            fflush(stdin);
            gets(fajl);
            FILE* datV;
            datV = fopen(kodpravog,"r+");

            FILE* datPom;
            datPom = fopen("Folderi\\Novi.txt","w+");
            if(datPom == NULL){

            }
            int pom = 0;
            while(5){

                fscanf(datV,"%[^\n]s",s1);
                fgetc(datV);
                if(feof(datV)){

                    break;
                }
                fputs(s1,datPom);
                fputc('\n',datPom);
                if(strcmp(s1,"$") == 0 && pom == 0){
                    fputs(fajl,datPom);
                    fputc('\n',datPom);
                    pom = 1;
                }
            }
            fclose(datV);
            fclose(datPom);
            remove(kodpravog);
            rename("Folderi\\Novi.txt",kodpravog);
        }
        break;

    }



}
