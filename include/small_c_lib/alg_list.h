#ifndef __AUTO_LIB_ALG_LIST_H__
#define __AUTO_LIB_ALG_LIST_H__

#include "../memory_mgmt.h"

struct auto_lib_sll {
    void *node;
    struct auto_lib_sll *next;
};

int auto_lib_sll_init();
int auto_lib_sll_add(void *item);
int auto_lib_sll_add_head(void *item);
int auto_lib_sll_del(void *item, void (*callback)(void *item));
int auto_lib_ssl_find(void *item);
int auto_lib_sll_for_each(void *item, void (*callback)(void *item));
int auto_lib_sll_free();

#endif


