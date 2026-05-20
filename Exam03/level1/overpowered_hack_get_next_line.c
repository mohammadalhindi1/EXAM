//Bad solution, but it works.
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
  char *line = malloc(100000), *buf = line;
  int  r;

  if (fd < 0 || !line)
    return (NULL);
  while ((r = read(fd, buf, 1)) > 0)
  {
    if (*buf++ == '\n')
      break;
  }
  if (r < 1 && buf == line)
    return (free(line), NULL);
  *buf = 0;
  return (line);
}
