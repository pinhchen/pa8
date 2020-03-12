// Fix the bug in insert so that it continues to work, and so that running with
// the given main doesn't cause a valgrind error for an out-of-bounds memory
// access.  Run with
//
// 		make insert
//
// This insert can assume that the last element in the array elts can be
// overwritten and lost. So for an input array like
//
// 4, 5, 6, 7
//
// inserting 44 at index 2 should change elts to contain:
//
// 4, 5, 44, 6
//
// You *don't* need to make new space and return the new array, just fix the
// memory error that results from trying to do the above.
void insert(int* elts, int size, int index, int toInsert) {
	int i;
	for(i = size - 2; i >= index; i -= 1) {
		elts[i + 1] = elts[i];
  	}
 	elts[index] = toInsert;
  	return;
}

