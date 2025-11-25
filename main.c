#include "ft_printf.h"
#include <stdio.h>
#include <fcntl.h>
//SOME CRAZY TESTS
int main () 
{
    int x = 42;
    
  int j = ft_printf("un test de ft_printf: --%d-- --%s-- --%u-- --%p-- \n",0, NULL, 0, NULL);
	int i = printf("un test de ft_printf: --%d-- --%s-- --%u-- --%p-- \n",0, NULL, 0, NULL);
	printf("ft_printf : ret = %d ||||||||| printf : ret = %d \n",j,i);
    
  int a = ft_printf("ttt%cttt%d\n");
  ft_printf("%d\n", a);
  printf("\n");
  int b = printf("ttt%cttt%d\n");
  printf("%d\n", b);

  int a = ft_printf("%d\n",-45);
  ft_printf("%d\n", a);
  printf("\n");
  int b = printf("%d\n",-45);
  printf("%d\n", b);
    
  int a = ft_printf("Test %% simple : %%\n");
  ft_printf("%d\n", a);
   
  int c = printf(NULL);//if format == NULL
  printf("%d\n", c);
    
  fclose(stdout); // if stdout is close
  int a = ft_printf("fedyhew");
  fprintf(stderr,"%d\n",a);
    
  printf("\ncomparaison : \n\n");
    
  int i = printf("un test de ft_printf: --%d-- --%s-- --%u-- --%p-- \n",0, NULL, 0, NULL);
  printf("%d%%\n", i);
  printf("Test %% simple : %%\n");
  int a =ft_printf("%rey");
	ft_printf("%d\n",a);
	printf("%%%\n");

  
  int a = ft_printf("%%%%%l");
  printf("\n");
  printf("%d\n", a);
  printf("abdoul  ||||  %%%%");
  write(1," A ",3);
  int a = ft_printf("");
  printf("%d",a);
  return 0;
}