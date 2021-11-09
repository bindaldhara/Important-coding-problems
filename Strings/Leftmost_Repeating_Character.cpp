#include <bits/stdc++.h>
using namespace std;
#define CHARS 256

int leftRepeating(string& str){
    
    bool visited[CHARS];
    for (int i = 0; i < CHARS; i++)
        visited[i] = false;
 
    // Traverse from right and update res as soon
    // as we see a visited character.
    int res = -1;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (visited[str[i]] == false)
            visited[str[i]] = true;
        else
            res = i;
    }
 
    return res;
}
 
int main(){
    string str = "geeks";
    int index = leftRepeating(str);
    if (index == -1)
        cout<<"Either all characters are distinct or string is empty"<<endl;
    else
        cout<<"First Repeating character is "<<str[index]<<endl;
    return 0;
}
