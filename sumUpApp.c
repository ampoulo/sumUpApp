// Mouhamadou Ousmane Mbaye.(amadou mbow).77 818 66 42.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
typedef struct
{
    int numero;
    int quantite;
    int Apayer;
    char profil[10];
} Facture;
void color(int col)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,(WORD)col);
}

void gotoxy(int i, int j)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c;

    c.X=i;
    c.Y=j;
    SetConsoleCursorPosition(h,c);
}
// pocede po cad
void cadre()
{
    int i,j,n=68;
    color(3);
    printf("\t\t\t\t\t\t _________________________");
    printf("\n\t\t\t\t\t\t | ");
    color(15);
    printf("SUM UP APP Version 1.0");
    color(3);
    printf("|\n");
    for(i=0; i<n/2-2; i++)
    {
        for(j=0; j<2*n; j++)
        {
            if(i==0 && j<=2*n && j>2 || i!=n-1 && j==2*n/3 || i!=n-1 && j==4*n/3 || j==2 || i==n/2-3 && j<=2*n && j>2  || i!=n-1 && j==2*n-1 || i==3 && j<=2*n && j>2)
                printf("²");
            else
                printf(" ");
        }
        printf("\n");

    }
    printf("\n");
    color(15);
    gotoxy(15,4);
    printf(" OPTION");
    gotoxy(59,4);
    printf("GUIDE");
    gotoxy(97,4);
    printf(" RESULTAT(S) ");
    color(3);
    gotoxy(1,1);
}

// 1-Fonction qui calcul le produit de deux entiers pris en argument.
int prod(int a,int b)
{
    return (a*b);
}
// 11-effacer
void efface()
{
    printf("                ");
}
// 11-effacer
void effaced()
{

    int i,j;
    for(i=7;i<19;i++)
    {
            gotoxy(94,i);
            printf("                                         ");
    }
}
void effacem()
{

    int m,j;
    for(m=9;m<17;m++)
    {
        gotoxy(47,m);
            printf("                                          ");
    }
}
// 2-procedure d'enregistrement de l'ensemble des factures.
void enregistrer(Facture *f,int n)
{
    int i,j,k,control_de_saisi;
    gotoxy(94,7);
    printf("Nombre de facture :");
    do
        {
            gotoxy(114,7);
            printf("                   ");gotoxy(114,7);
            control_de_saisi = scanf("%d", &n);
            scanf("%*[^\n]");
            if(control_de_saisi !=1 || n <= 0 )
            {
                gotoxy(114,7);
                printf("               ");gotoxy(114,7);
                MessageBox(NULL,TEXT("SAISIE  INCORRECTE\n\nVOUS DEVEZ SAISIR DES CHIFFRES"),TEXT("ERREUR"),MB_ICONWARNING);
            }
        }
        while( control_de_saisi !=1 || n<= 0 );
    //scanf("%d",&n);gotoxy(94,7);effaced();
    for(i=0; i<n; i++)
    {
        gotoxy(94,7);
        efface();
        gotoxy(105,7);
        printf("FACTURE %d\n",i+1);
        gotoxy(94,9);printf("numero : \n");
        gotoxy(94,10);printf("Quantite :");
        do
        {
            gotoxy(114,7);
            printf("               ");gotoxy(114,7);
            gotoxy(105,10);
            printf("            ");gotoxy(105,10);
            gotoxy(103,9);
            printf("               ");gotoxy(103,9);
            control_de_saisi = scanf("%d", &f[i].numero);
            scanf("%*[^\n]");
            if(control_de_saisi !=1 || f[i].numero <= 0 )
            {
                gotoxy(103,9);
                printf("               ");gotoxy(103,9);
                MessageBox(NULL,TEXT("SAISIE  INCORRECTE\n\nVOUS DEVEZ SAISIR DES CHIFFRES"),TEXT("ERREUR"),MB_ICONWARNING);
            }
        }
        while( control_de_saisi !=1 || f[i].numero<= 0 );
        for(j=0; j<i; j++)
        {
            if(f[i].numero==f[j].numero)
            {
                gotoxy(103,11);
                printf("ce numero existe deja\n");gotoxy(93,12);
                system("pause");gotoxy(103,11);efface();efface();
                gotoxy(93,12);efface();efface();
                i--;
                goto am;
            }
        }

        do
        {
            gotoxy(105,10);
            printf("            ");gotoxy(105,10);
            control_de_saisi = scanf("%d", &f[i].quantite);
            scanf("%*[^\n]");
            if(control_de_saisi !=1 || f[i].quantite <= 0 )
            {
                gotoxy(105,10);
                printf("            ");gotoxy(105,10);
                MessageBox(NULL,TEXT("SAISIE  INCORRECTE\n\nVOUS DEVEZ SAISIR DES CHIFFRES"),TEXT("ERREUR"),MB_ICONWARNING);
            }
        }
        while( control_de_saisi !=1 || f[i].quantite<= 0 );
        if(f[i].quantite>50)
        {
            strcpy(f[i].profil,"PREMIUM");
            f[i].Apayer=(2500*f[i].quantite)-(0.05*2500*f[i].quantite);
        }
        else
            strcpy(f[i].profil,"GOLDEN");
        f[i].Apayer=2500*f[i].quantite;

am:;

    }
    effaced();
    gotoxy(48,14);menu:effacem();effaced();
    gotoxy(48,14);
    printf("Faites un autre choix :");
    do
        {
            gotoxy(72,14);
            control_de_saisi = scanf("%d", &k);
            scanf("%*[^\n]");
            if(control_de_saisi !=1 || k <= 0 )
            {
                gotoxy(72,14);
                printf("           ");
                MessageBox(NULL,TEXT("SAISIE  INCORRECTE\n\nVOUS DEVEZ SAISIR DES CHIFFRES"),TEXT("ERREUR"),MB_ICONWARNING);
            }
        }
        while( control_de_saisi !=1 || k<= 0 );
    gotoxy(48,13);
    effacem();

    switch(k)
    {
        case 1: gotoxy(48,14);printf("Donnees deja enregistrer!!");
                gotoxy(48,15);system("pause");effacem();
                goto menu;
        case 2: gotoxy(48,14);printf("Liste de Facture des clients :");gotoxy(110,7);affichage(f,k,0);
                goto menu;
        case 3: gotoxy(48,14);printf("Comparaison les profil");comparerSomProfil(f,k);
                goto menu;
        system("pause");goto menu;
        case 4:gotoxy(94,14);printf("Montant total amasse :%d",MontantTotal(f,n));
        gotoxy(94,18);system("pause");goto menu;
        case 5: goto menu;
        case 6: main();
    }

}
// 3-Fonction qui Calcul du montant total amasse par l'entreprise.
int MontantTotal(Facture *f,int n)
{
    int i,somTotal=0;

    for(i=0; i<n; i++)
        somTotal+=f[i].Apayer;

    return somTotal;
}
// 4-Fonction qui retourne 1 si profil du client est PREMIUM 0 sinon.
int profil(Facture *f,int i)
{
    if(!strcasecmp(f[i].profil,"PREMIUM"))
        return 1;
    return 0;
}
// 5-Fonction qui compare la somme gagné en pourcentage par le profil PREMIUM et GOLDEN.
void comparerSomProfil(Facture *f,int n)
{
    int i,somPRM=0,somGLD=0;
    float t,l;
    for(i=0; i<n; i++)
    {
        if(profil(f,i)==1)
            somPRM+=f[i].Apayer;
        else
            somGLD+=f[i].Apayer;
    }
    t=(float)somGLD/MontantTotal(f,n)*100;
    if(t>50)
    {
        gotoxy(94,12);
        printf("Montant GOLDEN (%.2f %) est superieur",t);
        gotoxy(94,15);
        printf("au montant PREMUIM (%.2f %)",100-t);
    }
    else
    {
        gotoxy(94,12);
        printf("Montant GOLDEN(%.2f%) est inferieur",t);
        gotoxy(94,13);
        printf("au montant PREMUIM(%.2f%)",100-t);
    }
    gotoxy(94,18);
    system("pause");
}
// 6-Procedure qui permute deux clients.
void permuter(Facture *f,int a,int b)
{
    Facture x=f[a];
    f[a]=f[b];
    f[b]=x;
}
// 7-Le tri des clients par ordre croisssant du montant total a payer.
void tri(Facture *f,int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=i; j<n; j++)
            if(f[i].Apayer>f[j].Apayer)
                permuter(f,i,j);
    }
}
// 8-affichage simple des clients
void affichage(Facture *f,int n,int i)
{
    if (i==n-1)
    {
        effaced();
        gotoxy(94,7);
        printf("numero: %d",f[i].numero);
        gotoxy(94,9);
        printf("A payer: %d",f[i].Apayer);
        gotoxy(94,11);
        printf("profil: %s\n",f[i].profil);
        gotoxy(94,15);
        printf("pour voir le suivant");
        gotoxy(94,16);
        system("pause");
    }
    else
    {
        effaced();
        gotoxy(94,7);
        printf("numero: %d",f[i].numero);
        gotoxy(94,9);
        printf("A payer: %d",f[i].Apayer);
        gotoxy(94,11);
        printf("profil: %s\n",f[i].profil);
        gotoxy(94,16);
        system("pause");
        i++;
        affichage(f,n,i);
    }
}
/*Partie MOT DE PASSE */
void mot_p()
{
    system("cls");
    color(3);
    printf("\t\t\t\t\t\t _________________________");
    printf("\n\t\t\t\t\t\t | ");
    color(15);
    printf("SUM UP APP Version 1.0");
    color(3);
    printf("|\n");
    int choix;
    gotoxy(5,3);color(15);
	puts("Veillez saisir le mot de passe pour continuer.");
	gotoxy(4,5);
    puts("mot de passe : ");

    gotoxy(18,5);
    mot_de_passe();
}
void mot_de_passe()
{
    int i,t;
    char passe[100],c;
    char bonpasse[]="cossam";
    do{
        i=0;
        do
        {
            c=getch();
            if (c=='\b')
            {
                if (i>0)
                {
                    putchar('\b');
                    putchar(' ');
                    putchar('\b');
                    i--;
                }
            }
            else if (c=='\r');
            else
            {
                passe[i]=c;
                i++;

                putchar('*');
            }
        }
        while (c!='\r');
        passe[i]='\0';
        if (strcmp(passe,bonpasse)==0)
        {
            t=0;
        }
        else
        {
            gotoxy(17,7);
            puts("Mot de passe incorrect veuillez reessayer!!");
            gotoxy(17,8);
            system("pause");
            passe[0]='\0';
            system("cls");
                mot_p();

        }
     }while(t!=0);

system("cls");
menu();
}
// 9-Fonction retournant le client ayant achete plus d'article.
int achatplus(Facture *f,int n)
{
    tri(f,n);
    return (f[n-1].numero);
}
// 10-Procedure d'affichage recursive de la liste de tous les clients.
// le choix des cas.
void switche(int n,Facture *f,int k)
{

}
void menu()
{
    system("color f");

    Facture *f;
    int n,i,k,control_de_saisi;
    f=(Facture*)malloc(n*sizeof(Facture));
    //gotoxy(66,6);
    //printf("client(s) :%d",n);
    cadre();
    gotoxy(47,10);
    color(15);
    printf("NB:(veuiller d'abord enregistrer les ");
    gotoxy(47,11);
    printf("clients pour acceder aux autres options)");
    gotoxy(48,7);
    printf("Veillez choisir un numero correspondant");
    gotoxy(48,8);
    printf("a votre choix a gauche de l'ecran.");
    gotoxy(3,7);
    printf("1.Enregistrement.");
    gotoxy(3,8);
    printf("2.Lister tous les clients.");
    gotoxy(3,9);
    printf("3.Comparaison entre Golden et Premium .");
    gotoxy(3,10);
    printf("4.Montant totale amassee par l'entreprise.");
    gotoxy(3,11);
    printf("6.Quitter.");
    menu:
    gotoxy(48,16);
    printf("Faites votre choix :");
    do
        {
            gotoxy(68,16);
            control_de_saisi = scanf("%d", &k);
            scanf("%*[^\n]");gotoxy(68,16);
            if(control_de_saisi !=1 || k <= 0 )
            {
                gotoxy(68,16);

                MessageBox(NULL,TEXT("SAISIE  INCORRECTE\n\nVOUS DEVEZ SAISIR DES CHIFFRES"),TEXT("ERREUR"),MB_ICONWARNING);printf("           ");gotoxy(68,16);
            }
        }
    while( control_de_saisi !=1 || k<= 0 );
        if(k != 1 && k!=6 )
            {
                effacem();
                MessageBox(NULL,TEXT("IL FAUT ENREGISTRER D'ABORD"),TEXT("ERREUR"),MB_ICONWARNING);goto menu;
            }
        gotoxy(48,16);efface();efface();
        gotoxy(48,14);
        printf("Choix : %d",k);

    switch(k)
    {
        case 1:enregistrer(f,k);gotoxy(55,13);
        printf("Faites votre choix :");break;
        case 6:break;
    }
}
// 10-Teste dans le programme principal.
int main()
{
    mot_p();
    system("pause");

return 0;
}

