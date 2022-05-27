#ifndef TRANSFORM_H_INCLUDED
#define TRANSFORM_H_INCLUDED

struct Layout;

typedef void (*TransformerFunc)(Layout* layout);

/* Les transformeurs permettent de faire des transformations sur les données. */

/* Quelques uns fournis par défaut, par exemple: */

/* Met tout le texte en lowercase */
void transform_lowercase(Layout* layout);

/* Arrondit toutes les valeurs numériques */
void transform_round(Layout* layout);

#endif
