// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class MySearchAndSortFunction
{
public:
	MySearchAndSortFunction()
	{
		data = { 2,5,4,7,9,3,6,8,7,1,0,10 };
	}
	void PrintData()
	{
		for (auto p : data)
			cout << p<<" ";
		cout << endl;
	}
	int BinarySearch(vector<int> & arr, int key);
	void InsertSort(vector<int> &arr);
	void BinaryInserSort(vector<int> & a);
	void ShellSort(vector<int> & a);
	void SelectSort(vector<int> &a);
	void BetterBubbleSort(vector<int> &a);
	void BubbleSort(vector<int> &a);

	void MergeSort(vector<int> &a);
	vector<int> data;
private:
	void MergeSort(vector<int> &a, int *temp, int low, int high);
	void Merge(vector<int> &a, int *temp, int low, int mid, int high);





	
};

int MySearchAndSortFunction::BinarySearch(vector<int> & arr, int key)
{
	int low = 0;
	int high = arr.size()-1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == key)
			return mid;
		else if (key < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;

	}
	return -1;
}

void MySearchAndSortFunction::InsertSort(vector<int> &arr)
{
	if (arr.empty())
		return;
	int length = arr.size();
	int temp;//用于存放当前要插入的元素，来与前面已排好序的各个数进行比较，找到插入点
	for (int i = 1; i < length; ++i)//假设第一个元素已插入，从第二个元素开始比较
	{
		temp = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > temp; --j)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
	return;

}

void MySearchAndSortFunction::BinaryInserSort(vector<int> & a)
{
	if (a.empty())
		return;
	
	int temp,j;
	for (int i = 1; i < a.size(); ++i)
	{
		temp = a[i];
		//二分查找到已排序序列最左边的那个大于待插入值的位置
		int low = 0;
		int high = i-1;
		
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (a[mid] > temp)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >=low; --j)
			a[j + 1] = a[j];
		a[low] = temp;
	}
}

void MySearchAndSortFunction::ShellSort(vector<int> & a)
{
	int d = a.size() / 2;
	int temp,j;
	while (d > 0)
	{
		for (int i = d; i < a.size(); ++i)
		{
			temp = a[i];
			for ( j = i - d; j >= 0 && a[j] > temp; j -= d)
			{
				a[j + d] = a[j];
			}
			a[j + d] = temp;
		}
		d = d / 2;
	}
	return;
}

void MySearchAndSortFunction::SelectSort(vector<int> &a)
{
	if (a.empty())
		return;
	int min,minindex;
	for (int i = 0; i < a.size(); ++i)
	{
		min = a[i];
		for (int j = i + 1; j < a.size(); ++j)
		{
			if (a[j] < min)
			{
				min = a[j];
				minindex = j;
			}
				
		}
		if (a[i] != min)
		{
			int temp = a[i];
			a[i] = min;
			a[minindex] = temp;
		}
			
	}
}

void MySearchAndSortFunction::BetterBubbleSort(vector<int> &a)
{
	if (a.empty())
		return;
	int length = a.size();
	int pos;//记录最后一次交换的位置，说明从该位置后面的都没有发生交换，也就是后面的有序，不用比较了
	bool is_exchange;//用于判断一趟是否有交换，如果没有发生交换说明数组整体已经有序
	int k=length-1;
	for (int i = 0; i < length-1; ++i)//确定趟数，每一趟都将一个剩余数组中最大的数移到剩余数组的最右边
	{
		is_exchange = false;
		for (int j = 0; j < k; ++j)// 确定比较范围，每一趟将最大值移到最右边
		{
			if (a[j] >a[j + 1])
			{
				swap(a[j], a[j + 1]);
				pos = j;
				is_exchange = true;
			}
		}
		if (!is_exchange)//如果没有发生交换说明数组整体已经有序
			break;
		k = pos;
	}

}

void MySearchAndSortFunction::BubbleSort(vector<int> &a)
{
	if (a.empty())
		return;
	for (int i = 0; i < a.size() - 1; ++i)//趟数
	{
		for (int j = 0; j < a.size()-1-i; ++j)//范围
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void MySearchAndSortFunction::MergeSort(vector<int> &a)
{
	if (a.empty())
		return;
	int * temp = new int[a.size()];
	MergeSort(a, temp, 0, a.size() - 1);
	delete[] temp;
}

void MySearchAndSortFunction::MergeSort(vector<int> &a, int *temp, int low, int high)
{
	if (low >= high)
	{
		return;

	}
		
	int mid = (low + high) / 2;
	MergeSort(a, temp, low, mid);
	MergeSort(a, temp, mid + 1, high);
	if (a[mid] <= a[mid + 1])
		return;
	Merge(a, temp, low, mid, high);
}



void MySearchAndSortFunction::Merge(vector<int> &a, int *temp, int low, int mid, int high)
{
	int lpos = low;//左边数组起点，终点mid
	int rpos = mid + 1;//右边数组起点，终点high
	for (int i = low; i <=high; ++i)
		temp[i] = a[i];

	for (int i = low; i <= high; ++i)
	{
		if (lpos > mid)
			a[i] = temp[rpos++];
		else if (rpos > high)
			a[i] = temp[lpos++];
		else if (temp[lpos] < temp[rpos])
			a[i] = temp[lpos++];
		else
			a[i] = temp[rpos++];
	}
		

}

int main()
{
	MySearchAndSortFunction a;
	a.PrintData();
	a.MergeSort(a.data);
	a.PrintData();
	//cout << a.BinarySearch(a.data, 11);
}

