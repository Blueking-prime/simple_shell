#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>                                                           
#include <unistd.h>                                                           
#include <sys/types.h>                                                        
#include <sys/stat.h>                                                         
#include <sys/wait.h>                                                         
#include <fcntl.h>                                                            
#include <stdio.h>                                                            

void type_prompt ();
void read_command ( char cmd[], char *par[]);

#endif /* MAIN_H */  
