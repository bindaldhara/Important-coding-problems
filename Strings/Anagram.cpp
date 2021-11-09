#include <bits/stdc++.h>
using namespace std;
#define CHARS 256

bool Anagram(string &str1, string &str2){
	
	int count[CHARS] = { 0 };
	if(str1.length()!=str2.length())
    return false;
	for (int i = 0; i<str1.length(); i++) {
		count[str1[i]]++;
		count[str2[i]]--;
	}
	
	for (int i = 0; i < CHARS; i++)
		if (count[i])
			return false;
	return true;
}

int main(){
	string str1 = "geeksforgeeks";
	string str2 = "forgeeksgeeks";
	if (Anagram(str1, str2))
		cout << "The two strings are anagram of each other";
	else
		cout << "The two strings are not anagram of each other";
	return 0;
}
