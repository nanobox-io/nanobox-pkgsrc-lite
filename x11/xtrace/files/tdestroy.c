/* modified version of the file below, from vlc */
/**
 * @file tdestroy.c
 * @brief replacement for GNU tdestroy()
 */
/*****************************************************************************
 * Copyright (C) 2009 Rémi Denis-Courmont
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdlib.h>
#include <assert.h>

#include <search.h>

static struct
{
    const void **tab;
    size_t count;
} list = { NULL, 0 };

static void list_nodes (const void *node, const VISIT which, const int depth)
{
    (void) depth;

    if (which != postorder && which != leaf)
        return;

    const void **tab = realloc (list.tab, sizeof (*tab) * (list.count + 1));
    if (tab == NULL)
        abort ();

    tab[list.count] = *(const void **)node;
    list.tab = tab;
    list.count++;
}

static struct
{
    const void *node;
} smallest = { NULL };

static int cmp_smallest (const void *a, const void *b)
{
    if (a == b)
        return 0;
    if (a == smallest.node)
        return -1;
    if (b == smallest.node)
        return +1;
    abort ();
}

void tdestroy (void *root, void (*freenode) (void *))
{
    const void **tab;
    size_t count;

    assert (freenode != NULL);

    /* Enumerate nodes in order */
    assert (list.count == 0);
    twalk (root, list_nodes);
    tab = list.tab;
    count = list.count;
    list.tab = NULL;
    list.count = 0;

    /* Destroy the tree */
    for (size_t i = 0; i < count; i++)
    {
         smallest.node = tab[i];
         if (tdelete (smallest.node, &root, cmp_smallest) == NULL)
             abort ();
    }
    assert (root == NULL);

    /* Destroy the nodes */
    for (size_t i = 0; i < count; i++)
         freenode ((void *)(tab[i]));
    free (tab);
}
