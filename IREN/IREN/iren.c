#include <stdio.h>
#define BUFFSIZE 42
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct  s_list
{
    void    *content;
    size_t    content_size;
    struct s_list*next;
}               t_list;

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char    *d;
    unsigned char    *s;
    size_t            i;

    i = 0;
    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    if (d == s && d == NULL)
        return (NULL);
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dst);
}

void    ft_bzero(void *s, size_t n)
{
    unsigned char *p;

    p = (unsigned char *)s;
    while (n--)
    {
        *p = 0;
        p++;
    }
}

void    *ft_memalloc(size_t size)
{
    char *p;

    p = (char *)malloc(sizeof(*p)* size);
    if (p == NULL)
        return (NULL);
    else
        ft_bzero(p, size);
    return (p);
}

char    *ft_strrchr(const char *s, int c)
{
    char    *str;
    int        i;

    str = (char *)s;
    i = 0;
    while (str[i] != '\0')
        i++;
    while (i > -1)
    {
        if (str[i] == (char)c)
            return (str + i);
        i--;
    }
    return (NULL);
}

char    *ft_strnew(size_t size)
{
    char *p;

    p = (char *)malloc(sizeof(*p)* (size + 1));
    if (p == NULL)
        return (NULL);
    memset(p, '\0', size + 1);
    return (p);
}


char    *ft_strjoin(char const *s1, char const *s2)
{
    char *p;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    p = ft_strnew(strlen(s1) + strlen(s2));
    if (p == NULL)
        return (NULL);
    strcpy(p, s1);
    strcat(p, s2);
    return (p);
}

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *p;

    if (s == NULL)
        return (NULL);
    p = ft_strnew(len);
    if (p == NULL)
        return (NULL);
    strncpy(p, s + start, len);
    return (p);
}



void    ft_lstadd(t_list **alst, t_list *new)
{
    if (new != NULL)
    {
        new->next = *alst;
        *alst = new;
    }
}

void    ft_putstr(char const *s)
{
    int i;

    i = 0;
    if (s)
    {
        while (s[i] != '\0')
            putchar(s[i++]);
    }
}

void    ft_putendl(char const *s)
{
    ft_putstr(s);
    putchar('\n');
}

t_list    *ft_lstnew(void const *content, size_t content_size)
{
    t_list *p;

    p = ft_memalloc(sizeof(*p));
    if (p == NULL)
        return (NULL);
    if (content == NULL)
    {
        p->content = NULL;
        p->content_size = 0;
    }
    else
    {
        if ((p->content = malloc(content_size)) == NULL)
        {
            free(p);
            return (NULL);
        }
        ft_memcpy(p->content, content, content_size);
        p->content_size = content_size;
    }
    p->next = NULL;
    return (p);
}

int ft_drobilka(char *buff, char *line, char *p_to_content)
{
    char    *tmp;   
    char    *tmp_freedom;

    if ((tmp = strchr(buff, '\n')) == NULL)
    {
        tmp_freedom = p_to_content;
        p_to_content = ft_strjoin(p_to_content, buff);
        free(tmp_freedom);
        return (0);
    }
    else
        *line = ft_strsub(buff, 0, tmp - buff);
    tmp_freedom = p_to_content;
    p_to_content = ft_strjoin(p_to_content, tmp);
    free(tmp_freedom);
    return (1);
}


int        get_next_line(const int fd, char **line)
{
    static t_list    *begin_tail;
    char            buff[BUFFSIZE + 1];
    char            *p_to_content;
    int                read_result;

    if (fd < 0 || fd > 10240 || !line)
        return (-1);
    if (begin_tail == NULL)
    {
        begin_tail = ft_lstnew("", 0);
        begin_tail->next = ft_lstnew("", fd);
    }
    begin_tail = begin_tail->next;
    p_to_content = begin_tail->content;
    while ((read_result = read(fd,buff, BUFFSIZE)) > 0)
    {
        buff[read_result] = '\0';
        if (ft_drobilka(buff, &line, p_to_content) == 1)
            break;
    }
    return (0);
}

int    main (int argc, char **argv)
{
    int        fd;
    char    *line;
    int        i;

    line = (char *)malloc(sizeof(*line)*1);
    if (argc == 1)
        printf("no file as an argument");
    else
        i = 1;
    while (i < argc)
    {
        if ((fd = open(argv[i], O_RDONLY)) != -1)
        {
            while (get_next_line(fd,&line) == 1)
            {
                ft_putendl(line);
                free(line);
            }
        }
        i++;
    }
    return (0);
}