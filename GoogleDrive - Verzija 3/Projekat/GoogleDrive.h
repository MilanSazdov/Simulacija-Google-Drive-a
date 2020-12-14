#ifndef GOOGLEDRIVE_H_INCLUDED
#define GOOGLEDRIVE_H_INCLUDED

typedef struct{

    char ime[20];
    char prezime[20];
    char email[40];
    char nickname[20];
    char password[20];

}Nalog;
int provera();
void Meni1();
void Meni2();
int Mail(char* niz);
int DodavanjeNaloga();
void Overflow(int n,FILE* dat);
void OverflowV2(int n,FILE* dat);
void OverflowV3(int n,FILE* dat,char* a);
void OverflowV4(int n,char* a);
void OverflowV5(int n,FILE* dat);
void OverflowV6(int n);

int Login();
void Logout();
void DeleteAndRewrite(int AccNumber);
void IzmenaNaloga();
void BrisanjeAcc();
char* GenerateLink(char* link);
void KreirajFolder();
void SerovanjeFoldera();
void IzmenaFoldera();
void BrisanjeFoldera();
void PretragaPrikazFoldera();
void PrikaziSveFoldereKorisnika();


#endif // GOOGLEDRIVE_H_INCLUDED
