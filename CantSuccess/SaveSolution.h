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
	//���α׷��ӽ� K��°�� Ǯ�̾��� ����
	vector<int> solution3(vector<int> array, vector<vector<int>> commands);
	// Ǯ�� �� �����۾�
	vector<int> solution4(vector<int> array, vector<vector<int>> commands);

	~Solution(){
		cout << "\nCall Destructor";
	}
private:

};