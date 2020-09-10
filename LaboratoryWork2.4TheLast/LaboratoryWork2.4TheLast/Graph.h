#pragma once
#include <string>
#include "Functions.h"
#include "Sequence.h"

template <typename TLabel, typename TWeight>
class Vertex {
private:
	TLabel Label;
	ArrayPriorityQueue<Vertex<TLabel, TWeight> *, TWeight> *Sm;
	bool Used;
public:
	Vertex() {
	}
	Vertex(TLabel Label0) {
		Label = Label0;
		Sm = new ArrayPriorityQueue<Vertex<TLabel, TWeight> *, TWeight>();
		Used = false;
	}
	TLabel GetLabel() {
		return Label;
	}
	int GetSmLength() {
		return Sm->PeekLength();
	}
	Vertex<TLabel, TWeight> *GetSmVertex(int Index) {
		return Sm->Peek(Index);
	}
	TWeight GetSmWeight(int Index) {
		return Sm->PeekPriority(Index);
	}
	bool GetUsed() {
		return Used;
	}
	void AppSmVertexAndWeight(Vertex<TLabel, TWeight> *Item, TWeight Priority) {
		Sm->Enqueue(Item, Priority);
	}
	void SetUsed() {
		Used = true;
	}
	void UnSetUsed() {
		Used = false;
	}
	~Vertex() {
	}
};

template <typename TLabel, typename TWeight>
class Edge {
private:
	Vertex<TLabel, TWeight> *FirstEndpoint;
	Vertex<TLabel, TWeight> *SecondEndpoint;
	TWeight Weight;
public:
	Edge() {
	}
	Edge(Vertex<TLabel, TWeight> *FirstEndpoint0, Vertex<TLabel, TWeight> *SecondEndpoint0, TWeight Weight0) {
		FirstEndpoint = FirstEndpoint0;
		SecondEndpoint = SecondEndpoint0;
		Weight = Weight0;
	}
	Vertex<TLabel, TWeight> *GetFirstEndpoint() {
		return FirstEndpoint;
	}
	Vertex<TLabel, TWeight> *GetSecondEndpoint() {
		return SecondEndpoint;
	}
	TWeight GetWeight() {
		return Weight;
	}
	~Edge() {
	}
};

template <typename TLabel, typename TWeight>
class Graph {
public:
	virtual void AddVertex(TLabel Label) = 0;
	virtual void AddEdge(TLabel TailLabel, TLabel HeadLabel, TWeight Weight) = 0;
	virtual void Clear() = 0;
};

template <typename TLabel, typename TWeight>
class ArrayUndirectedGraph : public Graph<TLabel, TWeight> {
private:
	ArraySequence<Vertex<TLabel, TWeight> *> *Vertices;
	ArraySequence<Edge<TLabel, TWeight> *> *Edges;
	struct Edge0 {
		Vertex<TLabel, TWeight> *FirstEndpoint;
		Vertex<TLabel, TWeight> *SecondEndpoint;
		TWeight Weight;
		bool operator ==(Edge0 Second) {
			return FirstEndpoint == Second.FirstEndpoint && SecondEndpoint == Second.SecondEndpoint;
		}
	};
public:
	ArrayUndirectedGraph() : Graph<TLabel, TWeight>() {
		Vertices = new ArraySequence<Vertex<TLabel, TWeight> *>();
		Edges = new ArraySequence<Edge<TLabel, TWeight> *>();
	}
	Edge<TLabel, TWeight> *GetEdge(int Index) {
		return Edges->Get(Index);
	}
	void AddVertex(TLabel Label) {
		Vertex<TLabel, TWeight> *Item = new Vertex<TLabel, TWeight>(Label);
		bool ContainsVertex = false;
		int MaximumIndex = Vertices->GetLength() - 1;
		for (int i = 0; i <= MaximumIndex; i++) {
			if (Vertices->Get(i)->GetLabel() == Label) {
				ContainsVertex = true;
				break;
			}
		}
		if (ContainsVertex) {
			throw std::out_of_range("Out of range");
		}
		Vertices->Append(Item);
	}
	void AddEdge(TLabel FirstEndpointLabel, TLabel SecondEndpointLabel, TWeight Weight) {
		if (FirstEndpointLabel > SecondEndpointLabel) {
			TLabel Copy = FirstEndpointLabel;
			FirstEndpointLabel = SecondEndpointLabel;
			SecondEndpointLabel = Copy;
		}
		Vertex<TLabel, TWeight> *FirstEndpoint = NULL;
		Vertex<TLabel, TWeight> *SecondEndpoint = NULL;
		int MaximumIndex1 = Vertices->GetLength() - 1;
		for (int i = 0; i <= MaximumIndex1; i++) {
			if (Vertices->Get(i)->GetLabel() == FirstEndpointLabel) {
				FirstEndpoint = Vertices->Get(i);
			}
			if (Vertices->Get(i)->GetLabel() == SecondEndpointLabel) {
				SecondEndpoint = Vertices->Get(i);
			}
			if (!(FirstEndpoint == NULL) && !(SecondEndpoint == NULL)) {
				break;
			}
		}
		if (FirstEndpoint == NULL || SecondEndpoint == NULL) {
			throw std::out_of_range("Out of range");
		}
		Edge<TLabel, TWeight> *Item = new Edge<TLabel, TWeight>(FirstEndpoint, SecondEndpoint, Weight);
		bool ContainsEdge = false;
		int MaximumIndex2 = Edges->GetLength() - 1;
		for (int i = 0; i <= MaximumIndex2; i++) {
			Edge<TLabel, TWeight> *Edge1 = Edges->Get(i);
			if (Edge1->GetFirstEndpoint()->GetLabel() == FirstEndpointLabel && Edge1->GetSecondEndpoint()->GetLabel() == SecondEndpointLabel) {
				ContainsEdge = true;
				break;
			}
		}
		if (ContainsEdge) {
			throw std::out_of_range("Out of range");
		}
		Edges->Append(Item);
		FirstEndpoint->AppSmVertexAndWeight(SecondEndpoint, Weight);
		SecondEndpoint->AppSmVertexAndWeight(FirstEndpoint, Weight);
	}
	ArrayUndirectedGraph<TLabel, TWeight> *GetMinimalSpanningTree() {
		ArrayUndirectedGraph<TLabel, TWeight> *Result = new ArrayUndirectedGraph<TLabel, TWeight>();
		if (Vertices->GetIsEmpty()) {
			return Result;
		}
		int MaximumIndex = Vertices->GetLength() - 1;
		for (int i = 0; i <= MaximumIndex; i++) {
			Result->AddVertex(Vertices->Get(i)->GetLabel());
		}
		ArrayPriorityQueue<Edge0, TWeight> *AvailableEdges0 = new ArrayPriorityQueue<Edge0, TWeight>();
		if (Vertices->Get(0)->GetSmLength() == 0) {
			Result->Clear();
			return Result;
		}
		Edge0 Item0 = { Vertices->Get(0), Vertices->Get(0)->GetSmVertex(0), Vertices->Get(0)->GetSmWeight(0) };
		AvailableEdges0->Enqueue(Item0, Item0.Weight);
		while (!AvailableEdges0->PeekIsEmpty()) {
			Edge0 Current = AvailableEdges0->Dequeue();
			Vertex<TLabel, TWeight> *FirstEndpoint = Current.FirstEndpoint;
			Vertex<TLabel, TWeight> *SecondEndpoint = Current.SecondEndpoint;
			TWeight Weight = Current.Weight;
			if (!FirstEndpoint->GetUsed() || !SecondEndpoint->GetUsed()) {
				Result->AddEdge(FirstEndpoint->GetLabel(), SecondEndpoint->GetLabel(), Weight);
				FirstEndpoint->SetUsed();
				SecondEndpoint->SetUsed();
				for (int i = 0; i <= FirstEndpoint->GetSmLength() - 1; i++) {
					if (!FirstEndpoint->GetSmVertex(i)->GetUsed()) {
						Item0 = { FirstEndpoint, FirstEndpoint->GetSmVertex(i), FirstEndpoint->GetSmWeight(i) };
						AvailableEdges0->Enqueue(Item0, Item0.Weight);
					}
				}
				for (int i = 0; i <= SecondEndpoint->GetSmLength() - 1; i++) {
					if (!SecondEndpoint->GetSmVertex(i)->GetUsed()) {
						Item0 = { SecondEndpoint, SecondEndpoint->GetSmVertex(i), SecondEndpoint->GetSmWeight(i) };
						AvailableEdges0->Enqueue(Item0, Item0.Weight);
					}
				}
			}
		}
		bool Success = true;
		for (int i = 0; i <= MaximumIndex; i++) {
			if (!Vertices->Get(i)->GetUsed()) {
				Success = false;
			}
			Vertices->Get(i)->UnSetUsed();
		}
		if (!Success) {
			Result->Clear();
		}
		return Result;
	}
	void Clear() {
		delete Vertices;
		delete Edges;
		Vertices = new ArraySequence<Vertex<TLabel, TWeight> *>();
		Edges = new ArraySequence<Edge<TLabel, TWeight> *>();
	}
	std::string ArrayGraphToString() {
		std::string Result = "";
		int MaximumIndex1 = Vertices->GetLength() - 1;
		for (int i = 0; i <= MaximumIndex1; i++) {
			Result += "(" + ToString(Vertices->Get(i)->GetLabel()) + ") ";
		}
		Result += "\n";
		int MaximumIndex2 = Edges->GetLength() - 1;
		for (int i = 0; i <= MaximumIndex2; i++) {
			Result += "[" + ToString(Edges->Get(i)->GetFirstEndpoint()->GetLabel()) + " , " +
				ToString(Edges->Get(i)->GetSecondEndpoint()->GetLabel()) + " : " + ToString(Edges->Get(i)->GetWeight()) + "] ";
		}
		Result += "\n";
		return Result;
	}
	~ArrayUndirectedGraph() {
		delete Vertices;
		delete Edges;
	}
};