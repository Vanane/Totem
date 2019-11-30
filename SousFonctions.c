//*********************************************
//         Prototypes des fonctions
//*********************************************


//************************************
//        Fonction SaisirEntre
//************************************

int SaisirEntre(int min, int max)
{
    int saisi;
 printf("Veuillez saisir un entier compris entre %d et %d :\n",min,max);
 scanf("%d",&saisi);

 while (saisi<min || saisi>max)
 {
  printf("Vous n'avez pas saisi un entier compris entre %d et %d, nouvelle saisie :\n",min,max);
  scanf("%d",&saisi);
 }
 return saisi;
}

bool SaisirReponse(char message[128])
{
    char c;
    do
    {
        if(c !='o' && c != 'n' && c != '\n')
            printf("%s\n", message);
        scanf("%c", &c);
    }while(c !='o' && c != 'n');
    return c =='o' ? true : false;
}

