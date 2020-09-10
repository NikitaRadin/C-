#include "Sequence.h"
#include "Graph.h"
#include "Tests.h"

bool ArrayPriorityQueueTest() {
	ArrayPriorityQueue<int, int> *TestArrayPriorityQueue = new ArrayPriorityQueue<int, int>();
	bool Result = true;
	Result &= (TestArrayPriorityQueue->PeekLength() == 0);//0
	TestArrayPriorityQueue->Enqueue(23, 2);
	Result &= (TestArrayPriorityQueue->PeekLength() == 1);//1
	Result &= (TestArrayPriorityQueue->PeekFirst() == 23);//23
	Result &= (TestArrayPriorityQueue->PeekLast() == 23);//23
	Result &= (TestArrayPriorityQueue->Peek(0) == 23);//23
	try {
		TestArrayPriorityQueue->Peek(-1);
		Result = false;
	}
	catch (std::out_of_range Error) {
	}
	try {
		TestArrayPriorityQueue->Peek(-1);
		Result = false;
	}
	catch (std::out_of_range Error) {
	}
	TestArrayPriorityQueue->Enqueue(43, 3);
	Result &= (TestArrayPriorityQueue->PeekLength() == 2);//2
	Result &= (TestArrayPriorityQueue->PeekFirst() == 23);//23
	Result &= (TestArrayPriorityQueue->PeekLast() == 43);//43
	Result &= (TestArrayPriorityQueue->Peek(0) == 23) && (TestArrayPriorityQueue->PeekPriority(0) == 2);//23
	Result &= (TestArrayPriorityQueue->Peek(1) == 43) && (TestArrayPriorityQueue->PeekPriority(1) == 3);//43
	try {
		TestArrayPriorityQueue->Peek(-1);
		Result = false;
	}
	catch (std::out_of_range Error) {
	}
	try {
		TestArrayPriorityQueue->Peek(2);
		Result = false;
	}
	catch (std::out_of_range Error) {
	}
	TestArrayPriorityQueue->Enqueue(53, 1);
	Result &= (TestArrayPriorityQueue->PeekLength() == 3);//3
	Result &= (TestArrayPriorityQueue->PeekFirst() == 53);//53
	Result &= (TestArrayPriorityQueue->PeekLast() == 43);//43
	Result &= (TestArrayPriorityQueue->Peek(0) == 53) && (TestArrayPriorityQueue->PeekPriority(0) == 1);//53
	Result &= (TestArrayPriorityQueue->Peek(1) == 23) && (TestArrayPriorityQueue->PeekPriority(1) == 2);//23
	try {
		TestArrayPriorityQueue->Peek(-1);
		Result = false;
	}
	catch (std::out_of_range Error) {
	}
	try {
		TestArrayPriorityQueue->Peek(3);
		Result = false;
	}
	catch (std::out_of_range Error) {
	}
	Result &= (TestArrayPriorityQueue->Dequeue() == 53);
	Result &= (TestArrayPriorityQueue->Dequeue() == 23);
	Result &= (TestArrayPriorityQueue->Dequeue() == 43);
	try {
		TestArrayPriorityQueue->Dequeue();
		Result = false;
	}
	catch (std::out_of_range Error) {
	}
	delete TestArrayPriorityQueue;
	return Result;
}

bool ArrayGraphTest() {
	ArrayUndirectedGraph<int, int> *TestArrayUndirectedGraph = new ArrayUndirectedGraph<int, int>();
	bool Result = true;
	TestArrayUndirectedGraph->AddVertex(1);
	try {
		TestArrayUndirectedGraph->AddVertex(1);
		Result = false;
	}
	catch (std::out_of_range Error) {
	}
	TestArrayUndirectedGraph->AddVertex(2);
	TestArrayUndirectedGraph->AddEdge(1, 2, 1);
	try {
		TestArrayUndirectedGraph->AddEdge(1, 2, 2);
		Result = false;
	}
	catch (std::out_of_range Error) {
	}
	try {
		TestArrayUndirectedGraph->AddEdge(2, 1, 2);
		Result = false;
	}
	catch (std::out_of_range Error) {
	}
	delete TestArrayUndirectedGraph;
	return Result;
}

bool GetMinimalSpanningTreeTest() {
	ArrayUndirectedGraph<int, int> *AUG = new ArrayUndirectedGraph<int, int>();
	bool Result = true;
	AUG->AddVertex(1);
	AUG->AddVertex(2);
	AUG->AddVertex(3);
	AUG->AddVertex(4);
	AUG->AddVertex(5);
	AUG->AddVertex(6);
	AUG->AddVertex(7);
	AUG->AddEdge(1, 7, 2);
	AUG->AddEdge(1, 2, 3);
	AUG->AddEdge(2, 3, 2);
	AUG->AddEdge(3, 4, 1);
	AUG->AddEdge(4, 5, 2);
	AUG->AddEdge(2, 5, 4);
	AUG->AddEdge(2, 4, 5);
	AUG->AddEdge(1, 5, 1);
	AUG->AddEdge(6, 7, 3);
	AUG->AddEdge(5, 6, 5);
	ArrayUndirectedGraph<int, int> *MST = AUG->GetMinimalSpanningTree();
	Result &= (MST->GetEdge(0)->GetFirstEndpoint()->GetLabel() == 1 && MST->GetEdge(0)->GetSecondEndpoint()->GetLabel() == 5);
	Result &= (MST->GetEdge(1)->GetFirstEndpoint()->GetLabel() == 1 && MST->GetEdge(1)->GetSecondEndpoint()->GetLabel() == 7);
	Result &= (MST->GetEdge(2)->GetFirstEndpoint()->GetLabel() == 4 && MST->GetEdge(2)->GetSecondEndpoint()->GetLabel() == 5);
	Result &= (MST->GetEdge(3)->GetFirstEndpoint()->GetLabel() == 3 && MST->GetEdge(3)->GetSecondEndpoint()->GetLabel() == 4);
	Result &= (MST->GetEdge(4)->GetFirstEndpoint()->GetLabel() == 2 && MST->GetEdge(4)->GetSecondEndpoint()->GetLabel() == 3);
	Result &= (MST->GetEdge(5)->GetFirstEndpoint()->GetLabel() == 6 && MST->GetEdge(5)->GetSecondEndpoint()->GetLabel() == 7);
	return Result;
}