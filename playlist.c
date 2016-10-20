#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

void add_song( char s[], char a[] ) {
  printf("adding %s - %s...\n", s, a);
  char letter = a[0]-97;
  lst[letter] = insert(lst[letter], s, a);
}

song_node * find_song(char s[]) {
  int i=0;
  song_node *tmp = 0;
  while(!tmp && i++ < 26)
    tmp = find_Song(lst[i], s, "");
  print_list(tmp);
  return tmp;
}

song_node * find_artist_songs(char a[]) {
  song_node *tmp = lst[a[0]-97];
  tmp = find_artist_songs(tmp, a);
  print_list(tmp);
  return tmp;
}

void print_letter( char l ) {
  printf("%c list:", l);
  print_list(lst[l-97]);
  printf("\n\n");
}

void print_artist( char a[] ) {
  printf("%s list:\n", a);
  song_node *l = find_artist_songs(a);
  while(l && strncmp(a, l->artist, 1) == 0) {
    if(strcmp(l->artist, a) == 0)
      printf("* %s - %s\n", l->artist, l->song);
    l = l->next;
  }
  printf("\n");
}

void print_library() {
  printf("\nyour library:");
  int i=0;
  while(i++ < 26)
    print_list(lst[i]);
}

void shuffle() {
  printf("shuffling playlist...\n");
  song_node *tmp = 0; int i=0;
  while(i++ < 26) {
    song_node *a = lst[i];
    while(a) {
      tmp = insert_front(tmp, a->song, a->artist);
      a = a->next;
    }
  }
  while(tmp) {
    song_node *rand = find_random(tmp);
    printf("%s - %s\n", rand->artist, rand->song);
    tmp = remove_song(tmp, rand->song, rand->artist);
  }
  printf("\n");
}

void delete_song( char s[], char a[] ) {
  printf("\n\ndeleting %s - %s...", a, s);
  lst[a[0]-97] = remove_song(lst[a[0]-97], s, a);
  print_library();
}

void delete_library() {
  int i=0;
  while(i++ < 26)
    lst[i] = free_list(lst[i]);
}
