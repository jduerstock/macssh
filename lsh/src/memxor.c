/* memxor.c
 *
 * $Id: memxor.c,v 1.1.1.1 2001/03/07 09:53:12 chombier Exp $
 */

/* XOR LEN bytes starting at SRCADDR onto DESTADDR.  Result undefined
   if the source overlaps with the destination.
   Return DESTADDR. */

#include "memxor.h"

UINT8 *memxor(UINT8 *dst, const UINT8 *src, size_t n)
{
  size_t i;
  for (i = 0; i<n; i++)
    dst[i] ^= src[i];

  return dst;
}
