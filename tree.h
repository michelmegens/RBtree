/*
 *  RBTree - Tree header
 *  Copyright (C) 2012   Michel Megens
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __RBTREE_H_
#define __RBTREE_H_

#include <stdlib.h>
#include <stdint.h>

typedef enum 
{
	RED,
	BLACK,
} rbtree_color_t;

typedef enum
{
	LEFT,
	RIGHT,
} tree_leaf_t;

struct rbtree_root
{
	struct rbtree *tree;
	
	size_t size;
};

struct rbtree
{
	struct rbtree *left;
	struct rbtree *right;
	struct rbtree *parent;
	struct rbtree *root;
	int key;
	rbtree_color_t color;
	
	void *data;
};

static inline struct rbtree *tree_parent(struct rbtree *node)
{
	if(node) {
		return node->parent;
	} else {
		return NULL;
	}
}

static inline struct rbtree *tree_grandparent(struct rbtree *node)
{
	struct rbtree *parent;
	if((parent = tree_parent(node)) != NULL) {
		return tree_parent(parent);
	} else {
		return NULL;
	}
}

extern int tree_insert(struct rbtree_root *root, struct rbtree *node);
#ifdef HAVE_DBG
extern void tree_dump(struct rbtree *tree, FILE *stream);
extern void tree_add_node(struct rbtree_root *root, int key);
void tree_cleanup(struct rbtree *root);
#endif

#endif