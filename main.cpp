#include "import.h"
#include "transform.h"
#include "export.h"
#include "memory.h"

/* L'utilisateur peut définir ses propres fonctions si il veut */
/* Par exemple pour importer un tableau sous la forme au lieu de la forme par défaut :
  ```
  numéro client | nom | prénom | salaire
  ========================================
  1 | Doe    | John | 2300
  2 | Doe    | Jane | 1800
  3 | Caddel | Lisa | 1750
  ```
*/
Layout import_txt_table_custom_syntax(void* filename, Allocator* alloc);

int main()
{
    Allocator alloc = allocator_create(2 * 1024 * 1024);
    
    /* On importe un tableau depuis un fichier texte */
    Layout layout = import_txt_table_custom_syntax((void*)"table.txt", &alloc);
    if (layout.has_errors)
    {
        /* On peut afficher les erreurs d'une manière ou d'une autre si on veut */
        /* dump_errors(layout.errors) */
    }
    
    /* On peut faire optionnelement des transformations */
    /* transform_lowercase(&layout); */
    
    /* On l'exporte dans une feuille excel */
    export_excel_table((void*)"table.xlsx", &layout);
    if (layout.has_errors)
    {
        /* dump_errors(layout.errors) */
    }

    /* Ici on a un exemple très intéressant de comment gérer les erreurs d'une manière fiable, sans exceptions, sans RAII et sans
    pour autant faire des goto dégueu à la C. */
    /* Tout simplement, les fonctions qui manipulent le layout peuvent vérifier qu'il est valide et si ce n'est pas le cas,
    elles ne font rien */

    allocator_clear(&alloc);
}
