#ifndef IMPORT_H_INCLUDED
#define IMPORT_H_INCLUDED

#include "data_layout.h"

struct Allocator;

typedef Layout (*ImporterFunc)(void* data_source, Allocator* alloc);

/* Quelques importeurs peuvent être proposés par défaut, on peut en imaginer d'autres avec une syntaxe
personnalisée par exemple. */

/********************************************************/
/* Fichiers texte */
/********************************************************/
/*
  Importe toutes les lignes d'un fichier.
  Renvoie un layout de type LayoutType_Rows.
*/
Layout import_txt_rows(void* filename, Allocator* alloc);

/*
  Importe un tableau, par exemple
  ```
  numéro client, nom, prénom, salaire
  1, Doe, John, 2300
  2, Doe, Jane, 1800
  3, Caddel, Lisa, 1750
  ```

  Renvoie un layout de type LayoutType_Table.
*/
Layout import_txt_table(void* filename, Allocator* alloc);

/********************************************************/
/* Fichiers Excel */
/********************************************************/
/*
  Importe les lignes d'un fichier excel (ignore le nom des colonnes).

  Renvoie un layout de type LayoutType_Rows.
*/
Layout import_excel_table(void* filename, Allocator* alloc);

/*
  Importe une feuille excel sous la forme d'un tableau.

  Renvoie un layout de type LayoutType_Table.
*/
Layout import_excel_table(void* filename, Allocator* alloc);

/* Ici on a des fonctions qui prennent un nom de fichier mais elles pourraient prendre tout et n'importe quoi */

#endif
