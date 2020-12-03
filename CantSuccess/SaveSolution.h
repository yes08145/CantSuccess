#include <string>
#include <vector>
#include <iostream>
#pragma once

using namespace std;

class Solution
{
public:
	//basic
	string solution1(vector<string> participant, vector<string> completion);
	//solution2 is hashmap
	string solution2(vector<string> participant, vector<string> completion);
	//프로그래머스 K번째수 풀이없이 성공
	vector<int> solution3(vector<int> array, vector<vector<int>> commands);
	// 풀이 후 수정작업
	vector<int> solution4(vector<int> array, vector<vector<int>> commands);

	~Solution(){
		cout << "\nCall Destructor";
	}
private:

};