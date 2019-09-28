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

using namespace std;
using namespace constants;

//A structure to track words and number of occurrences
struct entry{
	string word;
	int number_occurrences;
};

//Global array of entry structs (global to this file)
entry entryArray [2100];

//Index of next available slot in array
int nextSlot = 0;


//Invalid index
const int INVALID_INDEX = -1;

//Invalid word requested
const string INVALID_WORD = "";

//myfstream is not open
const bool STREAM_NOT_OPEN = false;

//File did not open
const bool FAILED_TO_OPEN = false;

//Zeroes out array that tracks words and their occurrences
void clearArray(){
	nextSlot = 0;
}

//Number of unique words in an array
int getArraySize(){
	if(nextSlot == 0){
		return 0;
	}
	return nextSlot;
}

//Gets word at given index from array
string getArrayWordAt(int i){
	if(i >= nextSlot || i<0){
		return INVALID_WORD;
	}
	return entryArray[i].word;
}

//Gets number of occurrences of word at given index
int getArrayWord_NumbOccur_At(int i){
	if(i >= nextSlot || i<0){
			return INVALID_INDEX;
	}
	return entryArray[i].number_occurrences;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(fstream &myfstream){
	if(myfstream.is_open()){
		string line;

		while(!myfstream.eof()){
			getline(myfstream, line);

			processLine(line);
		}
		return true;
	}

	return STREAM_NOT_OPEN;
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(string &myString){
	stringstream ss(myString);
	string temp;

	while(getline(ss,temp,' ')){
		processToken(temp);
	}
}

/*Keep track of how many times each token seen*/
void processToken(string &token){
	strip_unwanted_chars(token);
	if(token.size() == 0){
		return;
	}

	for(int i=0; i<nextSlot; i++){


		string copyToken = token;
		string copyEntry = entryArray[i].word;

		toUpper(copyToken);
		toUpper(copyEntry);

		if(copyToken == copyEntry){
			entryArray[i].number_occurrences++;
			return;
		}
	}
	entryArray[nextSlot].word = token;
	entryArray[nextSlot].number_occurrences = 1;
	nextSlot++;
}

//Opens file, returns true if successful and false otherwise
bool openFile(fstream& myfile, const string& myFileName,
		ios_base::openmode mode){
	myfile.open(myFileName, mode);
	if(myfile.is_open()){
		return true;
	}
	return FAILED_TO_OPEN;
}

// Closes myfile iff it is open
void closeFile(fstream& myfile){
	if(myfile.is_open()){
		myfile.close();
	}
}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const string &outputfilename){
	fstream outputFile;
	if(!openFile(outputFile,outputfilename,ios_base::openmode::_S_out)){
		return FAIL_FILE_DID_NOT_OPEN;
	}
	if(nextSlot == 0){
		return FAIL_NO_ARRAY_DATA;
	}

	for(int i = 0; i<nextSlot; i++){
		string occurString = to_string(entryArray[i].number_occurrences);
		outputFile << entryArray[i].word + " " + occurString + "\n";
	}

	closeFile(outputFile);
	return SUCCESS;
}

//Sort myEntryArray based on so enum value.
void sortArray(sortOrder so){
	switch(so){
		case NONE:
			break;
		case DESCENDING:
		{
			int i, j;

			int n = nextSlot;

			for (i = 1; i < n; i++){
				for (j = 0; j < n-1; j++){
					string currentCopy = entryArray[j].word;
					string nextCopy = entryArray[j+1].word;

					toUpper(currentCopy);
					toUpper(nextCopy);
					if(currentCopy<nextCopy){
						string tempWord;
						int tempOccur;
						tempWord = entryArray[j].word;
						tempOccur = entryArray[j].number_occurrences;
						entryArray[j].word = entryArray[j+1].word;
						entryArray[j].number_occurrences = entryArray[j+1].number_occurrences;
						entryArray[j+1].word = tempWord;
						entryArray[j+1].number_occurrences = tempOccur;
					}
				 }
			  }
			break;
		}
		case NUMBER_OCCURRENCES:
		{
			int i, j;

			int n = nextSlot;

			for (i = 1; i < n; i++){
				for (j = 0; j < n-1; j++){
					if(entryArray[j].number_occurrences < entryArray[j+1].number_occurrences){
						string tempWord;
						int tempOccur;
						tempWord = entryArray[j].word;
						tempOccur = entryArray[j].number_occurrences;
						entryArray[j].word = entryArray[j+1].word;
						entryArray[j].number_occurrences = entryArray[j+1].number_occurrences;
						entryArray[j+1].word = tempWord;
						entryArray[j+1].number_occurrences = tempOccur;
					}
				 }
			  }
			break;
		}
		case ASCENDING:
		{
			int i, j;

			int n = nextSlot;

			for (i = 1; i < n; i++){
				for (j = 0; j < n-1; j++){
					string currentCopy = entryArray[j].word;
					string nextCopy = entryArray[j+1].word;

					toUpper(currentCopy);
					toUpper(nextCopy);
					if(currentCopy>nextCopy){
						string tempWord;
						int tempOccur;
						tempWord = entryArray[j].word;
						tempOccur = entryArray[j].number_occurrences;
						entryArray[j].word = entryArray[j+1].word;
						entryArray[j].number_occurrences = entryArray[j+1].number_occurrences;
						entryArray[j+1].word = tempWord;
						entryArray[j+1].number_occurrences = tempOccur;
					}
				 }
			  }
			break;
		}
	}
}

