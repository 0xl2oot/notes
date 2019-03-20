#include <stdio.h>
#include <fcntl.h>
#include <utmp.h>
#include <stdlib.h>
#include <string.h>

char *get_tty( char * );
int main( int ac, char *av[] ) {
     int fd;
     char buf[BUFSIZ];
     char *tty_for_user;

     if ( ac != 2 ){                                    /* check args */
          fprintf(stderr, "usage: write logname\n");
          exit(1);
     }

     tty_for_user = get_tty( av[1] );                  /* find user  */
     if ( tty_for_user == NULL )
          return 1;

     sprintf(buf, "/dev/%s", tty_for_user);               /* open device */
     fd = open( buf, O_WRONLY );
     if ( fd == -1 ) {
          perror(buf); exit(1);
     }

     while( fgets(buf, BUFSIZ, stdin) != NULL )        /* write to user */
          if ( write(fd, buf, strlen(buf)) == -1 )
               break;
     close( fd );
     return 0;
}

char *get_tty( char *logname )
{
     static struct utmp utrec;
     int utfd;
     int namelen = sizeof( utrec.ut_name );
     char *retval = NULL;

     if ( (utfd = open( UTMP_FILE, O_RDONLY )) == -1 )   /* open utmp */
          return NULL;

     /* look for a line where the user is logged in */
     while( read( utfd, &utrec, sizeof(utrec)) == sizeof(utrec) ) {
          if ( strncmp(logname, utrec.ut_name, namelen ) == 0 )
          {
               retval = utrec.ut_line;
               break;
          }
     }
     close( utfd );                                       /* close & go */
     return retval;
}
