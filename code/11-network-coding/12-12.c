#include <csapp.c>

int main(int argc, char const *argv[])
{
  char **pp;
  struct in_addr addr;
  struct hostent *hostp;
  if(argc != 2) {
    fprintf(stderr, "usage %s <domain name or dotted-decimal>\n", argv[1]);
    exit(0);
  }

  if(inet_aton(argv[1], &addr) != 0) {
    hostp = Gethostbyaddr((const char *)&addr, sizeof(addr), 0);
  } else {
    hostp = Gethostbyname(argv[1]);
  }
  printf("official host name: %s\n", hostp->h_name);

  for(pp = hostp->h_aliases; *pp != NULL; pp++) {
    printf("alias: %s \n", *pp);
  }
  for(pp = hostp->h_addr_list; *pp != NULL; pp++) {
    addr.s_addr = *((unsigned int *)*pp);
    printf("address: %s\n", inet_ntoa(addr));
  }
  return 0;
}