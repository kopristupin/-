#include<iostream>
#include<vector>
#include <algorithm>




int main() {

	std::vector<int> arr;
	int b;
	//stopped by symbol
	while (std::cin)
	{
		std::cin >> b;
		arr.push_back(b);

		}
		
	std::vector<std::pair<int,int>> lengths;
	int n = 1;
	for (int i = 1; i <= arr.size() - 2 / 2 - 1; i = i + 2) {
		std::pair<int, int> p(n, arr[i + 1] - arr[i]);
		lengths.push_back(p);
		n++;
	}
	auto compare = [](std::pair<int, int>& p1, std::pair<int, int>& p2) { return p1.second < p2.second; };
	std::sort(lengths.begin(), lengths.end(), compare);

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
					
					if (arr[it->first*2-1] <= arr[(it2)->first * 2 - 1] && arr[it->first * 2 ] >= arr[it2->first * 2]) 		
						n2++;
	
					if (it2 == lengths.begin())
						break;
			}
			std::pair<int, int> r(it->first, n2-1);
			resultList.push_back(r);
	}

	int c=1;
	for (auto it : resultList) {
std::cout <<"line "<<it.first <<" "<< it.second << "\n";
c++;
	}
		
}
