//https://www.naukri.com/code360/problems/reverse-the-string_799927


#include <bits/stdc++.h> 
using namespace std;
string reverseString(string str)
{	
    int n=str.length();
	for(int i=0;i<n/2;i++){
		swap(str[i], str[n-i-1]);
	}
	return str;
        // Write your code here.
}