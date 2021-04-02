//
// Created by 陈扬珍 on 2020/11/24.
//

#ifndef NF16_TP4_TP4_H
#define NF16_TP4_TP4_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct t_position{
    int numero_ligne;
    int ordre;
    int numero_phrase;
    struct t_position* suivant;
}t_Position;

typedef struct t_listePositions{
    struct t_position* debut;
    int nb_elements;
}t_ListePositions;

typedef struct t_noeud{
    char *mot;
    int nb_occurences;
    t_ListePositions *positions;
    struct t_noeud* filsGauche;
    struct t_noeud* filsDroit;
}t_Noeud;

typedef struct t_index{
    t_Noeud *racine;
    int nb_mots_differents;
    int nb_mots_total;
    char **listephrase;
}t_Index;


struct t_listePositions *creer_liste_positions();

int ajouter_position(t_ListePositions *listeP, int ligne, int ordre,int num_phrase);

t_Index *creer_index();

char* tranfertomini(char* mot);

char* tranfertomaju(char* mot);

t_Noeud* rechercher_mot(t_Index *index, char *mot);

int ajouter_nouvel_noeud(t_Index *index, t_Noeud *noeud);

int ajouter_existe_noeud(struct t_index* index,struct t_noeud *noeud_existe,int n_ligne,int or,int n_pharse);

t_Index* indexer_fichier( char *filename);

struct t_noeud* creer_noeud(char *word,int numero_ligne,int ordre,int numero_pharse);

struct t_noeud* pere(t_Index* i,t_Noeud* noeud);

struct t_noeud* successeur(t_Index* i,t_Noeud* noeud);

struct t_noeud* predecesseur(t_Index* i,t_Noeud* noeud);

void afficher_index(t_Index *index);

void afficher_occurences_mot(t_Index *index, char *mot);

void afficher_mot(t_Index *index, char *mot);

int max(int a, int b);

int hauteur(t_Noeud *noeud);

int equilibre(t_Noeud *noeud);

int est_ce_que_cest_equilibre(t_Index *index);

t_Noeud* numeroter_noeud(t_Index *index,t_Noeud *liste_noeud);

void affcter_fils(int g,int d,t_Noeud* liste_noeud);

t_Index *equilibrer_index(t_Index *index,t_Noeud* liste_noeud) ;

void free_index(t_Noeud* noeud);

void librer_listeposition(t_Noeud *noeud);

void librer_listephrase(t_Index *index);

void menuprincipal();



//t_Index *equilibrer_index(t_Index *index);

//void affichage_noeud(struct t_noeud *n);
#endif //NF16_TP4_TP4_H
