#include "linkedlist.h"

song_node *lst[26];

void add_song( char song[], char artist[] );

song_node * find_song(char song[]);

song_node * find_artist_songs(char artist[]);

void print_letter( char letter );

void print_artist( char artist[] );

void print_library();

void shuffle();

void delete_song( char song[], char artist[] );

void delete_library();
