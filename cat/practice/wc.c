#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

static void do_wc(char *path);
static void die(char *s);
static void count_char(unsigned char *buf, char s);

int
main(int argc, char *argv[])
{
  if (argc == 1) {
    fprintf(stderr, "%s: file name not given\n", argv[0]);
    exit(1);
  }
  unsigned long i;
  for (i = 1; i < argc; i++) {
    do_wc(argv[i]);
  }
}

#define BUFFER_SIZE 2048

static void
do_wc( char *path)
{
  int fd;
  unsigned char buf[BUFFER_SIZE];
  int n;

  fd = open(path, O_RDONLY);
  if (fd < 0) die(path);
  for (;;) {
    n = read(fd, buf, BUFFER_SIZE);
    if (n < 0) {
      die(path);
    }
    if (n == 0) {
      break;
    }
  }
  count_char(buf, '\n');
}

static void
count_char(unsigned char *buf, char s)
{
  int count;
  unsigned long i;
  for (i = 0; i < sizeof buf; i++) {
    if (buf[i] == s) {
      count++;
    }
  }
  printf("%d\n", count);
}

static void
die(char *s)
{
  perror(s);
  exit(1);
}
