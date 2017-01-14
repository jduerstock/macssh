/* parse_macros.h
 *
 * Utility macros for managing a struct simple_buffer *buffer.
 *
 * $Id: parse_macros.h,v 1.1.1.1 2001/03/07 09:53:12 chombier Exp $ */

#ifndef LSH_PARSE_MACROS_H_INCLUDED
#define LSH_PARSE_MACROS_H_INCLUDED

#ifndef BUFFER
#define BUFFER buffer
#endif

#define LEFT (BUFFER->capacity - BUFFER->pos)
#define HERE (BUFFER->data + BUFFER->pos)
#define ADVANCE(n) (BUFFER->pos += (n))
#define GET() (BUFFER->data[BUFFER->pos++])

#endif /* LSH_PARSE_MACROS_H_INCLUDED */
