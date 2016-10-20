#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "playlist.h"

int main() {

  srand(time(NULL));

  printf("__ADDING SONGS__\n");
  add_song("sun is shining", "axwell & ingrosso");
  add_song("partition", "beyonce");
  add_song("lane boy", "twenty-one pilots");
  add_song("hotel california", "eagles");
  add_song("679", "fetty wap");
  add_song("message man", "twenty-one pilots");
  add_song("spontaneous me", "lindsey stirling");
  add_song("team", "lorde");
  add_song("stressed out", "twenty-one pilots");
  add_song("diva", "beyonce");
  add_song("trap queen", "fetty wap");
  print_library();
  printf("\n");

  printf("__FINDING SONGS__\n");
  printf("looking for team...");
  find_song("team");
  printf("\nlooking for partition...");
  find_song("partition");
  printf("\nlooking for something not there...");
  find_song("not there");

  printf("\n__FINDING ARTISTS' SONGS__\n");
  printf("looking for beyonce...");
  find_artist_songs("beyonce");
  printf("\nlooking for twenty-one pilots...");
  find_artist_songs("twenty-one pilots");
  printf("\nlooking for fetty wap...");
  find_artist_songs("fetty wap");
    
  printf("\n__PRINTING LETTERS__\n");
  print_letter('a');
  print_letter('b');
  print_letter('e');
  print_letter('t');
  print_letter('l');

  printf("__PRINTING ARTISTS__\n");
  print_artist("beyonce");
  print_artist("twenty-one pilots");
  print_artist("fetty wap");

  printf("\n__SHUFFLING__\n");
  shuffle();
  shuffle();

  printf("__DELETING SONGS__");
  print_library();
  delete_song("lane boy", "twenty-one pilots");
  delete_song("diva", "beyonce");
  delete_song("song_not_there", "artist_not_there");
  printf("\n");

  printf("\n__DELETING EVERYTHING__");
  print_library();
  printf("\n\n");
  delete_library();
  print_library();
  printf("\n");
}
