#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
  int i = 0;
  if(!s) // FIX: add if to handl NULL.
    return NULL; 
  while(s[i] && s[i] != c) // s[i] == '\0'
    i++;
  if (s[i] == c)
    return s + i; //delete else
  return NULL;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
  size_t i = 0; // type size_t i = 0;
  while(i < n) // bad while type (i < n) 
  { // add {
    ((char *)dest)[i] = ((char *)src)[i]; // switch n-1 to i
    i++; // type i++;
  } // add }
  return dest;
}

size_t ft_strlen(char *s)
{
  size_t res = 0;
  if (!s) // FIX: add if to handl segfault.
    return 0;
  while (*s)
  {
    s++;
    res++;
  }
  return res;
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
  size_t size1 = ft_strlen(*s1);
  char *tmp = malloc(size2 + size1 + 1);
  if (!tmp)
    return 0;
  ft_memcpy(tmp, *s1, size1);
  ft_memcpy(tmp + size1, s2, size2);
  tmp[size1 + size2] = '\0';
  free(*s1);
  *s1 = tmp;
  return 1; 
}

int str_append_str(char **s1, char *s2)
{
  return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
  size_t i; // type size_t i;
  if (dest > src)
  { // add {
    i = n; // add i = n;
    while(i > 0) // add
    { // add
      i--; // add
      ((char *)dest)[i] = ((char *)src)[i]; //add
    }// add
  }
  else
  { // add
    i = 0; // add
    while (i < n) // add i < n
    {
      ((char *)dest)[i] = ((char *)src)[i];
      i++; // add i++;
    }
  }// add
    return dest;
}

char *get_next_line(int fd)
{
  static char b[BUFFER_SIZE + 1] = "";
  char *ret = malloc(1); // switch NULL to malloc(1);
  char *tmp; // delete = ft_strchr(b, '\n');
  int read_ret; //add
  
  if(!ret) //add FIX
    return NULL;
  ret[0] = '\0'; // add FIX

  tmp = ft_strchr(b, '\n');// add 
  while(!tmp)
  {
    if (!str_append_str(&ret, b))
      return (NULL);
    read_ret = read(fd, b, BUFFER_SIZE); //delete int
    if (read_ret <= 0) //FIX
    {
      b[0] = '\0';//add
      if (ret[0] == '\0') //add
      {//add
        free(ret);//add
        return (NULL);
      }//add
      return ret; // add
    }
    b[read_ret] = 0;
    tmp = ft_strchr(b, '\n'); //add
  }
  if (!str_append_mem(&ret, b, tmp - b + 1))
  {
    free(ret);
    return NULL;
  }
  ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1); // add
  return ret;
}