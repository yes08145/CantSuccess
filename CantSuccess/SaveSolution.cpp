#include "SaveSolution.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
// basic sort
string Solution::solution1(vector<string> participant, vector<string> completion) {
		sort(participant.begin(), participant.end());
		sort(completion.begin(), completion.end());
		for (int i = 0; i < completion.size(); i++) {
			if (participant[i] != completion[i])
				return participant[i];
		}
		return participant[participant.size() - 1];
	}
//solution2 is hashmap
string Solution::solution2(vector<string> participant, vector<string> completion) {
		string answer = "";
		unordered_map<string, int> strMap;
		for (auto com : completion) {
			if (strMap.end() == strMap.find(com)) // find의 경우 해당키가 있으면 iterator, 없으면 end()리턴한다.
				strMap.insert(make_pair(com, 1));
		}

		for (auto part : participant) {

			if (strMap.end() == strMap.find(part))
			{
				answer = part;
				break;
			}
			else
			{
				strMap[part]--;
				if (strMap[part] < 0)
				{
					answer = part;
					break;
				}
			}
		}
		return answer;
	}
//프로그래머스 K번째수 풀이없이 성공
vector<int> Solution::solution3(vector<int> array, vector<vector<int>> commands) {
		vector<int> answer;

		for (int a = 0; a < commands.size(); a++) {
			int fir = commands[a][0];
			int sec = commands[a][1];
			int select = commands[a][2];
			vector<int> array2;
			answer.resize(commands.size());
			copy(array.begin() + fir - 1, array.begin() + sec, back_inserter(array2));
			sort(array2.begin(), array2.end());
			answer[a] = array2[select - 1];
		}
		return answer;
	}
// 풀이 후 수정작업
vector<int> Solution::solution4(vector<int> array, vector<vector<int>> commands) {
		vector<int> answer;
		vector<int> c_array;
		answer.resize(commands.size());

		for (int a = 0; a < commands.size(); a++) {
			c_array = array;
			sort(c_array.begin() + commands[a][0] - 1, c_array.begin() + commands[a][1]);
			answer[a] = c_array[commands[a][0] + commands[a][2] - 2]; // (commands[a][0] -1) + (commands[a][2] -1) 
			/*answer.push_back(c_array[commands[a][0] + commands[a][2] - 2]);  이렇게 하면 answer.resize(commands.size()가 없어도 됨*/
		}
		return answer;
	}

vector<int> Solution::solution5(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> cpypro;
	int value = 0;
	cpypro.resize(progresses.size());
	int count = 0;
	for (int i = 0; i < progresses.size(); i++) {
		cpypro[i] = (100 - progresses[i]) / speeds[i];

		if ((100 - progresses[i]) % speeds[i] != 0) {
			cpypro[i] += 1;
		}
		if (i == 1) {
			if (cpypro[1] > cpypro[0]) {
				answer.push_back(count);
				value = cpypro[1];
				count = 0;
			}
			else {
				value = cpypro[0];
			}
		}
		else if (i > 1) {
			if (cpypro[i] > value) {
				answer.push_back(count);
				value = cpypro[i];
				count = 0;
			}
		}
		count++;
	}
	answer.push_back(count);
	return answer;
}

vector<int> Solution::solution6(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int day;
	int max_day = 0;

	for (int i = 0; i < progresses.size(); i++) {
		day = (99 - progresses[i]) / speeds[i] + 1; // 99%까지 몇일이 걸리나 확인을 하는 과정(만약 2일이 걸리면 100% 까지는 2.xxxxx일이 걸리고 이는 즉 3일이 걸리는 것!)
		if (answer.empty() || max_day < day)
			answer.push_back(1);
		else
			++answer.back();

		if (max_day < day)
			max_day = day;
	}
	return answer;
}

bool Solution::solution7(vector<string> phone_book) {
	
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size()-1;i++) {
		if (phone_book[i+1].find(phone_book[i]) == 0) {
			answer = false;
			break;
		}
	}
	return answer;
}