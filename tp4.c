//
// Created by 陈扬珍 on 2020/11/24.
//
#include "tp4.h"

struct t_listePositions *creer_liste_positions() {
    struct t_listePositions *l;
    l = malloc(sizeof(t_ListePositions));
    if (l != NULL) {
        l->debut = NULL;
        l->nb_elements = 0;
        return l;
    } else return NULL;
}

int ajouter_position(t_ListePositions *listeP, int ligne, int ordre,
                     int num_phrase) {
    listeP->nb_elements++;
    t_Position *new;
    new = malloc(sizeof(t_Position));
    new->numero_ligne = ligne;
    new->ordre = ordre;
    new->numero_phrase = num_phrase;
    new->suivant = NULL;
    t_Position *P = listeP->debut;
    t_Position *P_pre;
    if (P == NULL) {
        listeP->debut = new;
        return 1;
    }
    while (P != NULL && P->numero_ligne<ligne) {
        P_pre = P;
        P = P->suivant;
    }
    if (P==NULL){
        P_pre->suivant = new;
        return 1;
    }
    else if (P->numero_ligne==ligne){
        while ( P!=NULL && P->ordre<ordre){
            P_pre=P;
            P=P->suivant;
        }
        if (P!=NULL && P->ordre==ordre) return 0;
        else{
            P_pre->suivant = new;
            return 1;
        }
    } else{
        P_pre->suivant = new;
        return 1;
    }
}

t_Index *creer_index() {
    t_Index *new = malloc(sizeof(t_Index));
    if (new != NULL) {
        new->racine = NULL;
        new->nb_mots_differents = 0;
        new->nb_mots_total = 0;
        new->listephrase= malloc(300 * sizeof(char *));
        /*for (int i = 0; i < 100; i++) {
            new->listephrase[i] = malloc(300 * sizeof(char));
        }*/
        return new;
    } else return NULL;
}

char *tranfertomini(char *mot) {
    char temp[100];
    strcpy(temp, mot);
    char *temp_p = temp;
    while ((*temp_p) != '\0') {
        if ('A' <= (*temp_p) && (*temp_p) <= 'Z') *temp_p = (*temp_p) + ('a' - 'A');
        temp_p = temp_p + 1;
    }
    return temp;
}

char *tranfertomaju(char *mot) {
    char temp[100];
    strcpy(temp, mot);
    char *temp_p = temp;
    while ((*temp_p) != '\0') {
        if ('a' <= (*temp_p) && (*temp_p) <= 'z') *temp_p = (*temp_p) - ('a' - 'A');
        temp_p = temp_p + 1;
    }
    return temp;
}

t_Noeud *rechercher_mot(t_Index *index, char *mot) {
    t_Noeud *n = index->racine;
    if (n == NULL) {
        return n;
    }

    char mot_mini[100];
    strcpy(mot_mini, tranfertomini(mot));


    char MotdeArbre_mini[100];
    strcpy(MotdeArbre_mini, tranfertomini(n->mot));

    if (strcmp(mot_mini, MotdeArbre_mini) == 0) return index->racine;
    while (strcmp(mot_mini, MotdeArbre_mini) != 0 && n != NULL) {
        if (strcmp(mot_mini, MotdeArbre_mini) < 0) {
            n = n->filsGauche;
        } else {
            n = n->filsDroit;
        }
        if (n != NULL) strcpy(MotdeArbre_mini, tranfertomini(n->mot));
    }
    return n;
}

int ajouter_nouvel_noeud(t_Index *index, t_Noeud *noeud) {
    t_Noeud *n = index->racine;
    t_Noeud *p;
    char mot_mini[100];
    strcpy(mot_mini, tranfertomini(noeud->mot));
    if (n == NULL) {//树为空
        index->racine = noeud;
        return 1;
    }
    char MotdeArbre_mini[100];
    strcpy(MotdeArbre_mini, tranfertomini(n->mot));

    while (n != NULL) {
        p = n;
        if (strcmp(mot_mini, MotdeArbre_mini) < 0) {
            n = n->filsGauche;
        } else {
            n = n->filsDroit;
        }
        if (n != NULL) strcpy(MotdeArbre_mini, tranfertomini(n->mot));
    }
    char MotdeP_mini[100];
    strcpy(MotdeP_mini, tranfertomini(p->mot));
    if (strcmp(mot_mini, MotdeP_mini) < 0) {
        p->filsGauche = noeud;
        return 1;
    } else {
        p->filsDroit = noeud;
        return 1;
    }
}

int ajouter_existe_noeud(struct t_index *index, struct t_noeud *noeud_existe, int n_ligne, int or, int n_pharse) {
    noeud_existe->nb_occurences++;
    ajouter_position(noeud_existe->positions, n_ligne, or, n_pharse);
    return 1;
}

struct t_noeud *creer_noeud(char *word, int numero_ligne, int ordre, int numero_pharse) {
    t_Noeud *noeud_new = malloc(sizeof(t_Noeud));
    noeud_new->mot = malloc(30 * sizeof(char));
    noeud_new->positions = creer_liste_positions();
    strcpy(noeud_new->mot, word);
    noeud_new->nb_occurences = 1;
    noeud_new->filsDroit = NULL;
    noeud_new->filsGauche = NULL;
    int a = ajouter_position(noeud_new->positions, numero_ligne, ordre, numero_pharse);
    if (a == 1) {
        return noeud_new;
    } else {
        return NULL;
    }
}

t_Index *indexer_fichier(char *filename) {
    FILE *fp = fopen(filename, "r");//假设该处文件是必定存在的
    t_Index *arb = creer_index();
    int num_phrase = 1;
    int nb_word_total = 0;
    int nb_word_diff = 0;
    char ch;
    char word[30];
    int len = 0;
    int ligne = 1;
    int ordre = 1;
    arb->listephrase[1]=malloc(300*sizeof(char));
    while ((ch = fgetc(fp)) != EOF) {
        len = 0;
        while (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
            word[len++] = ch;
            ch = fgetc(fp);
        }
        if (len != 0) {
            word[len] = '\0';
            t_Noeud *mot_e = rechercher_mot(arb, word);
            if (mot_e == NULL) {
                struct t_noeud *n_new = creer_noeud(word, ligne, ordre, num_phrase);
                ajouter_nouvel_noeud(arb, n_new);
                nb_word_total++;
                nb_word_diff++;
            } else {
                ajouter_existe_noeud(arb, mot_e, ligne, ordre, num_phrase);
                nb_word_total++;
            }
            arb->listephrase[num_phrase] = strcat(arb->listephrase[num_phrase], word);
            ordre++;
        }
        if (ch == '\n') {
            ligne++;
            ordre = 1;
        }
        if (ch == '.') {
            arb->listephrase[num_phrase] = strcat(arb->listephrase[num_phrase], ".");
            num_phrase++;
            arb->listephrase[num_phrase] = malloc(300 * sizeof(char));
        } else if (ch == ',') {
            arb->listephrase[num_phrase] = strcat(arb->listephrase[num_phrase], ",");
        } else {
            arb->listephrase[num_phrase] = strcat(arb->listephrase[num_phrase], " ");
        }
    }
    fclose(fp);
    arb->nb_mots_total = nb_word_total;
    arb->nb_mots_differents = nb_word_diff;
    return arb;
}


struct t_noeud *pere(t_Index *i, t_Noeud *noeud) {
    t_Noeud *n = i->racine;
    t_Noeud *p;
    char mot_mini[100];
    strcpy(mot_mini, tranfertomini(noeud->mot));

    char MotdeArbre_mini[100];
    strcpy(MotdeArbre_mini, tranfertomini(n->mot));

    if (strcmp(mot_mini, MotdeArbre_mini) == 0) {
        return NULL;
    }
    while (strcmp(mot_mini, MotdeArbre_mini) != 0 && n != NULL) {
        if (strcmp(mot_mini, MotdeArbre_mini) < 0) {
            p = n;
            n = n->filsGauche;
        } else {
            p = n;
            n = n->filsDroit;
        }
        if (n != NULL) strcpy(MotdeArbre_mini, tranfertomini(n->mot));
    }
    return p;

}


struct t_noeud *successeur(t_Index *i, t_Noeud *noeud) {
    t_Noeud *noeud_s;
    if (noeud->filsDroit != NULL) {
        noeud_s = noeud->filsDroit;
        while (noeud_s->filsGauche != NULL) {
            noeud_s = noeud_s->filsGauche;
        }
    } else {
        noeud_s = pere(i, noeud);
        while (noeud_s != NULL && noeud == noeud_s->filsDroit) {
            noeud = noeud_s;
            noeud_s = pere(i, noeud);
        }
    }
    if (noeud_s == NULL) {
        return NULL;
    }
    return noeud_s;
}

struct t_noeud *predecesseur(t_Index *i, t_Noeud *noeud) {
    t_Noeud *noeud_p;
    if (noeud->filsGauche != NULL) {
        noeud_p = noeud->filsGauche;
        while (noeud_p->filsDroit != NULL) {
            noeud_p = noeud_p->filsDroit;
        }
    } else {
        noeud_p = pere(i, noeud);
        while (noeud_p != NULL && noeud == noeud_p->filsGauche) {
            noeud = noeud_p;
            noeud_p = pere(i, noeud);
        }
    }
    return noeud_p;
}


void afficher_index(t_Index *index) {
    struct t_noeud *n = index->racine;
    while (n->filsGauche != NULL) {
        n = n->filsGauche;
    }
    t_Noeud *n_s = successeur(index, n);
    while (n != NULL) {
        t_Noeud *n_p = predecesseur(index, n);
        if (n_p == NULL) printf("%C\n", tranfertomaju(n->mot)[0]);
        if (n_p != NULL && (tranfertomaju(n_p->mot)[0]) != (tranfertomaju(n->mot)[0]))
            printf("\n%C\n", tranfertomaju(n->mot)[0]);
        printf("|--%s\n", n->mot);
        t_Position *position = n->positions->debut;
        while (position != NULL) {
            printf("|----(l:%d, o:%d, p:%d)\n", position->numero_ligne, position->ordre, position->numero_phrase);
            position = position->suivant;
        }
        printf("|\n");
        n = n_s;
        if (n_s != NULL) n_s = successeur(index, n_s);
    }
}

void afficher_occurences_mot(t_Index *index, char *mot) {
    t_Noeud *n_cherche = rechercher_mot(index, mot);
    if (n_cherche == NULL) {
        printf("ce mot n'existe pas\n");
        return;
    } else {
        printf("Mot = %s\n", mot);
        printf("Occurences = %d\n", n_cherche->nb_occurences);
        printf("les pharses:\n");
        t_Position *p = n_cherche->positions->debut;
        while (p != NULL) {
            printf("| %s \n",
                   index->listephrase[p->numero_phrase]);
            p = p->suivant;
        }
    }
}

void afficher_mot(t_Index *index, char *mot) {
    t_Noeud *n_cherche = rechercher_mot(index, mot);
    if (n_cherche == NULL) {
        printf("ce mot n'existe pas\n");
        return;
    } else {
        printf("Mot = %s\n", mot);
        printf("Occurences = %d\n", n_cherche->nb_occurences);
        t_Position *p = n_cherche->positions->debut;
        while (p != NULL) {
            printf("| Ligne %d, mot %d, numero de phrase :%d \n", p->numero_ligne, p->ordre, p->numero_phrase);
            p = p->suivant;
        }
    }
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int hauteur(t_Noeud *noeud) {
    if (noeud == NULL) return -1;
    else return (1 + max(hauteur(noeud->filsGauche), hauteur(noeud->filsDroit)));
}

int equilibre(t_Noeud *noeud) {
    if (noeud == NULL) return 0;
    return (hauteur(noeud->filsGauche) - hauteur(noeud->filsDroit));
}

int est_ce_que_cest_equilibre(t_Index *index) {//if equilibre return 1 sinon return 0
    t_Noeud *noeud = index->racine;
    while (noeud->filsGauche!=NULL){
        noeud=noeud->filsGauche;
    }
    while (abs(equilibre(noeud)) < 2 && noeud != NULL) {
        noeud = successeur(index, noeud);
    }
    if (abs(equilibre(noeud)) >= 2) return 0;
    if (noeud==NULL) return 1;
}

t_Noeud *numeroter_noeud(t_Index *index, t_Noeud *liste_noeud) {
    t_Noeud *noeud = index->racine;
    while (noeud->filsGauche != NULL) {
        noeud = noeud->filsGauche;
    }
    int i = 0;
    while (noeud != NULL) {
        liste_noeud[i].mot = malloc(30 * sizeof(char));
        strcpy(liste_noeud[i].mot, noeud->mot);
        liste_noeud[i].positions=creer_liste_positions();
        t_Position *position=noeud->positions->debut;
        while (position!=NULL){
            ajouter_position(liste_noeud[i].positions,position->numero_ligne,position->ordre,position->numero_phrase);
            position=position->suivant;
        }
        liste_noeud[i].nb_occurences = noeud->nb_occurences;
        i++;
        noeud = successeur(index, noeud);
    }
    for (int j = 0; j < index->nb_mots_differents; j++) {
        liste_noeud[j].filsDroit = NULL;
        liste_noeud[j].filsGauche = NULL;
    }
    return liste_noeud;
}

void affcter_fils(int g, int d, t_Noeud *liste_noeud) {
    if (g + 1 < d ) {
        int m = (g + d) / 2;
        t_Noeud *temp = &(liste_noeud[m]);
        if(m==1) temp->filsGauche=&(liste_noeud[0]);
        if (((g + m) /2) != m && (g+m)/2!=g ) temp->filsGauche = &(liste_noeud[(g + m) / 2]);
        if (((d + m) /2) != m && ((d + m) /2) != d) temp->filsDroit = &(liste_noeud[(m + d) / 2]);
        if (((g + m) /2) != m )affcter_fils(g, m, liste_noeud);
        if (((d + m) /2) != m && ((d + m) /2) != d)affcter_fils(m, d, liste_noeud);
    } else return;
}


t_Index *equilibrer_index(t_Index *index, t_Noeud *liste_noeud) {
    int valeur = est_ce_que_cest_equilibre(index);
    if (valeur == 1) {
        printf("index est déja équilibré\n");
        free(liste_noeud);
        return index;

    }

    numeroter_noeud(index, liste_noeud);
    t_Index *index_new = malloc(sizeof(t_Index));
    index_new->nb_mots_differents = index->nb_mots_differents;
    index_new->nb_mots_total = index->nb_mots_total;
    index_new->listephrase = index->listephrase;
    index_new->racine = &(liste_noeud[(0 + index_new->nb_mots_differents) / 2]);
    affcter_fils(0, index_new->nb_mots_differents, liste_noeud);

//    for (int i = 0; i < index->nb_mots_differents; i++) {
//        printf("%s,%d\n",liste_noeud[i].mot,i);
//        if (liste_noeud[i].filsGauche!=NULL)printf("fils gauche: %s\n",liste_noeud[i].filsGauche->mot);
//        else printf("pas de fils gauche\n");
//        if (liste_noeud[i].filsDroit!=NULL)printf("fils droite: %s\n",liste_noeud[i].filsDroit->mot);
//        else printf("pas de fils droite\n");
//    }

    t_Noeud *temp = index->racine;
    free_index(temp);
    printf("réussie d'équilibrer\n");
    return index_new;

}

void free_index(t_Noeud *noeud) {
    if (noeud != NULL) {
        free_index(noeud->filsGauche);
        free_index(noeud->filsDroit);
        librer_listeposition(noeud);
        free(noeud->mot);
        free(noeud);
    } else return;
}

void librer_listeposition(t_Noeud *noeud) {
    char mot[30];
    strcpy(mot,noeud->mot);
    t_Position *p = noeud->positions->debut;
    while (p != NULL) {
        free(p);
        p = p->suivant;
    }
}

void librer_listephrase(t_Index *index){
    for (int i = 0; i < 100; i++) {
        free(index->listephrase[i]);
    }
    free(index->listephrase);
}

void menuprincipal() {
    int a = 0;
    static t_Index *index = NULL;
    t_Noeud listenoeud[100];
    do {
        printf("1. Charger un fichier:\n"
               "2. Caractéristiques de l'index :\n"
               "3. Afficher index :\n"
               "4. Rechercher un mot :\n"
               "5. Afficher les occurrences d’un mot :\n"
               "6. Equilibrer l’index\n"
               "7. Quitter\n"
        );
        printf("Veuillez sasir votre choix\n");
        printf("===========================\n");
        scanf("%d", &a);
        while (!(a > 0 && a < 8)) {
            printf("entrée fausse\n");
            printf("Veuillez sasir votre choix\n");
            fflush(stdin);
            scanf("%d", &a);
        }
        switch (a) {
            case 1: {
                int signe = 0;
                char filename[30];
                char choix;
                while (signe == 0) {
                    printf("Veuillez saisir le nom du fichier d'une index\n");
                    scanf("%s", filename);
                    FILE *fp = fopen(filename, "r");
                    if (fp != NULL) {
                        signe = 2;
                        fclose(fp);
                    }
                    while (fp == NULL) {
                        printf("ce fichier n'existe pas\n");
                        printf("Continuer? y or n\n");
                        fflush(stdin);
                        scanf("%c", &choix);
                        if (choix == 'y') {//contiunuer
                            break;
                        } else if (choix == 'n') {//ne pas continuer return to menuprincipal
                            signe = 1;
                            break;
                        } else {
                            printf("fausse entrée\n");
                            continue;
                        }
                    }
                }
                if (signe == 1) break;
                index = indexer_fichier(filename);
                printf("réussie de creéer un index\n");
                printf("le nombre de mots lu dans le fichier: %d\n", index->nb_mots_total);
                printf("=========================================\n");
                break;
            }
            case 2: {
                if (index != NULL) {
                    printf("le nombre de mots total d'index: %d\n", index->nb_mots_total);
                    printf("le nombre de mots differents d'index: %d\n", index->nb_mots_differents);
                    int equilibre = est_ce_que_cest_equilibre(index);
                    if (equilibre == 1)printf("index est équilibré\n");
                    else printf("index n'est pas équilibré\n");
                    printf("================================\n");
                    break;
                } else {
                    printf("il n'y a pas de index! Veuillez importer un index.\n");
                    printf("===================================================\n");
                    break;
                }

            }
            case 3: {
                if (index != NULL) {
                    afficher_index(index);
                    printf("===================================================\n");
                    break;
                } else {
                    printf("il n'y a pas de index! Veuillez importer un index.\n");
                    printf("===================================================\n");
                    break;
                }
            }
            case 4: {
                if (index != NULL) {
                    char mot[30];
                    printf("Veuillez saisir le mot \n");
                    scanf("%s", mot);
                    afficher_mot(index, mot);
                    printf("===================================================\n");
                    break;
                } else {
                    printf("il n'y a pas de index! Veuillez importer un index.\n");
                    printf("===================================================\n");
                    break;
                }
            }
            case 5: {
                if (index != NULL) {
                    char mot[30];
                    printf("Veuillez saisir le mot \n");
                    scanf("%s", mot);
                    afficher_occurences_mot(index, mot);
                    printf("===================================================\n");
                    break;
                } else {
                    printf("il n'y a pas de index! Veuillez importer un index.\n");
                    printf("===================================================\n");
                    break;
                }
            }
            case 6: {
                if (index != NULL) {
                    index = equilibrer_index(index, listenoeud);
                    printf("===================================================\n");
                    break;

                } else {
                    printf("il n'y a pas de index! Veuillez importer un index.\n");
                    printf("===================================================\n");
                    break;
                }
            }

        }
    } while (a != 7);
    librer_listephrase(index);
    librer_listeposition(index->racine);
    free(index);
    return;
}
