#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

song_node * insert_front( song_node *node, char s[], char a[] ) {

  song_node *new = (song_node *)malloc(sizeof(song_node));

  new->next = node;
  strcpy(new->song, s);
  strcpy(new->artist, a);

  return new;
}

song_node * insert( song_node *node, char s[], char a[] ) {
  song_node *tmp = node;
  return insert_ordered(tmp, s, a);
}
song_node * insert_ordered( song_node *node, char s[], char a[] ) {

  if( !node )
    return insert_front(node, s, a);

  if( strcmp(a, node->artist) < 0 )
    return insert_front(node, s, a);

  if( strcmp(a, node->artist) == 0 && strcmp(s, node->song) < 0 )
    return insert_front(node, s, a);

  else
    node->next = insert(node->next, s, a);
  
  return node;
}

void print_list( song_node *node ) {

  song_node *tmp = node;
  
  while(tmp != NULL) {
    printf("\n* %s - %s", tmp->artist, tmp->song);
    tmp = tmp->next;
  }
  printf("\n");
  
}

song_node * find_Song(song_node *node, char s[], char err[]) {
  
  song_node *tmp = node;

  if( !tmp )
    printf("%s", err);

  else if( strcmp(s, tmp->song) == 0 )
    return tmp;

  else
    return find_Song(tmp->next, s, err);

  return 0;
}

song_node * find_Artist(song_node *node, char a[]) {

  song_node *tmp = node;

  if( !tmp )
    printf("\nArtist not found.");

  else if( strcmp(a, tmp->artist) < 0 )
    printf("\nArtist not found.");

  else if( strcmp(a, tmp->artist) == 0 )
    return tmp;

  else
    return find_Artist(tmp->next, a);

  return 0;
  
}

int len(song_node *node) {
  
  int i=0;
  
  while(node) {
    node = node->next;
    i++;
  }
  
  return i;
  
}

song_node * find_random(song_node *node) {

  song_node *tmp = node;
  
  int r = rand() % len(tmp);
  
  while(r) {
    tmp = tmp->next;
    r--;
  }

  return tmp;
  
}

song_node * remove_song(song_node *node, char s[], char a[]) {

  song_node *tmp = node;
  if( !tmp ) {
    return node;
  }

  song_node *tmps = find_Song(tmp, s, "\nSong not found.");
  if( !tmps ) {
    return node;
  }

  if(tmp == tmps) {
    return tmp->next;
  }

  song_node *prv = 0;
  while(tmp->next && tmp != tmps) {
    prv = tmp;
    tmp = tmp->next;
  }
  prv->next = tmps->next;
  free(tmp);
  
  return node;
}

song_node * free_list( song_node *node ) {

  song_node *f = node;
  while ( node ) {
    node = node->next;
    printf("freeing node: %s - %s\n", f->artist, f->song );
    free(f);
    f = node;
  }

  return node;
}
