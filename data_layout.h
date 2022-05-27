#ifndef DATA_LAYOUT_H_INCLUDED
#define DATA_LAYOUT_H_INCLUDED

#include "data_types.h"
#include "stream.h"

/* On peut représenter les données sous différentes formes comme des lignes, tableaux, graphes, ... */

/* Représente une ligne de données */
struct Row
{
    Data* fields;
    size_t count;
};

/* Représente plusieurs lignes de données */
struct Rows
{
    Row* rows;
    size_t count;
};

/* Représente un tableau */
struct Table
{
    String* headers;
    size_t header_count;
    Rows rows;
};

/* Représente une structure arborescente */
struct GraphNode
{
    String name;
    GraphNode* children;
    size_t child_count;
};

enum LayoutType
{
    LayoutType_Row,
    LayoutType_Rows,
    LayoutType_Table,
    LayoutType_Node,
};

struct Layout
{
    LayoutType type;
    void* data; /* Le type détermine ce qu'il y a dedans, on aurait pu faire une union mais on préfère que le layout reste très générique */

    Stream errors;
    bool has_errors;
};

/* On pourrait saupoudrer de sucre le layout en remplaçant les "types" par des tags, pour faire des Layout<Tag> (je ne suis pas contre) */

#endif
