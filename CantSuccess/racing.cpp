// ConsoleApplication1.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#include "SaveSolution.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main(){
	Solution solut;
	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
	vector<string> p = { "marina", "josipa", "nicola", "vinko", "filipa" };
	vector<string> c = { "josipa", "filipa" ,"marina" ,"nicola" };
	vector<int> progress = { 95,90,99,80,80,99 };
	vector<int> speeds = { 1,1,1,1,1,1 };
	/*string answer = so.solution1(p,c);*/
	/*vector<int> answer = solut.solution4(array, commands);*/
	/*vector<int> answer = solut.solution6(progress, speeds);
	for (auto ans : answer);
	cout << ans;*/
	vector<string> phone_book = { "119", "97674223", "1195524421" };
	/*cout << answer;*/
	bool sol7_answer = solut.solution7(phone_book);
	cout << sol7_answer;
	
}




// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
