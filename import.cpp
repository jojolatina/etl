#include "import.h"
#include "memory.h"
#include "data_layout.h"
#include <stdio.h>

Layout import_txt_rows(void* source, Layout* out, Allocator* alloc)
{
    char const* filename = (char const*)source; /* Dans cette fonction on suppose qu'on nous a passé un nom de fichier */
    Layout layout = {};
    /* Le layout dans cette fonction est de type ROWS */
    Rows* rows;

    /* Ce n'est pas implémenté mais on pourrait faire en sorte de sauvegarder le point actuel de l'allocateur
        pour pouvoir vider toutes les allocations faites ici en cas d'erreur */
    /* SubAlloc sub_alloc = allocator_save(alloc); */

    FILE* file = fopen(filename, "rt");
    if (!file)
    {
        layout.has_errors = true;
        stream_append(&layout.errors, "Fichier invalide");
    }
    else
    {
        /* On peut parser le fichier, on va extraire les lignes car c'est le layout ROWS */
        rows = (Rows*)allocator_allocate(alloc, sizeof(Rows));
        rows->count = ...; /* il faut compter le nombre de lignes à sauvegarder */
        rows->rows = (Row*)allocator_allocate(alloc, rows->count * sizeof(Row));

        for (int i = 0; i < rows->count; ++i)
        {
            Row* row = rows->rows[i];
            row->count = ...; /* Il faut compter le nombre de champs de la ligne */
            row->fields = (Data*)allocator_allocate(alloc, row->count * sizeof(Data*));

            for (int j = 0; j < row->count; ++j)
            {
                /* On parse chaque champ */
                if (...le champ actuel est un nombre flottant...)
                {
                    row->fields[j].type = DataType_Number;
                    row->fields[j].data.number.type = NumberType_f32;
                    row->fields[j].data.number.value = ...parseF32()...;
                }
                else if (...le champ est une string...)
                {
                    row->fields[j].type = DataType_String;
                    row->fields[j].data.string = ...parseString()...;
                }
                /* Plutot que de remplir les champs à la main, on pourrait se faire une abstraction à ce niveau là */
            }
        }
    }

    if (!layout.has_errors)
    {
        /* Pas d'erreur, on remplit officiellement le layout */
        layout.type = LayoutType_Rows;
        layout.data = rows;
    } else {
        /* On peut "jetter" toutes les allocations faites entre temps, puisqu'il y a eu une erreur */
        /* allocator_rollback(&sub_alloc); */
            
        /* Cette libération mémoire pourrait potentiellement se faire en UNE SEULE opération
            (alloc->cur_block->size = sub_alloc->old_size) si jamais le bloc courant était assez gros pour contenir toutes nos
            allocations (sinon il faudrait aussi libérer les nouveaux blocs alloués entre temps).
            Donc aucun appel à free, aucun destructeur à appeler, juste une simple opération et tout disparait
            Et le RAII ne peut pas nous aider ici puisqu'on ne veut libérer la mémoire qu'uniquement en cas d'erreur */        
    }

    return layout;
}
