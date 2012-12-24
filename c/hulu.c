/*
i686-w64-mingw32-gcc hulu.c -Wall
mapfile vids < <(grep -aoz "<video [^>]*>" pg.core | sort | uniq -w123)
*/

#include <stdio.h> // fopen
#include <stdlib.h> // malloc
#include <string.h> // strstr

int
main (void)
{
  int size;
  char *buffer;
  FILE *f;

  /* need array big enough for the biggest "video" line (888) */
  size = 1000;
  buffer = malloc (size);

  /* need the "b" */
  f = fopen ("pg.core", "rb");

  while (! feof (f))
    {
      fgets (buffer, size, f);
      if (
        strstr (buffer, "<video ") &&
        strstr (buffer, "/>")
      )
        printf ("%s", buffer);
    }

  fclose (f);
  return 0;
}
