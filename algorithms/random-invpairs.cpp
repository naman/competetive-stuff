#include <random>
#include <algorithm>
#include <iostream>

//compile with -std=c++11 flag

using namespace std;

void print_vector(vector<int> v){

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
}

int merge(vector<int> v, int start, int mid, int end){

	int merge_count = 0;
	int i = start;
	int j = mid;

	// vector<int> sorted_vector;

	int left_bound = mid - 1; //for i ptr (left subarray)
	int right_bound  = end; // for j ptr (right subarray)

	while(i <= left_bound && j <= right_bound){
		
		if (v[i] > v[j])
		{
			// sorted_vector.push_back(v[j]);
			merge_count += mid - i;
			j++;

		}else{

			// sorted_vector.push_back(v[i]);
			i++;
		}
	}

/*
	//Now this loop ends when any 1 condition of the two fails.
	//We need to copy to the rest of the elements to the sorted vector

	//first copy the left sorted elements
	while(i <= left_bound){
		sorted_vector[i] = v[i];
		i++;
	}

	while(j <= right_bound){
		 sorted_vector[j] = v[j];
		j++;
	}

	for(i = start; i <= end; i++){
		v[i] = sorted_vector[i - start]; //why?
	}
*/
	return merge_count;
}


int merge_sort(vector<int> v, int start, int end){
	int count = 0;

	if (end > start){

		int mid = (start + end)/2;
		count  = merge_sort(v, start, mid) 
			   + merge_sort(v, mid + 1, end)
			   + merge(v, start, mid + 1, end);	
	}
	return count;
}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	vector<int> results;
	for (int j = 0; j < 10; ++j)
	{
		vector<int> v(n);
		/* code */

		for (int i = 1; i <= n; ++i)
		{
			v[i-1] = i;
		}

		random_device rd;
		mt19937 generator(rd());
		shuffle(v.begin(), v.end(), generator);

	// print_vector(v);

		cout << merge_sort(v, 0, n - 1) << endl;
		results.push_back(merge_sort(v, 0, n - 1));
	}

	int sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		sum+=results[i];
	}

	printf("Average: %d\n", sum / (int) results.size());
	printf("as a function of n = n*(n-1)/4\n");
	return 0;
}
