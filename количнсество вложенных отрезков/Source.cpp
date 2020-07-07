#include<iostream>
#include<vector>
#include <algorithm>
#include<sstream>
#include<string>



int main() {


	std::vector<int> arr;
	std::string inp;
		std::stringstream strs;
		int count;
		std::cin >> count;
		std::vector<int> result2;
	
		for (int i = 0; i <= count; i++) {
			getline(std::cin, inp);
			strs << inp + " ";
		}

		int num;
		while (strs >> num)
			arr.push_back(num);


	std::vector<std::pair<int,int>> lengths;
	int n = 1;
	for (int i = 0; i <= arr.size() - 2 / 2 - 1; i = i + 2) {
		std::pair<int, int> p(n, arr[i + 1] - arr[i]);
		lengths.push_back(p);
		n++;
	}
	auto compare = [](std::pair<int, int>& p1, std::pair<int, int>& p2) { return p1.second < p2.second; };
	std::sort(lengths.begin(), lengths.end(), compare);

	std::cout << " sorted: "; for (auto it : lengths) std::cout << it.first << " " << it.second << "\n";

	std::vector<std::pair<int, int>>::iterator it= lengths.end()-1;// current object to check
	std::vector<std::pair<int, int>>::iterator it2;

	std::vector<std::pair<int,int>> resultList;
	
	for (; it >= lengths.begin(); it--) {
		int n2 = 1;
		
		if (it == lengths.begin()) {
			std::pair<int, int> r(it->first, n2 - 1);
			resultList.push_back(r);
			break;
		}
				
		it2 = it-1;
			for (; it2>= lengths.begin();it2--) {	
					
					if (arr[it->first*2-2] <= arr[(it2)->first * 2 - 2] && arr[it->first * 2-1 ] >= arr[it2->first * 2-1]) 		
						n2++;
	
					if (it2 == lengths.begin())
						break;
			}
			std::pair<int, int> r(it->first, n2-1);
			resultList.push_back(r);
	}

	auto compareNumber = [](std::pair<int, int>& p1, std::pair<int, int>& p2) { return p1.first < p2.first; };
	std::sort(resultList.begin(), resultList.end(), compareNumber);
		
	int c=1;
	for (auto it : resultList) {
std::cout <<"line "<<it.first <<" "<< it.second << "\n";
c++;
	}
		
}
