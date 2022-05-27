#include "export.h"
#include "data_layout.h"

void export_excel_table(void* filename, Layout* layout)
{
    if (layout->has_errors)
    {
        return;
    }

    /* Cette fonction suppose qu'on exporte une TABLE */
    if (layout->type != LayoutType_Table)
    {
        /* Pour les fonctions d'export on pourrait imaginer mettre les erreurs ailleurs que dans le layout mais bon */
        layout->has_errors = true;
        stream_append(&layout->errors, "Layout invalide (type TABLE attendu)");
    }
    
    /* ... */
}