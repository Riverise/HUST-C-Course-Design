#ifndef _LISTHSTY_H
#define _LISTHSTY_H

#include "LISTDF.h"
#include <string.h>

struct My_vector_ *add_to_history(struct My_vector_ *vhead, struct My_filenode *theNode);
void move_dir(struct My_vector_ *history, struct My_vector_ **currenthead, char d, struct My_filenode *fatherNode = NULL);

#endif _LISTHSTY_H