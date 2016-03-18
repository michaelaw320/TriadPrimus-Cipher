/*
 * NewGeneration.cpp
 *
 *  Created on: 17 Mar 2016
 *      Author: Michael
 */

#include "NewGeneration.h"

using namespace std;

NewGeneration::NewGeneration(std::string _key, std::vector<Block>* blockToModify) {
	key = _key;
	workingBlock = blockToModify;
}

NewGeneration::~NewGeneration() {
	// TODO Auto-generated destructor stub
}

void NewGeneration::scramble() {
}

void NewGeneration::descramble() {
}

void NewGeneration::generateTableOfDataPlacement() {
	/*
	 * Translate this from Java Module:
	 public static int[] getShuffledInts(String strSeed, int min, int max){
        // bentuk seed untuk random
        long seed = 0;
        for (int i = 0; i < strSeed.length(); i++)
            seed += (long)strSeed.charAt(i);

        // buat array berisi angka dari min sd max
        List<Integer> arrayToShuffle = new ArrayList<Integer>();
        for (int i = min; i <= max; i++)
            arrayToShuffle.add(i);

        // acak-acak dengan seed yang diberikan
        Collections.shuffle(arrayToShuffle, new Random(seed));

        // convert ke primitive
        int shuffledInts[] = new int[max - min + 1];
        for (int i = 0; i < shuffledInts.length; i++){
            shuffledInts[i] = arrayToShuffle.get(i);
        }

        return shuffledInts;
    }
	 */
}
