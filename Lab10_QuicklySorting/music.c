// This file includes the implementations
// of all of the functions found in the music.h file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "music.h"
 
// @Name    fileLineCount
// @Brief   Helper function to count the number
//          of lines in a file
//
//          Returns -1 if file is not able to
//          be opened.
//          Returns >=0 for number of lines in
//          a file.
int fileLineCount(const char* fileName){
    // Open file for read only access.
    // We do not need to modify the contents.
    FILE* myFile = fopen(fileName,"r");
    if(NULL==myFile){
        return -1;
    }

    int lines =0;
    char buffer[MAX_SONG_LENGTH];
    while(fgets(buffer,MAX_SONG_LENGTH,myFile)){
        lines++;
    }

    // Close our file when we are done.
    fclose(myFile);

    return lines;
}

// @Name    loadMusicDatabase
// @Brief   Load the music database from a text file
//          'size' is the size of the database.
musicDB_t* musicDB_createDatabase(const char* fileName){
  musicDB_t* db = (musicDB_t*)malloc(sizeof(musicDB_t));
  if(NULL==db){
    perror("Could not allocate memory for music database");
    return NULL;
  }

  FILE *myFile = fopen(fileName,"r");
  if(NULL==myFile){
    perror("Could not open file");
    return NULL;
  }

  // Setup our music database
  // Figure out how many lines are in our file we are reading.
  db->size = fileLineCount(fileName); 
  if(db->size==0){
      perror("Cannot continue with empty database file\n");
      exit(1);
  }
  // Allocate memory for each character-string pointer
  // We need a pointer to every
  db->database = malloc(sizeof(char*)*db->size);

  char buffer[MAX_SONG_LENGTH];
  for(size_t i =0; i < db->size; i++){
      // Allocate memory for each individual character string
      // Note: Songs can only be at max '80' characters long
      db->database[i] = malloc(sizeof(char)*MAX_SONG_LENGTH);
      // Read in line from file
      fgets(buffer,sizeof(char)*MAX_SONG_LENGTH,myFile);
      // Copy over string
      strcpy(db->database[i],buffer);
  }
  
  // Import to always remember to close any file we open.
  fclose(myFile);
  // Return the pointer to our database
  return db;
}

// @Name    musicDB_freeDatabase
// @Brief   Frees memory in a music database.
//          Should be called before exiting program.
//
//          Returns -1 if database was unable to be freed.
//          Returns 1 if database was freed.
int musicDB_freeDatabase(musicDB_t* db){
    if(NULL==db){
        return -1;
    }
    // Free each song
    for(int i=0; i < db->size; i++){
        free(db->database[i]);
    }
    // Free the pointers to the songs
    free(db->database);
    // Free the struct
    free(db);

    return 1;
}


// @Name    musicDB_printDatabase
// @Brief   Print out a range of songs from the database 
void musicDB_printDatabase(musicDB_t* db, unsigned int start, unsigned int end){
  int i;
  for(i = start; i < end; i++){
    printf("[%d] %s",i,db->database[i]);
  }
}
