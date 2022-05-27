#ifndef EXPORT_H_INCLUDED
#define EXPORT_H_INCLUDED

struct Layout;

typedef void (*ExporterFunc)(void* data_dest, Layout* layout);

/* Exporte le layout dans un fichier texte */
void export_txt_rows(void* filename, Layout* layout); /* LayoutType_Rows */
void export_txt_table(void* filename, Layout* layout); /* LayoutType_Table */

/* Exporte le layout dans une feuille excel */
void export_excel_rows(void* filename, Layout* layout); /* LayoutType_Rows */
void export_excel_table(void* filename, Layout* layout); /* LayoutType_Table */

#endif
