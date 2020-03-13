#include "cutest/CuTest.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
    
/* 
 * Add your tests here
 * A few sample tests 
 * are provided
 */

void TestHeap(CuTest *tc) {
  Heap* h = makeHeap(10);
  CuAssertIntEquals(tc, 0, h->size);
  cleanupHeap(h);
}

void TestOne(CuTest *tc) {
  int two = 2;
  int four = 4;
  CuAssertIntEquals(tc, four, two+two);
}

void TestTwo(CuTest *tc) {
  char* lol = "lol";
  char* alsoLol = "lol";
  CuAssertStrEquals(tc, lol, alsoLol);
}

void TestAdd(CuTest *tc) {
	Heap* h = makeHeap(2);  
	add(h, 1, "a"); 
	add(h, 3, "b"); 
	CuAssertIntEquals(tc, 2, h->size);
	cleanupHeap(h);
}

void TestExpandCapacity(CuTest *tc) {
	Heap* h = makeHeap(2); 
	add(h, 1, "a");
	add(h, 3, "b");
	add(h, 4, "c");
	CuAssertIntEquals(tc, 3, h->size); 
	cleanupHeap(h);
}

void TestBubbleUp(CuTest *tc) {
	Heap* h = makeHeap(4); 
	add(h, 3, "a");
	add(h, 1, "b");
	CuAssertIntEquals(tc, h->elements[0]->key, 1);
	cleanupHeap(h);
}

void TestRemoveMin(CuTest *tc) {
	Heap* h = makeHeap(4);
	add(h, 2, "a");
	add(h, 5, "b");
	add(h, 6, "c");
	add(h, 7, "d");
	add(h, 10, "e");
	removeMin(h);
	CuAssertIntEquals(tc, h->size, 4);
	cleanupHeap(h);
}

void TestPeek(CuTest *tc) {
	Heap* h = makeHeap(4); 
	add(h, 10, "a");
	add(h, 3, "b");
	peek(h);
	CuAssertIntEquals(tc, h->size, 2);
	cleanupHeap(h);
}

void TestPeekonEmpty(CuTest *tc) {
	Heap* h = makeHeap(5); 
	//peek(h); 
	CuAssertStrEquals(tc, NULL, peek(h));
	cleanupHeap(h); 
}

void TestRemoveMinSize1(CuTest *tc) {
	Heap* h = makeHeap(2); 
	add(h, 1, "a");
       	removeMin(h);	
	CuAssertIntEquals(tc, h->size, 0); 
	cleanupHeap(h);
}

void TestAddReverseOrder(CuTest *tc) {
	Heap* h = makeHeap(3); 
	add(h, 9, "a"); 
	add(h, 6, "asd"); 
	add(h, 6, "df"); 
	add(h, 4, "gd"); 
	add(h, 2, "dfag"); 
	CuAssertIntEquals(tc, h->size, 5); 
	cleanupHeap(h);
}

void TestAddDuplicate(CuTest *tc) {
	Heap* h = makeHeap(2); 
	add(h, 2, "a");
	add(h, 2, "b");
	CuAssertIntEquals(tc, h->size, 2);
	cleanupHeap(h); 
}

void TestSize(CuTest *tc) {
	Heap* h = makeHeap(3);
	add(h, 4, "a");
	add(h, 5, "v");
	CuAssertIntEquals(tc, size(h), 2); 
	cleanupHeap(h); 
}

void TestRemoveonEmpty(CuTest *tc) {
	Heap* h = makeHeap(10); 
	CuAssertStrEquals(tc, NULL, removeMin(h));
	cleanupHeap(h); 
}

void TestBubbleDownChooseRight(CuTest *tc) {
	Heap* h = makeHeap(1); 
	add(h, 2, "v");
	add(h, 5, "vgt");
	add(h, 3, "hhv");
	add(h, 6, "vh");
	removeMin(h);
	CuAssertIntEquals(tc, h->elements[0]->key, 3);
       	cleanupHeap(h);
}

void TestBubbleDownStopEarly(CuTest *tc) {
	Heap* h = makeHeap(2); 
	add(h, 1, "t");
	add(h, 2, "t");
	add(h, 4, "t");
	add(h, 6, "t");
	add(h, 7, "t");
	add(h, 8, "t");
	add(h, 5, "t");
	removeMin(h); 
	CuAssertIntEquals(tc, h->elements[1]->key, 5);
	cleanupHeap(h); 
}

	
CuSuite* StrUtilGetSuite() {
  CuSuite* suite = CuSuiteNew();

  /** ADD YOUR TESTS HERE **/
  SUITE_ADD_TEST(suite, TestHeap);
  SUITE_ADD_TEST(suite, TestOne);
  SUITE_ADD_TEST(suite, TestTwo);
  SUITE_ADD_TEST(suite, TestAdd);
  SUITE_ADD_TEST(suite, TestExpandCapacity);
  SUITE_ADD_TEST(suite, TestBubbleUp); 
  SUITE_ADD_TEST(suite, TestRemoveMin);
  SUITE_ADD_TEST(suite, TestPeek);
  SUITE_ADD_TEST(suite, TestRemoveMinSize1);
  SUITE_ADD_TEST(suite, TestAddDuplicate);
  SUITE_ADD_TEST(suite, TestSize);
  SUITE_ADD_TEST(suite, TestPeekonEmpty);
  SUITE_ADD_TEST(suite, TestRemoveonEmpty);
  SUITE_ADD_TEST(suite, TestBubbleDownChooseRight);
  SUITE_ADD_TEST(suite, TestBubbleDownStopEarly);

  return suite;
}


// Don't edit below this line

void RunAllTests(void) {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();
  CuSuite* ourSuite = StrUtilGetSuite();
  
  CuSuiteAddSuite(suite, ourSuite);

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);

  CuStringDelete(output);
  CuSuiteDelete(suite);
  free(ourSuite);
}

int main(void) {
  RunAllTests();
  return 0;
}
