/* memxor.c
 *
 * $Id: memxor.c,v 1.1 2001/09/18 16:23:30 chombier Exp $
 */

/* XOR LEN bytes starting at SRCADDR onto DESTADDR.  Result undefined
   if the source overlaps with the destination.
   Return DESTADDR. */

#include "memxor.h"

uint8_t *memxor(uint8_t *dst, const uint8_t *src, size_t n)
{
  size_t i;
  for (i = 0; i<n; i++)
    dst[i] ^= src[i];

  return dst;
}
