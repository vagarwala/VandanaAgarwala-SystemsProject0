typedef struct song_node {
  char song[256];
  char artist[256];
  struct song_node *next;
} song_node;


song_node * insert_front(song_node *list, char song[], char artist[]);

song_node * insert(song_node *list, char song[], char artist[]);

song_node * insert_ordered(song_node *list, char song[], char artist[]);

void print_list(song_node *list);

song_node * find_Song(song_node *list, char song[], char err[]);

song_node * find_Artist(song_node *list, char artist[]);

int len(song_node *list);

song_node * find_random(song_node *list);

song_node * remove_song(song_node *list, char song[], char artist[]);

song_node * free_list(song_node *list);