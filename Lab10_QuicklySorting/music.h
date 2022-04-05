#ifndef MUSIC_H
#define MUSIC_H

/* The music header file
 *
 * This includes a structure for
 * holding a database of music 
 * consisting of song titles and
 * the total number of songs
 * in our music database
*/

#define MAX_SONG_LENGTH 80

// This is a music database
typedef struct musicDB{
    unsigned int size;  // Number of songs in the database
    char** database;   // An array of all of the song names.
}musicDB_t;

// Functions
int fileLineCount(const char* fileName);
musicDB_t* musicDB_createDatabase(const char* fileName);
int musicDB_freeDatabase(musicDB_t* db);
void musicDB_printDatabase(musicDB_t* db, unsigned int start, unsigned int end);
#endif
