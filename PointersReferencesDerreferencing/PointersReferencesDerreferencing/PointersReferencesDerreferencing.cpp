// PointersReferencesDerreferencing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

void passByValue(int i)
{
    i += i;
    std::wcout << L"...inside passByValue, new value of i: " << i << std::endl;
}

void passByReference(int &i)
{
    i += i;
    std::wcout << L"...inside passByReference, new value of i: " << i << std::endl;
}

void passByPointer(int* i)
{
    *i += *i;
    std::wcout << L"...inside passByReference, new value of *i: " << *i << std::endl;
}

void passByValue(std::wstring s)
{
    s = std::wstring(L"This is a strange world with penguins, trees, compasses, and others.");
    std::wcout << L"...inside passByValue, new value of s: " << s << std::endl;
}

void passByReference(std::wstring &s)
{
    s = std::wstring(L"This is a strange world with penguins, trees, compasses, and others.");
    std::wcout << L"...inside passByReference, new value of s: " << s << std::endl;
}

void passByPointer(std::wstring *s)
{
    *s = std::wstring(L"هذا هو عالم غريب مع طيور البطريق، والأشجار، البوصلات، وغيرها.");
    std::wcout << L"...inside passByPointer, new value of s: " << *s << std::endl;
}

void createIntAndReturnByPointer(int *i)
{
    int n(4);
    i = &n;
}

int main()
{
    int *pi = NULL;

    int entero1(12);
    int entero2(3);
    int entero3(59);

    std::wstring texto1(L"Este es un extraño mundo con pingüinos, árboles, brújulas, y otros.");
    std::wstring texto2(L"Das ist eine seltsame Welt mit Pinguinen, Bäume, Kompaße und andere");

    //std::wcout << L"pi: " << *pi << std::endl;

    std::wcout << L"entero1: " << entero1 << std::endl;
    std::wcout << L"entero2: " << entero2 << std::endl;
    std::wcout << L"entero3: " << entero3 << std::endl;

    std::wcout << L"texto1: " << texto1 << std::endl;
    std::wcout << L"texto2: " << texto2 << std::endl;

    createIntAndReturnByPointer(pi);
    std::wcout << L"valor of pi, después de createIntAndReturnByPointer: " << *pi << std::endl;

    passByValue(entero1);
    std::wcout << L"entero1, después de passByValue: " << entero1 << std::endl;

    passByReference(entero1);
    std::wcout << L"entero1, después de passByReference: " << entero1 << std::endl;

    passByPointer(&entero1);
    std::wcout << L"entero1, después de passByPointer: " << entero1 << std::endl;

    passByValue(texto1);
    std::wcout << L"texto1, después de passByValue: " << texto1 << std::endl;

    passByReference(texto1);
    std::wcout << L"texto1, después de passByReference: " << texto1 << std::endl;

    passByPointer(&texto1);
    std::wcout << L"texto1, después de passByPointer: " << texto1 << std::endl;


    return 0;
}

