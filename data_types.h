#ifndef DATA_TYPES_H_INCLUDED
#define DATA_TYPES_H_INCLUDED

#include <stddef.h> /* size_t */

/* On a différents types de données : pour l'instant des nombres et des strings */

/* Les nombres peuvent être de plusieurs types */
enum NumberType
{
    NumberType_i8,
    NumberType_i16,
    NumberType_i32,
    NumberType_i64,
    NumberType_i128,
    
    NumberType_u8,
    NumberType_u16,
    NumberType_u32,
    NumberType_u64,
    NumberType_u128,
    
    NumberType_f16,
    NumberType_f32,
    NumberType_f64,
};

struct Number
{
    NumberType type;
    char value[16]; // on suppose qu'on supporte des nombres jusqu'à 128 bits
};

struct String
{
    char* data;
    size_t length;
};

enum DataType
{
    DataType_Number,
    DataType_String,
};

/* Représente une donnée */
struct Data
{
    DataType type;
    
    union
    {
        Number number;
        String string;
    } data;
};

#endif
