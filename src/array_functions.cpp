/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 *  Edits on: Sep 24, 2019
 *      Author: George Minnigerode
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "array_functions.h"
#include "constants.h"
#include "utilities.h"


//A structure to track words and number of occurrences
struct entry{
	std::string word;
	int number_occurrences;
};

//Global array of entry structs (global to this file)
entry entryArray [2100];

//Index of next available slot in array
int nextSlot = 0;

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

//Invalid input file
const int EMPTY_INPUT_FILE = 0;

//Invalid index
const int INVALID_INDEX = -1;

//Invalid word requested
const std::string INVALID_WORD = "invalid";

//myfstream is not open
const bool STREAM_NOT_OPEN = false;

//File failed to open
const int FAILED_TO_OPEN = false;

//Can't open file with given filename
const int FAIL_FILE_DID_NOT_OPEN = -1;


//Zeroes out array that tracks words and their occurrences
void clearArray(){
	nextSlot = 0;
}

//Number of unique words in an array
int getArraySize(){
	if(nextSlot == 0){
		return EMPTY_INPUT_FILE;
	}
	return nextSlot;
}

//Gets word at given index from array
std::string getArrayWordAt(int i){
	if(i < nextSlot){
		return INVALID_WORD;
	}
	return entryArray[i].word;
}

//Gets number of occurrences of word at given index
int getArrayWord_NumbOccur_At(int i){
	if(i < nextSlot){
			return INVALID_INDEX;
		}
		return entryArray[i].number_occurrences;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){

	return STREAM_NOT_OPEN;
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){

}

/*Keep track of how many times each token seen*/
void processToken(std::string &token){

}

//Opens file, returns true if successful and false otherwise
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode){
	return FAILED_TO_OPEN;
}

// Closes myfile iff it is open
void closeFile(std::fstream& myfile){

}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename){
	return FAIL_FILE_DID_NOT_OPEN;
}

//Sort myEntryArray based on so enum value.
void sortArray(constants::sortOrder so){

}

