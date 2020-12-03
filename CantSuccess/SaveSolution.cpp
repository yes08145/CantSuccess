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