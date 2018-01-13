#include "stdafx.h"
#include "Stack.h"

void InitStack(LiStack *&s) {
	s = (LiStack *)malloc(sizeof(LiStack));
	s->next = NULL;
}

void DestroyStack(LiStack *&s) {
	LiStack *p = s, *q = s->next;
	while (q != NULL) {
		free(p);
		p = q;
		q = p->next;
	}
	free(p); // p point to the last node, release the space
}

bool StackEmpty(LiStack *s)
{
	/*
	if (s->next != NULL && s != NULL) {
		return false;
	}
	return true;
	*/
	return (s->next == NULL);
}

bool StackEmpty(SqStack *s)
{
	if (s->top == -1) {
		return true;
	}
	else {
		return false;
	}
}

void Push(LiStack *&s, ElemType e)
{
	LiStack *p;
	p = (LiStack *)malloc(sizeof(LiStack));
	p->data = e;
	p->next = s->next; // not p->next = null;
	s->next = p;
}

bool Push(SqStack *&s, ElemType e)
{
	if (s->top == MaxSize -1) {
		return false; // stack overflow
	}
	else {
		s->data[++s->top] = e;
		return true;
	}
}

bool Pop(LiStack *&s, ElemType &e)
{
	/*
	LiStack *p = s->next; 
	e = p->data;
	s->next = p->next;
	free(p);
	*/

	LiStack *p;
	if (s->next == NULL)
		return false;
	p = s->next; // p point to the first node
	e = p->data;  // copy the value to e
	s->next = p->next; // change the s->next pointing
	free(p); // release the node p
	return true;

}

bool Pop(SqStack *&s, ElemType &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top--];
	return true;
}

bool GetTop(LiStack *s, ElemType &e)
{
	if (s->next == NULL) // check if the link stack is empty, which is logic need
		return false;
	e = s->next->data;
	return true;
}

bool GetTop(SqStack *&s, ElemType &e)
{
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	return false;
}

// embraces match test
bool Match(char exp[], int n)
{
	int i = 0; char e = 0;
	
	bool match = true;

	LiStack *st;
	ElemType el;

	InitStack(st);
	while (i < n && match) {
		if (exp[i] == '(') {
			el = exp[i];
			Push(st, el);
		}
		else if (exp[i] == ')') {
			if (GetTop(st, el) == true) {
				if (e != '(')
					match = false;
				else
					Pop(st, el);
			}
			else match = false;
		}
	}

	if (!StackEmpty(st)) { // if the stack is not empty, alse false;
		match = false;
	}
	DestroyStack(st); // destroy the stack 
	return match;
}

void TestSqStack(void){

}

void InitStack(SqStack * s){
	s->top = 1;
}

