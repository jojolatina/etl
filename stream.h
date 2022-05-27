#ifndef STREAM_H_INCLUDED
#define STREAM_H_INCLUDED

/*************************************************/
/* De quoi stocker un flux de données quelconque (utilisé pour les erreurs
 mais on pourrait l'utiliser aussi pour le reste) */
struct StreamChunk
{
    char* data;
    size_t count;
    StreamChunk* next;
};

struct Stream
{
    StreamChunk* first_chunk;
    size_t count;
};

/* Ajoute des données au stream */
void stream_append(Stream* stream, char const* data);
/*************************************************/

#endif
